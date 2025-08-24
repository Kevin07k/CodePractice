#include <iostream>
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

int main()
{
    Nodo *x = new Nodo(23);
    x = insertar(x, 10);
    x = insertar(x, 40);
    return 0;
}