#include<stdio.h>
#include<stdlib.h>

int i,j,n,m,alloc[10][10],max[10][10],need[10][10],avail[10],finish[10],seq[10];

void accept()
{
    printf("enter n and m :");
    scanf("%d%d",&n,&m);

    printf("Enter allocation : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);
    }

    printf("Enter max : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    }

    printf("Enter available : \n");
    for(j=0;j<m;j++)
        scanf("%d",&avail[j]);
}

void calc_need()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            need[i][j] = max[i][j]-alloc[i][j];
    }
}

int find()
{
    for(i=0;i<n;i++)
    {
        if(!finish[i])
        {
            for(j=0;j<m;j++)
                if(need[i][j]>avail[j]) break;
            if(j==m) return i;
        }
    }
    return -1;
}

void bankers()
{
    int k=0;
    while((i=find())!=-1)
    {
        finish[i]=1;
        for(j=0;j<m;j++) avail[j]+=alloc[i][j];
        seq[k++]=i;
    }
    if(k==n)
    {
        printf("Safe Seq : ");
        for(i=0;i<n;i++) printf("%d ",seq[i]);
    }else{
        printf("UNSAFE State!");
    }
}

void display()
{
    printf("\nOutPut:");
    printf("\nProcess\t\tAllocation\t\t\tMax\t\t\t\tNeed\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t",i);
        for(j=0;j<m;j++)
            printf("%d\t",alloc[i][j]);
        printf("\t\t");
        for(j=0;j<m;j++)
            printf("%d\t",max[i][j]);
        printf("\t\t");
        for(j=0;j<m;j++)
            printf("%d\t",need[i][j]);
        printf("\n");
    }
    printf("\nAvailable :\n");
    for(j=0;j<m;j++)
        printf("%d\t",avail[j]);
    printf("\n");
}


int main()
{
    accept();
    calc_need();
    display();
    bankers();
    return 0;
}