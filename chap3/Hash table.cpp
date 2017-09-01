//Hash 
#include <stdio.h>   
#include <stdlib.h>   
#define OK 1 
#define ERROR 0 
#define TRUE 1 
#define FALSE 0 
#define SUCCESS 1 
#define UNSUCCESS 0 
#define HASHSIZE 7          
#define NULLKEY -32768  
typedef int Status;   
typedef struct
{ 
  int *elem;           
  int count;             
}HashTable; 
  
int m = 0;

Status Init(HashTable *hashTable) 
{ 
  int i; 
  m = HASHSIZE; 
  hashTable->elem = (int *)malloc(sizeof(int) *m);
  hashTable->count = m; 
  for (i = 0; i < m;i++) 
  { 
    hashTable->elem[i] = NULLKEY; 
  } 
  return OK; 
} 
  
int Hash(int data) 
{ 
  return data % m; 
} 
  
void Insert(HashTable *hashTable,int data) 
{ 
  int hashAddress=Hash(data);
  
  while(hashTable->elem[hashAddress]!=NULLKEY) 
  { 
    hashAddress=(++hashAddress)%m; 
  } 
  hashTable->elem[hashAddress]=data; 
} 

int Search(HashTable *hashTable,int data) 
{ 
  int hashAddress=Hash(data);

  while(hashTable->elem[hashAddress]!=data) 
  { 
    hashAddress=(++hashAddress)%m; 
  
    if (hashTable->elem[hashAddress]==NULLKEY||hashAddress==Hash(data)) return -1; 
  } 
  
  return hashAddress; 
} 
  
void Display(HashTable *hashTable) 
{ 
  int i; 
  printf("\n//==============================//\n"); 
  
  for (i=0;i<hashTable->count;i++) 
  { 
    printf("%d ",hashTable->elem[i]); 
  } 
  
  printf("\n//==============================//\n"); 
} 
  
int main() 
{ 
  int i,j,result; 
  HashTable hashTable; 
  int arr[HASHSIZE]={13,29,27,28,26,30,38}; 
  
  printf("***************Hash***************\n"); 
  
  Init(&hashTable); 
  
  for (i=0;i<HASHSIZE;i++) 
  { 
    Insert(&hashTable,arr[i]); 
  } 
  Display(&hashTable);  
  result= Search(&hashTable,29); 
  if (result==-1)  
      printf("not found!\n"); 
  else 
      printf("the address of 29 in Hash table is:%d\n",result); 
  return 0; 
}
