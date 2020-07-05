#include "graph.h"

AdjGraph *create_graph(AdjGraph *g, char name[])
{
	freopen(name, "r", stdin);
	g = (AdjGraph*)malloc(sizeof(AdjGraph));
	rewind(stdin);
	for (int i = 0; i < 410000; i++) {
		g->adjlist[i].firstarc = NULL;
	}
	ArcNode *p;
	int u, v, w;
	while (scanf("%d %d %d", &u, &v, &w) != EOF) {
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = v;
		p->weight = w;
		p->nextarc = g->adjlist[u].firstarc;
		g->adjlist[u].firstarc = p;
	}
	fclose(stdin);
	return g;
}

AdjGraph *create_undirected_graph(AdjGraph *g, char name[])
{
	freopen(name, "r", stdin);
		
	g = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (int i = 0; i < 410000; i++) {
		g->adjlist[i].firstarc = NULL;
	}
	ArcNode *p, *q, *s;
	int u, v, w;
	int flag1;
	while (scanf("%d %d %d", &u, &v, &w) != EOF) {
		flag1 = 1;
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s = g->adjlist[u].firstarc;
		//检查u->v是否存过 
		while (s != NULL) {
			if (s->adjvex == v) {
				flag1 = 0;
				break;
			}
			s = s->nextarc;
		}

		if (flag1) {
			//存u->v 和v->u 
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = v;
			p->weight = w;
			p->nextarc = g->adjlist[u].firstarc;
			g->adjlist[u].firstarc = p;
			
			q = (ArcNode*)malloc(sizeof(ArcNode));
			q->adjvex = u;
			q->weight = w;
			q->nextarc = g->adjlist[v].firstarc;
			g->adjlist[v].firstarc = q;
		}
	}
	fclose(stdin);
	return g;
}
