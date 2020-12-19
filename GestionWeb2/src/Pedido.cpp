#include "Pedido.h"
#include "iostream"
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//Variables auxiliares para constructores
string VIP = "VIP";
string NVIP = "NVIP";
string NR ="NR";
Pedido::Pedido(){

}
Pedido::Pedido(string n, string c, string d , string tp , string tj, int t,bool err){
    nombre = n;
    ncliente = c;
    direccion = d;
    tipo = tp;
    tarjeta = tj;
    tiempo = t;
    erroneo = err;

    if(strcmp(VIP.c_str(),tipo.c_str()) == 0){
            prioridad = 2;

    }
    else if (strcmp(NVIP.c_str(),tipo.c_str()) == 0){
            prioridad = 1;
    }
    else if(strcmp(NR.c_str(),tipo.c_str()) == 0){
            prioridad = 0;
    }

}
Pedido::Pedido(string n,string d,int t){
    nombre = n;
    direccion = d;
    tiempo = t;
}
Pedido::Pedido(string datos)
{

    erroneo = false;                    //confiamos en que el pedido no es erroneo, y si encuentra alguna cosa lo cambia a true mas abajo en la funcion

    string n,c,d,tp,tj;
    int t,contador = 0;
    string str;

    size_t posicion = datos.find("//");
    str = datos.substr(0,posicion);
    n = str;
    datos.erase(0,posicion+2);              //registramos el primer campo del string y lo eliminamos de los datos

    while((contador < 5) && !datos.empty()){        //si el contador llega a 5 es que ya ha leido todos los campos
        posicion = datos.find("//");
        str = datos.substr(0,posicion);

        switch(contador){
            case(0): c = str; break;
            case(1): d = str; break;
            case(2): tp = str; break;
            case(3): tj = str;  break;
            case(4):
                try{                                            //try y catch por si se introduce un tiempo que no puede convertirse a entero
                    t = stoi(str);
                }
                catch(exception e){
                    cout << "Pedido erroneo: tiempo no válido" << endl;
                    t = (rand() % 10) + 1;                              //el tiempo se genera random si se ha introducido mal
                    erroneo = true;
                }
                break;

        }
        if(posicion == 4294967295){                                    //si la posicion es ese valor es porque ya no hay mas //
            datos.erase(0,strlen(datos.c_str()));
        }
        else{
            datos.erase(0,posicion+2);
        }
        contador++;
    }
    if (contador == 5){    //si el contador es 5 no hay errores y todo esta bien
        nombre = n;
        ncliente = c;
        direccion = d;
        tipo = tp;
        tarjeta = tj;
        tiempo = t;
    }
    else{                  //si no es que falta algun dato que se ha omitido, por lo que mira a ver cuantos datos se han leido
        erroneo = true;
        cout << "Pedido erroneo: faltan datos(completado del pedido automatico)" << endl;
        switch(contador){
        case(0):                        //si el contador es 0 es que solo se ha leido 1 dato
            nombre = n;
            ncliente = "No rellenado";
            direccion = "Calle no especificada";
            tipo = NR;;
            tarjeta = to_string((rand() % 100000000));      //la tarjeta y el tiempo se generan random si no se han introducido
            tiempo = (rand() % 10) + 1;
            break;
        case(1):
            nombre = n;
            ncliente = c;
            direccion = "Calle no especificada";
            tipo = NR;
            tarjeta = to_string((rand() % 100000000));
            tiempo = (rand() % 10) + 1;
            break;
        case(2):
            nombre = n;
            ncliente = c;
            direccion = d;
            tipo = NR;
            tarjeta = to_string((rand() % 100000000));
            tiempo = (rand() % 10) + 1;
            break;
        case(3):
            nombre = n;
            ncliente = c;
            direccion = d;
            tipo = tp;
            tarjeta = to_string((rand() % 100000000));
            tiempo = (rand() % 10) + 1;
            break;
        case(4):
            nombre = n;
            ncliente = c;
            direccion = d;
            tipo = tp;
            tarjeta = tj;
            tiempo = (rand() % 10) + 1;
            break;
        }
    }

    if(strcmp(VIP.c_str(),tipo.c_str()) == 0){                  // por ultimo, para asignarle la prioridad al producto, se compara su tipo con los strings VIP(2),NVIP(1),NR(0)
            prioridad = 2;

    }
    else if (strcmp(NVIP.c_str(),tipo.c_str()) == 0){
            prioridad = 1;
    }
    else if(strcmp(NR.c_str(),tipo.c_str()) == 0){
            prioridad = 0;
    }
    else{
        cout << "Pedido erroneo: tipo de cliente mal especificado(automatico NR)" << endl;          //si el tipo no coincide con ninguno de los tres valores se la asigna automaticamente NR y
        tipo = "NR";                                                                                //prioridad 0
        prioridad = 0;
        erroneo = true;

    }

}
Pedido::~Pedido()
{
    //dtor
}
string Pedido::getTipo(){
    return tipo;
}
int Pedido::getPrioridad(){
    return prioridad;
}

void Pedido::toStr(){
    cout << "Producto: " << nombre << endl;
    cout << "Nombre Cliente: " << ncliente << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Categoria: " << tipo << endl;
    cout << "Tiempo de preparacion: " << tiempo << " minuto(s)" << endl;
    cout << "Tarjeta de credito: " << tarjeta << endl;
    cout << "Numero de prioridad: " << prioridad << endl;
    string err;
    if(erroneo){
        err="SI";
    }
    else{
        err="NO";
    }
    cout<<"Erroneo: "<<err<<endl;
}
void Pedido::toStr2(){
    cout << "Producto: " << nombre << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Tiempo de preparacion: " << tiempo << " minuto(s)" << endl;
}

