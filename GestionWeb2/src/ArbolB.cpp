#include "ArbolB.h"

ArbolB::ArbolB()
{
raiz = NULL;
}
ArbolB::ArbolB(Cliente c){
    raiz = new NodoArbol(c);
}
ArbolB::~ArbolB()
{
    //dtor
}

bool ArbolB::vacio(){
    return (raiz == NULL);
}

void ArbolB::insertar(Cliente c, NodoArbol *nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    if (vacio()){
        raiz = new NodoArbol(c);
    }
    else{
        if(nodo->cliente.nombre==c.nombre || nodo->cliente.nombre > c.nombre){
            if(nodo->izq !=NULL){
                insertar(c, nodo->izq);
            }
            else{
                nodo->izq = new NodoArbol(c);
            }
        }
        else{
            if(nodo->der !=NULL){
                insertar(c, nodo->der);
            }
            else{
                nodo->der = new NodoArbol(c);
            }
        }
    }
}

void ArbolB::insertarPedido(Pedido p, NodoArbol * nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    Pedido introducir = Pedido(p.nombre,p.direccion,p.tiempo);
    if(esta(p.ncliente,raiz)){
        if(p.ncliente == nodo->cliente.nombre){
            nodo->cliente.listaPedidos.insertarDer(introducir);
        }
        else if (p.ncliente < nodo->cliente.nombre && nodo->izq !=NULL){
                insertarPedido(p,nodo->izq);
        }
        else if (p.ncliente > nodo->cliente.nombre && nodo->der !=NULL){
                insertarPedido(p,nodo->der);
        }
    }
    else{
        Cliente nuevoC =  Cliente(p.ncliente,p.tipo,p.tarjeta,p.prioridad);
        nuevoC.listaPedidos.insertarDer(introducir);
        insertar(nuevoC,raiz);
    }
}


bool ArbolB::esta(string nombre, NodoArbol *nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    if(!vacio()){
        if(nombre == nodo->cliente.nombre)return true;
        else if (nombre < nodo->cliente.nombre){
            if(nodo->izq !=NULL){
                return esta(nombre, nodo->izq);
            }
            else return false;
        }
        else if (nombre > nodo->cliente.nombre){
            if(nodo->der !=NULL){
                return esta(nombre, nodo->der);
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

// 3º entrega
void ArbolB::buscar(string nombre, NodoArbol *nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    if (!esta(nombre,nodo)){
        cout << "Este cliente no esta en el arbol" << endl;
    }
    else{
        if(nombre == nodo->cliente.nombre){
            nodo->cliente.verCliente();
        }
        else if (nombre < nodo->cliente.nombre) buscar(nombre,nodo->izq);
        else if (nombre > nodo->cliente.nombre) buscar(nombre, nodo->der);
    }
}

void ArbolB::mostrarPreorden(NodoArbol *nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    if (vacio()){
        cout << "El arbol esta vacio" << endl;
    }
    else{
        nodo->cliente.verCliente();
        cout << "-----------------" << endl;
        cout << "-----------------" << endl;
        if(nodo->izq !=NULL){
            mostrarPreorden(nodo->izq);
        }
        if(nodo->der !=NULL){
            mostrarPreorden(nodo->der);
        }
    }
}

int ArbolB::altura(NodoArbol *nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    if(nodo !=NULL){
        if(nodo->izq == NULL){
            if(nodo->der != NULL){
                return 1 + altura(nodo->der);
            }
            else return 0;
        }
        else if(nodo->der == NULL){
            if(nodo->izq !=NULL){
                return 1 + altura(nodo->izq);
            }
            else return 0;
        }
        else{
            return 1 + (altura(nodo->der)>altura(nodo->izq)?altura(nodo->der):altura(nodo->izq)); //se queda con la mayor de las alturas
        }
    }
    else return 0;

}

int ArbolB::cuentaProducto(string descripcion, NodoArbol *nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    int r = 0, i = 0,d = 0;
    if (vacio()){
        cout << "El arbol esta vacio" << endl;
    }
    if(!nodo->cliente.listaPedidos.es_vacia()){
         pnodo aux = nodo->cliente.listaPedidos.primero;
         while(aux != NULL){
            string ped = aux->ped.nombre;
            aux = aux->siguiente;
            if(strcmp(descripcion.c_str(),ped.c_str())== 0){
                r++;
            }
         }
    }
    if(nodo->izq !=NULL){
        i = cuentaProducto(descripcion,nodo->izq);
    }
    if(nodo->der !=NULL){
        d = cuentaProducto(descripcion,nodo->der);
    }
    return r+i+d;
}

void ArbolB::mostrarVip(NodoArbol *nodo){
    //A la hora de llamar a esta función para el árbol introducir la raiz de este
    //Como todo el arbol esta ordenado de forma: izq<raiz<der para mostrar los datos de forma ordenada se utiliza el inorden
    if(nodo->izq !=NULL){
        mostrarVip(nodo->izq);
    }
    if(nodo->cliente.prioridad == 2){
        cout<< nodo->cliente.nombre <<endl;
        cout<< nodo->cliente.tarjeta <<endl;
        cout<< nodo->cliente.tipo <<endl;
        cout<<"----------------------------------"<<endl;
    }
    if(nodo->der !=NULL){
        mostrarVip(nodo->der);
    }
}
