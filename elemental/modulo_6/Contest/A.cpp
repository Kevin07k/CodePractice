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
    vector <int> nodos_iniciales;
    int componentes = 0;
    // * Voy a tirar de varios DFS's
    for (int i = 1; i < nodos+1; i++) {
        if (!visitado[i]) {
            componentes++;
            nodos_iniciales.push_back(i);
            DFS(i);
        }
    }
    cout<< componentes-1 << endl;

    // * Imprimir las carreteras
    for (int i = 1; i < nodos_iniciales.size(); ++i) {
        cout<<nodos_iniciales[i-1]<<" "<< nodos_iniciales[i]<<endl;
    }
    return 0;
}