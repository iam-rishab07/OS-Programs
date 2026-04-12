/*
Q.2 Write a simulation program for disk scheduling using LOOK algorithm. Accept total

number of disk blocks, disk request string, and current head position from the user.

Display the list of request in the order in which it is served.

Also display the total number of head moments. [15] 176, 79, 34, 60, 92, 11, 41, 114

Starting Head Position: 65

Direction: Left
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, dir, i, j, temp, pos, mov = 0;

    printf("Enter n, head, dir(0:L, 1:R): ");
    scanf("%d %d %d", &n, &head, &dir);

    int req[20];
    printf("Enter %d requests: ", n);
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    // 1. Add only the head (LOOK does NOT need boundaries 0 or Max)
    req[n++] = head;

    // 2. Sort the requests
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(req[j] > req[j+1]) {
                temp = req[j]; req[j] = req[j+1]; req[j+1] = temp;
            }
        }
    }

    // 3. Find current head position
    for(i = 0; i < n; i++) if(req[i] == head) { pos = i; break; }

    printf("\nSequence: %d", head);

    if(dir == 0) { // Moving LEFT
        for(i = pos - 1; i >= 0; i--) {
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
        for(i = pos + 1; i < n; i++) {
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
    } else { // Moving RIGHT
        for(i = pos + 1; i < n; i++) {
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
        for(i = pos - 1; i >= 0; i--) {
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Movements: %d\n", mov);
    return 0;
}