#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph {
  int v_num;
  int e_num;
  int **matrix;
};

Graph *GRAPH(int v_num) {
  Graph *g = malloc(sizeof(*g));;

  g->v_num = v_num;
  g->e_num = 0;

  g->matrix = malloc(v_num * sizeof(int*));

  for (int i = 0; i < v_num; i++) {
    g->matrix[i] = malloc(v_num * sizeof(int));
  }
  
  for (int i = 0; i < v_num; i++) {
    for (int j = 0; j < v_num; j++) {
      g->matrix[i][j] = 0;
    }
  }

  return g;
}

void GRAPHinsert_edge(Graph *g, Edge e) {
  if (g->matrix[e.v1][e.v2] == 0 && e.v1 != e.v2) {
    g->matrix[e.v1][e.v2] = 1;
    g->matrix[e.v2][e.v1] = 1;
    g->e_num++;
  }
}

void GRAPHremove_edge(Graph *g, Edge e) {
  if (g->matrix[e.v1][e.v2] != 0) {
    g->matrix[e.v1][e.v2] = 0;
    g->matrix[e.v2][e.v1] = 0;
    g->e_num--;
  }
}

int GRAPHget_e_num(Graph *g){
  return g->e_num;
}

int GRAPHget_v_num(Graph *g) {
  return g->v_num;
}

void GRAPHprint(Graph *g) {
  for(int i = 0; i < g->v_num; i++) {
    printf("%d:", i);
    for (int j = 0; j < g->v_num; j++) {
      if (g->matrix[i][j]) printf(" %d", j);
    }
    printf("\n");
  }
}

static bool path(Graph *g, int v, int w, int marked[], int indent) {
  for (int i = 0; i < indent; i++) printf(" ");
  printf("path (%d, %d)\n", v, w);

  if (v == w) return true;

  marked[v] = 1;

  for (int u = 0; u < g->v_num; u++) {
    if (g->matrix[v][u] != 0) {
      if (marked[u] == 0) {
        if (path(g, u, w, marked, (indent + 4))) {
            return true;
        }
      }
    }
  }

  return false;
}

bool GRAPHpath(Graph *g, int v, int w) {
  int marked[g->v_num];

  for (int i = 0; i < g->v_num; i++) marked[i] = 0;

  return path(g, v, w, marked, 0);
}

void GRAPHwipe(Graph *g) {
  for (int i = 0; i < g->v_num; i++) free(g->matrix[i]);
  
  free(g->matrix);
  free(g);
}
