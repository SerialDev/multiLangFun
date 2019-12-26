
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to represent a weighted edge
struct
Edge
{
  int src, dest, weight;
};

// struct to represent connected, undirected and weighted graphs
struct Graph
{
  // V->n of vertices ; E->n of edges;
  int V, E;

  // Represent a graph as an array of Edges.
  struct Edge* edge;
};


struct Edge* createEdge(int E)
{
  struct Edge* edge = malloc(E * sizeof(struct Edge));
  /* edge->src = E; */
  return edge;
}

struct Graph*
createGraph(int V, int E)
{

  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;

  graph->edge = createEdge(E);

  return graph;
}



int main() {

  int V = 4; // Number of vertices in a graph
  int E = 5; // Number of edges in a graph

  struct Graph* graph = createGraph(V, E);
  printf("\ngraph %i",graph->E);
  printf("\ngraph %i",graph->edge[2].src);

  return 0;
}
