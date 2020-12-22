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
        void buscarCliente(string nombre); //busca un cliente en el arbol de clientes a partir del nombre
        void alturaArbol(); //muestra la altura del arbol de clientes
        void verPreorden(); //recorre el arbol en preorden
        void cuentaProducto(string desc); //cuenta el numero de productos pedidos que cumplen una descripcion
        void mostrarVip();//muestra los clientes vip de un arbol alfabeticamente

    private:
        //Operación auxiliar privada
        int incluirListaEnvios(Cola& c , int n,int cont);//Introduce n pedidos correctos a listaEnviar1 o 2 (dependiendo del contador) enviando los errones a pilaErroneos
        void insertarWeb();//Funcion encargada de rellenar las listas Enviar dependiendo del caso y orden establecido
        //Atributos
        Pila pilaErroneos;
        Cola colaReg;
        Cola colaNR;
        Lista listaEnviar1;
        Lista listaEnviar2;
        ArbolB arbolCliente;

};

#endif // WEB_H
