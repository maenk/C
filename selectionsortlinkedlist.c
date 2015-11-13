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
	printf("enter the data of the linked list : ");
	scanf("%d",&n);
	struct node*ptr;
	struct node* newnode;
	newnode= (struct node*)malloc (sizeof(struct node));
	newnode->data=n;
	newnode->next = NULL;

	if(start==NULL)
		{
			start=newnode; 
		}
	else
		{	
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next= newnode;			
		}
}
void display()
{
	struct node*ptr=start;
	printf("the list after insertion is\n");
	while( ptr!=NULL)
		{
			printf(" %d -> ",ptr->data);
			ptr=ptr->next;
		}
  printf("\n");
}
void selection_sort()
{
	struct node*min=NULL;
	struct node*preptr=NULL;
	struct node*ptr=start;
	struct node*preMin=NULL;
	struct node*newlist=NULL;
	struct node*list=start;
	
	while(list != NULL)
		{
      ptr=list;
      preptr=NULL;  
			min=list;
			preMin=NULL;		
			while(ptr->next != NULL)
				{
          preptr=ptr;
					ptr=ptr->next;
					if(ptr->data < min->data)
						{
              min=ptr;
							preMin=preptr;
						}	
				}
      // move the min element from list to new list
      // First node has to be moved?
      if(preMin == NULL)
				{
					list=list->next;
					min->next=newlist;
					newlist=min;
				}
      // A non-first node deletion
      else 
        {
					preMin->next=min->next;
					min->next=newlist;
					newlist=min;
				}
		}		
	start=newlist;
}

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

