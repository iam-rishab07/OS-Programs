#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int i,j,n,mov=0,temp,pos,dir,head;
    printf("Enter n, head, dir(1,0) : ");
    scanf("%d%d%d",&n,&head,&dir);

    int req[20];
    printf("Enter %d requests : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    req[n++] = head;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(req[i]==head){pos=i; break;}
    }

    printf("\nC-LOOK\n");
    printf("Head Sequence : %d",head);

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

    printf("Total Movement : %d",mov);

    return 0;
}
