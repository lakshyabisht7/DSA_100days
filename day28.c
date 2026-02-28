/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int value;
    struct Node* link;
};

int main() 
{
    int n;
    scanf("%d",&n);

    if(n<=0)
        return 0;

    struct Node* start = NULL;
    struct Node* last = NULL;

    for(int i=0; i<n; i++) 
    {
        int num;
        scanf("%d",&num);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = num;
        newNode->link = NULL;

        if(start==NULL) 
        {
            start=newNode;
            last=newNode;
        } 
        else 
        {
            last->link=newNode;
            last=newNode;
        }
    }

    last->link=start;

    struct Node* tempNode = start;

    do 
    {
        printf("%d ",tempNode->value);
        tempNode=tempNode->link;
    } 
    while(tempNode != start);

    return 0;
}