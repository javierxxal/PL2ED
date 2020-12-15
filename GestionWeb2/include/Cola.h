#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
#include "Pedido.h"

class Cola
{
public:
        //Constructores
        Cola();
        ~Cola();
        //Operaciones
        void encolar(Pedido p); //Añade un elemento al final de la cola
        void desencolar(); //Elimina el primer elemento de la cola
        Pedido prim(); //Devuelve el primer elemento de la cola
        Pedido ult(); //Devuelve el último elemento de la cola
        bool esVacia(); //Comprueba si la cola es vacia
        void verCola();  //funcion hecha con fines de comprension de la practica
    private:
        //Atributos
        pnodo primero;
        pnodo ultimo;
        int longitud;
};

#endif // COLA_H
