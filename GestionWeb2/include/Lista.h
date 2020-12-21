#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Pedido.h"

class Lista
{
  public:
        //Constructores
        Lista();
        virtual ~Lista();
        //Operaciones
        void insertarIzq(Pedido p); //Añade un pedido por la izquierda
        void insertarDer(Pedido p); //Añade un pedido por la derecha
        void insertarOrdenado(Pedido p);//Inserta un pedido a más derecha de su tipo
        void resto();//Elimina el primero pedido de la lista
        void eult(); //Elimina el ultimo pedido de la lista
        bool es_vacia();//Comprueba si una lista es vacia
        Pedido& prim(); //Devuelve el primer pedido de la lista
        Pedido& ult(); //Devuelve el último pedido de la lista
        int lon();//Devuelve la longitud de la lista
        void verLista(); //muestra todos los datos de los pedidos
        void verLista2(); //solo muestra ciertos datos de los pedidos

    private:
        //Atributos
        pnodo primero;
        pnodo ultimo;
        int longitud;  // Mide la longitud de la lista

        friend class ArbolB;
};

#endif // LISTA_H
