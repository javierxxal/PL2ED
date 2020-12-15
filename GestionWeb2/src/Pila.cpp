#include "Pila.h"
#include <iostream>
Pila::Pila()
{
    cima = NULL;
}

Pila::~Pila()
{
    //dtor
}

bool Pila::esVacia(){return cima == NULL;}

void Pila::apilar(Pedido p){
    pnodo nuevo = new Nodo(p,cima);
    cima = nuevo;
}
void Pila::apilarOrdenado(Pedido p){
    Pila aux;
    if(esVacia()){
        apilar(p);
    }
    else if(p.prioridad >= cima->ped.prioridad){
        apilar(p);
    }
    else{
        while(!esVacia() && p.prioridad < cima->ped.prioridad){
            aux.apilar(cima->ped);
            desapilar();
        }
        apilar(p);
        while(!aux.esVacia()){
            apilar(aux.cima->ped);
            aux.desapilar();
        }
    }
}
void Pila::desapilar(){
    pnodo borrar;
    if(cima){
        borrar = cima;
        cima = borrar->siguiente;
        delete(borrar);
    }
}
Pedido Pila::mostrarCima(){
    return cima->ped;
}
void Pila::verPila(){
    if(esVacia()){
        cout<<"PILA VACIA"<<endl;
    }
    pnodo aux = cima;
    while(aux != NULL){
        aux->ped.toStr();
        cout << "-------------------" << endl;
        aux = aux->siguiente;
    }

}
