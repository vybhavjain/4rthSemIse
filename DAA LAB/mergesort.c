#include<stdio.h>
#include<time.h>
//char a[100];
int a[10000];
int i,j,l,h;

void merge( int l,int mid,int h)
{
//char B[100];
int B[10000];
for(i=l;i<=h;i++)
B[i]=a[i];
i=l;
j=mid+1;
int k=l;
while(i<=mid&&j<=h)
{
if(B[i]<=B[j])
a[k++]=B[i++];
else
a[k++]=B[j++];
}
while(i<=mid)
a[k++]=B[i++];
}

void mergesort(int l,int h)
{
int mid;
if(l<h)
{
mid=(l+h)/2;
mergesort(l,mid);
mergesort(mid+1,h);
merge(l,mid,h);
}
}

void main()
{
int n;
printf("enter the size of the array \n");
scanf("%d",&n);
printf("enter the elements to be sorted \n");
for(i=n;i>=1;i--)
a[n-i]=i;
//for(i=0;i<n;i++)
//scanf("%s",&a[i]);
clock_t start,end;
double cpu_time;
start=clock();
l=0;
h=n-1;
mergesort(l,h);
//printf("elements are : \n ");
//for(i=0;i<n;i++)
//printf(" %c \n ",a[i]);
end=clock();
cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("time is %f",cpu_time);
}

