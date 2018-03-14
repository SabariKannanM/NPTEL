/*
Write a program in C to reverse a linked list.

You are supposed to implement only these following three functions:

push(struct Node** head_ref, int new_data);
// This function takes two arguments, first is the address of the pointer to the head
of the linked list and second is the data which has to be inserted
// The function should create a new node with data as new_data and
appends this new node in the front of the original linked list.

Working Example:
push(&head, 2);
Linked List: 2

push(&head, 3);
Linked List: 3->2

push(&head, 4)
Linked List: 4->3->2

reverse(struct Node** head_ref);
//This function takes the address of the pointer to the head node of the linked list as the
argument.
//This function reverse the linked list

printList(struct Node *head);
// This function takes the address of the head node of the linked list and prints the N elements of the list in a single line separated by space.

Input:
The first line of input contains an integer N denoting the number of elements.
The second line contains the N integers in a single line separated by space.

Output:
Output the reverse of linked list in single line separated by space

Example:
Input:
5
5 4 3 2 1

Output:
5 4 3 2 1
*/

#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
// You are supposed to implement following three functions

//push(struct Node** head_ref, int new_data);
// This function takes two arguments, first is the address of the pointer to the head
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
        
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
//of the linked list and second is the data which has to be inserted
// The function should create a new node with data as new_data and
//appends this new node in the front of the original linked list.

static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
//This function takes the address of the pointer to the head node of the linked list as the
//argument.
//This function reverse the linked list

void printList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);    
        temp = temp->next;  
    }
}    
// This function takes the address of the head node of the linked list and prints the elements of the list.

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
   	 int a,x,i;
   	 scanf("%d",&a);
   	 for(i=0; i<a; i++){
   	 	scanf("%d",&x);
   	 	push(&head, x);
   	 }	
   
     
     reverse(&head);                      
     printList(head);    
     getchar();
}
/*
Sample Test Cases
Input	Output
Test Case 1	
5
1 2 3 4 5
1 2 3 4 5
Test Case 2	
6
6 5 4 3 2 1
6 5 4 3 2 1
Test Case 3	
6
1 6 2 5 3 4
1 6 2 5 3 4
Test Case 4	
10
7 3 1 9 7 5 3 8 6 2
7 3 1 9 7 5 3 8 6 2
Test Case 5	
20
23 12 34 65 23 65 3 56 34 3 12 34 54 89 76 45 78 12 34 87
23 12 34 65 23 65 3 56 34 3 12 34 54 89 76 45 78 12 34 87

*/
