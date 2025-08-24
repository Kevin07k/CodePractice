#include <iostream>
#include <vector>
using namespace std;
struct Nodo
{
    int valor;
    Nodo *izquierda;
    Nodo *derecha;
    // Constructor del nodo
    Nodo(int val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

Nodo *insertar(Nodo *raiz, int val)
{
    // Si no tiene hijo o hojas el nodo insertamos uno
    if (raiz == nullptr)
    {
        return new Nodo(val);
    }
    // Si el valor es menor al valor del nodo a la izquierda
    if (val < raiz->valor)
    {
        raiz->izquierda = insertar(raiz->izquierda, val);
    }
    // Si el valor es mayor al valor del nodo a la derecha
    if (val > raiz->valor)
    {
        raiz->derecha = insertar(raiz->derecha, val);
    }
    return raiz;
}

void pre_order(Nodo* raiz){
    if(raiz == nullptr){
        return;
    }
    cout<<raiz->valor<<" ";
    pre_order(raiz->izquierda);
    pre_order(raiz->derecha);
}
/* Print of sorting treee binary*/
void in_order(Nodo* raiz){
    if(raiz == nullptr){
        return;
    }
    in_order(raiz->izquierda);
    cout<< raiz->valor<< " ";
    in_order(raiz->derecha);
}
/* Print for layers */
void post_order(Nodo* raiz){
    if(raiz == nullptr){
        return;
    }
    post_order(raiz->izquierda);
    post_order(raiz->derecha);
    cout<< raiz->valor<<" ";
}

int main()
{
    Nodo *raiz = new Nodo(30);
    vector<int> v = {23, 47, 10, 39, 51, 3, 15, 60};
    for(auto x: v) raiz = insertar(raiz, x);
    pre_order(raiz); cout<<endl;
    in_order(raiz); cout<<endl;
    post_order(raiz); cout<<endl;
    // x = insertar(x, 10);
    // x = insertar(x, 40);
    return 0;
}