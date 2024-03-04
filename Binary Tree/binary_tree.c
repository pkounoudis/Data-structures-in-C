#include <stdio.h>
#include <stdlib.h>

#include "tree1.h"



/*Tr_init: arxikopoiei to dentro*/
void TR_init(TREE_PTR *root)
{
	*root=NULL;
}

/*Tr_empty: elegxei ean to dentro einai iso me NULL*/
int TR_empty(TREE_PTR root)
{
	return root == NULL;
}

/*Tr_data: epistrefei ta dedomena toy komvoy poy deixnei o deikths*/
elem TR_data(TREE_PTR p)
{
	return p->data;
}

/*Tr_insert_root: eisagei to stoixeio x sth riza tou dentroy*/
int TR_insert_root(TREE_PTR *root, elem x)
{
	TREE_PTR newnode;
	
	if(*root!=NULL)
		return FALSE;
		
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(!newnode)
	{
		printf("Adynamia desmeyshs mnhmhs!");
		return FALSE;
	}
	
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	*root=newnode;
	return TRUE;
}

/*Tr_insert_left: eisagei to stoixeio x ws aristero paidi toy node*/
int TR_insert_left(TREE_PTR node, elem x)
{
	TREE_PTR newnode;
	
	if(node->left!=NULL)
		return FALSE;
		
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeyshs mnhmhs!");
		return FALSE;
	}
	
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	node->left=newnode;
	return TRUE;	
}

/*Tr_insert_right: eisagei to stoixeio x ws deksi paidi toy node*/
int TR_insert_right(TREE_PTR node, elem x)
{
	TREE_PTR newnode;
	
	if(node->right!=NULL)
		return FALSE;
		
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if (!newnode)
	{
		printf("Adynamia desmeyshs mnhmhs!");
		return FALSE;
	}
	
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	
	node->right=newnode;
	return TRUE;	
}

/*Tr_delete_root(): diagrafei th riza enos dentroy efoson DEN exei paidia*/
int TR_delete_root(TREE_PTR *root, elem *x)
{
	if((*root)->left!=NULL || (*root)->right!=NULL)
		return FALSE;
	
	*x=(*root)->data;
	free(*root);
	*root=NULL;
	return TRUE;		
}

/*Tr_delete_left(): diagrafei to aristero paidi efoson DEN exei paidia*/
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

/*Tr_delete_right(): diagrafei to aristero paidi efoson DEN exei paidia*/
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

/*TR_preorder(): Ektypwnei kata thn prodiatetagmenh diadromh*/
void TR_preorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_print_node(v);
		TR_preorder(v->left);
		TR_preorder(v->right);
	}
	
	
}


/*TR_inorder(): Ektypwnei kata thn endodiatetagmenh diadromh*/
void TR_inorder(TREE_PTR v)
{
	if(v!=NULL)
	{
		TR_inorder(v->left);
		TR_print_node(v);
		TR_inorder(v->right);
	}
	
	
}

/*TR_postorder(): Ektypwnei kata thn metadiatetagmenh diadromh*/
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

/*TR_search_BST(): anazhthsh toy x sto dyadiko dentro me riza root*/
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

/*TR_insert_BST(): eisagwgh toy x sto dyadiko dentro me riza root*/
int TR_insert_BST(TREE_PTR *root, elem x)
{
	TREE_PTR current;
	
	//1. Eisagwgh se adeio dentro
	if (*root==NULL)
	{
		TR_insert_root(root, x);
		return TRUE;
	}
	
	//2. Anazhthsh kai eisagwgh sto dentro
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
