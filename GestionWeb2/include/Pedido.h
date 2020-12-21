#ifndef PEDIDO_H
#define PEDIDO_H
#include <string.h>
#include<string>
using namespace std;

class Pedido
{
    public:
        //Constructores
        Pedido();
        Pedido(string datos);
        Pedido(string n, string c, string d , string tp , string tj, int t);
        Pedido(string n,string d,int t);
        virtual ~Pedido();
        //Operaciones
        string getTipo(); //Devuelve el tipo de pedido
        int getPrioridad(); //Devuelve la prioridad del pedido siendo VIP=2 NVI=1 NR=0
        void toStr();     //Muestratodo el pedido
        void toStr2(); //muestra solo el nombre la direccion y el tiempo del pedido
    private:
        string nombre;
        string ncliente;
        string direccion;
        string tipo;       //"VIP","NVIP","NR"
        string tarjeta;
        int tiempo;
        int prioridad;
        bool erroneo;
        friend class Nodo;
        friend class Pila;
        friend class Cola;
        friend class Lista;
        friend class Web;
        friend class ArbolB;
};

#endif // PEDIDO_H
