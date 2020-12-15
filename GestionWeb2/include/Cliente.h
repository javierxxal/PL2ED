#ifndef CLIENTE_H
#define CLIENTE_H
#include"Lista.h"

class Cliente
{
    public:
        Cliente();
        Cliente(string n, string t, string tj);
        ~Cliente();
        void insertarPedido(Pedido);
    private:
        string nombre;
        string tipo;
        string tarjeta;
        Lista listaPedidos;
        friend class NodoArbol;
        friend class ArbolB;
};

#endif // CLIENTE_H
