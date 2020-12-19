#ifndef ARBOLB_H
#define ARBOLB_H
#include "Cliente.h"
#include "NodoArbol.h"
#include "string"
#include "string.h";
#include "Pedido.h"
#include "Nodo.h"


class ArbolB
{
    public:
        ArbolB();
        ArbolB(Cliente c);
        ~ArbolB();
        bool vacio();
        int altura(NodoArbol *nodo);
        void insertar(Cliente c, NodoArbol *nodo);
        void insertarPedido(Pedido p, NodoArbol * nodo);
        bool esta(string nombre, NodoArbol *nodo);
        void buscar(string nombre, NodoArbol *nodo);
        //3º entrega
        void mostrarPreorden(NodoArbol *nodo);
        int cuentaProducto(string descripcion,NodoArbol *nodo); //Convertir todo a mayus para evitar problemas
        void mostrarVip(NodoArbol *nodo); //Repetir metodo de preorden

    private:
    NodoArbol *raiz;
    friend class Web;




};

#endif // ARBOLB_H
