#ifndef __STATS_H__
#define __STATS_H__
#include <stdio.h>
#include <stdlib.h>

int flag[410000];	//记录结点是否存在 
int degree[410000];  //记录每个结点的度 

extern int numberOfEdges(char name[]);
extern int numberOfVertices(char name[]);
extern float freemanNetworkCentrality(char name[]);

#endif
