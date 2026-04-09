/*
Q.1 Write a C program to simulate Banker’s algorithm for the purpose of deadlock
avoidance. Consider the following snapshot of system, A, B, C and D is the resource type.
a) Calculate and display the content of need matrix?
b) Is the system in safe state? If display the safe sequence.
*/

#include <stdio.h>

int n, m, i, j, alloc[10][10], max[10][10], need[10][10], avail[10], finish[10], seq[10];

void accept() {
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);
    
    printf("Enter Allocation:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter Max:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++) scanf("%d", &max[i][j]);

    printf("Enter Available: ");
    for(j=0; j<m; j++) scanf("%d", &avail[j]);
}

void calc_need() {
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int find() {
    for(i=0; i<n; i++) {
        if(!finish[i]) {
            for(j=0; j<m; j++)
                if(need[i][j] > avail[j]) break;
            if(j == m) return i; // Found a process that can run
        }
    }
    return -1;
}

void bankers() {
    int k = 0;
    while((i = find()) != -1) {
        finish[i] = 1;
        for(j=0; j<m; j++) avail[j] += alloc[i][j]; // Release resources
        seq[k++] = i;
    }

    if(k == n) {
        printf("\nSystem is in SAFE state.\nSafe Sequence: ");
        for(i=0; i<n; i++) printf("P%d ", seq[i]);
    } else {
        printf("\nSystem is in UNSAFE state!");
    }
}

int main() {
    accept();
    calc_need();
    bankers();
    return 0;
}