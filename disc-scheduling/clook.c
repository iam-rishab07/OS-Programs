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
        // Jump to Max
        mov += abs(max - head); head = max; printf(" -> %d", head);
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
        // Jump to 0
        mov += head; head = 0; printf(" -> %d", head);
        for(i = pos - 1; i >= 0; i--) {
            mov += abs(req[i] - head);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Movements: %d\n", mov);
    return 0;
}