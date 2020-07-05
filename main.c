#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stats.h"
#include "search.h"

int main(int argc, char *argv[]) 
{
//	char s[20] = "dummy_test.txt";
//	char a[20] = "test.txt";
////	freopen("dummy_test_key.txt", "w",stdout);
//	printf("eages = %d\n", numberOfEdges(s));
//	printf("vertices = %d\n", numberOfVertices(s));
//	printf("freeman network centrality = %f\n", freemanNetworkCentrality(s));
//	shortestPath(2, 34372, "DFS", a);
////	shortestPath(0, 1, "BFS", s);
//	shortestPath(0, 1, "Dijkstra", s);
	
	
//	fclose(stdout);

//	argv[0] = "./search-cli";
//	argv[1] = "-g";
//	argv[2] = "dummy_test.txt";
//	argv[3] = "-sp";
//	argv[4] = "Dijkstra";
//	argv[5] = "-u";
//	argv[6] = "0";
//	argv[7] = "-v";
//	argv[8] = "1";
	if (cmp(argv[1], "-h") == 0) {
		printf("\n\n0.Display hlep menu by inputing:\n\n");
		printf("    ./search-cli -h\n\n");
		printf("1.Find basic infomation of graph by inputing:\n\n");
		printf("    ./search-cli -g FILE_PATH -s STATS_PARAMS\n\n");
		printf("    --STATS_PARAMS include : 'edges','vertices','freeman'\n\n");
		printf("2.Find shortest path from u to v of graph by inputing:\n\n");
		printf("    ./search-cli -g FILE_PATH -sp SEARCH_PARAMS -u STARTING_POINT -v TARGET_POINT\n\n");
		printf("  The path will be displayed.\n\n");
		printf("    Example-in  : ./search-cli -g ./sx-stackoverflow.txt -sp Dijkstra -u 1 -v 5\n");
		printf("    EXample-out : 1 -> 2 -> 3 -> 4 ->5\n\n");
		printf("3.Display an image of garlic boy by inputing:\n\n");
		printf("    ./search-cli -j\n\n");
	} else if (cmp(argv[1], "-g") == 0) {
		if (cmp(argv[3], "-s") == 0) {
			if (cmp(argv[4], "edges") == 0) {
				printf("eages = %d\n", numberOfEdges(argv[2]));
			} else if (cmp(argv[4], "vertices") == 0) {
				printf("vertices = %d\n", numberOfVertices(argv[2]));
			} else if (cmp(argv[4], "freeman") == 0) {
				printf("freeman network centrality = %f\n", freemanNetworkCentrality(argv[2]));
			} else {
				printf("\n\nWrong command!\n\n");
			}
		} else if (cmp(argv[3], "-sp") == 0) {
			int u, v;
			u = v = 0;
			int i = 0;
			while (argv[6][i] != '\0') {
				i++;
			}
			int l = i;
			while (i) {
				u = u * 10 + argv[6][l - i] - '0';
				i--;
			}
			while (argv[8][i] != '\0') {
				i++;
			}
			l = i;
			while (i) {
				v = v * 10 + argv[8][l - i] - '0';
				i--;
			}
			if (cmp(argv[4], "DFS") == 0) {
				shortestPath(u, v, argv[4], argv[2]);
			} else if (cmp(argv[4], "BFS") == 0) {
				shortestPath(u, v, argv[4], argv[2]);
			} else if (cmp(argv[4], "Dijkstra") == 0) {
				shortestPath(u, v, argv[4], argv[2]);
			}
		} else {
			printf("\n\nWrong command!\n\n");
		}
	} else if (cmp(argv[1], "-j") == 0) {
		printf("\n\n    \\ /    \n");
		printf("   *****   \n");
		printf("   *^*^*   \n");
		printf("   **~**   \n");
		printf(" )--***--( \n");	
		printf("    ***    \n");
		printf("    ***    \n");
		printf("    / \\    \n\n");
	} else {
		printf("\n\nWrong command!\n\n"); 
	}
	return 0;
}
