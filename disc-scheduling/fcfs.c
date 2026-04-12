/*
Q.2) Write a simulation program for disk scheduling using FCFS algorithm. Accept total
number of disk blocks, disk request string, and current head position from the user.
Display the list of request in the order in which it is served. Also display the total number
of head moments. 55, 58, 39, 18, 90, 160, 150, 38, 184 Start Head Position: 50
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,head,totalMovement=0;
    printf("enter the no. of requests :\n");
    scanf("%d",&n);
    int requests[n];
    printf("enter the requests (disk track numbers) :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&requests[i]);
    }

    printf("enter the initial head position :\n");
    scanf("%d",&head);

    printf("FCFS Disk Scheduling Alogrithm\n");
    printf("Head movement sequence : %d",head);

    for(int i=0;i<n;i++)
    {
        totalMovement += abs(requests[i]-head);
        head = requests[i];
        printf("->%d",head);
    }
    printf("\nTotal head movement : %d\n",totalMovement);
    return 0;
}