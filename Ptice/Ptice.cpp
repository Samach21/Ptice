#include<stdio.h>

bool checkABC(char*);
int Adrian_check(char*, char*, int);
int Bruno_check(char*, char*, int);
int Goran_check(char*, char*, int);

int main()
{
	int n;
	char answer[100];
	char* p = answer;
	char Adrian[] = { 'A', 'B', 'C' }, Bruno[] = { 'B', 'A', 'B', 'C' }, Goran[] = { 'C', 'C', 'A', 'A', 'B', 'B' };
	char* a = Adrian, * b = Bruno, * g = Goran;
	int Max_Adrian = 0, Max_Bruno = 0, Max_Goran = 0;
	if (scanf_s("%d", &n) != 1)
	{
		printf("ERROR CAN'T READ");
		return 1;
	}
	else if (n < 1 || n > 100)
	{
		printf("ERROR OUT OFF N");
		return 1;
	}
	for (int i = 0; i < n; i++, p++)
	{
		scanf_s("%c", &answer[i]);
		if (static_cast<int>(answer[i]) == 10)
		{
			i--;
			p--;
		}
		else if (!checkABC(p))
		{
			printf("ERROR NOT ABC");
			return 1;
		}
	}
	///////////////////////////////////////
	p = answer;
	Max_Adrian = Adrian_check(p, a, n);
	p = answer;
	Max_Bruno = Bruno_check(p, b, n);
	p = answer;
	Max_Goran = Goran_check(p, g, n);
	///////////////////////////////////////
	if (Max_Adrian >= Max_Bruno && Max_Adrian >= Max_Goran && Max_Adrian != 0)
	{
		printf("%d", Max_Adrian);
		printf("\nAdrian");
		if (Max_Adrian == Max_Bruno)
		{
			printf("\nBruno");
		}
		if (Max_Adrian == Max_Goran)
		{
			printf("\nGoran");
		}
	}
	else if (Max_Bruno >= Max_Goran && Max_Bruno != 0)
	{
		printf("%d", Max_Bruno);
		printf("\nBruno");
		if (Max_Bruno == Max_Goran)
		{
			printf("\nGoran");
		}
	}
	else
	{
		printf("%d", Max_Goran);
		if (Max_Goran != 0)
		{
			printf("\nGoran");
		}
	}
	return 0;
}

bool checkABC(char* x)
{
	switch (*x)
	{
	case 'A':
		return true;
		break;
	case 'B':
		return true;
		break;
	case 'C':
		return true;
		break;
	default:
		return false;
		break;
	}
}

int Adrian_check(char* x, char* y, int n)
{
	int max = 0;
	for (int i = 1; i <= n; i++, x++, y++)
	{
		if (*x == *y)
		{
			max++;
		}
		if (i % 3 == 0)
		{
			y = y - 3;
		}
	}
	return max;
}

int Bruno_check(char* x, char* y, int n)
{
	int max = 0;
	for (int i = 1; i <= n; i++, x++, y++)
	{
		if (*x == *y)
		{
			max++;
		}
		if (i % 4 == 0)
		{
			y = y - 4;
		}
	}
	return max;
}

int Goran_check(char* x, char* y, int n)
{
	int max = 0;
	for (int i = 1; i <= n; i++, x++, y++)
	{
		if (*x == *y)
		{
			max++;
		}
		if (i % 6 == 0)
		{
			y = y - 6;
		}
	}
	return max;
}
