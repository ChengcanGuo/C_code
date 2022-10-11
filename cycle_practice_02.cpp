//º∆À„1!+2!...+10!---01
#include<stdio.h>

int main()
{
	int i=0,n=0,ret=1,sum=0;
	for(n=1;n<=3;n++)
	{
		ret=1;
		for(i=1;i<=n;i++)
		{
			ret=ret*i;
		}
		sum=sum+ret;
	}
	printf("%d",sum);
	return 0;
}
