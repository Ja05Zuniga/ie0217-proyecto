#ifndef TRANSACCION_HPP
#define TRANSACCION_HPP
#include "Producto.hpp"
#include "Dinero.hpp"
class Transaccion
{
private:
    unsigned int id;
    Producto *pagador;
    Producto *receptor;
    Dinero monto;

public:
    Transaccion(Producto *pagador, Producto *receptor, Dinero monto);
    Transaccion();
    ~Transaccion();
    unsigned int generarId();
    void operator()() const;
};

#endif