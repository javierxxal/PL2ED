#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Pedido.h"
class Nodo
{
    public:
        Nodo(Pedido p,Nodo *sig = NULL);
        ~Nodo();


    private:
        Pedido ped;
        Nodo *siguiente;
        friend class Pila;
        friend class Cola;
        friend class Lista;
        friend class Pedido;
        friend class Web;
};
typedef Nodo *pnodo;

#endif // NODO_H
