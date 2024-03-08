#include "linked_list.h"

/*LL_init(): initialising the linked list*/
void LL_init(LIST_PTR *head)
{
	*head=NULL;
}

/*LL_empty(): returns TRUE/FALSE if list is empty or full*/
int LL_empty(LIST_PTR head)
{
	return head==NULL;
}

/*LL_insert_start(): Inserts element x after head, at the beginning of the list*/
int LL_insert_start(LIST_PTR *head, elem x)
{
	LIST_PTR newnode;
	
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if(!newnode)
	{
		printf("Cannot allocate memory!");
		return FALSE;
	}
	newnode->data=x;
	
	newnode->next=*head;
	*head=newnode;
	return TRUE;
}

/*LL_insert_after(): Inserts the element x after the element that pointer points at*/
int LL_insert_after(LIST_PTR p, elem x)
{
	LIST_PTR newnode;
	
	newnode=malloc(sizeof(LIST_NODE));
	if(!newnode)
	{
		printf("Cannot allocate memory!");
		return FALSE;
	}
	newnode->data=x;
	
	newnode->next=p->next;
	p->next=newnode;
	return TRUE;
}

/*LL_delete_start(): Deletes the first element of the list Diagrafei*/
int LL_delete_start(LIST_PTR *head, elem *x)
{
	LIST_PTR current;
	
	if (*head==NULL)
		return FALSE;
	
	current=*head;
	*x=current->data;
	
	(*head)=(*head)->next;
	free(current);
	return TRUE; 
}

/*LL_delete_after(): Diagrafei to prwto stoixeio meta to stoixeio poy deixnei o prev*/
int LL_delete_after(LIST_PTR prev, elem *x)
{
	LIST_PTR current;
	
	if (prev->next==NULL)
		return FALSE;
		
	current=prev->next;
	*x=current->data;
	
	prev->next=current->next;
	free(current);
	return TRUE;
}

/*void LL_destroy:() Apodesmeyei to xvro poy exei desmeusei h lista*/
void LL_destroy(LIST_PTR *head)
{
	LIST_PTR ptr;
	
	while (*head!=NULL)
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
	
}

/*void LL_print(): Prints list's content*/
void LL_print(LIST_PTR head)
{
	LIST_PTR current;
	
	current=head;
	while(current!=NULL)
	{
		printf("%d", current->data);
		current=current->next;
	}
}
