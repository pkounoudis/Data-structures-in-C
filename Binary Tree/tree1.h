/*tree.h: Dhlwseis dyadikoy dentrou*/

#define TRUE 1
#define FALSE 0

typedef int elem;   /*  tree data type  */

struct node{			/*  tree node type  */
	elem data;			/*  data  */
	struct node *left;  /*  left child  */
	struct node *right; /*  right child  */
};

typedef struct node TREE_NODE; /*synonym of tree node*/
typedef struct node *TREE_PTR;	/*synonym of ponter tree node*/

void TR_init(TREE_PTR *root);
int TR_empty(TREE_PTR root);
elem TR_data(TREE_PTR p);
int TR_insert_root(TREE_PTR *root, elem x);
int TR_insert_left(TREE_PTR node, elem x);
int TR_insert_right(TREE_PTR node, elem x);
int TR_delete_root(TREE_PTR *root, elem *x);
int TR_delete_left(TREE_PTR parent, elem *x);
int TR_delete_right(TREE_PTR parent, elem *x);
void TR_preorder(TREE_PTR v);
void TR_inorder(TREE_PTR v);
void TR_postorder(TREE_PTR v);
void TR_print_node(TREE_PTR v);

int TR_search_BST(TREE_PTR root, elem x);
int TR_insert_BST(TREE_PTR *root, elem x);






