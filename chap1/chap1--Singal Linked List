#include <stdio.h>  
#include <stdlib.h>  
typedef int ElemType;  
 

typedef struct Node  
{  
    ElemType data;             
    struct Node *next;          
}Node,*LinkedList;  


LinkedList LinkedListInit()  
{  
    Node *L;  
    L = (Node *)malloc(sizeof(Node));     
    if(L == NULL)                         
        printf("place apply failed/n");  
    L->next = NULL;                   
}  
 
//list setup, header insert
LinkedList LinkedListCreatH()  
{  
    Node *L;  
    L = (Node *)malloc(sizeof(Node));    
    L->next = NULL;                      
      
    ElemType x;                         
    while(scanf("%d",&x) != EOF)  
    {  
        Node *p;  
        p = (Node *)malloc(sizeof(Node));     
        p->data = x;                       
        p->next = L->next;                    
        L->next = p;   
    }  
    return L;   
}   

//end insert 
LinkedList LinkedListCreatT()  
{  
    Node *L;  
    L = (Node *)malloc(sizeof(Node));   
    L->next = NULL;                  
    Node *r;  
    r = L;                           
    ElemType x;                         
    while(scanf("%d",&x) != EOF)  
    {  
        Node *p;  
        p = (Node *)malloc(sizeof(Node));   
        p->data = x;                     
        r->next = p;                 
        r = p;   
    }  
    r->next = NULL;   
      
    return L;     
}  
  
//insert
LinkedList LinkedListInsert(LinkedList L,int i,ElemType x)  
{  
    Node *pre;                       
    pre = L;  
    int tempi = 0;  
    for (tempi = 1; tempi < i; tempi++)  
        pre = pre->next;                
    Node *p;                                
    p = (Node *)malloc(sizeof(Node));  
    p->data = x;   
    p->next = pre->next;  
    pre->next = p;  
      
    return L;                             
}   

//delete
LinkedList LinkedListDelete(LinkedList L,ElemType x)  
{  
    Node *p,*pre;                      
    p = L->next;  
    while(p->data != x)              
    {     
        pre = p;   
        p = p->next;  
    }  
    pre->next = p->next;             
    free(p);  
    return L;  
}   

int main()  
{  
    LinkedList list,start;  
/*  printf("please insert data of list:");  
    list = LinkedListCreatH(); 
    for(start = list->next; start != NULL; start = start->next) 
        printf("%d ",start->data); 
    printf("/n"); */
    printf("data: ");   
    list = LinkedListCreatT();  
    for(start = list->next; start != NULL; start = start->next)  
        printf("%d ",start->data);  
    printf("/n");  
    int i;  
    ElemType x;  
    printf("position: ");  
    scanf("%d",&i);  
    printf("dat: ");  
    scanf("%d",&x);  
    LinkedListInsert(list,i,x);  
    for(start = list->next; start != NULL; start = start->next)  
        printf("%d ",start->data);  
    printf("/n");  
    printf("deletion dat: ");  
    scanf("%d",&x);  
    LinkedListDelete(list,x);   
    for(start = list->next; start != NULL; start = start->next)  
        printf("%d ",start->data);  
    printf("/n");  
      
    return 0;  
}
