//
// Created by brand on 8/21/2025.
//

#include<iostream>
#include <vector>
using namespace std;

vector<vector<int> >G;
vector<bool> visitado;

void DFS(int nodo) {
    visitado[nodo] = true;
    for (auto vecino: G[nodo]) {
        if (!visitado[vecino]) {
            DFS(vecino);
        }
    }
}

int main() {
    int nodos, arcos;
    cin>> nodos>> arcos;
    G.assign(nodos+1, vector<int>());
    visitado.assign(nodos+1, false);
    while (arcos--) {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return 0;
}