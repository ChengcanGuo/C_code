//for循环
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
//	int i = 0;
//	for (i = 1; i < 10; i++)//初始化；判断；调整//建议左闭右开-->10循环打印元素
//	{
//		if (i == 5)
//		{
//			continue;//continue&break均可用
//		}
//		printf("%d ", i);
//	}
////变种01-->循环hehe  判断条件恒为真
//	for (;;)
//	{
//		printf("hehe\n");
//
//	}
//变种02
	int x, y;
	for (x = 0, y = 0; x < 4 && y < 5; x++, y++)
	{
		printf("hehe\n");
	}
//循环0次
	int m = 0;
	int n = 0;
	for (m = 0, n = 0; m = 0; m++, n++)//等于0为假，停止运行
		m++;
	

	


	return 0;
}
