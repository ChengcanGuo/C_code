#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
	char passward[20]={0};
	for(i=0;i<3;i++)
	{
		printf("����������:");
		scanf("%s",passward); 
		if(strcmp(passward,"12345678")==0)
		{
			printf("��¼�ɹ�");
			break;
		}
		else
		{
			printf("�������\n");
		}
		
	}
	if(i==3)
	{
		printf("�˳�����");
	}
	return 0;
}
