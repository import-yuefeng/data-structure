 # define TRUE 1
 # define FALSE 0
 # define MAX_VERTEX_NUM 50
 
typedef struct{
  NodeChar node[MAX_VERTEX_NUM];
 int vexnum;
 int content[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 
Graph CreateGraph(){
    Graph G;
    printf("Enter node number: ");
    scanf("%d", &G.vexnum);
    printf("依次输⼊入顶点: ");
    for(int i=0; i<G.vexnum; i++) scanf(" %c", &G.node[i]);
        printf("Enter vex info: \n");
    for(int i=0; i<G.vexnum; i++){ 
        for(int j=0; j<G.vexnum; j++){
            scanf("%d", &G.content[i][j]);
        }
    }
 }

    printf("Create Success!\n");
    return G;

int degree(Graph G){
    int z;
    int vIn = 0, vOut = 0;
    NodeChar i;
    getchar();
    printf("请输⼊入顶点如 a: ");
    scanf("%c", &i);
    for(z=0; z<G.vexnum; z++){
        if (G.node[z] == i){
            break;
        }
    }
    for(i=0; i<G.vexnum; i++){
        if(G.content[z][i] == 1)
            vOut++;
        }
        if(G.content[i][z] == 1)
            vIn++;
    printf("第%d个顶点即%c的出度为:%d,⼊入度为:%d\n", z+1, G.node[i], vOut, vIn);
    return TRUE; 
    }


void PrintGraph(Graph G){


    for(int i=0; i<G.vexnum; i++){
        printf("%c ", G.node[i]);
        for(int j=0; j<G.vexnum; j++){
            printf("%d ", G.content[i][j]);
        }
        printf("\n");
    }

int main(){
    Graph G;
    G = CreateGraph();
    PrintGraph(G);
    degree(G);
}
   
