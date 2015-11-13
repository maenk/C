#include<stdio.h>
#include<malloc.h>

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
int main()
{
 struct node *root=newNode(5);
  root->lc=newNode(2);
  root->rc=newNode(1);
  root->lc->lc=newNode(3);
  root->lc->rc=newNode(4);
	preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  return 0;
}
