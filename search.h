#ifndef __SEARCH_H__
#define __SEARCH_H__
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define inf 0x3f3f3f3f

typedef struct {
	int path[410000];
	int d;
} Path;

typedef struct {
	int data;
	int parent;
}Queue;

int visited[410000];
int dist[410000];
int S[410000];
int pp[410000];
Queue qu[410000];

extern char* shortestPath(int u, int v, char algorithm[], char name[]);
extern int cmp(char *s, char *str);
extern void DFS(AdjGraph *g, int u, int v, Path *p);
extern Path *Dijkstra(AdjGraph *g, int u, int v, Path *P);
extern void BFS(AdjGraph *g, int u, int v);

#endif
