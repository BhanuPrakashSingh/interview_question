#include<stdio.h>
#include<string.h>

char *strip_str(char *str, int n)
	{
	return (char *)(memmove(str,str+n,strlen(str)-n+1));
	}

int main()
	{
	char str[]="HELLO_World";
	int n=6;
	printf("str=%s\n",strip_str(str,n));
	return 0;
	}
	
