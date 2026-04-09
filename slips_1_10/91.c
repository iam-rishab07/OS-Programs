/*
safe sequence
*/

#include <stdio.h>

int n, m, i, j, k, alloc[10][10], max[10][10], need[10][10], avail[10], safe[10], finish[10];

int main() {
    printf("Enter n, m: ");
    scanf("%d %d", &n, &m);

    printf("Enter Allocation Matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &max[i][j]);

    printf("Enter Available: ");
    for(j=0; j<m; j++) scanf("%d", &avail[j]);

    // Calculate Need Matrix
    printf("\nNeed Matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
        finish[i] = 0; // Initialize finish array here
    }

    // Safety Algorithm
    int work[10], count = 0;
    for(j=0; j<m; j++) work[j] = avail[j];

    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(!finish[i]) {
                for(j = 0; j < m; j++) 
                    if(need[i][j] > work[j]) break;
                
                if(j == m) { // All resources satisfied
                    for(k = 0; k < m; k++) work[k] += alloc[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(!found) break; // System entered unsafe state
    }

    if(count == n) {
        printf("\nResources can be Granted. System is SAFE.\nSafe Sequence: ");
        for(i=0; i<n; i++) printf("P%d ", safe[i]);
    } else {
        printf("\nResources can be Granted. System is NOT SAFE!");
    }
    return 0;
}