#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

//��Ϸ���� 
void game()
{
	int ret = 0;
	int guess; 
	//1.ȡ�����
	ret = rand()%100+1;
	//2.������  
	while(1)
	{
		scanf("%d",&guess);
	
		if(guess>ret)
		{
			printf("����\n");
		 	
		}
		else if(guess<ret)
		{
			printf("С��\n");
		}
		else
		{
			printf("����\n"); 
			break;
	
		}
	}
	

}
//��ʼ�˵� 
void menu()
{
	printf("*******---��������Ϸ---**********\n");
	printf("*********************************\n");
	printf("******��ʼ��Ϸ?(1.y/2.n)*********\n");
	printf("*********************************\n");
}
//������ 
int main()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d",&choice); 
		switch(choice)
		{
			case 1:
				printf("��ʼ��Ϸ,�������\n");
				game();
				goto error;
			case 2:
				printf("�˳���Ϸ\n");
				goto error;
			default:
				printf("������Ϸ\n");
				goto error; 
		}
	}while(choice);
	error:
		printf("GAME OVER[�ֶ���ͷ]\n");
	
	return 0;
} 
