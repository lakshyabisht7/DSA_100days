/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct PolyNode* head = NULL;
    struct PolyNode* tail = NULL;

    for(int i = 0; i < n; i++) {
        int coeff, expo;
        scanf("%d %d", &coeff, &expo);

        struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
        newNode->coefficient = coeff;
        newNode->exponent = expo;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct PolyNode* temp = head;

    while(temp != NULL) {

        if(temp->exponent == 0) {
            printf("%d", temp->coefficient);
        }
        else if(temp->exponent == 1) {
            printf("%dx", temp->coefficient);
        }
        else {
            printf("%dx^%d", temp->coefficient, temp->exponent);
        }

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}