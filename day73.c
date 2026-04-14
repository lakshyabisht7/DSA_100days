/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/

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