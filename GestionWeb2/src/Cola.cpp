#include "Cola.h"
#include <iostream>
#include "Pedido.h"
Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;

}

Cola::~Cola()
{
    //dtor
}
void Cola::encolar(Pedido p){
    pnodo nuevo = new Nodo(p);
    if(esVacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    longitud++;
}
void Cola::desencolar(){
    if(!esVacia()){
        pnodo aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL)){
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
    }
}
Pedido Cola::prim(){
    return primero->ped;
}
Pedido Cola::ult(){
    return ultimo->ped;
}
bool Cola::esVacia(){
    return  (primero==NULL);
}
void Cola::verCola(){
    if(esVacia()){
        cout<<"COLA VACIA"<<endl;
    }
    pnodo aux = primero;
    while(aux != NULL){
        aux->ped.toStr();
        cout << "-------------------" << endl;
        aux = aux->siguiente;
    }
}

