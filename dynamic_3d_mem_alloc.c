#include <stdio.h>

int ***allocate3D(int l, int m, int n)
	{
	int i,j,k;
	int ***arr3D;
	arr3D= (int ***)malloc(l * sizeof(int **));
	for(i=0;i<l;i++)
		{
		arr3D[i] = (int **)malloc(m * sizeof(int *));
		for(j=0;j<m;j++)
			{
			arr3D[i][j]=(int *) malloc (n* sizeof(int));
			}
		}
	return arr3D;
	}

void deallocate3D(int arr3D, int l, int m)
	{
	int i,j,k;
	for (i=0;i<l;i++)
		{
		for (j=0;j<m;j++)
			{
			free(arr3D[i][j]);
			}
		free(arr3D[i]);
		}
	free(arr3D);
	}
