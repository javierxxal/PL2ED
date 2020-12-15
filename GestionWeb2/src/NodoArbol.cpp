#include "NodoArbol.h"

NodoArbol::NodoArbol(Cliente c, NodoArbol *i = NULL , NodoArbol *d = NULL)
{
    valor = c;
    izq = i;
    der = d;

}

NodoArbol::~NodoArbol()
{
    //dtor
}
