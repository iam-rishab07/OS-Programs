/*
Q.2 Write a simulation program for disk scheduling using SSTF algorithm. Accept total

number of disk blocks, disk request string, and current head position from the user.

Display the list of request in the order in which it is served.

Also display the total number of head moments. 186, 89, 44, 70, 102, 22, 51, 124

Start Head Position: 70
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, head, i, j, mov = 0;
    
    printf("Enter n: "); scanf("%d", &n);
    int req[n], done[n];

    printf("Enter %d requests: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        done[i] = 0; // Mark all as unvisited
    }

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("\nSequence: %d", head);

    for(i = 0; i < n; i++) {
        int min = INT_MAX, idx = -1;

        // Find the unvisited request with the shortest seek time
        for(j = 0; j < n; j++) {
            if(!done[j] && abs(req[j] - head) < min) {
                min = abs(req[j] - head);
                idx = j;
            }
        }

        done[idx] = 1;
        mov += min;
        head = req[idx];
        printf(" -> %d", head);
    }

    printf("\nTotal Movement: %d\n", mov);
    return 0;
}