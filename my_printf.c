#include <stdio.h>
#include <stdarg.h>

void myPrintf(char *, ...);		// printf function
char* convert(unsigned int, int);	//convert integer number into hex, oct, etc

int main()
	{
	myPrintf("Hello it's : %s\n %d","Surya",9);
	return 0;
	}

void myPrintf(char* format,...)
	{
	char *traverse,*s;
	unsigned int i;

	//Inititalizing myPrintf's argument
	va_list arg;
	va_start(arg,format);

	for(traverse=format; *traverse != '\0'; traverse++)
		{
			while(*traverse != '%')
			{
				putchar(*traverse);
				traverse++;
			}
			traverse++;

		//Fetching and executing arguments
		switch(*traverse)
			{
			case 'c' : i = va_arg(arg,int);
					putchar(i);
					break;
			case 'd' : i = va_arg(arg,int);
					if(i<0)
						{
						i=-1;
						putchar('-');
						}
					puts(convert(i,10));
					break;
			case 'o' : i = va_arg(arg,unsigned int);
					puts(convert(i,8));
					break;

			case 's' : s = va_arg(arg,char *);
					puts(s);
					break;
			case 'x' : i = va_arg(arg,unsigned int);
					puts(convert(i,16));
					break;
			}
		}
	va_end(arg);
}

char *convert(unsigned int num, int base)
	{
	static char representation[] = "0123456789abcdef";
	static char buff[50];
	char *ptr;
	ptr=&buff[49];
	
	while(num)
		{
		*--ptr = representation[num%base];
		num/=base;		
		}
	return (ptr);
	}
