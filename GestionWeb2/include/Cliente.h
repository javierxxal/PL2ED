#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    public:
        Cliente(string n, string t, string tj);
        ~Cliente();
        //Mirar para insertar un pedido raro a la lista
    private:
        string nombre;
        string tipo;
        string tarjeta;
        //Mirar lio listas para esto Apartado 4
};

#endif // CLIENTE_H
