#include "search.h"
#include "graph.h"

int cmp(char *s, char *str)
{
	int i = 0;
	while (s[i] != '\0' && str[i] != '\0') {
		if (s[i] > str[i]) {
			return 1;
		} else if (s[i] < str[i]) {
			return -1;
		}
		i++;
	}
	if (s[i] == '\0' && str[i] == '\0') {
		return 0;
	} else if (s[i] == '\0') {
		return -1;
	} else if (str[i] == '\0') {
		return 1;
	}
}

char* shortestPath(int u, int v, char algorithm[], char name[])
{
	AdjGraph *g;
	g = create_graph(g, name);
	for (int i = 0; i < 410000; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < 410000; i++) {
		dist[i] = 0;
	}
	for (int i = 0; i < 410000; i++) {
		S[i] = 0;
	}
	for (int i = 0; i < 410000; i++) {
		pp[i] = 0;
	}
	char *s;
	s = (char*)malloc(sizeof(char));
	
	char algo1[10] = "DFS";
	char algo2[10] = "BFS";
	char algo3[10] = "Dijkstra";
	if (cmp(algorithm, algo1) == 0) {
		Path *p = (Path*)malloc(sizeof(Path));
		p->d = -1;
		DFS(g, u, v, p);
	} else if (cmp(algorithm, algo2) == 0) {
		BFS(g, u, v);
	} else if (cmp(algorithm, algo3) == 0) {
		Path *p = (Path*)malloc(sizeof(Path));
		p = Dijkstra(g, u, v, p);
		int i = 0;
		while( p->path[v] != u) {
			pp[i] = v;
			v = p->path[v];
			i++;
		} 
		pp[i++] = v;
		pp[i] = u;
		while(i>0){
			printf("%d -> ", pp[i]);
			i--;
		}
		printf("%d\n", pp[0]);
		pp[i++] = v;
		pp[i] = u;
		int j = 0;
	}
	return s;
}

void DFS(AdjGraph *g, int u, int v, Path *P)
{
	int w, i;
	ArcNode *p;
	visited[u] = 1;
	P->d = P->d + 1;
	P->path[P->d] = u;
	if (u == v) {
		for (int i = 0; i < P->d; i++) {
			printf("%d -> ", P->path[i]);
		}
		printf("%d\n", P->path[P->d]);
		return;
	}
	p = g->adjlist[u].firstarc;
	while (p != NULL) {
		w = p->adjvex;
		if (visited[w] == 0) {
			DFS(g, w, v, P);
		}
		p = p->nextarc;
	}
}

void BFS(AdjGraph *g, int u, int v)
{
	ArcNode *p;
	int w, i;
	int front, rear;
	front = rear = -1;
	rear++;
	qu[rear].data = u;
	qu[rear].parent = -1;
	visited[u] = 1;
	while (front != rear) {
		front++;
		w = qu[front].data;
		if (w == v) {
			i = front;
			while (qu[i].parent != -1) {
				pp[i] = qu[i].data;
				printf("%d -> ", qu[i].data);
				i = qu[i].parent;
			}
			printf("%d\n", qu[i].data);
			return;
		}
		p = g->adjlist[w].firstarc;
		while (p != NULL) {
			if (visited[p->adjvex] == 0) {
				visited[p->adjvex] = 1;
				rear++;
				qu[rear].data = p->adjvex;
				qu[rear].parent = front;
			}
			p = p->nextarc;
		}
	}
}

Path *Dijkstra(AdjGraph *g, int u, int v, Path *P)
{

    int i;
    for (i = 0; i < 410000; i++) {
        dist[i] = inf;
    }
    S[u] = 1;
    dist[u] = 0;
    
    ArcNode *q;
    q = (ArcNode *)malloc(sizeof(ArcNode));
    q = g->adjlist[u].firstarc;
    while (q != NULL) {
        P->path[q->adjvex] = u;
        dist[q->adjvex] = q->weight;
        q = q->nextarc;
    }
    int min;
    int j;
    int k;
    for (i = 0; i < 410000; i++) {
        if (g->adjlist[i].firstarc == NULL) {
            continue;
        }
        min = inf;
        for (j = 0; j < 410000; j++) {
            if (g->adjlist[j].firstarc == NULL) {
                continue;
            }
            if (S[j] == 0 && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        S[k] = 1;
        q = g->adjlist[k].firstarc;
        while (q != NULL) {
            if (dist[k] + q->weight < dist[q->adjvex]) {
                dist[q->adjvex] = dist[k] + q->weight;
                P->path[q->adjvex] = k;
            }
            q = q->nextarc;
        }        
    }
    return P;
 }
