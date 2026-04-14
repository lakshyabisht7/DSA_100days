/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/

#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;

// Initialize table
void init() {
    for(int i = 0; i < m; i++)
        table[i] = -1;  // -1 means empty
}

// Insert using quadratic probing
void insert(int key) {
    for(int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;

        if(table[index] == -1) {
            table[index] = key;
            return;
        }
    }
    // table full → ignore
}

// Search using quadratic probing
void search(int key) {
    for(int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;

        if(table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if(table[index] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of queries

    init();

    char op[10];
    int key;

    for(int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0)
            insert(key);
        else if(strcmp(op, "SEARCH") == 0)
            search(key);
    }

    return 0;
}