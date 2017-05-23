/*
 * var_arg.c -- program shows how a function with variable
 * arguments can be implemented
 */
#include <stdio.h>
#include <stdarg.h>

/*
 *Three ellipsis indicate unspecified arguments with unspecified type 
 */
int sum (int num, ...)
	{
	va_list valist;                   //declared valist as va_list type
	int sum=0,count=0;
	va_start(valist,num);             // initialize valist to point to first variable in arguments
	
	for(count=0;count<num;count++)
		{
		// to access the value of variable call va_arg
		sum+=va_arg(valist,int);
		}
	//call va_end to free memory assigned by valist;
	va_end(valist);
	return sum;
	}
	
int main()
	{
	printf("sum=%d\n",sum(5,1,2,3,4,5));
	printf("sum=%d\n",sum(7,1,2,3,4,5,7,9));
	return 0;
	}
