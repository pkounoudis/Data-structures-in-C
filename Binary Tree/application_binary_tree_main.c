#include <stdio.h>
#include <stdlib.h>

#include "tree1.h"


main()
{
	int elem;
	TREE_PTR root;
	
	TR_init(&root);
	
	//Number ten as input
	TR_insert_root(&root, 10);
	
	//More input
	TR_insert_left(root, 6);
	TR_insert_right(root, 14);
	
	TR_insert_left(root->left, 5);
	TR_insert_right(root->left, 7);
	TR_insert_right(root->right, 19);
	
	TR_insert_left(root->left->left, 2);
	TR_insert_right(root->left->right, 8);

	TR_insert_right(root->left->left->left, 3);

	
	/*Printing the tree*/
	printf("\n preorder: ");
	TR_preorder(root);	
	
	printf("\n inorder: ");
	TR_inorder(root);	
	
	printf("\n postorder: ");
	TR_postorder(root);		
	
	
	
	
	
	
	
	
	
}
