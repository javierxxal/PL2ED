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
        void insertar(Cliente c, NodoArbol *nodo);//A�ade nuevos clientes al �rbol
        void insertarPedido(Pedido p, NodoArbol * nodo); //A�ade a la lista de Pedidos del cliente y si no existe crea uno nuevo
        bool esta(string nombre, NodoArbol *nodo);//Comprueba que un cliente esta en el �rbol

        //Funciones para 3� punto
        void buscar(string nombre, NodoArbol *nodo);//Busca un cliente en el �rbol y ense�a sus datos
        void mostrarPreorden(NodoArbol *nodo);//Muestra los datos del cliente en preorden
        int altura(NodoArbol *nodo);//Calcula la altura del �rbol
        int cuentaProducto(string descripcion,NodoArbol *nodo);//Cuenta el n� de productos con el mismo nombre introducido
        void mostrarVip(NodoArbol *nodo);//Muestra ordenado alfabeticamente los datos de los clientes VIPS

    private:
    NodoArbol *raiz;
    friend class Web;




};

#endif // ARBOLB_H
