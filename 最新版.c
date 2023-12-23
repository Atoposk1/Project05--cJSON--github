#include <stdio.h>
#include <stdlib.h>



typedef struct JSONNode {
    char key;
    char value;
    struct JSONNode* child;  // 子节点，用于表示对象的成员
    struct JSONNode* next;   // 兄弟节点，用于表示数组的元素或对象的兄弟成员
} JSONNode;



int main() {
    // 读取 JSON 文件路径
    char file_path1[300];
    printf("输入要读取的 JSON 文件路径: ");
    scanf("%s", file_path1);

    // 打开读取的文件
    FILE* file1 = fopen(file_path1, "r");
    if (file1 == NULL) {
        printf("无法打开文件");
        return 0;
    }

    // 读取文件大小
    fseek(file1, 0, SEEK_END);
    long file_size = ftell(file1);
    fseek(file1, 0, SEEK_SET);

    // 分配内存保存 JSON 数据
    char* jsonData = (char*)malloc(file_size + 1);
    if (jsonData == NULL) {
        printf(stderr, "内存分配失败\n");
        fclose(file1);//内存分配失败关闭文件
        return 0;
    }

    // 读取 JSON 数据
    fread(jsonData, 1, file_size, file1);//以二进制形式读取文件，从file1中读取到jsonData中
    //jsonData[file_size] = '\0';  // 在字符串末尾添加 null 终止符

    // 关闭读取的文件
    fclose(file1);

    // 输出 JSON 数据
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

    // 释放动态分配的内存
    free(jsonData);

    printf("JSON 数据已成功写入文件 %s\n", file_path2);

    return 0;
}


