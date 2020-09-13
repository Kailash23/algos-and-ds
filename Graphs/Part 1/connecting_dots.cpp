/*
   Connecting Dots

   Gary has a board of size NxM. Each cell in the board is a coloured dot. There
   exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z).
   Now Gary is getting bore and wants to play a game. The key of this game is to
   find a cycle that contain dots of same colour. Formally, we call a sequence of
   dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

   1. These k dots are different: if i ≠ j then di is different from dj.
   2. k is at least 4.
   3. All dots belong to the same colour.
   4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should
   also be adjacent. Cells x and y are called adjacent if they share an edge.

   Since Gary is colour blind, he wants your help. Your task is to determine if
   there exists a cycle on the board.
   Assume input to be 0-indexed based.

   Input Format :
   Line 1 : Two integers N and M, the number of rows and columns of the board
   Next N lines : a string consisting of M characters, expressing colors of dots
   in each line. Each character is an uppercase Latin letter.

   Output Format :
   Return 1 if there is a cycle else return 0

   Sample Input :
   3 4
   AAAA
   ABCA
   AAAA

   Sample Output :
   1
 */

#include <iostream>
using namespace std;

#include <cstring> // for memset

int cycleFound = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int visited[50][50];

void DFS(char **board, int x, int y, int fromX, int fromY, char color, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }
    if (board[x][y] != color) {
        return;
    }
    if (visited[x][y]) {
        cycleFound = 1;
        return;
    }
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX == fromX && nextY == fromY) {
            continue;
        }
        DFS(board, nextX, nextY, x, y, color, n, m);
    }
}

int solve(char **board, int n, int m) {
    int i, j;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                DFS(board, i, j, -1, -1, board[i][j], n, m);
            }
        }
    }
    return cycleFound;
}

int main() {
    int n, m;
    cin >> n >> m;

    char **board = new char *[n];
    for (int i = 0; i < n; i++) {
        board[i] = new char[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cout << solve(board, n, m);
}

/*
   3 4
   AAAA
   ABCA
   AAAA
   1
 */
