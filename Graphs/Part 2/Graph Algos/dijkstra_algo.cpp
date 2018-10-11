/*
   Code : Dijkstra's Algorithm

   Given an undirected, connected and weighted graph G(V, E) with V number of
   vertices (which are numbered from 0 to V-1) and E number of edges.
   Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all
   other vertices (including source vertex also) using Dijkstra's Algorithm.
   Print the ith vertex number and the distance from source in one line separated by
   space. Print different vertices in different lines.
   Note : Order of vertices in output doesn't matter.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next E lines : Three integers ei, ej and wi, denoting that there exists an edge
   between vertex ei and vertex ej with weight wi (separated by space)

   Output Format :
   In different lines, ith vertex number and its distance from source (separated by space)

   Constraints :
   2 <= V, E <= 10^5

   Sample Input 1 :
   4 4
   0 1 3
   0 3 5
   1 2 1
   2 3 8

   Sample Output 1 :
   0 0
   1 3
   2 4
   3 5
 */

#include <iostream>
using namespace std;

#include <climits>

int findMinVertex(int* distance, bool* visited, int v){
	int minVertex = -1;
	for(int i = 0; i < v; i++){
	    if(!visited[i] && ( minVertex == -1 || distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** edges, int v){
	int* distance = new int[v];
	bool* visited = new bool[v];

	for(int i = 0; i < v; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[0] = 0;
	/*
		Time Complexity :
		(v - 1) * 2v = O(v^2) // of this algorithm
		But we can achieve : (v + e) log v
	*/
	for(int i = 0; i < v - 1; i++) {			// v - 1
		int minVertexIndex = findMinVertex(distance, visited, v);		// v
		visited[minVertexIndex] = true;
		for(int j = 0; j < v; j++){			// v
		    if(edges[minVertexIndex][j] != 0 && !visited[j]){
				int dist = distance[minVertexIndex] + edges[minVertexIndex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	for(int i = 0; i < v; i++){
	    cout << i << " " << distance[i] << endl;
	}
	delete [] visited;
	delete [] distance;
}

int main(){
	int v, e;
	cin >> v >> e;
	int** edges = new int*[v];
	for(int i = 0; i < v; i++) {
		edges[i] = new int[v];
		for(int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}

	for(int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	dijkstra(edges, v);

	for(int i = 0; i < v; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

/*
   5 7
   0 1 4
   0 2 8
   1 3 5
   1 2 2
   2 3 5
   2 4 9
   3 4 4

   0 0
   1 4
   2 6
   3 9
   4 13
 */
