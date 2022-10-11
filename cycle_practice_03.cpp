//º∆À„1!+2!+...+n!----02 
#include<stdio.h>

int main()
{
	int n=0,ret=1,sum=0;
	for(n=1;n<=3;n++)
	{
		ret=ret*n;   
		sum=sum+ret; 
	}
	printf("%d",sum);
	return 0;
}
