#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct node*start;
void sortinsert()
{
	struct node* newnode;
	
	int val;
	printf("enter the value you Want to insert");
	scanf("%d",&val);
 	newnode=(struct node*)malloc(sizeof(struct node));
 	newnode->data=val;
	newnode->next=NULL;

	if(start==NULL)
		{
			start=newnode;
		}
	else if (val < start->data)
		{
			newnode->next=start;
			start=newnode;
		}
	else
		{
			struct node*preptr;
			struct node*ptr;
			ptr=start;
			preptr = ptr;

			while (ptr->next!=NULL && ptr->next->data < val)
				{
					ptr=ptr->next;
				}
			if(ptr->next==NULL)
				{
					ptr->next=newnode;
				}
			else
				{		
					preptr=ptr;
					ptr=ptr->next;
					preptr->next=newnode; 
					newnode-> next =ptr;   
				}
		}
}
void display()
{
	struct node*ptr=start;
	printf("\nthe list after insertion is\n");
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
			printf("\nenter option\n1:insert sorted\n2:display\n3: exit\n");
			scanf("%d",&op);
			switch (op)
				{
				case 1:  sortinsert();
					break;
				case 2: display();
					break;
				case 3: break;
				}
		}
	while (op!=3);
}	
