#include<stdio.h>
#include <stdlib.h>//实现内存的动态分配
#include <string.h>




typedef struct JSONNode {
	    char key;
	    char value;
	    struct JSONNode* child;  // 子节点，用于表示对象的成员
	    struct JSONNode* next;   // 兄弟节点，用于表示数组的元素或对象的兄弟成员
	} JSONNode;



int main()
{
	//读取 JSON 文件路径
	char file_path1[300];
	printf("输入文件路径: ");
	scanf("%s", file_path1);

	//打开文件
	FILE* file = fopen(file_path1, "r");
	if ((file = fopen(file_path1, "r")) == NULL)
	{
		/*printf("无法打开 JSON 文件\n");
		return 0;*/
		perror("无法打开文件");
		return EXIT_FAILURE;
	}
	
	
	
	
	//获取文件大小，用于内存动态分配
	fseek(file, 0, 2);
	long file_size = ftell(file);//ftell函数默认从文件开始位置到文件指针的指向位置计算字节数的大小
	fseek(file, 0, SEEK_SET);//计算完成后将文件指针在移回文件的起始位置
	long long k = file_size;

	
	
	//JSONNode* head = 0;//定义头指针
	//JSONNode* fp = 0;
	//JSONNode* p = (JSONNode*)malloc(sizeof(JSONNode));//创建子节点
	//if (p == 0) 
	//{
	//	fprintf(stderr, "内存分配失败\n");
	//	fclose(file);
	//	return 1;
	//}






	// 分配内存保存 JSON 数据
	char* jsonData = (char*)malloc(file_size + 1);
	if (jsonData == NULL) 
	{
		printf("内存分配失败");
		return 0;
	}

	//读取json数据
	fread(jsonData, malloc(sizeof(char)), file_size, file);//将读取的json数据存放在jsonData中
	

	





	char file_path2[300];
	printf("输入要写入的文件路径: ");

	scanf("%s", file_path2);

	FILE* file1 = fopen(file_path2, "w");
	if (file_path2 == NULL)
	{
		printf("无法打开文件");
		return 0;
	}
	
	//写入文件
	fwrite(jsonData, malloc(sizeof(char)),file_size, file1);


	//关闭文件
	fclose(file);



	//关闭2号文件

	fclose(file1);



	//释放动态内存
	free(jsonData);
	





	




	//输出文件大小，跳过判断文件格式是否符合json文件格式的判断操作
	//先关闭文件文件在输出文件的大小
	//fclose(file);
	//printf("File size: %ld bytes\n", file_size);




	////先跳过缩进，直接将文件保存到另一个文件当中
	//char file_path2[300];
	//printf("Enter the scanf path to the JSON file: ");
	//scanf("%s", file_path2);
	//FILE* file1 = fopen(file_path2, "w");
	//if(file_path2 == NULL)
	//{
	//	printf("Error");
	//	return 0;
	//}

	//写入文件//先读取文件
	/*char ch[10000];

	fscanf(file, "%s", &ch);

	fprintf(file1, "%s", ch);*/




	
	return 0;
}
