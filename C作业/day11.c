1.  
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//第一种
#if 0
int main()
{
	int a=0, b=0, c=0, d=0, e=0;
	for (a = 1; a <= 5;a++)
		for (b = 1; b <= 5;b++)
			if (b!=a)
				for (c = 1; c <= 5;c++)
					if (c!=a&&c!=b)
						for (d = 1; d <= 5;d++)
							if (d!=a&&d!=b&&d!=c)
								for (e= 1; e<= 5; e++)
								{
		
									if (e!=a&&e!=b&&e!=c&&e!=d)
									if (((b == 2) + (a == 3) == 1) && ((b == 2) + (e == 4) == 1) && \
									((c == 1) + (d == 2) == 1) && ((c == 5) + (d == 3) == 1) && \
									((e == 4) +(a == 1) == 1))
									printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
								}
	system("pause");
	return 0;
}
#endif

//第二种
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 1; a <= 5; a++)
	for (b = 1; b <= 5; b++)
	for (c = 1; c <= 5; c++)
	for (d = 1; d <= 5; d++)
	for (e = 1; e <= 5; e++)
	{
		if (((b == 2) + (a == 3) == 1) && ((b == 2) + (e == 4) == 1) && \
			((c == 1) + (d == 2) == 1) && ((c == 5) + (d == 3) == 1) && \
			((e == 4) + (a == 1) == 1))
		if (a*b*c*d*e == 120)    //过滤掉名次的不唯一性，不能用1+2+3+4+5=15因为和的值不唯一（3+3+3+3+3=15)
		{
			printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
		}
	}
	system("pause");
	return 0;
}

2.  
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。以下为4个嫌疑犯的供词。
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
int main()
{
	char killer='\0';
	for (killer= 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer== 'c') + (killer == 'd') + (killer != 'd') == 3)
			printf( "%c is a killer\n",killer);
	}
	system("pause");
	return 0;
}


3.在屏幕上打印杨辉三角。
1 
1 1 
1 2 1 
1 3 3 1 


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ROW 20

//第一种
#if 0
void yanghuisanjiao1(int *a, int n)
{
	int i, j;
	printf("%4d\n",1);
	a[1] = a[2] = 1;
	printf("%4d%4d\n", a[1], a[2]);
	for (i = 3; i <= n; i++)
	{
		a[1] = a[i] = 1;
		for (j = i - 1; j > 1; j--)
		{
			a[j] = a[j] + a[j - 1];
		}
		for (j = 1; j <=i; j++)
		{
			printf("%4d", a[j]);
		}
		printf("\n");
	}
}
int main()
{
	int a[100] = { 0 };
	int n;
	printf("请输入一个数n：");
	scanf("%d", &n);
	yanghuisanjiao1(a, n);
	system("pause");
	return 0;
}
#endif

//第二种
void Yanghuisanjiao2(int(*a)[ROW])         //int (*arr)[20]  数组指针      
{                                          //int  *arr[20]   指针数组
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			if ((i == j) || (j == 0))
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}

	}
}
void Show(int(*a)[ROW])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j <=i; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int a[ROW][ROW]= { 0 };
	int num;
	printf("请输入一个数num：");
	scanf("%d", &num);
	Yanghuisanjiao2(a);     //注意：这是二维数组
	Show(a);
	system("pause");
	return 0;
}
