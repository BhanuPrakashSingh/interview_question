#include <stdio.h>


void tower_of_hanoi(int n,char Beg, char End, char Aux)
	{
	if (n==1)
		{
		printf("move disk 1 from peg %c to peg %c\n",Beg,End);
		return;
		}

		{
		tower_of_hanoi(n-1,Beg,Aux,End);
		printf("move disk %d from peg %c to peg %c\n",n,Beg,End);
		tower_of_hanoi(n-1,Aux,End,Beg);
		}
	return;
	}


int main()
	{
	int num;
	printf("Enter the number of disks: ");
	scanf("%d",&num);
	tower_of_hanoi(num,'A','C','B');
	return 0;
	}
