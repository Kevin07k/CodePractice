//
// Created by brand on 8/21/2025.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

vvi G;
vb visitados;

void bfs(int nodo);

int main() {
    int nodos, arcos, a, b;
    cin >> nodos >> arcos;
    G.assign(nodos, vector<int>());
    visitados.assign(nodos, false);
    while (arcos--) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs(nodos);
    for (int i = 0; i < nodos; i++) {
        cout<< visitados[i] << " ";
    }
    cout << endl;
    return 0;
}

void bfs(int nodo) {
    queue <int> q;
    // * El nodo en el que estamos lo marcamos como visitado
    visitados[nodo] = true;
    // * Metemos al nodo en una cola
    q.push(nodo);
    while (!q.empty()) { // ? Mientras la cola no este vacia repetira
        // * Asignamos el valor del primer elemento de la cola a nodo
        nodo = q.front();
        // ! Eliminamos primero de la cola en la estructura
        q.pop();
        // TODOs Los elementos que conectan como es lista ahi tenemos con quien tenemos conexiones
        for (auto vecino : G[nodo]) {
            if (!visitados[vecino]) { // ? Si el nodo no esta visitado lo visitamos
                // * Marcamos el nodo como visitado
                visitados[vecino] = true;
                // * Añadimos el nodo a la cola
                q.push(vecino);
            }
        }
    }
}
