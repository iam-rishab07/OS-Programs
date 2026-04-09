/*
Q.1) Write a C Menu driven Program to implement following functionality
a) Accept Available
b) Display Allocation, Max
c) Display the contents of need matrix
d) Display Available
*/

#include<stdio.h>

int i,j,n,m,alloc[10][10],max[10][10],need[10][10],avail[10],finish[10],seq[10];

void accept()
{
    printf("Enter n and m :\n");    // n:processes, m:resources
    scanf("%d %d",&n,&m);

    printf("Enter Allocation :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);
    }

    printf("Enter Max :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    }

    printf("Enter Available :\n");
    for(j=0;j<m;j++) scanf("%d",&avail[j]);
}

void calc_need()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

void display()
{
    printf("\nProcess\t\tAllocation\t\t\tMax\t\t\t\tNeed \n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t",i);
        for(j=0;j<m;j++)
        {
            printf("%d\t",alloc[i][j]);
        }
        printf("\t\t");
        for(j=0;j<m;j++)    
            printf("%d\t",max[i][j]);
        printf("\t\t");
        for(j=0;j<m;j++)    
            printf("%d\t",need[i][j]);
        printf("\n");
    }
    printf("\nAvailable :\t");
    for(j=0;j<m;j++) printf("%d\t",avail[j]);
}

int main()
{
    accept();
    calc_need();
    display();
    return 0;
}