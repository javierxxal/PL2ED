#include "Web.h"

#include<fstream>
#include<string>
#include<cstdlib>

Web::Web()
{
    //Creamos un cliente centinela encargado de dividir los clientes alfabeticamente
    Cliente cli = Cliente("Nnnnnnn","123441231","5252523425",0);
    arbolCliente.insertar(cli,arbolCliente.raiz);
}

Web::~Web()
{
    //dtor
}
// variables globales
// El int caso se utiliza para saber que tipo de pedido introducir en las listas de envios
//El int orden tiene la función de contar cuantos productos han sido introducidos para poder ser divididos en las dos listas de envios.
//Cuando orden es par, introduce pedidos en la lista1 y cuando es impar lo hace en la 2
int orden=0 , caso = 0;
void Web::introducirPedido(Pedido p){
    if(p.prioridad == 2 || p.prioridad == 1){
        colaReg.encolar(p);
    }
    else{
        colaNR.encolar(p);
    }
}


int Web::introducirTxt(){
    ifstream fe("Pedidos.txt");
    string str;
    int contador = 0;
    while(!fe.eof()){
        getline(fe,str);
        if(!str.empty()){
            Pedido p = Pedido(str);
            introducirPedido(p);
            contador++;
        }
    }
    fe.close();
    return contador;

}

int Web::incluirListaEnvios(Cola& c, int n,int cont){
    int contador=0;
    while(contador<n && !c.esVacia()){
        if(c.prim().erroneo){
            pilaErroneos.apilar(c.prim());
            c.desencolar();
        }
        else{
            //Utilizamos el int contador de pasarTiempo para dividir los productos introducidos a las listas
            if (cont%2 == 0){
                listaEnviar1.insertarOrdenado(c.prim());
            }
            else {
                listaEnviar2.insertarOrdenado(c.prim());
            }
            c.desencolar();
            cont++;
            contador++;
        }
    }
    return cont;
}

void Web::insertarWeb(){
    if (colaNR.esVacia() && colaReg.esVacia() && pilaErroneos.esVacia()){
        cout << "Han pasado dos minutos pero no se ha añadido ningun pedido nuevo, ya que no quedan mas pedidos que añadir." << endl;
    }
    else{
        //Como tenemos que introducir 2 pedidos en las listas usamos un for
        for(int i=0; i<2; i++){
                //Caso1
                if(caso<3 && !colaReg.esVacia()){
                    orden = incluirListaEnvios(colaReg,1,orden);
                    caso++;
                }
                //Resto de casos
                else{
                    //Caso 2
                    if(!pilaErroneos.esVacia() && pilaErroneos.mostrarCima().prioridad !=0){
                        if(orden%2 == 0){
                            listaEnviar1.insertarOrdenado(pilaErroneos.mostrarCima());
                            orden++;
                        }
                        else{
                            listaEnviar2.insertarOrdenado(pilaErroneos.mostrarCima());
                            orden++;
                        }
                        pilaErroneos.desapilar();
                    }
                    //Caso 3
                    else if(!colaNR.esVacia()){
                        orden = incluirListaEnvios(colaNR,1,orden);
                    }
                    //Caso 4
                    else if(!pilaErroneos.esVacia()){
                        if(orden%2 == 0){
                            listaEnviar1.insertarOrdenado(pilaErroneos.mostrarCima());
                        }
                        else{
                            listaEnviar2.insertarOrdenado(pilaErroneos.mostrarCima());
                        }
                        orden++;
                        pilaErroneos.desapilar();
                    }
                    caso = 0;
                }
        }
        //despues de insertarse los dos pedidos se muestran las EEDD del sistema
        cout<<"Han pasado 2 minutos y se han introducido dos pedidos mas:\n";
        mostrarColas();
        system("pause");
        system("cls");
        mostrarLista();
        system("pause");
        system("cls");
        mostrarPila();
        system("pause");
        system("cls");

    }
}

void Web::pasarTiempo(){
    //Primero insertamos 3 pedidos correctos de usuarios registrados y otro de cliente no registrado
    orden = incluirListaEnvios(colaReg,3,0);
    orden = incluirListaEnvios(colaNR,1,orden);
    cout<<"Estas son las estructuras de datos del sistema web:\n";
    mostrarColas();
    system("pause");
    system("cls");
    mostrarLista();
    system("pause");
    system("cls");
    mostrarPila();
    system("pause");
    system("cls");
    // Continuar sirve para que el usuario pare el simulador después  de cada pedido.
    char continuar = 'Y';
    // treal es el encargado de insertar nuevos pedidos a las listas cada 2 minutos.
    int treal = 0;
    while((!webVacia()) && continuar != 'N'){
        //Preparamos los pedidos e incluimos 1 pedido cada 2 min
        //Tenemos 3 casos el primero de ellos es cuando ninguna de las dos listas esta vacia
        if(!listaEnviar1.es_vacia()&&!listaEnviar2.es_vacia()){
            while(listaEnviar1.prim().preparacion != 0 && listaEnviar2.prim().preparacion != 0){
                if(listaEnviar1.prim().preparacion != 0){
                    cout<<"El pedido "<<listaEnviar1.prim().nombre<<" esta preparandose, espere "<<listaEnviar1.prim().preparacion<<" minutos."<<endl;
                    listaEnviar1.prim().restarPreparacion();
                }
                if(listaEnviar2.prim().preparacion != 0){
                    cout<<"El pedido "<<listaEnviar2.prim().nombre<<" esta preparandose, espere "<<listaEnviar2.prim().preparacion<<" minutos."<<endl;
                    listaEnviar2.prim().restarPreparacion();
                }
                treal++;
                system("pause");
                system("cls");
                //Cada 2 minutos introducimos un pedido nuevo
                if(treal%2==0){
                        insertarWeb();
                }
            }

        }
        //Segundo caso la lista Enviar 2 es vacia pero la lista Enviar 1 NO
        else if (!listaEnviar1.es_vacia()){
            while(listaEnviar1.prim().preparacion !=0){

                if(listaEnviar1.prim().preparacion != 0){
                    cout<<"El pedido "<<listaEnviar1.prim().nombre<<" esta preparandose, espere "<<listaEnviar1.prim().preparacion<<" minutos."<<endl;
                    listaEnviar1.prim().restarPreparacion();
                }
                treal++;
                system("pause");
                system("cls");

                if(treal%2==0){
                    insertarWeb();
                }
            }

        }
        //Tercer caso la lista Enviar 1 es vauca pero la lista Enviar 2 NO
        //si las dos fueran vacias no entraria en el bucle, por lo que podemos poner else
        else{
            while(listaEnviar2.prim().preparacion !=0){

                if(listaEnviar2.prim().preparacion != 0){
                    cout<<"El pedido "<<listaEnviar2.prim().nombre<<" esta preparandose, espere "<<listaEnviar2.prim().preparacion<<" minutos."<<endl;
                    listaEnviar2.prim().restarPreparacion();
                }
                treal++;
                system("pause");
                system("cls");

                if(treal%2==0){
                    insertarWeb();
                }
            }
        }
        // Si alguna de las condiciones se cumple significa que se ha terminado de preparar sus respectivos pedidos y solo hay que mostrar sus datos y enviarlos.
        if( !listaEnviar1.es_vacia() && listaEnviar1.prim().preparacion == 0){
            cout<<"El pedido: "<<listaEnviar1.prim().nombre <<" ha sido enviado."<<endl;
            cout<<"----------------------------------"<<endl;
            listaEnviar1.prim().toStr();
            cout<<"----------------------------------"<<endl;
            system("pause");
            system("cls");
            arbolCliente.insertarPedido(listaEnviar1.prim(),arbolCliente.raiz);
            listaEnviar1.resto();
        }
        if( !listaEnviar2.es_vacia() && listaEnviar2.prim().preparacion == 0){
            cout<<"El pedido: "<<listaEnviar2.prim().nombre <<" ha sido enviado."<<endl;
            cout<<"----------------------------------"<<endl;
            listaEnviar2.prim().toStr();
            cout<<"----------------------------------"<<endl;
            system("pause");
            system("cls");
            arbolCliente.insertarPedido(listaEnviar2.prim(),arbolCliente.raiz);
            listaEnviar2.resto();
        }
        if(!listaEnviar1.es_vacia() || !listaEnviar2.es_vacia()){
            //Después de realizar esto preguntamos al usuario si desea continuar con el simulador
            cout<<"Quiere continuar al siguiente pedido?(Y:Si,N:No):";
            cin>>continuar;
            if(continuar=='n'){
                continuar='N';
            }
            else{
                continuar='Y';
            }
        }
    }
    if(webVacia()){
        cout<<"Todos los pedidos introducidos del sistema han sido enviados exitosamente."<<endl;
    }
    else{
       cout<<"Se ha parado el procesado de pedidos, aunque hay pedidos pendientes de envío."<<endl;
    }
}
void Web::mostrarColas(){
    cout << "Cola de Registrados:\n";
    colaReg.verCola();
    cout << "\nCola de No Registrados\n";
    colaNR.verCola();
    cout<<"\n";
}
void Web::mostrarPila(){
    cout<<"Pila erroneos:\n";
    pilaErroneos.verPila();
    cout<<"\n";
}
void Web::mostrarLista(){
    cout<<"Lista enviar 1:\n";
    listaEnviar1.verLista();
    cout<<"\n";

    cout<<"Lista enviar 2:\n";
    listaEnviar2.verLista();
    cout<<"\n";

}
bool Web::webVacia(){
    return pilaErroneos.esVacia() && colaReg.esVacia() && colaNR.esVacia() && listaEnviar1.es_vacia() && listaEnviar2.es_vacia();
}
void Web::buscarCliente(string nombre){
    arbolCliente.buscar(nombre,arbolCliente.raiz);
}
void Web::alturaArbol(){
    int altura = arbolCliente.altura(arbolCliente.raiz);
    cout << "La altura del arbol es de: " << altura << endl;
}
void Web::verPreorden(){
    arbolCliente.mostrarPreorden(arbolCliente.raiz);
}
void Web::cuentaProducto(string desc){
    int cont = arbolCliente.cuentaProducto(desc,arbolCliente.raiz);
    cout << "Se han realizado " << cont << " pedidos con esa descripcion." << endl;
}
void Web::mostrarVip(){
    arbolCliente.mostrarVip(arbolCliente.raiz);
}
