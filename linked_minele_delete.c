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
void delete_min()
{
	struct node*preptr=start;
	struct node*ptr=start;
	struct node*min=start;
	while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			if(ptr->data<min->data)
				{
					min=ptr;
					
				}
			if(start==min)	
				{
					preptr=preptr->next;
					start=preptr;
				}
			if(min->next==NULL)
				{
					while(preptr->next!=min)
						{
							preptr=preptr->next;
						}
							preptr->next=NULL;
						free (min);
							
				}
		
			if(ptr->next==NULL && min->next!=NULL)
				{
					while(preptr->next!=min)
						{
							preptr=preptr->next;
						}
							preptr->next=min->next;
							free (min);
						
				}
		}
}


void main()
{
	int op;
	do
		{
			printf("enter option\n1: insert\n2:display\n3:delete min\n 4: exit\n");
			scanf("%d",&op);
			switch (op)
				{
				case 1:  insert_end();
					break;
				case 2:  display();
					break;
				case 3:  delete_min();
					break;
				case 4: break;
				}
		}
	while (op!=4);
}

