#ifndef ARBOLB_H
#define ARBOLB_H
#include "Cliente.h"
#include "NodoArbol.h"

class ArbolB
{
    public:
        ArbolB();
        ArbolB(Cliente c);
        ~ArbolB();
        bool vacio();
        int altura();
        void insertar(Cliente c);
        esta(string nombre);

    private:
    NodoArbol *raiz;
    string nombreRaiz;




};

#endif // ARBOLB_H
