#include "NodoArbol.h"

NodoArbol::NodoArbol(Cliente c, NodoArbol *i, NodoArbol *d)
{
    cliente = c;
    izq = i;
    der = d;

}

NodoArbol::~NodoArbol()
{
    //dtor
}
