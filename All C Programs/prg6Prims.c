#include <stdio.h>

void main(){
    int graph[10][10];
    int visited[10]={0};
    int n,cost=0,k=1,a,b,u,v,min,i,j;
    printf("enter node \n");
    scanf("%d",&n);
    printf("Enter adjacency matrix : \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %d",&graph[i][j]);
            if(graph[i][j]==0){
                graph[i][j]=999;
            }
        }
    }
 
    visited[1]=1;
    printf("\n");

    while(k<n){
        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(graph[i][j]<min){
                    if(visited[i]!=0){
                        min=graph[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }

        if(visited[u]==0 || visited[v]==0){
            printf("\nEdge %d:(%d %d) cost : %d",k++,a,b,min);
            cost+=min;
            visited[b]=1;
        }
        graph[a][b]=graph[b][a]=999;
    }

    printf("\nminimum cost : %d",cost);

}
