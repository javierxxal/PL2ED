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
        Pedido(string n,string d,int t); //constructor con datos reducidos para los pedidos de los clientes en el arbol
        virtual ~Pedido();
        //Operaciones
        string getTipo(); //Devuelve el tipo de pedido
        int getPrioridad(); //Devuelve la prioridad del pedido siendo VIP=2 NVI=1 NR=0
        void toStr();     //Muestratodo el pedido
        void toStr2(); //muestra solo el nombre la direccion y el tiempo del pedido (utilizado en los clientes)
        void restarPreparacion();//resta 1 minuto al tiempo real de preparacion
    private:
        string nombre;
        string ncliente;
        string direccion;
        string tipo;       //"VIP","NVIP","NR"
        string tarjeta;
        int tiempo;
        int prioridad;
        bool erroneo;
        int preparacion; //atributo que guarda el tiempo de preparacion a tiempo real
        friend class Nodo;
        friend class Pila;
        friend class Cola;
        friend class Lista;
        friend class Web;
        friend class ArbolB;
};

#endif // PEDIDO_H
