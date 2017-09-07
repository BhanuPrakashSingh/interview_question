#include<stdio.h>
#define N 4

void matrix_multiply (int a[N][N], int b[N][N], int c[N][N])
	{
	int i,j,k;
	for(i=0;i<N;i++)
		{
		for(j=0;j<N;j++)
			{
			c[i][j]=0;
			for(k=0;k<N;k++)
				{
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
				}
			}
		}
	return;	
	}

int main()
	{
	int a[N][N] = { {1,1,1,1},
			{2,2,2,2},
			{3,3,3,3},
			{4,4,4,4}};
			
	int b[N][N] = { {1,1,1,1},
			{2,2,2,2},
			{3,3,3,3},
			{4,4,4,4}};
	int c[N][N]={0};
	matrix_multiply(a,b,c);

	int i,j;
	for(i=0;i<N;i++)
		{
		for(j=0;j<N;j++)
			{
			printf("%d",c[i][j]);
			}
		printf("\n");
		}
	return 0;
	}
