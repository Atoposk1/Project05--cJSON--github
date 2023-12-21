#include<stdio.h>
#include <stdlib.h>//实现内存的动态分配
#include <string.h>
int main()
{
	//读取 JSON 文件路径
	char file_path[300];
	printf("Enter the path to the JSON file: ");
	scanf("%s", file_path);

	//打开文件
	FILE* file = fopen(file_path, "r");
	if ((file = fopen(file_path, "r")) == NULL)
	{
		printf("无法打开 JSON 文件\n");
		return 0;
	}
	//获取文件大小，用于内存动态分配
	fseek(file, 0, 2);
	long file_size = ftell(file);//ftell函数默认从文件开始位置到文件指针的指向位置计算字节数的大小
	                             
	fseek(file, 0, SEEK_SET);//计算完成后将文件指针在移回文件的起始位置

	//输出文件大小，跳过判断文件格式是否符合json文件格式的判断操作
	//先关闭文件文件在输出文件的大小
	fclose(file);
	printf(file_size);
}