/*
Q.2 Write a simulation program for disk scheduling using SCAN algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user.
Display the list of request in the order in which it is served.
Also display the total number of head moments. 86, 147, 91, 170, 95, 130, 102, 70
Starting Head position= 125
Direction: Left
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, max, dir, temp, i, j, pos, mov = 0;
    
    printf("Enter n, MaxTrack, Head, Dir(0:L, 1:R): ");
    scanf("%d %d %d %d", &n, &max, &head, &dir);
    
    int req[20]; // Array for requests
    printf("Enter %d requests: ", n);
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    // 1. Add boundaries and head to the list
    req[n] = head;
    req[n+1] = 0;
    req[n+2] = max;
    n += 3;

    // 2. Sort the requests
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(req[j] > req[j+1]) {
                temp = req[j]; req[j] = req[j+1]; req[j+1] = temp;
            }
        }
    }

    // 3. Find head position in sorted array
    for(i = 0; i < n; i++) if(req[i] == head) { pos = i; break; }

    printf("\nSCAN Disc-Scheduling Algorithm");
    printf("\nHead Movement Sequence: %d", head);

    if(dir == 0) { // LEFT
        for(i = pos-1; i >= 0; i--) {
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
        for(i = pos+1; i < n-1; i++) { // Skip the 'max' boundary in sequence if not needed
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
    } else { // RIGHT
        for(i = pos+1; i < n; i++) {
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
        for(i = pos-1; i > 0; i--) { // Skip '0' boundary if not needed
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Movements: %d\n", mov);
    return 0;
}