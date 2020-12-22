#ifndef CLIENTE_H
#define CLIENTE_H
#include"Lista.h"

class Cliente
{
    public:
        Cliente();
        Cliente(string n, string t, string tj, int p);
        void verCliente();//muestra los datos del cliente
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
