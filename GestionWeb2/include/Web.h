#ifndef WEB_H
#define WEB_H
#include "Pedido.h"
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"
#include "ArbolB.h"
#include "Cliente.h"

class Web
{
public:
        //Constructores
        Web();
        virtual ~Web();
        //Operaciones
        void introducirPedido(Pedido p); //Introduce un pedido en el sistema.
        int introducirTxt(); //Lee un txt e introduce todos los pedidos en el sistema. Devuelve el numero de pedidos leidos del fichero
        void pasarTiempo(); //Simula el paso del tiempo y no termina hasta que todo este enviado.
        void mostrarColas(); //funcion para ver las dos colas del sistema
        void mostrarPila();
        void mostrarLista();
        bool webVacia(); //devuelve si TODAS las EEDD de la web estan vacias (a excepcion del arbol)
        void buscarCliente(string nombre);
        void alturaArbol();
        void verPreorden();
        void cuentaProducto(string desc);
        void mostrarVip();
    private:
        //Operación auxiliar privada
        int incluirListaEnvios(Cola& c , int n,int cont);//Introduce n pedidos correctos a listaEnviar enviando los errones a pilaErroneos
        //Atributos
        Pila pilaErroneos;
        Cola colaReg;
        Cola colaNR;
        Lista listaEnviar1;
        Lista listaEnviar2;
        ArbolB arbolCliente;

};

#endif // WEB_H
