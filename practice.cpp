#include<stdio.h>
#include<string.h>
#include<windows.h>



int main()
{
	char arr1[]="                ";
	char arr2[]="^^^^^^^^^^^^^^^^";
	int left=0,right=strlen(arr1);
	while(left<=right)
	{
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		printf("%s\n",arr2);
		Sleep(500);
		left++;
		right--;
	}
	
	
	return 0;
}
