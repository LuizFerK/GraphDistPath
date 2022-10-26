#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "graph.h"

int main() {
  Graph *graph = GRAPH(4);
  GRAPHinsert_edge(graph, EDGE(0, 1));
  GRAPHinsert_edge(graph, EDGE(0, 2));

  printf("Number of vertices: %d\n", GRAPHget_v_num(graph));
  printf("Number of edges: %d\n\n", GRAPHget_e_num(graph));
  GRAPHprint(graph);

  GRAPHremove_edge(graph, EDGE(3, 2));

  printf("Number of vertices: %d\n", GRAPHget_v_num(graph));
  printf("Number of edges: %d\n\n", GRAPHget_e_num(graph));
  GRAPHprint(graph);

  if (GRAPHpath(graph, 0, 2)) {
    printf("There is a path between 0 and 2\n");
  } else {
    printf("There is no path between 0 and 2\n");
  }
  printf("\n");

  GRAPHremove_edge(graph, EDGE(0, 2));

  printf("Number of vertices: %d\n", GRAPHget_v_num(graph));
  printf("Number of edges: %d\n\n", GRAPHget_e_num(graph));
  GRAPHprint(graph);

  if (GRAPHpath(graph, 0, 3)) {
    printf("There is a path between 0 and 3\n");
  } else {
    printf("There is no path between 0 and 3\n");
  }

  GRAPHwipe(graph);

  return 0;
}
