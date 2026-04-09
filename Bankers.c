#include<stdio.h>

int i,j,m,n,alloc[10][10],max[10][10],need[10][10],avail[10],finish[10],seq[10];

void accept()
{
    printf("Enter n (processes) and m (resources) :\n");
    scanf("%d %d",&n,&m); 

    printf("enter allocation :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("enter max :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("enter available :\n");
    for(j=0;j<m;j++)
    {
        scanf("%d",&avail[j]);
    }
}

void calc_need()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
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
        printf("\nSystem is in SAFE State, Resources can be Granted :)\nSAFE Sequence :\n");
        printf("P%d",seq[0]);
        for(i=1;i<n;i++)
            printf("->P%d ",seq[i]);
    }else{
        printf("\nSystem is in UNSAFE State!\nResources cant be Granted :(");
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