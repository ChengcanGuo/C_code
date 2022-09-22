//while循环语句
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
//1.while语句01
	int i = 1;
	while (i <= 10)
	{
		printf("%d \n", i);
		if (i == 10)
		{
			printf("终\n");
		}
		i++;
	}
//2.while语句02
	int a = 1;
	while (a <= 5)
	{
		if (a == 4)
		{
			printf("终");
			break;
		}
		printf("%d \n", a);
		a++;
	}
//3.while语句03getchar&putchar  //EOF->end of file   //getchar遇到ctrl+z结束
	int ch = 0;
	while (ch = getchar() != EOF)
	{
		putchar(ch);
	}
//4.while语句04continue作用
	int b = 0;
	while (b <= 10)
	{
		b++;
		if (b == 4 || b==5)
		{
			continue;
		}
		printf("%d ", b);

	}
//5.输入缓冲区
	int c = 0;
	char passward[20] = { 0 };
	int ret = 0;
	printf("请输入数字密码:>");
	scanf("%s", passward);//它是格式输入函数，即按用户指定的格式从键盘上把数据输入到指定的变量之中
	while (c = getchar()!='\n')//getchar();//吸收字符\n,防止后面的getchar识别，即让getchar准确吸收Y/N   getchar只吸收一个字符含空格
	{
		;
	}
		printf("请确认密码(Y/N):>");
	ret = getchar();
	if (ret == 'Y')
	{
		printf("确认成功");
	}
	else
	{
		printf("确认失败");
	}

		return 0;
}
