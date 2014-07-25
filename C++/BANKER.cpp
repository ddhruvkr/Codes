#include<stdio.h>
#include<stdlib.h>
int main()
{
int clm[7][5],req[7][5],alloc[7][5],rsrc[5],avail[5],comp[7];
int first,p,r,i,j,prc,count,t;
count=0;
for(i=1;i<=7;i++)
comp[i]=0;
printf("Enter the no of processes:\n");
scanf("%d",&p);
printf("Enter the no of resources:\n");
scanf("%d",&r);
printf("Enter the claim for each process:");
for(i=1;i<=p;i++)
{
printf("\nFor process %d",i);
for(j=1;j<=r;j++)
{
scanf("%d",&clm[i][j]);
}
}
printf("Enter the allocation for each process:\n");
for(i=1;i<=p;i++)
{
printf("\nFor process ",i);
for(j=1;j<=r;j++)
{
scanf("%d",&alloc[i][j]);
}
}
printf("Enter total no of each resource:");
for(j=1;j<=r;j++)
scanf("%d",&rsrc[j]);
for(j=1;j<=r;j++)
{
int total=0;
avail[j]=0;
for(i=1;i<=p;i++)
{total+=alloc[i][j];}
avail[j]=rsrc[j]-total;
}
do
{
for(i=1;i<=p;i++)
{
for(j=1;j<=r;j++)
{
req[i][j]=clm[i][j]-alloc[i][j];
}
}
printf("\n\nAvailable resorces is:");
for(j=1;j<=r;j++)
{ printf(" ",avail[j]); }
printf("\nClaim matrix:\t\tAllocation matrix:\n");
for(i=1;i<=p;i++)
{
for(j=1;j<=r;j++)
{
printf("%d",clm[i][j]);
}
printf("\t\t\t");
for(j=1;j<=r;j++)
{
printf("%d",alloc[i][j]);
}
printf("\n");
}
prc=0;
for(i=1;i<=p;i++)
{
if(comp[i]==0)//if not completed
{
prc=i;
for(j=1;j<=r;j++)
{
if(avail[j])
{
prc=0;
break;
}
}
}
if(prc!=0)
break;
}
if(prc!=0)
{
printf("\nProcess ",prc,"runs to completion!");
count++;
for(j=1;j<=r;j++)
{
avail[j]+=alloc[prc][j];
alloc[prc][j]=0;
clm[prc][j]=0;
comp[prc]=1;
}
}
}
while(count!=p&&prc!=0);
if(count==p)
printf("\nThe system is in a safe state!!");
else
printf("\nThe system is in an unsafe state!!");
getchar();
//getch();
return 0;
}
