/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged. */

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
    scanf("%d",&n);

    struct node* head1 = NULL;
    struct node* tail1 = NULL;

    for(int i=0; i<n; i++)
    {
        int value;
        scanf("%d",&value);

        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head1 == NULL)
        {
            head1 = newnode;
            tail1 = newnode;
        }
        else
        {
            tail1->next = newnode;
            tail1 = newnode;
        }
    }

    int m;
    scanf("%d",&m);

    struct node* head2 = NULL;
    struct node* tail2 = NULL;

    for(int i=0; i<m; i++)
    {
        int value;
        scanf("%d", &value);

        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head2 == NULL)
        {
            head2 = newnode;
            tail2 = newnode;
        }
        else
        {
            tail2->next = newnode;
            tail2 = newnode;
        }
    }

    struct node* resultHead = NULL;
    struct node* resultTail = NULL;

    while(head1!=NULL && head2!=NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;

        if(head1->data <= head2->data)
        {
            newnode->data = head1->data;
            head1 = head1->next;
        }
        else
        {
            newnode->data = head2->data;
            head2 = head2->next;
        }

        if(resultHead == NULL)
        {
            resultHead = newnode;
            resultTail = newnode;
        }
        else
        {
            resultTail->next = newnode;
            resultTail = newnode;
        }
    }

    while(head1!=NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head1->data;
        newnode->next = NULL;

        if(resultHead == NULL)
        {
            resultHead = newnode;
            resultTail = newnode;
        }
        else
        {
            resultTail->next = newnode;
            resultTail = newnode;
        }

        head1 = head1->next;
    }

    while(head2!=NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head2->data;
        newnode->next = NULL;

        if(resultHead == NULL)
        {
            resultHead = newnode;
            resultTail = newnode;
        }
        else
        {
            resultTail->next = newnode;
            resultTail = newnode;
        }

        head2 = head2->next;
    }

    struct node* temp = resultHead;

    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}