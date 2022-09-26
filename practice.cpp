#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,sum=0; 
	int i;
	scanf("%d",&n);
	sum=(1+n)*n/2;
	printf("%I64d",sum);
	return 0;
}
