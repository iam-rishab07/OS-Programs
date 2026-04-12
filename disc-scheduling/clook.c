#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, n, mov = 0, temp, pos, dir, head;
    printf("Enter n, head, dir(1-Right, 0-Left): ");
    scanf("%d %d %d", &n, &head, &dir);

    int req[25]; // Safe buffer
    printf("Enter %d requests: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    // Add head to array to sort it into the sequence
    req[n++] = head;

    // Sort requests
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(req[j] > req[j+1])
            {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }

    // Find current head position
    for(i = 0; i < n; i++)
    {
        if(req[i] == head) { pos = i; break; }
    }

    printf("\nC-LOOK\n");
    printf("Head Sequence: %d", head);

    if(dir == 1) { // DIRECTION: RIGHT
        // Go right to the largest request
        for(i = pos + 1; i < n; i++) {
            mov += abs(req[i] - head);
            head = req[i]; 
            printf(" -> %d", head);
        }
        // Jump to the smallest request (C-LOOK behavior)
        if(pos > 0) {
            mov += abs(head - req[0]); 
            head = req[0];
            printf(" -> %d", head);
            
            // Continue right from the smallest request up to the original head
            for(i = 1; i < pos; i++) {
                mov += abs(req[i] - head);
                head = req[i]; 
                printf(" -> %d", head);
            }
        }
    } 
    else { // DIRECTION: LEFT
        // Go left to the smallest request
        for(i = pos - 1; i >= 0; i--) {
            mov += abs(req[i] - head);
            head = req[i]; 
            printf(" -> %d", head);
        }
        // Jump to the largest request (C-LOOK behavior)
        if(pos < n - 1) {
            mov += abs(head - req[n-1]);
            head = req[n-1];
            printf(" -> %d", head);

            // Continue left from the largest request down to the original head
            for(i = n - 2; i > pos; i--) {
                mov += abs(req[i] - head);
                head = req[i]; 
                printf(" -> %d", head);
            }
        }
    }

    printf("\nTotal Head Movement: %d\n", mov);

    return 0;
}