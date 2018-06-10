#include<stdio.h>
#include<time.h>
#include<math.h>
int h[50];
void heapify(int h[],int n)
{
 int i,j,n1,k,heap,v;
 n1=n;
 for(i=n/2;i>=1;i--)
 {
  k=i;
  v=h[k];
  heap=0;
  while(!(heap)&&(2*k)<=n1)
  {
   j=2*k;
   if(j<n1)
    if(h[j]<h[j+1])
      j=j+1;
   if(v>=h[j])
       heap=1;
   else 
   {
    h[k]=h[j];
    k=j;
   }
  }
h[k]=v;
 }
}


void main()
{
 int i,n,size,t;
 printf("Enter the value of n \n");
 scanf("%d",&n);
 printf("Enter the array elements \n");
 for(i=1;i<=n;i++)
  scanf("%d",&h[i]);
  heapify(h,n);
  printf("Elements heapified \n");
  for(i=1;i<=n;i++)
   printf("%d \t",h[i]);
  for(i=n;i>=1;i--)
  {
   t=h[1];
   h[1]=h[i];
   h[i]=t;
   size=i-1;
    heapify(h,size);
  }
 printf("ROtated elements are: \n");
 for(i=1;i<=n;i++)
  printf("%d \t",h[i]);
}
