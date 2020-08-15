#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h> 

typedef struct Node 
{ 
	int data; 
	struct Node* npx; 
}NODE; 

NODE* XOR (NODE *a, NODE *b) 
{ 
	return (NODE*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 

void insert(NODE **head_ref, int d) 
{ 
	 // Allocate memory for new node 
    struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) ); 
    new_node->data = data; 
  
    /* Since new node is being inserted at the  
       beginning, npx of new node will always be 
       XOR of current head and NULL */
    new_node->npx = *head_ref; 
  
    /* If linked list is not empty, then npx of  
       current head node will be XOR of new node 
       and node next to current head */
    if (*head_ref != NULL) 
    { 
        // *(head_ref)->npx is XOR of NULL and next.  
        // So if we do XOR of it with NULL, we get next 
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx); 
    } 
  
    // Change head 
    *head_ref = new_node; 
} 	


void printList (NODE *head) 
{ 
	NODE *curr = head; 
	NODE *prev = NULL; 
	NODE *next; 

	printf ("Following are the nodes of Linked List: \n"); 

	while (curr != NULL) 
	{ 
	
		printf ("%d ", curr->data); 
		next = XOR (prev, curr->npx); 
		prev = curr; 
		curr = next; 
	} 
} 

int main () 
{ 
	NODE *head = NULL; 
	insert(&head, 10); 
	insert(&head, 20); 
	insert(&head, 30); 
	insert(&head, 40); 
	printList (head); 

	return (0); 
} 

