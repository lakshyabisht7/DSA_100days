/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointeProblem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() 
{
    int n;
    scanf("%d",&n);

    if(n<=0)
        return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for(int i=0; i<n; i++) 
    {
        int value;
        scanf("%d",&value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head==NULL) 
        {
            head=newNode;
            tail=newNode;
        } 
        else 
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    struct Node* temp = head;

    while(temp!=NULL) 
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}