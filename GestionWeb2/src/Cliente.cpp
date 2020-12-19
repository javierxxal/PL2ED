#include "Cliente.h"
#include <iostream>
#include "Nodo.h"
using namespace std;

Cliente::Cliente()
{

}
Cliente::Cliente(string n, string t, string tj, int p)
{
    nombre = n;
    tipo =t;
    tarjeta = tj;
    prioridad = p;
}

Cliente::~Cliente()
{
    //dtor
}

void Cliente::verCliente(){

    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Tarjeta: " << tarjeta << endl;
    cout << "Pedidos realizados: " << endl;
    listaPedidos.verLista2();
}
