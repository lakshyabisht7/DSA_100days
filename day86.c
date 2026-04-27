/*Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64

Output:
8

Input:
20

Output:
4

Input:
1

Output:
1

*/

#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int left = 1, right = n;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // avoid overflow
        if (mid <= n / mid) {
            ans = mid;          
            left = mid + 1;     
        } else {
            right = mid - 1;    
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}