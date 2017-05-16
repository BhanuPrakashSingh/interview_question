#include <stdio.h>
#include <stdlib.h>

//create a node
struct node 
	{
	int data;
	struct node *next;
	};

typedef struct node mynode;

//get the length of link list
int number_of_nodes;

//insert a node at front of the list
void insert_at_front (struct node **head, int data)
	{
	mynode *tmp, *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=(mynode *)0;
	tmp = (*head);
	
	if((*head) == (mynode *)0)
		{
		printf("head is null, inserting first node\n");
		(*head) = new_node;
		number_of_nodes++;
		return;
		}
	new_node->next=(*head);
	(*head)=new_node;
	number_of_nodes++;
	return;
	}

// insert a node ate the end of link list
void insert_at_end ( struct node **head, int data)
	{
	struct node *tmp, *new_node = (struct node *)malloc (sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	tmp=(*head);
	
	if ((*head) == (mynode*)0)
		{
		printf("head is null, inserting first node\n");
		(*head)=new_node;
		number_of_nodes++;
		return;
		}
	 while(tmp->next != NULL)
		{
		tmp=tmp->next;
		}
	printf("Adding a node at the end of list\n");
	tmp->next=new_node;
	number_of_nodes++;
	return;
	}

//insert at given position
void insert_at_given_position(mynode **head, int data, int pos)
	{
	if ((number_of_nodes + 1) < pos)
		{
		printf("given position %d is beyond length %d of linklist\n",pos,number_of_nodes);
		return;
		}
	struct node *tmp, *prev, *new_node = (struct node *)malloc(sizeof(struct node));
	int k=1;
	if (!new_node)
		{
		printf("memory error\n");
		return;
		}
		
	new_node->data = data;
	new_node->next = (mynode *)0;
	tmp=(*head);

	if (pos == 1)
		{
		insert_at_front(head, data);
		return;
	}

	while ((tmp != (mynode *)0) && (k < pos))
		{
		prev = tmp;
		tmp=tmp->next;
		k++;
		}
	prev->next=new_node;	
	new_node->next=tmp;
	number_of_nodes++;
	return;	
	}

//delete from front
void delete_from_front(mynode **head)
	{
	if ((*head)==NULL)
		{
		printf("link list is empty\n");
		return;
		}
	mynode *tmp;
	tmp=(*head);
	(*head) = tmp->next;
	free(tmp);
	number_of_nodes--;
	return;
	}

// delete last node
void delete_from_end(mynode **head)
	{
	if ((*head)==NULL)
		{
		printf("empty link list\n");
		return;
		}
	mynode *tmp,*prev;
	tmp=(*head);
	while(tmp->next != NULL)
		{
		prev=tmp;
		tmp=tmp->next;
		}
	prev->next=NULL;
	free(tmp);
	number_of_nodes--;
	if(number_of_nodes == 0)
		{
		(*head) = NULL;
		}
	return;
	}

//delete given node
void delete_given_node(mynode **head, int pos)
	{
	int k=1;
	if (*head == NULL)
		{
		printf("link list is empty\n");
		return;
		}
	if (number_of_nodes < pos)
		{
		printf("given node %d doesn't exit in link list \n",pos);
		return;
		}
	if (pos == 1 || number_of_nodes == 1)
		{
		delete_from_front(head);
		return;
		}

	mynode *tmp,*prev;
	tmp=(*head);
	while((tmp->next != NULL) && (k<pos))
		{
		prev=tmp;
		tmp=tmp->next;
		k++;
		}
	prev->next=NULL;
	free(tmp);
	number_of_nodes--;
	}

//delete link list
void delete_link_list(mynode **head)
	{
	mynode *tmp,*prev;
	tmp=*head;
	while(tmp != NULL)
		{
		prev=tmp;
		tmp=tmp->next;
		free(prev);
		}
	(*head) = NULL;
	return;
	}

//reverse link list
void reverse_ll(mynode **head)
	{
	mynode *p,*q,*r;
	if ((*head) == (mynode *)0)
		{
		printf("head is empty\n");
		return;
		}
	p = (*head);
	q = p->next;
	p->next=(mynode *)0;
	while (q != (mynode *)0)
		{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
		}
	(*head)=p;
	}

// display the linklist
void display(struct node **head)
	{
	struct node *tmp;
	tmp=(*head);		
	printf("ll");
	while (tmp != (mynode *)0)
		{
		printf("->%d",tmp->data);
		tmp=tmp->next;
		}
	printf("\n");
	}

//main program
int main()
	{
	int choice=0,data=0,pos=0;
	mynode *head;
	head = (mynode *)0;
	while(1)
		{
		printf("0 Exit\n");
		printf("1 insert at front\n");
		printf("2 insert at end\n");
		printf("3 insert at given position\n");
		printf("4 Delete front node\n");
		printf("5 Delete last node\n");
		printf("6 Delete given node\n");
		printf("7 Reverse link list\n");
		printf("8 delete link list\n");
		printf("9 dispaly the link list\n");
		printf("Please enter your choice: ");
		scanf("%d",&choice);

		switch(choice)
			{
			case 0 : 
				printf("\nexit link list ADT\n");
				exit(0);
				break;
			case 1 :
				printf("please enter the data to insert at front: ");
				scanf("%d",&data);
				insert_at_front(&head,data);
				break;
			case 2 :
				printf("please enter the data to insert at end: ");
				scanf("%d",&data);
				insert_at_end(&head,data);
				break;
			case 3 :
				printf("please enter the data to insert and it's position: ");				
				scanf("%d %d",&data,&pos);
				insert_at_given_position(&head,data,pos);
				break;
			case 4 :
				printf("deleting first node\n");
				delete_from_front(&head);
				break;
			case 5 :
				printf("deleting last node\n");
				delete_from_end(&head);
				break;
			case 6 :
				printf("deleting given node\n");
				printf("please insert node to be deleted: ");
				scanf("%d",&pos);
				delete_given_node(&head,pos);
				break;
			case 7 :
				printf("reverse link list\n");
				reverse_ll(&head);
				break;
			case 8 :
				delete_link_list(&head);
				break;
			case 9 :
				display(&head);
				break;
			default:
				printf("Wrong choice, please enter appropriate option\n");
			}
		}
	return 0;
	}
