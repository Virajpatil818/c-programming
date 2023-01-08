#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int minkey(int key[],bool mstset[]){
    int min = INT_MAX,min_index;

    for(int v=0;v<V;v++){
        if(mstset[v]==false && key[v]<min){
            min=key[v],min_index=v;
        }
    }
    return min_index;
}

int printMST(int parent[],int graph[V][V]){
    int min_cost=0;
    printf("Edge \tWeight\n");
    for(int i=1;i<V;i++){
        printf("%d- %d \t%d \n",parent[i],i,graph[i][parent[i]]);
        min_cost+=graph[i][parent[i]];
    }
    printf("Minimum cost : %d\n",min_cost);
}

void primMST(int graph[V][V]){
      // Array to store constructed MST
    int parent[V];
    // Key values used to pick minimum weight edge in cut
    int key[V];
    // To represent set of vertices included in MST
    bool mstset[V];

    for(int i=0;i<V;i++){
        key[i]=INT_MAX , mstset[i]=false;
    } 
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.  
    key[0]=0;
    parent[0]=-1;// First node is always root of MST
    
    for(int count=0;count<V-1;count++){
        int u=minkey(key,mstset);
        mstset[u]=true;

        for(int v=0;v<V;v++){
            if(graph[u][v] && mstset[v]==false && graph[u][v] <key[v]){
                parent[v]=u,key[v]=graph[u][v];
            }
        }
    }
    printMST(parent,graph);
}

void main(){
    int graph[V][V];
    printf("Enter Adjecency Matrix\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf(" %d",&graph[i][j]);
        }
    }
    primMST(graph);
}