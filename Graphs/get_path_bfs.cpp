/*
   Code : Get Path - BFS

   Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find
   and print the path from v1 to v2 (if exists). Print nothing if there is no path
   between v1 and v2.
   Find the path using BFS and print the shortest path available.
   V is the number of vertices present in graph G and vertices are numbered from 0
   to V-1.
   E is the number of edges present in graph G.
   Print the path in reverse order. That is, print v2 first, then intermediate vertices
   and v1 at last.
   Note : Save the input graph in Adjacency Matrix.

   Input Format :
   Line 1: Two Integers V and E (separated by space)
   Next E lines : Two integers a and b, denoting that there exists an edge between
   vertex a and vertex b (separated by space)
   Line (E+2) : Two integers v1 and v2 (separated by space)

   Output Format :
   Path from v1 to v2 in reverse order (separated by space)
 */

#include <iostream>
using namespace std;

#include <vector>
#include <queue>
#include <unordered_map>


vector<int>* getPath(int** edges, int V, int sv, int ev){
	bool* visited = new bool[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}

	unordered_map<int, int> parent;
	queue<int> bfsQ;
	bfsQ.push(sv);
	visited[sv] = true;
	vector<int>* output = new vector<int>();
	bool done = false;

	while(bfsQ.size() != 0 && !done) {
		int front = bfsQ.front();
		bfsQ.pop();
		for(int i = 0; i < V; i++) {
			if(i == front) {
				continue;
			}
			if(edges[front][i] == 1 && !visited[i]) {
				bfsQ.push(i);
				parent[i] = front;      // front is reponsible for inserting this i into queue
				visited[i] = true;
				if(ev == i) {
					done = true;
					break;
				}
			}
		}
	}
	delete [] visited;
	if(!done) {      // Means never went to end vertex
		return NULL;
	} else {
		int current = ev;
		output->push_back(ev);
		while(current != sv) {
			current = parent[current];      // next current is the parent of current
			output->push_back(current);
		}
		return output;
	}
	delete output;
}

int main(){
	int V, E;
	cin >> V >> E;

	int** edges = new int*[V];
	for(int i = 0; i < V; i++) {
		edges[i] = new int[V];
		for(int j = 0; j < V; j++) {
			edges[i][j] = 0;
		}
	}

	for(int i = 0; i < E; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	int sv, ev;
	cin >> sv >> ev;

	vector<int>* output = getPath(edges, V, sv, ev);
	if(output != NULL) {
		cout << "Path (bfs) :" << endl;
		for(int i = 0; i < output->size(); i++) {
			cout << output->at(i) << " ";
		}
		delete output;
	} else {
		cout << "No path found !" << endl;
	}

	for(int i = 0; i < V; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

/*
   4 4
   0 1
   0 3
   1 2
   2 3
   1 3
   Path (bfs) :
   3 0 1
 */

/*
   For any possible path, DFS would be enough. But, BFS gives you the shortest
   path between the two vertices.
 */
