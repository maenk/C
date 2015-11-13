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
	printf("enter the data");
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
	struct node*preptr;
	struct node*ptr=start;
	preptr=ptr;
	printf("the list after insertion is\n");
	if(preptr==start)
		{
			printf("previous NULL");		
			printf("current %d",preptr->data);
		
		}

	while( ptr->next!=NULL)
		{
			printf("previous % d  ",ptr->data);
			preptr=preptr->next;
			printf("current % d  " ,preptr->data);
			ptr=ptr->next;
		}
}


	void main()
	{
		int op;
		do
			{
				printf("enter option\n1: insert\n2:display\n 3: exit\n");
				scanf("%d",&op);
				switch (op)
					{
					case 1:  insert_end();
						break;
					case 2:  display();
						break;
		 
					case 3: break;
					}
			}
		while (op!=3);
	}
	
	
