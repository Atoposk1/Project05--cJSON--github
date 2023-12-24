#include <stdio.h>
#include <stdlib.h>

void yichu(char* str);

typedef struct JSONNode {
    char* key;
    char* value;            //改成指针使得存放和提取更加的灵活
    struct JSONNode* child;  
    struct JSONNode* next;   
} JSONNode;


int main() {
    // 读取 JSON 文件路径
    char file_path1[300];
    printf("输入要读取的 JSON 文件路径: ");
    scanf("%s", file_path1);

    // 打开读取的文件
    FILE* file1 = fopen(file_path1, "r");
    if (file1 == NULL) 
    {
        printf("无法打开文件");
        return 0;
    }

    // 读取文件大小
    fseek(file1, 0, SEEK_END);//将文件指针移到文件末尾
     long int file_size = ftell(file1);//ftell计算json文件大小，默认相对于文件开头
    fseek(file1, 0, SEEK_SET);//计算结束后再将文件指针移动到文件开头位置
                             //因为在对文件进行读写操作时，文件的指针位置是关键的，如果在计算大小后不降指针移回文件的开头位置，会出现错误

    // 分配内存保存 JSON 数据
    char* jsonData = (char*)malloc(file_size + 1);
    if (jsonData == NULL) 
    {
        printf("内存分配失败\n");
        fclose(file1);//内存分配失败关闭文件
        return 0;
    }
    //jsonData[file_size + 1] = '\0';

    // 读取 JSON 数据
    fread(jsonData, 1, file_size, file1);//以二进制形式读取文件，从file1中读取到jsonData中
    //jsonData[file_size + 2] = '\0';

    // 关闭读取的文件
    fclose(file1);

   
    // 输出压缩前的树状格式 JSON 数据
    printf("JSON 数据:\n%s\n", jsonData);

    // 输入要写入的 JSON 文件路径
    char file_path2[300];
    printf("输入要写入的 JSON 文件路径: ");
    scanf("%s", file_path2);

    // 打开要写入的文件
    FILE* file2 = fopen(file_path2, "w");
    if (file2 == NULL) {
        printf("无法打开文件");
        free(jsonData);  // 释放动态分配的内存
        return 0;
    }

    // 写入 JSON 数据到另一个文件
    fwrite(jsonData, 1, file_size, file2);
    
    // 关闭写入的文件
    fclose(file2);

    // 释放动态分配的内存     //该动态分配的内存需要在压缩写入另一个文件之后再释放
    //free(jsonData);

    printf("JSON 数据已成功写入文件 %s\n", file_path2);




    //以上实现以树状的形式输出并以树状形式存入文件
    //以下将对文件进行压缩并存入另一个文件


    //输入3号文件的路径
    char file_path3[300];
    printf("请输入要再次存入的文件路径:");
    scanf("%s", file_path3);

    //打开3号文件
    FILE* file3 = fopen(file_path3, "w");
    if (file3 == NULL)
    {
        printf("无法打开文件\n");
        return 0;
    }

    //压缩文件
    
        // 移除空格和换行符，实现压缩
        yichu(jsonData);
    
        //将文件写入3号文件
        fprintf(file3, "%s", jsonData);
        printf("JSON数据已成功写入");


    //写入完成后释放为 jsonData 所分配的内存
        free(jsonData);

     //关闭文件
        fclose(file3);




    return 0;
}

// 移除字符串中的空格和换行符
void yichu(char* str)
{
    int i = 0, j = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            str[j] = str[i];//跳过非字符的
            j++;
        }
        i++;
    }

   // str[j] = '\0';//加上字符串终止符，正确终止
}
