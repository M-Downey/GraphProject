#include "stats.h"
#include "graph.h"

int numberOfEdges(char name[])
{
	AdjGraph *g;
	g = create_graph(g, name);	
	int cnt = 0;
	ArcNode *p;
	for (int i = 0; i < 410000; i++) {
		p = g->adjlist[i].firstarc;
		while (p!= NULL) {
			cnt++;
			p = p->nextarc;
		}
	}
	g->e = cnt;
	return g->e;
}

int numberOfVertices(char name[])
{
	AdjGraph *g;
	g = create_graph(g, name);
	int cnt = 0;
	
	ArcNode *p;
	for (int i = 0; i < 410000; i++) {
		p = g->adjlist[i].firstarc;
		while (p != NULL) {
			flag[i] = 1;
			flag[p->adjvex] = 1;
			p = p->nextarc;
		}
	}
	for (int i = 0; i < 410000; i++) {
		if (flag[i]) {
			cnt++;
		}
	}
	g->n = cnt;
	return g->n;
}

float freemanNetworkCentrality(char name[])
{
	float freeman_network_centrality;
	long long n = numberOfVertices(name);
	long long mother = (n - 1) * (n - 2);
	AdjGraph *g;
	g = create_undirected_graph(g, name);
	ArcNode *p;
	for (int i = 0; i < 410000; i++) {
		p = g->adjlist[i].firstarc;
		while (p != NULL) {
			degree[i]++;
			p = p->nextarc;
		}
	}
	int maxdegree = 0;
	for (int i = 0; i < 410000; i++) {
		if(degree[i] > maxdegree) {
			maxdegree = degree[i];
		} 
	}
//	printf("\nmaxd = %d\n", maxdegree);
	long long sumd = 0;
	for (int i = 0; i < 410000; i++) {
		if (g->adjlist[i].firstarc != NULL) {
			sumd += maxdegree - degree[i];
		}
	}
//	printf("\nsumd = %lld \nmother = %lld\n", sumd, mother);
	freeman_network_centrality = sumd / (double)mother;
//	printf("\nfnc = %f\n", );
	return freeman_network_centrality;
}

