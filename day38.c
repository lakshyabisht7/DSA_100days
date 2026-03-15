/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int count = 0;

void push_front(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if(front != NULL)
        front->prev = newNode;

    front = newNode;

    if(rear == NULL)
        rear = newNode;

    count++;
}

void push_back(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if(rear != NULL)
        rear->next = newNode;

    rear = newNode;

    if(front == NULL)
        front = newNode;

    count++;
}

void pop_front()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if(front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
    count--;
}

void pop_back()
{
    if(rear == NULL)
    {
        printf("-1\n");
        return;
    }

    struct Node* temp = rear;
    printf("%d\n", temp->data);

    rear = rear->prev;

    if(rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
    count--;
}

void get_front()
{
    if(front == NULL)
        printf("-1\n");
    else
        printf("%d\n", front->data);
}

void get_back()
{
    if(rear == NULL)
        printf("-1\n");
    else
        printf("%d\n", rear->data);
}

void empty()
{
    if(count == 0)
        printf("1\n");
    else
        printf("0\n");
}

void size()
{
    printf("%d\n", count);
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        char op[20];
        scanf("%s",op);

        if(strcmp(op,"push_front")==0)
        {
            int x;
            scanf("%d",&x);
            push_front(x);
        }
        else if(strcmp(op,"push_back")==0)
        {
            int x;
            scanf("%d",&x);
            push_back(x);
        }
        else if(strcmp(op,"pop_front")==0)
            pop_front();

        else if(strcmp(op,"pop_back")==0)
            pop_back();

        else if(strcmp(op,"front")==0)
            get_front();

        else if(strcmp(op,"back")==0)
            get_back();

        else if(strcmp(op,"empty")==0)
            empty();

        else if(strcmp(op,"size")==0)
            size();
    }

    return 0;
}