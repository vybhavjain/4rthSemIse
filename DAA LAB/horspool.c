#include <stdio.h>
#include <string.h>

int table[128];

void shiftTable( char pattern [])
{
        int i,j,m;
        m=strlen(pattern);
        for(i=0; i<128; i++)
                table[i]=m;
        for(j=0; j<m-1; j++)
                table[pattern[j]]=m-1-j;
}

int horspool (char pattern[],char text[])
{
        int i,k,m,n;
        shiftTable(pattern);
        m=strlen(pattern);
        n=strlen(text);
        i=m-1;
        while(i<n)
        {
                k=0;
                while(k<m && text[i-k]==pattern[m-1-k])
                        k++;
                if(k==m)
                        return(i-m+1);
                else
                        i=i+table[text[i]];
        }
        return -1;
}

void main()
{
        char pattern[50],text[50];
        printf("enter text : \n");
        scanf("%s",text);
        printf("enter pattern : \n");
        scanf("%s",pattern);
        int flag=horspool(pattern,text);
        if(flag==-1)
                printf("not found ");
        else
                printf("found at position %d",flag);
}
