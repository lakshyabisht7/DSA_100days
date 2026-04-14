/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e*/

#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    // Step 1: count frequency
    for(int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: find first non-repeating
    for(int i = 0; s[i]; i++) {
        if(freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[1000];
    scanf("%s", s);

    printf("%c\n", firstNonRepeating(s));

    return 0;
}