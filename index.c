#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "graph.h"

int main() {
  int v, e, x, y, o;

  scanf("%d %d", &v, &e);
  
  Graph *g = GRAPH(v);

  for (int i = 0; i < e; i++) {
    scanf("%d %d", &x, &y);

    GRAPHinsert_edge(g, EDGE(x, y));
  }

  scanf("%d", &o);

  for (int i = 0; i < o; i++) {
    scanf("%d", &x);

    GRAPHbfs(g, x);
  }

  GRAPHwipe(g);
}
