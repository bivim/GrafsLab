#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#define N 100

int main()
{
	setlocale(LC_ALL, "Rus");
	int a[N][N], i, j, s, n, k, tmp, count;

	//printf("������� ����� ����: ");
	while (1)
	{
		printf("������� ���������� ����: ");
		if (scanf("%d", &n) && (n > 0) && (n <= N))
			break;

		printf("�� ����� �� ������� ���������� �������� ��� ����� ����������� ��������!\n");
		getchar();
		//fflush(stdin);
		//return 0;
	}

	for (i = 0; i < n; i++)
	{
		printf("������� ��������� � ��������� ������� �����\n");
		for (j = 0; j < 2; j++)
		{
			while (1)
			{
				if (scanf("%d", &a[i][j]) && (a[i][j] > 0))
					break;
				printf("�� ����� ����������� ��������!\n");
				getchar();
			}
		}
	}
	for (s = 0; s < n; s++)
	{
		for (k = 0; k < n; k++)
		{
			count = 0;
			for (i = 0; i < n; i++)
			{
				if (i == k)
					continue;
				if ((a[i][0] == a[k][0]) || (a[i][1] == a[k][0]))
				{
					count++;
					break;
				}
			}
			if (count == 1)
			{
				for (i = 0; i < n; i++)
				{
					if (i == k)
						continue;
					if ((a[i][0] == a[k][1]) || (a[i][1] == a[k][1]))
					{
						count++;
						break;
					}
				}
			}
			if (count != 2)
			{
				a[k][0] = 0;
				a[k][1] = 0;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (a[i][0] > 0)
		{
			printf("���� �������� ����\n");
			break;
		}
	}
	if (i == n)
		printf("���� �� �������� ����\n");
	return 0;
}