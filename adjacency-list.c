
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
# define MAX_VERTEX_NUM 50

typedef struct node{
    char data;
    struct node *nextNode;
};

typedef struct {
    char topData;
    struct node* firstNode;
}nodeTop;

typedef struct {
    nodeTop* topList[MAX_VERTEX_NUM];
    int length, hight;
}lGraph;



lGraph CreateGraph(){
    lGraph G;
    int nodeNumber = 0;
    int value = 0;
    char nodeName;
    struct node* tmpLink;
    nodeTop* initTopNode;
    struct node* node;
    
    printf("Enter node number: ");
    scanf("%d", &nodeNumber);

    
    G.hight = nodeNumber;
    printf("请依次输入节点: ");
    
    for(int i=0; i<G.hight; i++){
        scanf(" %c", &nodeName);
        
        initTopNode = (nodeTop*)malloc(sizeof(nodeTop));
        initTopNode->topData = nodeName;
        initTopNode->firstNode = NULL;
        G.topList[i] = initTopNode;
        
    }
    
    printf("请输入相邻信息: ");
    
    for(int i=0; i<G.hight; i++){
        for (int q=0; q<G.hight; q++){
            scanf(" %d", &value);
            node = (struct node*)malloc(sizeof(node));
            node->data = value;
            node->nextNode = NULL;
            if (G.topList[i]->firstNode == NULL){
                G.topList[i]->firstNode = node;
            }
            else{
                tmpLink = G.topList[i]->firstNode;
                while (tmpLink->nextNode != NULL) tmpLink = tmpLink->nextNode;
                tmpLink->nextNode = node;
            }
        }
        
    }
    return G;
    
}


void degree(lGraph G){
    char nodeName, tmpChar;
    int i, count, q;
    int vOut = 0, vIn = 0;
    struct node* tmpLink;
    
    printf("Enter you want degree node: ");
    getchar();
    scanf("%c", &nodeName);
    tmpChar = G.topList[i]->topData;
    for(i=0; i<G.hight; i++) {
        if (G.topList[i]->topData == tolower(nodeName)){
            break;
        }
    }
    if (i == G.hight && tolower(nodeName) != G.topList[i-1])
        printf("没有这个节点");
    else{

        tmpLink = G.topList[i]->firstNode;
        
        while (tmpLink != NULL){
            if (tmpLink->data == 1)
                vOut++;
            tmpLink = tmpLink->nextNode;
        }
        
        printf("\n第%d个顶点即%c的出度为:%d\n",i+1, nodeName, vOut);
        count = i;
        for(int i=0; i<G.hight; i++){
            tmpLink = G.topList[i]->firstNode;
            q = 0;
            while(tmpLink != NULL){
                
                if(q == count && tmpLink->data == 1)
                    vIn++;
                q++;
                tmpLink = tmpLink->nextNode;

            }
        }
        
        printf("\n第%d个顶点即%c的入度为:%d\n",i+1, nodeName, vIn);
    }
    
}


void PrintGraph(lGraph G){
    printf("\n");
    struct node* tmpLink;
    for(int i=0; i<G.hight; i++){
        
        printf("%c ", G.topList[i]->topData);
        tmpLink = G.topList[i]->firstNode;
        do{
            
            printf("%d ", tmpLink->data);
            tmpLink = tmpLink->nextNode;
            
        }while(tmpLink != NULL);
        printf("\n");
    }
}


int isConnect(lGraph G, char fromNodeA, char toNodeB){
    int i, fromNodeIndex, toNodeIndex, count;
    struct node* tmpLink;
    
    for(i=0; i<G.hight; i++){
        if(G.topList[i]->topData == fromNodeA){
            fromNodeIndex = i;
        }
        if(G.topList[i]->topData == toNodeB){
            toNodeIndex = i;
        }
    }
    tmpLink = G.topList[fromNodeIndex]->firstNode;
    count = 0;
    while(tmpLink != NULL){
        if(count == toNodeIndex && tmpLink->data == 1){
            printf("%c -> %c 有边相连接\n", fromNodeA, toNodeB);
            return 1;
        }
        count++;
        tmpLink = tmpLink->nextNode;
    }
    printf("%c -> %c 没有边相连接\n", fromNodeA, toNodeB);
    return 0;
}



main(){
    lGraph G =  CreateGraph();
    PrintGraph(G);
//    degree(G);
    isConnect(G, 'a', 'b');
}


