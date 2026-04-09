#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,n,head,max,mov,dir,temp,pos;

    printf("Enter n, head, maxTrack, direction(0,1) : ");
    scanf("%d %d %d %d",&n,&head,&max,&dir);
    int req[20];
    printf("Enter %d requests :\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);

    // add boundaries and head to the list
    req[n] = head;
    req[n+1] = 0;
    req[n+2] = max;
    n=+3;

    // sort the req
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (req[j]>req[j+1])
            {
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }

    // find the head
    for(i=0;i<n;i++)
        if(req[i]==head){pos=i;break;}

    printf("Head Movement : %d",head);

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

    printf("\ntotal head movement : %d",mov);
}