//whileѭ�����
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
//1.while���01
	int i = 1;
	while (i <= 10)
	{
		printf("%d \n", i);
		if (i == 10)
		{
			printf("��\n");
		}
		i++;
	}
//2.while���02
	int a = 1;
	while (a <= 5)
	{
		if (a == 4)
		{
			printf("��");
			break;
		}
		printf("%d \n", a);
		a++;
	}
//3.while���03getchar&putchar  //EOF->end of file   //getchar����ctrl+z����
	int ch = 0;
	while (ch = getchar() != EOF)
	{
		putchar(ch);
	}
//4.while���04continue����
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
//5.���뻺����
	int c = 0;
	char passward[20] = { 0 };
	int ret = 0;
	printf("��������������:>");
	scanf("%s", passward);//���Ǹ�ʽ���뺯���������û�ָ���ĸ�ʽ�Ӽ����ϰ��������뵽ָ���ı���֮��
	while (c = getchar()!='\n')//getchar();//�����ַ�\n,��ֹ�����getcharʶ�𣬼���getchar׼ȷ����Y/N   getcharֻ����һ���ַ����ո�
	{
		;
	}
		printf("��ȷ������(Y/N):>");
	ret = getchar();
	if (ret == 'Y')
	{
		printf("ȷ�ϳɹ�");
	}
	else
	{
		printf("ȷ��ʧ��");
	}

		return 0;
}
