/*
Given a singly linked list, write a program to swap the elements of the linked list pairwise. For example, if the linked list is 1->2->3->4->5 then the program
should change it to 2->1->4->3->5.

You need to implement ONLY the following functions, the main() function is already provided with the code, so do not implement the main() function.

push(struct Node** head_ref, int new_data)
// This function takes the address of the pointer to the head of the linked list and an integer as arguments.
// This function creates a new node with data as "new_data" and appends this node to the front of the original linked list.

Working Example:

push(&start, 5)
Linked List: 5
head pointed to: 5

push(&start, 6)
Linked List: 6->5
Head Pointed to: 6

push(&start, 1)
Linked List: 1->6->5
Head Pointed to: 1

pairWiseSwap(struct Node *head);
// This function takes the address of the head node as an argument.
// Inside this function, you need to implement the pairwise swapping.

printList(struct Node *node)
// This function takes the address of the head node as argument and prints the elements of the linked list in a single line separated by space.

The structure of the node of linked list has already been defined as the following, hence do not define it in your code:

struct Node
{    int data;
    struct Node *next;
};

Input:
The first line of input contains an integer N, denoting the number of elements in linked list
The second line contains the N elements in a single line separated by space

Output:
Output the manipulated linked list elements in a single line separated by space.

Example:
Input:
5
5 4 3 2 1

Output:
2 1 4 3 5

*/
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct Node
{
    int data;
    struct Node *next;
};
void swap(int *k, int *b);
 
/* Function to pairwise swap elements of a linked list */
void pairWiseSwap(struct Node *head)
{
    struct Node *temp = head;
 
    /* Traverse further only if there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL)
    {
        /* Swap data of node with its next node's data */
        swap(&temp->data, &temp->next->data);
 
        /* Move temp by 2 for the next pair */
        temp = temp->next->next;
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to swap two integers */
void swap(int *k, int *b)
{
    int temp;
    temp = *k;
    *k = *b;
    *b = temp;
}
 
/* Function to add a node at the begining of Linked List */
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
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
       node = node->next;
    }
}
int main()
{
    struct Node *start = NULL;

    int a, x, i;
    scanf("%d", &a);

    for (i = 0; i < a; i++)
    {
        scanf("%d",&x);
        push(&start, x);
    }
 
 
 
    pairWiseSwap(start);
 
    printList(start);
 
    return 0;
}
