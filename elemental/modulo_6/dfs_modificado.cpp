#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<vector<int>>G;
vector<bool> visitado;
deque<int> orden_topologico;
void DFS(int nodo){
    visitado[nodo] = true;
    for(auto vecino: G[nodo]){
        if(!visitado[vecino]){
            DFS(vecino);
        }
    }
    orden_topologico.push_front(nodo); // Para colocar el orden topologico
}
int main(){
    int nodos, arcos;
    cin >> nodos >> arcos;
    G.assign(nodos + 1, vector<int>());
    visitado.assign(nodos + 1, false);
    while(arcos--){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b); // No hay G[b].push_back(a) pues el grafo es dirigido
    }
    for (int i = 1; i <= nodos; i++)
    {
        if (!visitado[i])
        {
            DFS(i);
        }
    }
    // Imprimir el orden topologico
    for (int i = 0; i < orden_topologico.size(); i++)
    {
        cout<<orden_topologico[i]<<" ";
    }
    
    return 0;
}