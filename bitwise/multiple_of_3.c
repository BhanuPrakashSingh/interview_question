/**
 *A number is multiple of 3, if the difference between the count of SET bits in odd and even postions are also multiple of 3.
 *
 */

#include<stdio.h>

int is_multiple_of_three(int n)
	{
	int odd_c=0; int even_c = 0;
	if (n == 0)
		{
		return 1;
		} 
	if (n == 1) {
		return 0;	
		}
	
	while(n)
		{
		if(n&1)
			{
			odd_c++;
			}
		n>>=1;
		
		if(n&1)
			{
			even_c++;
			}
		n>>=1;
		}
	return(is_multiple_of_three(abs(odd_c - even_c)));
	}

int main()
	{
	int num;
	printf("please enter your number to check: ");
	scanf("%d",&num);

	if (is_multiple_of_three(num) == 1)
		printf("no. %d is multiple of three\n",num);
	else
		printf("no. %d is not multiple of three\n",num);
	return 0;		
	}
	
