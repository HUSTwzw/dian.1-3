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

gt1:printf("����������Ʒ�ơ�ͨ����ţ�1-5�������ۣ�1-9������Ʒ������С��50�������ÿո������������ɺ�ֱ�����롰�س���\n");
	scanf("%c", &grand);
	scanf("%d", &number);
	scanf("%d", &price);
	scanf("%d", &max_amount);
	rewind(stdin);

	if (number < 1 || number>5)
	{
		printf("����ͨ���Ŵ��󣬴˴β�����Ч\n");
		rewind(stdin);
		if (price < 1 || price>9)
		{
			printf("���뵥�۴��󣬴˴β�����Ч\n");
			rewind(stdin);
		}
		if (max_amount > 50)
		{
			printf("������Ʒ�������࣬�˴β�����Ч\n");
			rewind(stdin);
		}
		goto gt1;
	}
	else if (price < 1 || price>9)
	{
		printf("���뵥�۴��󣬴˴β�����Ч\n");
		rewind(stdin);
		if (max_amount > 50)
		{
			printf("������Ʒ�������࣬�˴β�����Ч\n");
			rewind(stdin);
		}
		goto gt1;
	}
	else if (max_amount > 50)
	{
		printf("������Ʒ�������࣬�˴β�����Ч\n");
		rewind(stdin);
	}
	else
	{
	}

gt2:printf("��ʼȡ������\n");
	rewind(stdin);
	for (; i < max_amount;)
	{

		scanf("%c", &grand2);
		scanf("%d", &number2);
		scanf("%d", &once_amount);
		i += once_amount;


		if (grand2 != grand)
		{
			printf("��ȡ�������������ڷŻ������಻ͬ���˴β�����Ч\n");
			rewind(stdin);
			i -= once_amount;
			goto gt2;
		}
		else if (number2 != number)
		{
			printf("����ͨ���Ŵ��󣬴˴β�����Ч\n");
			rewind(stdin);
			i -= once_amount;
			goto gt2;
		}
		else if (i > max_amount)
		{
			printf("�����������㣬�˴β�����Ч\n");
			i -= once_amount;
			rewind(stdin);
			goto gt2;
		}
		else
		{
			for (; sum < once_amount * price;)
			{
				printf("��������\n");
				scanf("%d", &once_pay);
				if (once_pay != 1 && once_pay != 2 && once_pay != 5)
				{
					printf("���������\n");
					once_pay = 0;
				}
				else
				{
					sum = sum + once_pay;
				}
			}
			back = sum - once_amount * price;
			printf("�һ���ǮΪ%d\n", back);
			if (i < max_amount)
			{
				printf("���Լ�������\n");
			}
			rewind(stdin);
			sum = 0;//�����һ�ι����sum
			once_pay = 0;
		}
	}

	return 0;
}
