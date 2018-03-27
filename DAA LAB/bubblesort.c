#include<stdio.h>
#include<time.h>

void main()
{
int i,n,j,temp;
int a[100000];
printf("enter the size of the array \n");
scanf("%d",&n);
for(i=n;i>=1;i--)
a[n-i]=i;
clock_t start,end;
double cpu_time;
start=clock();
for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
end=clock();
cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("time is %f",cpu_time);
for(i=0;i<n;i++)
printf(" %d",a[i]);
}


