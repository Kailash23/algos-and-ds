/*
   Islands

   An island is a small piece of land surrounded by water . A group of islands is
   said to be connected if we can reach from any given island to any other island
   in the same group . Given N islands (numbered from 1 to N) and two lists of size
   M (u and v) denoting island u[i] is connected to island v[i] and vice versa .
   Can you count the number of connected groups of islands.

   Constraints :
   1<=N<=100
   1<=M<=(N*(N-1))/2
   1<=u[i],v[i]<=N

   Input Format :
   Line 1 : Two integers N and M
   Line 2 : List u of size of M
   Line 3 : List v of size of M

   Output Return Format :
   The count the number of connected groups of islands

   Sample Input :
   2 1
   1
   2

   Sample Output :
   1
 */

#include <iostream>
using namespace std;

#include <vector>

void DFS(int **edges, int n, int sv, bool *visited) {
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i]) {
            DFS(edges, n, i, visited);
        }
    }
}

int solve(int n, int m, vector<int> u, vector<int> v) {
    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int f = v[i] - 1;
        int s = u[i] - 1;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            DFS(edges, n, i, visited);
        }
        bool check = visited[0];
        for (int i = 1; i < n; i++) {
            check = check && visited[i];
        }
        if (check) {
            return count;
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> u;
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        u.push_back(n);
    }

    vector<int> v;
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    cout << solve(N, M, u, v);
}

/*
   6 6
   3 3 1 5 6 4
   1 2 2 4 5 6
   2
 */
