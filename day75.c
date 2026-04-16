/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>

#define MAX 1000

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = 8;

    int prefixSum = 0;
    int maxLen = 0;

    // hashmap substitute (sum → index)
    int map[2000];   // to handle negative sums
    for(int i = 0; i < 2000; i++)
        map[i] = -2; // -2 = not seen

    map[1000] = -1; // sum = 0 at index -1

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int key = prefixSum + 1000; // shift for negative

        if(map[key] != -2) {
            int len = i - map[key];
            if(len > maxLen)
                maxLen = len;
        } else {
            map[key] = i; // store first occurrence
        }
    }

    printf("%d\n", maxLen);
    return 0;
}