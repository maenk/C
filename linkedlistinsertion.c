#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct node*start;
void insert_beg()
{
	int n;
	printf("enter the data");
	scanf("%d",&n);
	struct node* newnode;
	newnode= (struct node*)malloc (sizeof(struct node));
	newnode->data=n;
	newnode ->next= start;
	start = newnode;
}
void insert_end()
{
	int n;
	printf("enter the data");
	scanf("%d",&n);
	struct node*ptr;
	struct node* newnode;
	newnode= (struct node*)malloc (sizeof(struct node));
	newnode->data=n;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next= newnode;
	newnode->next=NULL;
}
void delete_beg()
{
	if (start==NULL)
		printf("cannot delete first insert\n");
	else
		{	
			struct node*ptr=start;
			start=start->next;
			free(ptr);
		}
}
void delete_end()
{
	if (start==NULL)
		printf("cannot delete first insert\n");
	else
		{
			struct node*preptr;
			struct node*ptr=start;
			preptr=ptr;
			while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
			while (preptr->next!=ptr)
				{
					preptr=preptr->next;
				}
			preptr->next=NULL;
			free (ptr);
		}
}
void display()
{struct node*ptr=start;
	printf("the list after insertion is\n");
	while( ptr!=NULL)
		{
			printf(" % d",ptr->data);
			ptr=ptr->next;
		}
}
void main()
{
	int op;
	do
		{
			printf("enter option\n1:insert at beginning\n2: insert at end\n5:display\n3:delete beg\n4:delete end\n6: exit\n");
			scanf("%d",&op);
			switch (op)
				{
				case 1:  insert_beg();
					break;
				case 2:  insert_end();
					break;
				case 3:  delete_beg();
					break;
				case 4:  delete_end();
					break;
				case 5: display();
					break;
				case 6: break;
				}
		}
	while (op!=6);
}
	
