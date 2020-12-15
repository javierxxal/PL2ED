#include "Lista.h"
#include "iostream"
#include "Pedido.h"
Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Lista::~Lista()
{
    //dtor
}

void Lista::insertarIzq(Pedido p){
    pnodo nuevo = new Nodo(p);
    if(es_vacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    longitud++;
}

void Lista::insertarDer(Pedido p){
    pnodo nuevo = new Nodo(p);
    if(es_vacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }
    longitud++;
}
void Lista::insertarOrdenado(Pedido p){
    if(!es_vacia()){
        if(ultimo->ped.getPrioridad()>= p.getPrioridad()){
            insertarDer(p);
        }
        else if(primero->ped.getPrioridad() < p.getPrioridad()){
            insertarIzq(p);
        }
        else{
            Pedido aux = primero->ped;
            resto();
            insertarOrdenado(p);
            insertarIzq(aux);
        }
    }
    else{
        insertarIzq(p);
    }
}
void Lista::resto(){
    if(!es_vacia()){
        pnodo borrar = primero;
        if ((primero==ultimo) && (primero->siguiente = NULL)){
            primero=NULL;
            ultimo=NULL;
            borrar->siguiente = NULL;
            delete(borrar);
        }
        else{
            primero = primero->siguiente;
            borrar->siguiente = NULL;
            delete(borrar);
        }
        longitud--;
    }

}
void Lista::eult(){
    pnodo p,aux;
    if(!es_vacia()){
        p = primero;
        if(p->siguiente == NULL){
            primero = NULL;
            delete(p);
        }
        else{
            while (p->siguiente->siguiente != NULL){
                p = p->siguiente;
            }
            aux = p->siguiente;
            p->siguiente = NULL;
            delete(aux);
        }
        longitud--;
    }

}
bool Lista::es_vacia(){
    return(longitud == 0);
}
Pedido Lista::prim(){
    return primero->ped;
}
Pedido Lista::ult(){
    return ultimo->ped;
}
int Lista::lon(){
    return longitud;
}
void Lista::verLista(){
    if(es_vacia()){
        cout<<"LISTA VACIA"<<endl;
    }
    pnodo aux = primero;
    while(aux != NULL){
        aux->ped.toStr();
        cout << "-------------------" << endl;
        aux = aux->siguiente;
    }
}
