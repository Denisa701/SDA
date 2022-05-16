#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void getGcost(int Graph[MAX][MAX])
{
  FILE *f;
  f = fopen("cost.txt", "rt");
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      fscanf(f, "%d", &Graph[i][j]);
  fclose(f);
}

void getGcost2(int Graph[MAX][MAX])
{
  FILE *f;
  f = fopen("cost2.txt", "rt");
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      fscanf(f, "%d", &Graph[i][j]);
  fclose(f);
}

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++)
  {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1)
  {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i])
      {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i])
        {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  for (i = 0; i < n; i++)
    if (i != start)
    {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}

void Bellman_Ford(int graph[10][10], int n, int beginning)
{
  int distance[10], pred[10], edge[100][2];
  int i, j, x, u, v, E;

  E = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      if (graph[i][j] != 0)
      {
        edge[E][0] = i;
        edge[E][1] = j;
        E++;
      }
    }

  for (i = 0; i < n; i++)
  {
    distance[i] = INFINITY;
    pred[i] = -1;
  }
  distance[beginning - 1] = 0;

  for (i = 0; i < n - 1; i++)
  {
    for (x = 0; x < E; x++)
    {
      u = edge[x][0];
      v = edge[x][1];
      if (distance[u] != INFINITY && distance[u] + graph[u][v] < distance[v])
      {
        distance[v] = distance[u] + graph[u][v];
        pred[v] = u;
      }
    }
  }

  for (x = 0; x < E; x++)
  {
    u = edge[x][0];
    v = edge[x][1];
    if (distance[u] != INFINITY && distance[u] + graph[u][v] < distance[v])
    {
      printf("Graph contains negative weight cycle\n");
      return;
    }
  }

  for (i = 0; i < n; i++)
    if (i != beginning - 1)
    {
      printf("Distance from source to %d : %d \n", i, distance[i]);
      
    }
}

int main()
{
  int Graph[MAX][MAX], Graph2[MAX][MAX], i, j, n, u;
  getGcost(Graph);
  getGcost2(Graph2);
  n = 10;

  // u = 0;
  // printf("\nDijkstra:\n\n");
  // Dijkstra(Graph, n, u);
  // u = 1;
  // printf("\n\nBellman-Ford:\n\n");
  // Bellman_Ford(Graph, n, u);

  u = 0;
  printf("\nDijkstra:\n\n");
  Dijkstra(Graph2, n, u);
  u = 1;
  printf("\n\nBellman-Ford:\n\n");
  Bellman_Ford(Graph2, n, u);
  return 0;
}
