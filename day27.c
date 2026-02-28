/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n, m;
    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;

    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head1 == NULL)
        {
            head1 = newNode;
            tail1 = newNode;
        }
        else
        {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;

    for(int i = 0; i < m; i++)
    {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head2 == NULL)
        {
            head2 = newNode;
            tail2 = newNode;
        }
        else
        {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    int l1 = 0, l2 = 0;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while(temp1 != NULL)
    {
        l1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL)
    {
        l2++;
        temp2 = temp2->next;
    }

    temp1 = head1;
    temp2 = head2;

    int diff = l1 - l2;
    if(diff < 0)
        diff = -diff;

    if(l1 > l2)
    {
        for(int i = 0; i < diff; i++)
            temp1 = temp1->next;
    }
    else
    {
        for(int i = 0; i < diff; i++)
            temp2 = temp2->next;
    }

    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data == temp2->data)
        {
            printf("%d", temp1->data);
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("No Intersection");
    return 0;
}