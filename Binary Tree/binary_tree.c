#include <stdio.h>
#include <stdlib.h>

#include "tree1.h"



/*Tr_init: Initialising the tree*/
void TR_init(TREE_PTR *root)
{
	*root=NULL;
}

/*Tr_empty: Checks if tree == NULL*/
int TR_empty(TREE_PTR root)
{
	return root == NULL;
}

/*Tr_data: returns node data where the pointer points*/
elem TR_data(TREE_PTR p)
{
	return p->data;
}

/*Tr_insert_root: inserts element x in tree's root*/
int TR_insert_root(TREE_PTR *root, elem x)
{
	TREE_PTR newnode;
	
	if(*root!=NULL)
		return FALSE;
		
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(!newnode)
	{
		printf("Canot allocate memory!");
		return FALSE;
	}
	
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	*root=newnode;
	return TRUE;
}

/*Tr_insert_left: inserts element as the node's left child*/
int TR_insert_left(TREE_PTR node, elem x)
{
	TREE_PTR newnode;
	
	if(node->left!=NULL)
		return FALSE;
		
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode)
	{
		printf("Canot allocate memory!");
		return FALSE;
	}
	
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	node->left=newnode;
	return TRUE;	
}

/*Tr_insert_right: inserts element as the node's right child*/
int TR_insert_right(TREE_PTR node, elem x)
{
	TREE_PTR newnode;
	
	if(node->right!=NULL)
		return FALSE;
		
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode)
	{
		printf("Cannot allocate memory!");
		return FALSE;
	}
	
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	node->right=newnode;
	return TRUE;	
}

/*Tr_delete_root(): deletes tree's root if there are NO CHILDREN*/
int TR_delete_root(TREE_PTR *root, elem *x)
{
	if((*root)->left!=NULL || (*root)->right!=NULL)
		return FALSE;
	
	*x=(*root)->data;
	free(*root);
	*root=NULL;
	return TRUE;		
}

/*Tr_delete_left(): deletes left child if it has no other children*/
int TR_delete_left(TREE_PTR parent, elem *x)
{
	TREE_PTR current;
	
	if(parent->left==NULL)
		return FALSE;
		
	current=parent->left;
	if(current->left!=NULL || current->right!=NULL)
		return FALSE;
		
	*x=current->data;
	free(current);
	parent->left=NULL;
	return TRUE;	
}

/*Tr_delete_right(): deletes right child if it has no other children*/
int TR_delete_right(TREE_PTR parent, elem *x)
{
	TREE_PTR current;
	
	if(parent->right==NULL)
		return FALSE;
		
	current=parent->right;
	if(current->left!=NULL || current->right!=NULL)
		return FALSE;
		
	*x=current->data;
	free(current);
	parent->right=NULL;
	return TRUE;	
}

/*TR_preorder(): prints preorder route*/
void TR_preorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_print_node(v);
		TR_preorder(v->left);
		TR_preorder(v->right);
	}
	
	
}


/*TR_inorder(): prints inorder route*/
void TR_inorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_inorder(v->left);
		TR_print_node(v);
		TR_inorder(v->right);
	}
	
	
}

/*TR_postorder(): prints postorder route*/
void TR_postorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_postorder(v->left);
		TR_postorder(v->right);
		TR_print_node(v);
		
	}
	
	
}

/*Ektypwsh dentroy*/
void TR_print_node(TREE_PTR v)
{
	printf("%d ",v->data);
}

/*TR_search_BST(): searching x in binary tree with root*/
int TR_search_BST(TREE_PTR root, elem x)
{
	TREE_PTR current;
	
	current=root;
	
	while(current!=NULL)
	{
		if (x==current->data)
			return TRUE;
		else if (x<current->data)
			current=current->left;
		else if (x>current->data)
			current=current->right;	
	}
	
	return FALSE;
}

/*TR_insert_BST(): insterting x in binary tree with root*/
int TR_insert_BST(TREE_PTR *root, elem x)
{
	TREE_PTR current;
	
	//1. Insert in empty tree
	if (*root==NULL)
	{
		TR_insert_root(root, x);
		return TRUE;
	}
	
	//2. Searching and inserting in the tree
	current=*root;
	while(1)
	{
		if (x==current->data)
			return FALSE;
			
		else if (x<current->data)
		{
			if (current->left==NULL)
			{
				TR_insert_left(current, x);
				return TRUE;
			}
			else
				current=current->left;			
		}
		else if (x>current->data)
		{
			if (current->right==NULL)
			{
				TR_insert_right(current, x);
				return TRUE;
			}
			else
				current=current->right;	
			
		}
	}
		
}
