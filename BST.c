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
struct node* insert_BST(struct node*root,int val)
{
	if(root==NULL)
		{
			root=newNode(val);
			return root;
		}
	else if(val<root->data)
		{
			root->lc=insert_BST(root->lc,val);
		}
	else
		root->rc=insert_BST(root->rc,val);
	return root;   
}
int main()
{
	struct node *root=NULL;
	root=insert_BST(root,5);
	root=insert_BST(root,4);
	root=insert_BST(root,1);
	root=insert_BST(root,3);
	root=insert_BST(root,2);

	preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  return 0;
}
