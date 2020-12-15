#ifndef WEB_H
#define WEB_H
#include "Pedido.h"
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"


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
    private:
        //Operación auxiliar privada
        void incluirListaEnvios(Cola& c , int n);//Introduce n pedidos correctos a listaEnviar enviando los errones a pilaErroneos
        //Atributos
        Pila pilaErroneos;
        Cola colaReg;
        Cola colaNR;
        Lista listaEnviar;

};

#endif // WEB_H
