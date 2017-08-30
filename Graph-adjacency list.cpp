#include <stdio.h>
#include <string.h>

#define MAX_VERTEX_NUM 100
#define MAX_VERTEX_NAMELEN 100

typedef struct{
    char name[MAX_VERTEX_NAMELEN];
}VerType;

typedef struct{
    int VertexNum,EdgeNum;                        
    VerType Vertex[MAX_VERTEX_NUM];               
    int Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     
}MGragh;

// visit information
int visit[MAX_VERTEX_NUM];

//********************************************************//
//                    adjacent matrix                          //
//********************************************************//

void CreateMGragh(MGragh *Gra)
{
    int i,j,k;
    char v1[MAX_VERTEX_NAMELEN],v2[MAX_VERTEX_NAMELEN];

    printf("amounts of top and side(top side)\n");
    scanf("%d %d%*c",&(Gra->VertexNum),&(Gra->EdgeNum));

    printf("input top\n");
    for (i=0; i<Gra->VertexNum; i++){
        printf("%d.",i+1);
        gets(Gra->Vertex[i].name);
    }

    for (i=0; i<Gra->VertexNum; i++){
        for (j=0; j<Gra->VertexNum; j++){
            Gra->Edge[i][j] = 0;
        }
    }
    printf("please input side(top,top)\n");
    for (i=0; i<Gra->EdgeNum; i++){
        printf("%d.",i+1);
        scanf("%[^,]%*c%[^\n]%*c",v1,v2);
        for (j=0; j<Gra->VertexNum; j++){
            for (k=0; k<Gra->VertexNum; k++){
                if (strcmp(Gra->Vertex[j].name,v1) == 0 && strcmp(Gra->Vertex[k].name,v2) == 0){
                    Gra->Edge[j][k] = Gra->Edge[k][j] = 1;
                }
            }
        }
    }
}

//********************************************************//
//                          DFS                           //
//********************************************************//

void DFS(MGragh *Gra,int sub)
{
    printf("%s",Gra->Vertex[sub].name);
    visit[sub] = 1;
    for (int i=0; i<Gra->VertexNum; i++){
        if (Gra->Edge[sub][i] == 1 && visit[i] == 0){
            DFS(Gra,i);
        }
    }
}

void DFSTraverse(MGragh *Gra)
{
    int i;

    for (i=0; i<Gra->VertexNum; i++){
        visit[i] = 0;
    }

    for (i=0; i<Gra->VertexNum; i++){
        if (visit[i] == 0){
            DFS(Gra,i);
            printf("\n");
        }
    }
}

//********************************************************//
//                           BFS                          //
//********************************************************//

typedef struct{
    int first;
    int last;
    int que[MAX_VERTEX_NUM];                
}Queue;

void initQueue(Queue *q)                            // initialize
{
    q->first = q->last = 0;
}
int QueueEmpty(Queue *q)                            // if empty
{
    return q->last==q->first;
}
int QueueFull(Queue *q)                             // if full
{
    return (q->last-q->first) == MAX_VERTEX_NUM;
}
void DeQueue(Queue *q,int *i)                       // out
{
    *i = q->que[q->first];
    q->first = (q->first+1)%MAX_VERTEX_NUM;
}
void EnQueue(Queue *q,int i)                        // int
{
    q->que[q->last] = i;
    q->last = (q->last+1)%MAX_VERTEX_NUM;
}

void BFSTraverse(MGragh *Gra)
{
    int i,j,k;
    Queue q;
    
    //initialize
    for (i=0; i<Gra->VertexNum; i++){
        visit[i] = 0;
    }

    initQueue(&q);
    for (i=0; i<Gra->VertexNum; i++){
        if (visit[i] == 0){
            visit[i] = 1;
            EnQueue(&q,i);

            while(!QueueEmpty(&q)){
                DeQueue(&q,&k);
                printf("%s",Gra->Vertex[k].name);
                for (j=0; j<Gra->VertexNum; j++){
                    if (Gra->Edge[k][j] == 1 && visit[j] == 0){
                        visit[j] = 1;
                        EnQueue(&q,j);
                    }
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    MGragh g;
    CreateMGragh(&g);
    
    printf("DFS:");
    DFSTraverse(&g);
    printf("BFS:");
    BFSTraverse(&g);
    
    return 0;
}
