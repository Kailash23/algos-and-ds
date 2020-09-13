/*
   Coding Lover

   Given a NxM matrix containing Uppercase English Alphabets only. Your task is to
   tell if there is a path in the given matrix which makes the sentence CODINGLOVER .
   There is a path from any cell to all its neighbouring cells. A neighbour may share
   an edge or a corner.

   Input Format :
   Line 1 : Two space separated integers N  and M, where N is number of rows and M
   is number of columns in the matrix.
   Next N lines : N rows of the matrix. First line of these N line will contain 0th
   row of matrix, second line will contain 1st row and so on
 */

#include <iostream>
using namespace std;

#define MAXN 100

int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

char pattern[11] = {'C', 'O', 'D', 'I', 'N', 'G', 'L', 'O', 'V', 'E', 'R'};
int used[MAXN][MAXN];

int validPoint(int x, int y, int N, int M) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int DFS(char **Graph, int x, int y, int index, int N, int M) {
    if (index == 11) {
        return 1;
    }
    used[x][y] = 1;
    int i, newX, newY;
    int found = 0;
    for (int i = 0; i < 8; i++) {
        newX = x + directions[i][0];
        newY = y + directions[i][1];
        if (validPoint(newX, newY, N, M) && Graph[newX][newY] == pattern[index] && !used[newX][newY]) {
            found = found | DFS(Graph, newX, newY, index + 1, N, M);
        }
    }
    used[x][y] = 0;
    return found;
}

int solve(char **Graph, int N, int M) {
    int i, j, found;
    for (i = 0; i < N; i++) {
        for (j = 0, found = 0; j < M; j++) {
            if (Graph[i][j] == 'C') {
                found = DFS(Graph, i, j, 1, N, M);
                if (found) {
                    break;
                }
            }
        }
        if (found) {
            break;
        }
    }
    return found;
}

int main() {
    int N, M;
    cin >> N >> M;

    char **Graph = new char *[N];
    for (int i = 0; i < N; i++) {
        Graph[i] = new char[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Graph[i][j];
        }
    }
    cout << solve(Graph, N, M);
}

/*
   2 11
   CXDXNXLXVXR
   XOXIXGXOXEX
   1
 */
