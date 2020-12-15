#include "Nodo.h"
#include "Pedido.h"

Nodo::Nodo(Pedido p,Nodo *sig)
{
    ped = p;
    siguiente = sig;
}

Nodo::~Nodo()
{
    //dtor
}
