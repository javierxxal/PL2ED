#ifndef ARBOLB_H
#define ARBOLB_H
#include "Cliente.h"
#include "NodoArbol.h"
#include "string"
#include "string.h";

class ArbolB
{
    public:
        ArbolB();
        ArbolB(Cliente c);
        ~ArbolB();
        bool vacio();
        int altura();
        void insertar(Cliente c); // Metodo compare to
        bool esta(string nombre);
        Cliente buscar(string nombre);
        //3º entrega
        void mostrarPreorden();
        int cuentaProducto(string descripcion); //Convertir todo a mayus para evitar problemas
        void mostrarVip(); //Repetir metodo de preorden

    private:
    NodoArbol *raiz;
    string nombreRaiz;




};

#endif // ARBOLB_H
