#include<stdio.h>
#include<stdlib.h>

//arra structure
struct Array_stack
	{
	int top;
	int capacity;
	int *Array;
	};

//create stack
struct Array_stack *create_stack(int capacity)
	{
	struct Array_stack *stack = (struct Array_stack *)malloc(sizeof(struct Array_stack));
	stack->top=-1;
	stack->capacity=capacity;
	stack->Array=(int *)malloc(stack->capacity*sizeof(int));
	return stack;
	}

//check if stack is empty
int is_Empty(struct Array_stack *stack)
	{
	if(stack->top == -1)
		return 1;
	else
		return 0;
	}

//check if stack is full
int is_Full(struct Array_stack *stack)
	{
	if(stack->top == (stack->capacity - 1))
		return 1;
	else
		return 0;
	}

// push element into stack
void push(struct Array_stack *stack,int item)
	{
	if (is_Full(stack) == 1)
		{
		printf("Stack Overflow\n");
		return;
		}
	stack->Array[++(stack->top)]=item;
	return;
	}
	
//pop an element from stack
int pop(struct Array_stack *stack)
	{
	if(is_Empty(stack) == 1)
		{
		printf("stack underflow\n");
		return -1;
		}
	return (stack->Array[(stack->top)--]);
	}


int main()
	{
	struct Array_stack *stack;
	int capacity=0,choice=0;
	int item=0;
	printf("please enter stack capacity: ");
	scanf("%d",&capacity);
	stack = create_stack(capacity);
	
	fflush(stdin);
	while(1)
		{
		printf("0. exit\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("please enter your choice: \n");
		scanf("%d",&choice);
		switch(choice)
			{
			case 0:
				exit(0);
				break;
			case 1:
				fflush(stdin);
				printf("please enter item to push: ");
				scanf("%d",&item);
				push(stack,item);
				break;
			case 2:
				printf("poped element: %d\n",pop(stack));	
				break;
			default:
				printf("please enter valid choice\n");
			}
		}
	return 0;
	}
