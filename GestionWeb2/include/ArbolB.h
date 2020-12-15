#ifndef ARBOLB_H
#define ARBOLB_H
#include "Cliente.h"

class ArbolB
{
    public:
        ArbolB(Cliente c, NodoArbol *i = NULL, NodoArbol *d = NULL);
        ~ArbolB();
        ArbolB izquierdo();
        ArbolB derecho();
        bool vacio();
        int altura();
        void insertar(Cliente c);
        esta(string nombre);

    private:
        Cliente raiz;
        NodoArbol *izq;
        NodoArbol *der;




};

#endif // ARBOLB_H
