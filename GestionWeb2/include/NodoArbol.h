#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "Cliente.h"

class NodoArbol
{
    public:
        NodoArbol(Cliente c, NodoArbol *i = NULL, NodoArbol *d = NULL);
        ~NodoArbol();
    private:
        Cliente cliente;
        NodoArbol *izq;
        NodoArbol *der;
        friend class ArbolB;
        friend class Web;
        friend class main;

};

#endif // NODOARBOL_H
