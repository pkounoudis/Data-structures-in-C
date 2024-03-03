#include "linked_list.h"

/*LL_init(): initialising the linked list*/
void LL_init(LIST_PTR *head)
{
	*head=NULL;
}

/*LL_empty(): epistrefei TRUE/FALSE an h lista einai adeia h gemath*/
int LL_empty(LIST_PTR head)
{
	return head==NULL;
}

/*LL_insert_start(): Eisagei to stoixeio x meta ton head, sthn arxh ths listas dld*/
int LL_insert_start(LIST_PTR *head, elem x)
{
	LIST_PTR newnode;
	
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if(!newnode)
	{
		printf("Adynamia desmeyshs mnhmhs");
		return FALSE;
	}
	newnode->data=x;
	
	newnode->next=*head;
	*head=newnode;
	return TRUE;
}

/*LL_insert_after(): Eisagei to stoixeio x meta to stoixeio poy deixnei o p*/
int LL_insert_after(LIST_PTR p, elem x)
{
	LIST_PTR newnode;
	
	newnode=malloc(sizeof(LIST_NODE));
	if(!newnode)
	{
		printf("Adynamia desmeyshs mnhmhs");
		return FALSE;
	}
	newnode->data=x;
	
	newnode->next=p->next;
	p->next=newnode;
	return TRUE;
}

/*LL_delete_start(): Diagrafei to prwto stoixeio ths listas*/
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

/*void LL_print(): Typwnei ta periexomena ths listas*/
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
