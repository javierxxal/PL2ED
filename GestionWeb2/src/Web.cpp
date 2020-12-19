#include "Web.h"

#include<fstream>
#include<string>
#include<cstdlib>

Web::Web()
{
    //ctor
}

Web::~Web()
{
    //dtor
}

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
// ERROR falta buscar una forma de saber a que tipo de sistema se añade.
void Web::incluirListaEnvios(Cola& c, int n){
    int contador=0;
    while(contador<n && !c.esVacia()){
        if(c.prim().erroneo){
            pilaErroneos.apilar(c.prim());
            c.desencolar();
        }
        else{
            listaEnviar1.insertarOrdenado(c.prim());
            contador++;
            c.desencolar();
        }
    }
}

void Web::pasarTiempo(){
    //Primero insertamos 3 pedidos correctos de usuarios registrados en listaEnviar
    incluirListaEnvios(colaReg,1);
    incluirListaEnvios(colaNR,1);
    incluirListaEnvios(colaReg,2);
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
    // Los tiemps t1 y t2 son los tiempos de preparación de cada pedido mientras que treal es el encargado de insertar nuevos pedidos a las listas.
    int t1, t2 = -1 , treal = 0;
    // El int caso se utiliza para saber que tipo de pedido introducir en las listas de envios
    int caso = 0;
    while((!listaEnviar1.es_vacia() || !listaEnviar2.es_vacia()) && continuar != 'N'){
        // Comprobamos que los tiempos de preparación t1 y t2 son correctos.
        if(!listaEnviar1.es_vacia() && t1<=0){
            t1 = listaEnviar1.prim().tiempo;
        }
        else if (listaEnviar1.es_vacia() && t1<=0){
                t1 = -1;
        }

        if(!listaEnviar2.es_vacia() && t2<=0){
            t2 = listaEnviar2.prim().tiempo;
        }
        else if (listaEnviar2.es_vacia() && t2<=0){
            t2 = -1;
        }

        //Preparamos los pedidos e incluimos 1 pedido cada 2 min
        while(!t1 == 0 &&  !t2==0){
            if(!(t1 == -1)){
                cout<<"El pedido "<<listaEnviar1.prim().nombre<<" esta preparandose, espere "<<t1<<" minutos."<<endl;
                t1--;
            }
            if(!(t2 ==-1)){
                cout<<"El pedido "<<listaEnviar2.prim().nombre<<" esta preparandose, espere "<<t2<<" minutos."<<endl;
                t2--;
            }
            treal++;
            system("pause");
            system("cls");
            //Cada 2 minutos introducimos un pedido nuevo
            if(treal%2==0){
                //Como tenemos que introducir 2 pedidos en las listas usamos un for para no solo hacer las 2 vueltas sino para asegurarnos que se introducen en la lista correcta
                for(int i=0; i<2; i++){
                    //Caso1
                    if(caso<3){
                        incluirListaEnvios(colaReg,1);
                    }
                    //Resto de casos
                    else{
                        //Caso 2
                        if(pilaErroneos.mostrarCima().prioridad !=0){
                            if(i==0){
                                    listaEnviar1.insertarOrdenado(pilaErroneos.mostrarCima());
                            }
                            else{
                                listaEnviar2.insertarOrdenado(pilaErroneos.mostrarCima());
                            }
                            pilaErroneos.desapilar();
                        }
                        //Caso 3
                        else if(!colaNR.esVacia()){
                            incluirListaEnvios(colaReg,1);
                        }
                        //Caso 4
                        else if(!pilaErroneos.esVacia()){
                            if(i==0){
                                listaEnviar1.insertarOrdenado(pilaErroneos.mostrarCima());
                            }
                            else{
                                listaEnviar2.insertarOrdenado(pilaErroneos.mostrarCima());
                            }
                            pilaErroneos.desapilar();
                        }
                    }
                }
                //Para evitar saltarnos casos hacemos la respectiva cuenta fuera del for
                if(caso<3){caso++;}
                else{caso=0;}
            }
        }
        // Si alguna de las condiciones se cumple significa que se ha terminado de preparar sus respectivos pedidos y solo hay que mostrar sus datos y enviarlos.
        if(t1 ==0){
            cout<<"El pedido:"<<listaEnviar1.prim().nombre <<"ha sido enviado."<<endl;
            cout<<"----------------------------------"<<endl;
            listaEnviar1.prim().toStr();
            cout<<"----------------------------------"<<endl;
            system("pause");
            system("cls");
            arbolCliente.insertarPedido(listaEnviar1.prim(),arbolCliente.raiz);
            // Falta añadir un cliente a un nuevo arbol de busqueda.
            listaEnviar1.resto();
        }
        if(t2 ==0){
            cout<<"El pedido:"<<listaEnviar1.prim().nombre <<"ha sido enviado."<<endl;
            cout<<"----------------------------------"<<endl;
            listaEnviar2.prim().toStr();
            cout<<"----------------------------------"<<endl;
            system("pause");
            system("cls");
            arbolCliente.insertarPedido(listaEnviar2.prim(),arbolCliente.raiz);
            // Falta añadir un cliente a un nuevo arbol de busqueda.
            listaEnviar2.resto();
        }
        if(!listaEnviar1.es_vacia() || !listaEnviar2.es_vacia()){
            //Después de realizar esto
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
    if(listaEnviar1.es_vacia() && listaEnviar2.es_vacia()){
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
