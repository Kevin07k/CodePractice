#include<iostream>
#include<vector>
using namespace std;
// typedef endl "\n";
vector<vector<int>> G;
int main(){
    int nodos, arcos;
    cin>> nodos>> arcos;
    // Asignanos el tamaño y lo rellenamos de vectores vacios
    G.assign(nodos, vector<int>());
    while(arcos--){
        int a,b;
        // Quien con quien esta conectado
        cin>> a>> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // Imprimimos el grafo
    for (int i = 0; i < nodos; i++)
    {
        cout<< "El nodo "<< i<< " esta conectado con: ";
        for (auto &&vecino : G[i])
        {
            cout<< vecino<< " ";
        }
        cout<< "\n";
    }
    
    return 0;
}