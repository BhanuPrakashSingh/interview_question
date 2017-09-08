#include <stdio.h>

//swap the array elements
void swap(int *xp, int *yp)
	{
	int tmp=*xp;
	*xp=*yp;
	*yp=tmp;
	}

//function for selection sorting
//Run time Complexities:
//--------------------------------
/* Best Case    : O(n2)
 * Average Case : O(n2)
 * Worst Case   : O(n2)
 */
void selection_sort(int arr[], int size)
	{
	int i=0,j=0,iMin=0,tmp=0;
	//int size = get_array_size();
	for(i=0; i < (size - 1); i++)
		{
		iMin=i;
		for(j=i+1; j < (size); j++)
			{
			// find the minimum number in array
			if(arr[j] < arr[iMin])
				iMin=j;
			}
			//put the lowest number in it's appropriate location
		if(arr[i] != arr[iMin])
			{
			swap(&arr[i],&arr[iMin]);
			}
		}
	return;
	}

//function for bubble sorting
//--------------------------------
/* Best Case    : O(n2)
 * Average Case : O(n2)
 * Worst Case   : O(n2)
 */
void bubble_sort(int arr[], int size)
	{
	int i,j;
	for(i=0;i<size-1;i++)
		{
		for(j=0; j < (size-i-1); j++)
			{
			if(arr[j] > arr[j+1])
				{
				swap(&arr[j],&arr[j+1]);
				}
			}
		}
	}

//function for optimised bubble sorting
//--------------------------------
/* Best Case    : O(n)
 * Average Case : O(n2)
 * Worst Case   : O(n2)
 */
void optimise_bubble_sort(int arr[], int size)
	{
	int i,j,swapped;
	for(i=0;i<size-1;i++)
		{
		swapped=0;
		for(j=0; j < (size-i-1); j++)
			{
			if(arr[j] > arr[j+1])
				{
				swap(&arr[j],&arr[j+1]);
				swapped=1;
				}
			}
		if(swapped==0)
			break;
		}
	}

//display
void display(int arr[], int size)
	{
	int i;
	printf("sorted array: ");
	for (i=0;i<(size);i++)
		{
		printf("%d  ",arr[i]);
		}
	printf("\n");
	return;
	}

int main()
	{
	int arr[7]={5,3,6,2,8,21,1};
	int size=sizeof(arr)/sizeof(int);
	//selection_sort(arr,size);
	bubble_sort(arr,size);
	//optimise_bubble_sort(arr,size);
	display(arr,size);
	return 0;
	}
