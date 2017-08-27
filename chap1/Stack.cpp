#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define true 1
#define false 0


typedef struct Node
{
    int data;
    struct Node *pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
int pop(PSTACK pS , int *val);
void clear(PSTACK pS);
int empty(PSTACK pS);

int main(void)
{
    STACK S ;
    int val;
    int i;
    
    init(&S);
    
    push(&S,1);
    push(&S,2);
    push(&S,3);
    push(&S,4);
    push(&S,5);
    push(&S,6);

    traverse(&S);
    
    if(pop(&S ,&val))
    {
       printf("traverse succse,the data out of satck is%d\n",val);
    }
    else
    {
            printf("fail!\n");
    }
    traverse(&S);

    clear(&S);
    
    traverse(&S);
    
    return 0 ;
}

//initialization
void init(PSTACK pS)
{
    pS -> pTop = (PNODE)malloc(sizeof(NODE));
    
    if(NULL == pS -> pTop)
    {
        printf("space apply fail!");
        exit(-1);
    }
    else
    {
        pS -> pBottom = pS -> pTop;
        pS -> pTop -> pNext = NULL;
    }
    
    return ;
}

//push data to top
void push(PSTACK pS , int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    
    pNew -> data = val;
    pNew -> pNext = pS -> pTop;
    pS -> pTop = pNew;
    
    return ;
}

//traverse
void traverse(PSTACK pS)
{
    PNODE p = pS -> pTop;
    
    printf("stack data:");
    while(p != pS -> pBottom)
    {
        printf("%d\t", p -> data);
        p = p -> pNext;
    }
    
    printf("\n");
    return ;
}

//if stack is empty
int empty(PSTACK pS)
{
    if(pS -> pTop == pS -> pBottom)
    {
        return true;
    }
    else
        return false;
}

//delete and assign *val
int pop(PSTACK pS , int *val)
{
    if(empty(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS -> pTop;
        *val = r -> data;
        pS -> pTop = r -> pNext;
        free(r);
        r = NULL;
    }
}

//clear
void clear(PSTACK pS)
{
    if(empty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS -> pTop;
        PNODE q = NULL;
        
        while(p != pS -> pBottom)
        {
            q = p -> pNext;
            free(p);
            p = q ;
        }
        
        pS -> pTop = pS -> pBottom;
        
        return;
    }
}
