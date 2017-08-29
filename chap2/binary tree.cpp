#include <stdio.h>
#include <malloc.h> 
#define MAX 100 

typedef struct node
{ 
    int date; 
    struct node *lchild,*rchild; 
}bitnode,*bitree; 

bitree createbitree(bitree bt)
{ 
    int m; 
    printf("m="); 
    scanf("%d",&m); 
    if(m==-1) 
    bt=NULL; 
    else
    { 
        bt=(bitnode *)malloc(sizeof(bitnode)); 
        bt->date=m; 
        createbitree(bt->lchild); 
        createbitree(bt->rchild); 
    } 
    return bt; 
}
//set up tree
void leveltraverse(bitree bt)
{ 
    bitree queue[MAX],p=bt; 
    int rear=0,front=0; 
    if(p!=NULL)
    { 
        queue[++rear]=p; 
        while(front<rear)
        { 
            p=queue[++front]; 
            printf("%d\t",p->date); 
            if(p->lchild!=NULL) 
            queue[++rear]=p->lchild; 
            if(p->rchild!=NULL) 
            queue[++rear]=p->rchild; 
        } 
    } 
}
//preordertraverse
void preordertraverse(bitree bt)
{ 
    if(bt!=NULL)
    { 
        printf("%d\t",bt->date); 
        preordertraverse(bt->lchild); 
        preordertraverse(bt->rchild); 
    } 
}
//inordertraverse
void inordertraverse(bitree bt)
{ 
    if(bt!=NULL)
    { 
        inordertraverse(bt->lchild); 
        printf("%d\t",bt->date); 
        inordertraverse(bt->rchild); 
    } 
}
//postordertraverse
void postordertraverse(bitree bt)
{ 
    if(bt!=NULL)
    {
        postordertraverse(bt->lchild); 
        postordertraverse(bt->rchild); 
        printf("%d\t",bt->date); 
    } 
}
//depth
int bitreedepth(bitree bt)
{ 
    int h,lh,rh; 
    if(bt==NULL) 
        h=0; 
    else
    { 
        lh=bitreedepth(bt->lchild); 
        rh=bitreedepth(bt->rchild); 
        if(lh>=rh) 
            h=lh+1; 
        else 
            h=rh+1; 
     
    } 
    return h; 
}
//leaf of tree
int bitreeleaf(bitree bt)
{ 
    int m=0; 
    if(!bt) 
        return 0; 
    else if(bt->lchild==NULL&&bt->rchild==NULL) 
        return 1; 
    m+=bitreeleaf(bt->lchild)+bitreeleaf(bt->rchild); 
    return m; 
}

int countbitreenode(bitree bt)
{ 
    if(!bt) 
        return 0; 
    else 
        return countbitreenode(bt->lchild)+countbitreenode(bt->rchild)+1; 
    printf("The postorder traversal of the bitree is:\n\t"); 
    postordertraverse(bt); 
    printf("\n\n"); 
    printf("The number of the bitreenode is %d.\n",countbitreenode(bt)); 
    printf("The depth of the bitree is %d.\n",bitreedepth(bt)); 
    printf("The number of the leaves of the bitree is %d.\n\n",bitreeleaf(bt)); 
}

void OperateBitree(bitree bt)
{
    printf("\n"); 
    printf("The level traversal of the bitree is:\n\t"); 
    leveltraverse(bt); 
    printf("\n\n"); 
    printf("The preorder traversal of the bitree is:\n\t"); 
    preordertraverse(bt); 
    printf("\n\n"); 
    printf("The inorder traversal of the bitree is:\n\t"); 
    inordertraverse(bt); 
    printf("\n\n"); 
    printf("The postorder traversal of the bitree is:\n\t"); 
    postordertraverse(bt); 
    printf("\n\n"); 
    printf("The number of the bitreenode is %d.\n",countbitreenode(bt)); 
    printf("The depth of the bitree is %d.\n",bitreedepth(bt)); 
    printf("The number of the leaves of the bitree is %d.\n\n",bitreeleaf(bt)); 
}


int main()
{ 
    bitree bt;
    bt=createbitree(bt);
    OperateBitree(bt); 
}

