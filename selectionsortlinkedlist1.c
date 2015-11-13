#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct node*start;
void insert_end()
{
	int n;
	printf("enter the data of the linked list");
	scanf("%d",&n);
	struct node*ptr;
	struct node* newnode;
	newnode= (struct node*)malloc (sizeof(struct node));
	newnode->data=n;
	
	if(start==NULL)
		{
			newnode->next=start;
			start=newnode; 
		}
	else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			newnode->next=ptr->next;
			ptr->next= newnode;
			
		}
}
void display()
{
	struct node*ptr=start;
	printf("the list after insertion is\n");
	while( ptr!=NULL)
		{
			printf(" % d",ptr->data);
			ptr=ptr->next;
		}
}
void selection_sort()
{
 



void main()
{
	int op;
	do
		{
			printf("enter option\n1: insert\n2:display\n3:sort\n 4: exit\n");
			scanf("%d",&op);
			switch (op)
				{
				case 1:  insert_end();
					break;
				case 2:  display();
					break;
				case 3:  selection_sort();
					break;
				case 4: break;
				}
		}
	while (op!=4);
}

