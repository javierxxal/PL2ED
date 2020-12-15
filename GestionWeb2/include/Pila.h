#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include "Pedido.h"

class Pila
{
    public:
        //Constructores
        Pila();
        ~Pila();
        //Operaciones
        bool esVacia(); //Comprueba si una pila es vacia
        void apilar(Pedido p);//Añade un pedido a la cima de la pila
        void desapilar();//Elimina la cima de la pila
        Pedido mostrarCima();//Muestra la cima de la pila
        void apilarOrdenado(Pedido p);//Apila siguiendo el order de prioridad de los pedidos(VIP,NVIP,NR)
        void verPila(); //funcion hecha solo para fines de comprension de la práctica
    private:
        //Atributos
        pnodo cima;
};

#endif // PILA_H
