/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int first=arr[0];
    int second=arr[1];
    int min_sum=arr[0]+arr[1];

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum=arr[i]+arr[j];

            if(abs(sum) < abs(min_sum))
            {
                min_sum=sum;
                first=arr[i];
                second=arr[j];
            }
        }
    }

    if(first < second)
        printf("%d %d",first,second);
    else
        printf("%d %d",second,first);

    return 0;
}
