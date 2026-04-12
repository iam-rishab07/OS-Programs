/*
Q.2 Write a simulation program for disk scheduling using C-SCAN algorithm. Accept total

number of disk blocks, disk request string, and current head position from the user.

Display the list of request in the order in which it is served. Also display the total number

of head moments. 33, 99, 142, 52, 197, 79, 46, 65 Start Head Position: 72 Direction: Left
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, max, head, dir, i, j, temp, pos, mov = 0;

    printf("Enter n, Max, Head, Dir(0:L, 1:R): ");
    scanf("%d %d %d %d", &n, &max, &head, &dir);

    int req[20];
    printf("Enter %d requests: ", n);
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    // 1. Add Head and BOTH boundaries (0 and Max)
    req[n] = head; req[n+1] = 0; req[n+2] = max;
    n += 3;

    // 2. Sort
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(req[j] > req[j+1]) { temp = req[j]; req[j] = req[j+1]; req[j+1] = temp; }

    for(i = 0; i < n; i++) if(req[i] == head) { pos = i; break; }

    printf("\nSequence: %d", head);

    if(dir == 1) { // RIGHT
        for(i = pos + 1; i < n; i++) {
            mov += abs(req[i] - head);
            head = req[i]; printf(" -> %d", head);
        }
        // Jump to 0
        mov += head; head = 0; printf(" -> %d", head);
        for(i = 0; i < pos; i++) {
            mov += abs(req[i] - head);
            head = req[i]; printf(" -> %d", head);
        }
    } else { // LEFT
        for(i = pos - 1; i >= 0; i--) {
            mov += abs(req[i] - head);
            head = req[i]; printf(" -> %d", head);
        }
        // Jump to Max
        mov += abs(max - head); head = max; printf(" -> %d", head);
        for(i = n - 1; i > pos; i--) {
            mov += abs(req[i] - head);
            head = req[i]; printf(" -> %d", head);
        }
    }
    printf("\nTotal Movements: %d\n", mov);
    return 0;
}