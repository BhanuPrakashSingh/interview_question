#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10

void swap(char *ptr1, char *ptr2)
	{
	char tmp;
	tmp = *ptr1;
	*ptr1=*ptr2;
	*ptr2=tmp;
	}

char *resize_string_space(char *str, int size)
	{
	return (char *)realloc(str,(size+1));
	}

void insert_word_in_string(char *str, char *word, int index)
	{
	int str_size = strlen(str);
	int word_size = strlen(word);
	if ((str_size + word_size) > MAX_SIZE)
		{
		//char *n_str = (char *)realloc(str,(str_size+word_size+1));
		char *n_str = resize_string_space(str,(str_size + word_size));
		if(n_str == NULL)
		{
			printf("unable to allocate memory");
			return;
		} else{
			str=n_str;
		}
		}
	char *ptr,*ptr1;
	ptr=ptr1=(str+index);

	while(*ptr1 != '\0')
		{
		*(ptr1 + word_size)=*ptr1;
		ptr1++;
		}
	while(*word != '\0')
		{
		*ptr=*word;
		ptr++;
		word++;
		}
	printf("str=%s\n",str);
	return;
	}
	

int main()
	{
	char *str = malloc(15*sizeof(char));
	char *word = "hello_world";
	int index=5;
	printf("please insert a string: ");
	gets(str);
	insert_word_in_string(str,word,index);
	return 0;
	}
