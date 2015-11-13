#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
struct node
{
  int data;
  struct node *lc;
  struct node *rc;
};

struct node * newNode(int val)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->lc=NULL;
  newnode->rc=NULL;

  return newnode;
}

void inorder(struct node *root)
{
  if(root != NULL)
		{
			inorder(root->lc);
			printf("%d -> ",root->data);
			inorder(root->rc);
		}
}

void preorder(struct node *root)
{
  if(root != NULL)
		{
			printf("%d -> ",root->data);
			preorder(root->lc);
			preorder(root->rc);
		}
}
void postorder(struct node *root)
{
  if(root != NULL)
		{
			postorder(root->lc);
			postorder(root->rc);
			printf("%d -> ",root->data);
		}
}
bool search(struct node*root,int val)
{
	if(root==NULL)
		{
			return false;
		}
	else if(root->data==val)
		{
			return true;
		}
  else
		{
      // bool foundLeft = search(root->lc,val);
      // if(foundLeft == true)
      //  {
			//		return true;
			//	}
			// else
			//	{
			//		return search(root->rc,val);
			//	}
			return search(root->lc,val) || search(root->rc,val);
		}	
}
int main()
{ int i=0;
 struct node *root=newNode(5);
  root->lc=newNode(2);
  root->rc=newNode(1);
  root->lc->lc=newNode(3);
  root->lc->rc=newNode(4);
for(i=0;i<10;i++)
		{
			printf("Search: %d, Found: %d\n",i, search(root,i));
		}
	preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  return 0;
}
