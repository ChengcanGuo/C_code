#define _CRT_SECURE_NO_WARNINGS 1
//分支语句if&switch
#include <stdio.h>//standard input&output.header file

int main()
{
//1.打印
	printf("hello world\n");//print function

//2.if语句01
	int age01= 11; 
	if (age01 < 18)
	{
		printf("未成年\n");
		printf("禁止玩手机\n");
	}
	else 
	{
		if (age01 >= 18 && age01 < 50)//18<=age01<40
		{
			printf("青年\n");
		}
		else
		{
			printf("老年\n");
		}
	}

//3.if语句02
	int age02 = 32;
	if (age02 < 18)
	{
		printf("未成年\n");
		printf("禁止玩手机\n");
	}
	else if (age02 >= 18 && age02 < 50)//18<=age02<40
	{
		printf("青年\n");
	}
	else if(age02>=50 && age02<=100)
	{
		printf("老年\n");
	}

//4.if语句03_悬空else 养成良好习惯
	int a = 1;
    int b = 2;
	if (a == 3)
	{
		if (b == 2)
		{
			printf("AA");
		}
		else
		{
			printf("BB");
		}
	}

//5.练习 1.判断一个数是否为奇数	2.输出1-100的奇数
	//法一
	int i = 1;
	while(i<=100)
	{
		if (i % 2 ==1)
		{
			printf("%d", i );
		}
		i++;
		
		

	}
	//法二
	int c = 1;
	while (c <= 100)
	{
		printf("%d", c);
		c+=2;		
	}
//6.switch语句_实现多分支情况
	//switch为整姓常量表达式
	int day = 0;
	scanf("%d", &day);//scan format
	switch (day)
	{
		case 1:
		{
			printf("星期一");
		}
			break;
		case 2:
		{
			printf("星期二");
		}
			break;
		case 3:
		{
			printf("星期s三");
		}
			break;
		case 4:
		{
			printf("星期四");
		}
			break;
		case 5:
		{
			printf("星期五");
		}
				break;
		case 6:
		{
			printf("星期六");
		}
			break;
		case 7:
		{
			printf("星期天");
		}
			break;
	}
//7.switch语句02
	int day2 = 0;
	scanf("%d", &day2);//&取地址
	switch (day2)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		{
			printf("工作日");
		}
			break;
		case 6:
		case 7:
		{
			printf("休息日");
		}
			break;
		default:
		{
			printf("请输入1至7内的数字");
		}
	}

	return 0;
}
