//
// Created by brand on 8/24/2025.
//
#include <iostream>

using namespace std;

int n, m;
char mat[110][110];
int cf[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int f, int c);

int main() {
    while (cin >> m >> n) {
        if (m == 0) {
            break;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        int pozos = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '@') {
                    dfs(i, j);
                    pozos++;
                }
            }
        }
        cout << pozos << endl;
    }
    return 0;
}

void dfs(const int f, const int c) {
    mat[f][c] = '*'; // * Marcamos como visitado en este caso como el visitado
    for (int i = 0; i < 8; i++) {
        int nf = f + cf[i];
        int nc = c + cc[i];
        // ? Si es valida osea que esta en los rangos de la matriz o grilla y si es una '@'
        if (nf >= 0 and nf < m and nc >= 0 and nc < n and mat[nf][nc] == '@') {
            dfs(nf, nc);
        }
    }
}
