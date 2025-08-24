#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    int valor;
    Nodo *izquierda;
    Nodo *derecha;
    // Constructor del nodo
    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {
    }
};

Nodo *insertar(Nodo *raiz, int val) {
    // Si no tiene hijo o hojas el nodo insertamos uno
    if (raiz == nullptr) {
        return new Nodo(val);
    }
    // Si el valor es menor al valor del nodo a la izquierda
    if (val < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, val);
    }
    // Si el valor es mayor al valor del nodo a la derecha
    if (val > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, val);
    }
    return raiz;
}
/* Pre order*/
void pre_order(Nodo *raiz) {
    if (raiz == nullptr) {
        return;
    }
    cout << raiz->valor << " ";
    // Primero va a la izquierda
    pre_order(raiz->izquierda);
    // Luego recorre la derecha
    pre_order(raiz->derecha);
}

int main() {
    Nodo *raiz = new Nodo(30);
    vector<int> v = {23, 47, 10, 39, 51, 3, 15, 60};
    for (auto x: v) raiz = insertar(raiz, x);
    pre_order(raiz);
    // x = insertar(x, 10);
    // x = insertar(x, 40);
    return 0;
}
