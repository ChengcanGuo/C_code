#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
	char passward[20]={0};
	for(i=0;i<3;i++)
	{
		printf("ÇëÊäÈëÃÜÂë:");
		scanf("%s",passward); 
		if(strcmp(passward,"12345678")==0)
		{
			printf("µÇÂ¼³É¹¦");
			break;
		}
		else
		{
			printf("ÃÜÂë´íÎó\n");
		}
		
	}
	if(i==3)
	{
		printf("ÍË³ö³ÌÐò");
	}
	return 0;
}
