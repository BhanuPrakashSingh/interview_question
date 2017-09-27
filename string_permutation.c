#include<stdio.h>
#include<string.h>

void swap(char *x, char *y)
	{
	char ch;
	ch=*x;
	*x=*y;
	*y=ch;
	}

//program to print permutations

void permutations(char *str, int i, int n)
	{
	int j;
	static int count=0;
	if(i == n)
		{
		printf("permutation %d :%s\n",count,str);
		count++;
		}
	for(j=i;j<=n;j++)
		{
		swap((str+i),(str+j));
		permutations(str,i+1,n);
		swap((str+i),(str+j));
		}
	return;
	}

int main()
	{
	char str[] = "ABCD";
	permutations(str,0,strlen(str)-1);
	return 0;
	}
