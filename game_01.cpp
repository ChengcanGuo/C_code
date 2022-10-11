#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

//游戏主体 
void game()
{
	int ret = 0;
	int guess; 
	//1.取随机数
	ret = rand()%100+1;
	//2.猜数字  
	while(1)
	{
		scanf("%d",&guess);
	
		if(guess>ret)
		{
			printf("大了\n");
		 	
		}
		else if(guess<ret)
		{
			printf("小了\n");
		}
		else
		{
			printf("对了\n"); 
			break;
	
		}
	}
	

}
//开始菜单 
void menu()
{
	printf("*******---猜数字游戏---**********\n");
	printf("*********************************\n");
	printf("******开始游戏?(1.y/2.n)*********\n");
	printf("*********************************\n");
}
//主进程 
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
				printf("开始游戏,请猜数字\n");
				game();
				goto error;
			case 2:
				printf("退出游戏\n");
				goto error;
			default:
				printf("结束游戏\n");
				goto error; 
		}
	}while(choice);
	error:
		printf("GAME OVER[手动狗头]\n");
	
	return 0;
} 
