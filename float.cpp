#include<stdio.h>
int main() 
{
	int a=0,b=0;
	printf("请输入您的身高（英尺）");
	scanf("%d %d",&a,&b);
	printf("%f",(a+b/12.0)*0.3048);
	
	return 0;
}
