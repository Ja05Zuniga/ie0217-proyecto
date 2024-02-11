#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include <string>
#include <iostream>
#include <random>
#include "Dinero.hpp"

const int NUM_PRESTAMOS = 9;

class Producto
{
protected:
    unsigned int id;
    std::string nombre;

public:
    Producto(const std::string &nombre);
    Producto(const std::string &nombre, const unsigned int &id);
    virtual ~Producto();
    unsigned int generarId();
    unsigned int obtenerId();
    virtual void obtenerInfo();
    virtual void acreditar(const Dinero &monto);
    virtual void debitar(const Dinero &monto);
};

#endif