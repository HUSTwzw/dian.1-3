#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char grand;
	int number;
	int price;
	int max_amount;
	int once_amount;
	int once_pay;
	int sum = 0;
	int back;
	int i = 0;


	char grand2;
	int number2;

gt1:printf("请依次输入品牌、通道编号（1-5）、单价（1-9）、商品数量（小于50），并用空格隔开，输入完成后直接输入“回车”\n");
	scanf("%c", &grand);
	scanf("%d", &number);
	scanf("%d", &price);
	scanf("%d", &max_amount);
	rewind(stdin);

	if (number < 1 || number>5)
	{
		printf("输入通道号错误，此次操作无效\n");
		rewind(stdin);
		if (price < 1 || price>9)
		{
			printf("输入单价错误，此次操作无效\n");
			rewind(stdin);
		}
		if (max_amount > 50)
		{
			printf("输入商品数量过多，此次操作无效\n");
			rewind(stdin);
		}
		goto gt1;
	}
	else if (price < 1 || price>9)
	{
		printf("输入单价错误，此次操作无效\n");
		rewind(stdin);
		if (max_amount > 50)
		{
			printf("输入商品数量过多，此次操作无效\n");
			rewind(stdin);
		}
		goto gt1;
	}
	else if (max_amount > 50)
	{
		printf("输入商品数量过多，此次操作无效\n");
		rewind(stdin);
	}
	else
	{
	}

gt2:printf("开始取货环节\n");
	rewind(stdin);
	for (; i < max_amount;)
	{

		scanf("%c", &grand2);
		scanf("%d", &number2);
		scanf("%d", &once_amount);
		i += once_amount;


		if (grand2 != grand)
		{
			printf("所取货物种类与所摆放货物种类不同，此次操作无效\n");
			rewind(stdin);
			i -= once_amount;
			goto gt2;
		}
		else if (number2 != number)
		{
			printf("输入通道号错误，此次操作无效\n");
			rewind(stdin);
			i -= once_amount;
			goto gt2;
		}
		else if (i > max_amount)
		{
			printf("货物数量不足，此次操作无效\n");
			i -= once_amount;
			rewind(stdin);
			goto gt2;
		}
		else
		{
			for (; sum < once_amount * price;)
			{
				printf("请输入金额\n");
				scanf("%d", &once_pay);
				if (once_pay != 1 && once_pay != 2 && once_pay != 5)
				{
					printf("输入金额错误\n");
					once_pay = 0;
				}
				else
				{
					sum = sum + once_pay;
				}
			}
			back = sum - once_amount * price;
			printf("找回零钱为%d\n", back);
			if (i < max_amount)
			{
				printf("可以继续购买\n");
			}
			rewind(stdin);
			sum = 0;//清空上一次购买的sum
			once_pay = 0;
		}
	}

	return 0;
}
