/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int k;
    scanf("%d",&k);

    k=k%n;

    int t[k];

    for(int i=0; i<k; i++)
    {
        t[i]=arr[n-k+i];
    }

    for(int i=n-1; i>=k; i--)
    {
        arr[i]=arr[i-k];
    }

    for(int i=0; i<k; i++)
    {
        arr[i]=t[i];
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
