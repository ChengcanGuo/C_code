#include<stdio.h>

int main()
{
	int i,n,ret=0;
	printf("������һ������");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		ret=ret+i;
	}
	printf("%d",ret);
		
	return 0;
}
