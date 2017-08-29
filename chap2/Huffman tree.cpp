#include<stdio.h>
#include<stdlib.h> 
#define LENGTH 6

typedef int ElemType;  

typedef struct HuffmanTreeNode{  
    ElemType data;  //data of tree point
    struct HuffmanTreeNode* left;  
    struct HuffmanTreeNode* right;  
}HuffmanTreeNode,*PtrHuffman;  


/**
 * create
 */
PtrHuffman createHuffmanTree(ElemType arr[]){
    PtrHuffman ptrArr[LENGTH];
    PtrHuffman ptr,pRoot=NULL;  

    for (int i = 0; i < LENGTH; i++){  
        ptr = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));  
        ptr->data = arr[i];  
        ptr->left = ptr->right = NULL; 
        ptrArr[i] = ptr;
    }
    
    for(int i = 1; i < LENGTH; i++){   
     
        int k1 = -1, k2;
        for(int j = 0; j < LENGTH; j++){  
            if (ptrArr[j] != NULL && k1 == -1){  
                k1 = j;  
                continue;  
            }  
            if (ptrArr[j] != NULL){  
                k2 = j;  
                break;  
            }  
        }  
       
        for (int j = k2; j < LENGTH; j++){
            if(ptrArr[j] != NULL){
                if(ptrArr[j]->data < ptrArr[k1]->data){
                    k2 = k1;
                    k1 = j;
                }else if(ptrArr[j]->data < ptrArr[k2]->data){
                    k2 = j;
                }
            }
        }
        
        pRoot = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));
        pRoot->data = ptrArr[k1]->data + ptrArr[k2]->data;
        pRoot->left = ptrArr[k1];
        pRoot->right = ptrArr[k2];

        ptrArr[k1] = pRoot;
        ptrArr[k2] = NULL; 
    }

    return pRoot;
}

ElemType calculateWeightLength(PtrHuffman &ptrTree,int len){
    if(ptrTree==NULL){ 
        return 0;
    }else{
        if(ptrTree->left==NULL && ptrTree->right==NULL){ 
            return ptrTree->data * len;
        }else{
            return calculateWeightLength(ptrTree->left,len+1) + calculateWeightLength(ptrTree->right,len+1); 
        }
    }
}

void HuffmanCoding(PtrHuffman &ptrTree,int len){
    static int arr[20];  
    if(ptrTree != NULL){
        if(ptrTree->left==NULL && ptrTree->right==NULL){
           printf("note data is %d: ", ptrTree->data); 
           for(int i = 0; i < len; i++){
               printf("%d", arr[i]);      
           }   
           printf("\n"); 
        }else{
            arr[len] = 0;
            HuffmanCoding(ptrTree->left,len+1);
            arr[len] = 1;
            HuffmanCoding(ptrTree->right,len+1);
        }
    }
}

void printHuffmanTreeChildNode(PtrHuffman node){
    if(node->left == NULL && node->right == NULL){
        printf("x=%d is leafnode of tree",node->data);
        printf("\n\n");
        return;
    }
    if(node->left != NULL){
        printf("x=%d lchild=%d",node->data,node->left->data);
        printf("\n");
    }
    if(node->right != NULL){
        printf("x=%d rchild=%d",node->data,node->right->data);
        printf("\n");
    }
    printf("\n");
}

void midOrderprintHuffmanTreeNode(PtrHuffman &pRoot){
    if(pRoot==NULL){
        return;
    }else{
        midOrderprintHuffmanTreeNode(pRoot->left);
        printf("%d ",pRoot->data);
        midOrderprintHuffmanTreeNode(pRoot->right);
    }
}

void PreOrderprintHuffmanTreeNode(PtrHuffman &pRoot){
    if(pRoot==NULL){
        return;
    }else{
        printHuffmanTreeChildNode(pRoot); 
        PreOrderprintHuffmanTreeNode(pRoot->left);
        PreOrderprintHuffmanTreeNode(pRoot->right);
    }
}

int main(){
    ElemType arr[] = {3,9,5,12,6,15};
    PtrHuffman pRoot = createHuffmanTree(arr);

    printf("==========midOrder print ==========\n");
    midOrderprintHuffmanTreeNode(pRoot);
    printf("\n\n");

    printf("==========PreOrder print ==========\n");
    PreOrderprintHuffmanTreeNode(pRoot);

    printf("==========calculate path length==========\n");
    printf("WeightLength=%d\n",calculateWeightLength(pRoot,0));
    printf("\n");

    printf("===========Huffman code =========\n");
    HuffmanCoding(pRoot,0);

    fprintf(stdout,"\n");
    
    return 0;
}

