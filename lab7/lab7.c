// Kruskal's algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int N = 10;

// struct Graph
// {
//   struct Node *head[N];
// };

// struct Node
// {
//   int dest;
//   struct Node *next;
// };

// struct Edge //  struct edge {
// {
//   int src, dest; //   int u, v, w;
// };               // } edge;

// typedef struct edge_list {
//   edge data[MAX];
//   int n;
// } edge_list;
// edge_list elist;

// edge_list spanlist;

struct path
{
  int y, x, cost;
}v[MAX];

int Gcost[MAX][MAX];

void getGcost(int Gcost[MAX][MAX])
{
  FILE *f;
  f = fopen("cost.txt", "rt");
  for(int i =0; i<10; i++)
    for(int j = 0; j<10; j++)
      fscanf(f,"%d", &Gcost[i][j]);
  fclose(f);
}

void kruskalAlgo() {
  int *n = 0;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < i; j++) {
      if (Gcost[i][j] != 0) {
        v[*n].x= i;
        v[*n].y = j;
        v[*n].cost = Gcost[i][j];
        *n++;
      }
    }
  sort();
}

int main(){
  getGcost(Gcost);
  // for(int i =0; i<9; i++)
  // {
  //   for(int j = 0; j<10; j++)
  //     printf("%d ", Gcost[i][j]);
  //   printf("\n");
  // }

}