/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct node* head = NULL;
    struct node* tail = NULL;

    for(int i=0; i<n; i++)
    {
        int value;
        scanf("%d",&value);

        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head==NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    int key;
    scanf("%d",&key);

    if(head!=NULL && head->data==key)
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        struct node* current = head;

        while(current!=NULL && current->next!=NULL)
        {
            if(current->next->data == key)
            {
                struct node* temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
            current = current->next;
        }
    }

    struct node* temp = head;

    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}