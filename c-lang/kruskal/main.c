
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

// Represent  a subset for union find
struct subset
{
  int parent;
  int rank;
};

int edge_compare(struct Edge* a, struct Edge* b)
{
  return a->weight < b->weight;

}

int edge_compare_qsort(const void* a, const void* b)
{
  struct Edge* a1 = (struct Edge*)a; 
  struct Edge* b1 = (struct Edge*)b; 
  return a1->weight > b1->weight; 
  
}

int
find_subset(struct subset subsets[], int i)
{
  // path compression
  if (subsets[i].parent != i){
    subsets[i].parent = find_subset(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

// Union of two sets x and y : by rank
void
union_by_rank(struct subset subsets[], int x, int y)
{
  int xroot = find_subset(subsets,x);
  int yroot = find_subset(subsets,y);

  // Attach smaller rank tree under root of high rank tree
  if(subsets[xroot].rank < subsets[yroot].rank){
    subsets[xroot].parent = yroot;
  } else if (subsets[xroot].rank > subsets[yroot].rank){
    subsets[yroot].parent = xroot;
  }
  // if ranks are the same, then make one as root and increment its rank by 1
  else{
    subsets[yroot].parent = xroot;
    subsets[xroot].rank += 1;
  }
}

void kruskal_mst(struct Graph* graph)
{
  int V = graph->V;
  struct Edge result[V]; // store resultant Minnumum spanning tree
  int i = 0;
  int edge_index = 0;

  // Step 1: Sort all edges in non-decreasing order to their weight.
  // if we are not allowed to change the given graph, we can create
  // a copy of array of edges
  qsort(graph->edge,graph->E,sizeof(graph->edge[0]),edge_compare_qsort);

  // Allocate memory for creating V subsets
  struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));

  // Create V subsets with single elements
  for (int v = 0; v < V; ++v)
  {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  // Number of edges to be taken is equal to V-1
  while (edge_index < V - 1 && i < graph->E)
  {
    // Step 2: pick the smallest edge and increment index for next iteration
    struct Edge next_edge = graph->edge[i++];

    int x = find_subset(subsets,next_edge.src);
    int y = find_subset(subsets,next_edge.dest);

    // if including this edge doesn't cause cycle,
    // include it in result and increment index of result for next_edge
    if (x!=y){
      result[edge_index++] = next_edge;
      union_by_rank(subsets,x,y);
    }
    // else discard edges
  }
  // print the contents of result[] to display the build minnimum spanning tree
  printf("\nFollowing are all the edges in the constructed MST\n");
  for(i=0; i<edge_index; ++i){
    printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
  }
  return;
}

int main() {

  int V = 4; // Number of vertices in a graph
  int E = 5; // Number of edges in a graph

  struct Graph* graph = createGraph(V, E);

   // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    /* // add edge 2-3 */
    /* graph->edge[4].src = 2; */
    /* graph->edge[4].dest = 3; */
    /* graph->edge[4].weight = 4; */


  printf("\ngraph %i",graph->E);
  printf("\ngraph %i",graph->edge[2].weight);
  /* printf("\ngraph %i",graph[0].edge->weight); */
  printf("\ngraph %i",edge_compare(&graph->edge[2], &graph->edge[3]));

  kruskal_mst(graph);
  return 0;
}
