/*
1. Implement the following functionsof ADT Linked List
using singly linked list as a header file:
init_l(cur) –initialise a list
empty_l(head) –boolean function to return true if list pointed to byhead is empty
atend_l(cur) –boolean function to return true if cur points to the lastnode in the list
insert_front(target, head) –insert the node pointed to by target as the first node of the list pointed to by head
insert_after(target, prev) –insert the node pointed to by target afterthe node pointed to by prev
delete_front(head) –delete the first element of the list pointed to by head
delete_after(prev) –delete the node after the one pointed to by prev
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node_tag
{
    int data;
    struct Node_tag * next;
}Node;

Node *head, *cursor, *prev, *next, *target;                     // global declaration of the pointers for various operation

Node * create_node(int item)                                    // the linked list is thus created
{
    Node * head = NULL;
    if ((head = (Node *)malloc(sizeof(Node))) == NULL )
    {
        perror("malloc error");
    }
    else
    {
        head->data = item;
        head->next = NULL;
    }
    return head;
}

Node * init_l();   // initialize a list
int empty_l( Node * head ); // boolean function to return true if list pointed to by head is empty
int atend_l( Node * cursor );  // boolean function to return true if cur points to the last node in the list
void insert_front( Node * target, Node * head ); // insert the node pointed to by target as the first node of the list
void insert_after( Node * target, Node * head ); // insert the node pointed to by target after the node pointed to by prev
void delete_front( Node * head );    // delete the first element of the list pointed to by head
void delete_after( Node * prev );    // delete the node after the one pointed to by prev

int main(void)
{

    return 0;
}

Node * init_l()
{
    return NULL;
}

int empty_l( Node *head )
{
    return( head == NULL );
}

int atend_l( Node * cursor )
{
    if ( cursor == NULL )
    {
        return 0;
    }
    else
    {
        return (cursor->next == NULL);
    } 
    
}

void insert_front( Node * target, Node * head)
{

    /*
    operations that need to be poerformed here
    first traverse the list till the target is found
    now the target must be a data value
    */
    Node * temp;
    temp = head;

    while(temp->next == target)
    
}