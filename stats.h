#ifndef __STATS_H__
#define __STATS_H__
#include <stdio.h>
#include <stdlib.h>

int flag[410000];	//��¼����Ƿ���� 
int degree[410000];  //��¼ÿ�����Ķ� 

extern int numberOfEdges(char name[]);
extern int numberOfVertices(char name[]);
extern float freemanNetworkCentrality(char name[]);

#endif
