#include<stdio.h>
#include <stdlib.h>//ʵ���ڴ�Ķ�̬����
#include <string.h>
int main()
{
	//��ȡ JSON �ļ�·��
	char file_path[300];
	printf("Enter the path to the JSON file: ");
	scanf("%s", file_path);

	//���ļ�
	FILE* file = fopen(file_path, "r");
	if ((file = fopen(file_path, "r")) == NULL)
	{
		printf("�޷��� JSON �ļ�\n");
		return 0;
	}
	//��ȡ�ļ���С�������ڴ涯̬����
	fseek(file, 0, 2);
	long file_size = ftell(file);//ftell����Ĭ�ϴ��ļ���ʼλ�õ��ļ�ָ���ָ��λ�ü����ֽ����Ĵ�С
	                             
	fseek(file, 0, SEEK_SET);//������ɺ��ļ�ָ�����ƻ��ļ�����ʼλ��

	//����ļ���С�������ж��ļ���ʽ�Ƿ����json�ļ���ʽ���жϲ���
	//�ȹر��ļ��ļ�������ļ��Ĵ�С
	fclose(file);
	printf(file_size);
}