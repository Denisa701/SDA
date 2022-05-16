#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

 
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < 10; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
int print(int parent[], int graph[10][10])
{
    int cost = 0;
    for (int i = 1; i < 10; i++){
        printf("%d - %d:\t%d \n", parent[i], i, graph[i][parent[i]]);
        cost = cost + graph[i][parent[i]] ;
    }
    printf("\nSpanning tree cost: %d", cost);
}
 

void prim(int graph[10][10])
{
    
    int parent[10];
    int key[10];
    bool mstSet[10];
 
    
    for (int i = 0; i < 10; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    
    key[0] = 0;
    parent[0] = -1; 
 
   
    for (int count = 0; count < 9; count++) {
        
        int u = minKey(key, mstSet);
 
        mstSet[u] = true;
 
        for (int v = 0; v < 10; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){

                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
 
    print(parent, graph);
}

 void getGcost(int Graph[10][10])
{
  FILE *f;
  f = fopen("cost.txt", "rt");
  for(int i =0; i<10; i++)
    for(int j = 0; j<10; j++)
      fscanf(f,"%d", &Graph[i][j]);
  fclose(f);
}

int main()
{
    int graph[10][10];
    getGcost(graph);

    prim(graph);
 
    return 0;
}