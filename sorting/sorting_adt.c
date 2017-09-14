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

//--------------------------------------------------------------------------------------------------------------------------------
//Merge sort
/*Best Case	: O(nlogn)
 *Average Case  : O(nlogn)
 *Worst Case    : O(nlogn)
 */
void merge(int arr[],int start, int mid, int end)
	{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int Left_arr[n1];
	int Right_arr[n2];
	int i,j,k;

	for(i=0;i<n1;i++)
		{
		Left_arr[i]=arr[start+i];	
		}
	for(j=0;j<n2;j++)
		{
		Right_arr[j]=arr[mid+1+j];
		}

	i=0;
	j=0;
	k=start;
	while(i<n1 && j<n2)
		{
		if (Left_arr[i] <= Right_arr[j])
			{
			arr[k]=Left_arr[i];
			i++;
		} else {
			arr[k]=Right_arr[j];
			j++;
		}
		k++;
		}
	//copy remaining element from left array
	while(i<n1)
		{
		arr[k] = Left_arr[i];
		i++;
		k++;
		}
	//copy remaining element from right array
	while(j<n2)
		{
		arr[k] = Right_arr[j];
		j++;
		k++;
		}
	}

void merge_sort(int arr[], int start, int end)
	{
	//
	if(start < end)
		{
		int mid = start + (end-start)/2;
		//sorting elements
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1,end);

		//merge the sirted elements
		merge(arr,start,mid,end);
		}
	}
//------------------------------------------------------------------------------------------------------------------------------------------
//Quick Sort
/*
 *Runtime complexity
 *Best Case    : O(nlogn)
 *Average Case : O(nlogn)
 *Worst Case   : O(n2)
 */

//int pivot=0;
int partition(int arr[], int start, int end)
	{
	int i,pIndex=(start-1),pivot=arr[end];
	for (i=start; i < (end-1); i++)
		{
		if (arr[i] <= pivot)
			{
			pIndex++;
			swap(&arr[pIndex],&arr[i]);			
			}
		}
		swap(&arr[pIndex + 1],&arr[end]);
	return (pIndex + 1);
	}

void quick_sort(int arr[], int start, int end)
	{
	if(start >= end)
		return;
	else
		{
		int pivot = partition(arr,start,end);
		quick_sort(arr,start,pivot-1);
		quick_sort(arr,pivot+1,end);
		}
	}

//-------------------------------------------------------------------------------------------------------------------------------------------
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
	int arr[]={5,3,6,2,8,21,1};
	int size=sizeof(arr)/sizeof(int);
	//selection_sort(arr,size);
	//bubble_sort(arr,size);
	//optimise_bubble_sort(arr,size);
	//merge_sort(arr,0,size-1);
	quick_sort(arr,0,size-1);
	display(arr,size);
	return 0;
	}
