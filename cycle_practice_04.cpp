//二分查找法 
#include<stdio.h>

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int k=7;
	int sz=sizeof(arr)/sizeof(arr[0]);//计算元素个数 
	int left=0,right=sz-1;//left,right，mid指的是下标 
	while(left<=right)
	{
		int mid=(left+right)/2;
	
		if(arr[mid]>k)
		{
			right=mid-1;
		}
		else if(arr[mid]<k)
		{
			left=mid+1;
		}
		else
		{
			printf("找到了，下标为%d\n",mid);
			break;
		}
   }
   if (left>right)
   {
   		printf("找不到");
   }
  
	return 0;
}
