#include<stdio.h>

int fibonacci(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2 || n == 3 )
	{
		return 1;
		}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}


}

int main()
{
	int i = 1;
	for (i = 1;i <= 60;i++)
	{
		printf("%d\n",fibonacci(i));
	}

return 0;
}
