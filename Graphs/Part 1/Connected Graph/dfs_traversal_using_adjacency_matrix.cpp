/*
   Code : DFS Traversal

   Given an undirected and disconnected graph G(n, e), print its DFS traversal.
   n is the number of vertices present in graph G and vertices are numbered from 0
   to n-1.
   e is the number of edges present in graph G.

   Input Format :
   Line 1: Two Integers n and e (separated by space)
   Next 'e' lines, each have two space-separated integers, 'a' and 'b', denoting
   that there exists an edge between Vertex 'a' and Vertex 'b'.

   Output Format :
   DFS Traversal (separated by space)
 */

#include <iostream>
using namespace std;

void print(int **edges, int n, int sv, bool *visited) {
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if (edges[sv][i] == 1) {
            if (visited[i]) {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

int main() {
    int n; // Vertices
    int e; // Edges
    cin >> n >> e;
    int **edges = new int *[n]; // Adjacency matrix of n X n (where n is the no of vertices)
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0; // Initially all set to 0
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int startVertex;
    cin >> startVertex;
    cout << endl;
    print(edges, n, startVertex, visited); // Initially taking starting vertex as 0
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}

/*
   4
   3
   0 2
   2 1
   1 3
   0

   0
   2
   1
   3
 */

/*
	DFS: It goes into depth first.

				0
			/		\
		  1			  2
		 /			/	\
		5		  3		 6
		 \
		   4

		0 1 5 4 2 3 6

				0
			 /    \
			1	   2
		  /	  \     \
		  3	   4	6
		    \  |  /
		  	   5

	   DFS : 0 1 3 5 4 6 2
	   BFS : 0 1 2 3 4 6 5

*/

/*
   BFS and DFS - O(E) - O(n^2)
 */
