#include <stdio.h>

void binary_disp (int num)
	{
	int size = 8 * sizeof(num);
	int num1= num;
	char buff[32], *pbuff;
	pbuff = buff;
	if (num == 0)
		{
		*pbuff++ = '0';
		*pbuff = '\0';
		}

	// start from end
	pbuff +=size;
	*pbuff-- = '\0';	
	while (num != 0)
		{
		if (size-- == 0)
			break;
		*pbuff-- = ((num & 1) == 1) ? '1' : '0';
		num >>= 1;
		}

	printf ("binary equivalent of %d is %s\n",num1,pbuff);
	}

int reverse_bit(int num)
	{
	int  NO_OF_BITS = sizeof(num) * 8;
    	int reverse_num = 0;
    	int i;
    	for (i = 0; i < NO_OF_BITS; i++)
    		{
        	if((num & (1 << i)))
           		reverse_num |= 1 << ((NO_OF_BITS - 1) - i);  
   		}
    	return reverse_num;
	}

int reverse_bit_eff(int num)
	{
	int count = 8 * sizeof(num) -1;
	int rev_num = num;
	num >>= 1;
	while (num) 
		{
		rev_num <<= 1;
		rev_num |=num & 1;
		num >>= 1;
		count --;
		}
	rev_num <<= count;
	return rev_num;
	}

int reverse_bit_eff1(int num)
	{
	int count = 8 * sizeof(num) -1;
	int rev_num = num;
	num>>=1;
	for (;num ;num >>= 1)
		{
		rev_num <<= 1;
		rev_num |=num & 1;
		count --;
		}
	rev_num <<= count;
	return rev_num;
	}

int main ()
	{
	int num;
	printf("enter a num to get binary equivalen:");
	scanf("%d",&num);
	binary_disp(num);
	int res = reverse_bit_eff1(num);
	binary_disp(res);
	return 0;
	}
