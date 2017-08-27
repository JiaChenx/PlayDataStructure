#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct QueueRec
{  
    int front;  
    int rear;  
    int size;  
    int capacity;      
    int *Array;  
} lqueue,*Queue;  
  
int IsEmpty(Queue q)
{  
    return q->size==0;  
}  
  
int IsFull(Queue q)
{  
    return q->size==q->capacity;
}  
  
Queue CreateQueue(int capacity)
{  
    Queue queue;  
    queue = (Queue)malloc(sizeof(lqueue));  
    if(queue==NULL){  
        return NULL;  
    }  
    queue->Array = malloc(sizeof(int)*capacity);
    if(queue->Array == NULL )
    {  
        return NULL;  
    }  
    queue->capacity = capacity;
    queue->size = 0;  
    queue->front = 0;  
    queue->rear = -1;  
    return queue;  
}  
  
void MakEmpty(Queue q)
{  
    q->size = 0;  
    q->rear = -1;  
    q->front = 0;  
}  
  
void DisPoseQueue(Queue q)
{  
    if(q!=NULL)
    {  
        free(q);      
    }  
}  
  
//circulate queue
int circularQ(int index,Queue q)
{  
    if(++index > q->capacity)
    {  
        return 0;  
    }  
    return index;  
}  
  
//in queue
void EnQueue(Queue q,int item)
{  
    if(IsFull(q))
    {  
        printf("Queue is Full\n");  
    } 
    else 
    {  
        q->size ++;  
        q->rear = circularQ(q->rear,q);  
        q->Array[q->rear] = item;  
    }  
}  
  
//out queue
int DeQueue(Queue q)
{  
    int temp;  
    if(IsEmpty(q))
    {  
        printf("queue is Empty\n");  
    } 
    else 
    {  
        q->size --;  
        temp = q->Array[q->front];  
        q->front = circularQ(q->front,q);  
    }  
    return temp;  
}  
  
// find head data of queue
int front(Queue q){  
    return q->Array[q->front];  
}  
  
int main(void)
{  
    Queue q = CreateQueue(5);  
    EnQueue(q,1);  
    EnQueue(q,2);  
    EnQueue(q,3);  
    EnQueue(q,4);  
    EnQueue(q,5);  
    EnQueue(q,6);  
    printf("%d\n",front(q));  
    printf("%d\n",DeQueue(q));  
    printf("%d\n",DeQueue(q));  
    EnQueue(q,7);  
    printf("%d\n",front(q));  
    DisPoseQueue(q);  
    return -1;  
}
