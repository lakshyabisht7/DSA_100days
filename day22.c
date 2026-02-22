/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

struct item
{
    int value;
    struct item* next;
};

int main()
{
    int n;
    scanf("%d",&n);

    struct item* start = NULL;
    struct item* end = NULL;

    for(int i=0; i<n; i++)
    {
        int n;
        scanf("%d",&n);

        struct item* newitem = (struct item*)malloc(sizeof(struct item));
        newitem->value = n;
        newitem->next = NULL;

        if(start==NULL)
        {
            start=newitem;
            end=newitem;
        }
        else
        {
            end->next = newitem;
            end = newitem;
        }
    }

    int total=0;
    struct item* temp = start;

    while(temp!=NULL)
    {
        total++;
        temp = temp->next;
    }
    printf("%d",total);

    return 0;
}