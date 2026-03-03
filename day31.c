/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/

#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int stackArray[1000];
    int topIndex = -1;

    for(int i = 0; i < n; i++) 
    {

        int operationType;
        scanf("%d", &operationType);

        if(operationType == 1) 
        {
            int value;
            scanf("%d", &value);

            topIndex++;
            stackArray[topIndex] = value;
        }

        else if(operationType == 2) 
        {

            if(topIndex == -1) 
            {
                printf("Stack Underflow\n");
            } 
            else 
            {
                printf("%d\n", stackArray[topIndex]);
                topIndex--;
            }
        }

        else if(operationType == 3) 
        {

            if(topIndex == -1) 
            {
                printf("\n");
            } else 
            {
                for(int j = topIndex; j >= 0; j--) 
                {
                    printf("%d", stackArray[j]);
                    if(j != 0)
                        printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}