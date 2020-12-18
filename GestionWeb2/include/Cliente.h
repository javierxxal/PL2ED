#ifndef CLIENTE_H
#define CLIENTE_H
#include"Lista.h"

class Cliente
{
    public:
        Cliente();
        Cliente(string n, string t, string tj, int p); //Falta el cpp de esto
        void verCliente();// Una función void que muestre los datos del cliente y los pedidos de la lista de pedidos (puede que se tenga que retocar el toStr)
        ~Cliente();
    private:
        string nombre;
        string tipo;
        string tarjeta;
        int prioridad;
        Lista listaPedidos;
        friend class NodoArbol;
        friend class ArbolB;
        friend class Web;
};

#endif // CLIENTE_H
