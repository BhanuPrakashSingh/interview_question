#include<stdio.h>

int fibonacci(int num)
	{
	if (num == 1 || num == 2)
	{
		return 1;
	} else {
		return (fibonacci(num-1) + fibonacci(num-2));
	}	
	}

int main()
	{
	int num;
	printf("enter the number to print fibonacci: ");
	scanf("%d",&num);
	printf("%d fibonacci: ",num);
	for(int i=1;i<=num;i++)
		{
		printf(" %d",fibonacci(i));
		}
	printf("\n");
	return 0;
	}
