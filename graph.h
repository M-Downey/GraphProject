#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct ANode {
	int adjvex;
	struct ANode *nextarc;
	int weight;
} ArcNode;

typedef struct Vnode {
	ArcNode *firstarc;
} VNode;

typedef struct {
	VNode adjlist[410000];
	int n, e;
} AdjGraph; 

extern AdjGraph *create_graph(AdjGraph *g, char name[]);
extern AdjGraph *create_undirected_graph(AdjGraph *g, char name[]);

#endif
