#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "Cliente.h"

class NodoArbol
{
    public:
        NodoArbol(Cliente c, NodoArbol *i = NULL , NodoArbol *d = NULL);
        virtual ~NodoArbol();

    private:
        Cliente valor;
        NodoArbol *izq;
        NodoArbol *der;
        friend ArbolB;

};
typedef Nodo *anodo;

#endif // NODOARBOL_H
