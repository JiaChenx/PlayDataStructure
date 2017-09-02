#include<stdio.h>
#include<stdlib.h>
#define MAXE 20
typedef char KeyType;
typedef char InfoType[10];
typedef struct
{
    KeyType key;
    InfoType data;
}RecType;
 
//shell
void shellsort(RecType R[],int n)
{
     
    int d,i,j,k;
    RecType temp;
    d=n/2;
    while(d>0)
    {
        for(i=d;i<n;i++)
        {
            j=i-d;
            while(j>=0&&R[j].key>R[j+d].key)
            {
                temp=R[j];
                R[j]=R[j+d];
                R[j+d]=temp;
                j=j-d;
            }
        }
        printf("     d=%d:",d);
        for(k=0;k<n;k++)
            printf("%3d",R[k].key);
        printf("\n");
        d=d/2;
    }
}
 
//bubble
void bubblesort(RecType R[],int n)
{
    int i,j,k;
    RecType temp;
    for(i = 0; i <n-1; i++)
    {
        for(j=n-1;j>i;i--)         
            if(R[j].key<R[i-1].key)        
            {
                temp= R[j];
                R[j] = R[j-1];
                R[j-1] =temp;
            }
            printf("    i=%d ",i);
            for(k = 0; k <n; k++)
                printf("%2d",R[k].key);
            printf("\n");
    }
}
 
//quick
void quicksort(RecType R[],int s,int t)
{
    int i=s,j=t,k;
    RecType temp;
    if(s<t)
    {
        temp=R[s];
        while(i!=j)
        {
            while(j>i&&R[j].key>temp.key)
                j--;
            if(i<j)
            {
                R[i]=R[j];
                i++;
            }
            while(i<j&&R[i].key<temp.key)
                i++;
            if(i<j)
            {
                R[j]=R[i];
                j--;
            }
        }
        R[i]=temp;
        printf("      ");
        for(k=0;k<10;k++)
            if(k==i)
                printf("[%d]",R[k].key);
            else
                printf("%4d",R[k].key);
            printf("\n");
            quicksort(R,s,i-1);
            quicksort(R,i+1,t);
    }
}
 
//select
void selectsort(RecType R[],int n)
{
    int i,j,k,l;
    RecType temp;
    for(i = 0; i <n-1; i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(R[j].key<R[k].key)
                k=j;
            if(k!=i)
            {
                temp= R[i];
                R[i] = R[k];
                R[k] =temp;
            }
            printf("    i=%d ",i);
            for(l = 0; l<n; l++)
                printf("%2d ", R[l].key);
            printf("\n");
    }
}
 
//insert
void insertsort(RecType R[],int n)
{  //sort by insert
    int i,j,k;
    RecType temp;
    for(i=1;i<n;i++)
    {
        temp=R[i];
        j=i-1;
        while(j>=0&&temp.key<R[j].key)
        {
            R[j+1]=R[j];
            j--;
        }
        R[j+1]=temp;
        printf("  i=%d ",i);
        for(k=0;k<n;k++)
            printf("%3d",R[k].key);
        printf("\n");
    }
}
 
 
//sift
void sift(RecType R[], int low, int high)
{
    int i=low,j=2*i;
    RecType temp=R[i];
    while(j<=high)
    {
        if (j<high && R[j].key<R[j+1].key)
            j++;
        if (temp.key < R[j].key)
        {
            R[i]=R[j];
            i=j;
            j=2*i;
        }
        else 
            break;
    }
    R[i]=temp; 
}
 
void dispheap(RecType R[],int i,int n)
{
    if(i<=n)
        printf("%d",R[i].key);
    if(2*i<=n||2*i+1<n)
    {
        printf("(");
        if(2*i<=n)
            dispheap(R,2*i,n);
        printf(",");
        if(2*i+1<=n)
            dispheap(R,2*i+1,n);
        printf(")");
         
    }
}
 
void heapsort(RecType R[],int n)
{
    int i;
    RecType temp;
    for(i=n/2;i>=1;i--)
        sift(R,i,n);
    printf("initialize:");
    dispheap(R,1,n);
    printf("\n");
    for(i=n;i>=2;i--)
    {
        printf("exchange %d and %d,out put %d\n",R[i].key,R[1].key,R[1].key);
        temp=R[1];
        R[1]=R[i];
        R[i]=temp;
        sift(R,1,i-1);
        printf("answer:");
        dispheap(R,1,i-1);
        printf("\n");
    }
}
int main()
{
    int i,k,n=10,m=5;
    KeyType a[]={9,8,7,6,5,4,3,2,1,0};
    RecType R[MAXE];
    for(i=0;i<n;i++)
        R[i].key=a[i];
    printf("\n");
    printf("inital key:");
    for(k=0;k<n;k++)
        printf("%2d",R[k].key);
     
    printf("\n");
    selectsort(R,n);
    printf("answer:");
    for(k=0;k<n;k++)
        printf("%2d",R[k].key);
     
    printf("\n");
    shellsort(R,n);
    printf("answer:");
    for(k=0;k<n;k++)
        printf("%2d",R[k].key);
     
    printf("\n");
    insertsort(R,n);
    printf("answer:");
    for(k=0;k<n;k++)
        printf("%2d",R[k].key);
     
    printf("\n");
    for(i=n/2;i>=1;i--)
        sift(R,i,n);
    heapsort(R,n);
    printf("answer:");
    for(k=0;k<n;k++)
        printf("%2d",R[k].key);
    system("pause"); 
     
}
