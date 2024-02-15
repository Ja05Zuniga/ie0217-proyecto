#ifndef DINERO_HPP
#define DINERO_HPP
#include <string>
#include <iostream>
#include "constants.hpp"
#include "Moneda.hpp"
class Dinero
{
protected:
    float tasaCompra = Constantes::TASA_COMPRA;
    float tasaVenta = Constantes::TASA_VENTA;
    float monto;
    Moneda moneda;

public:
    Dinero();
    Dinero(const float &monto, Moneda moneda);
    ~Dinero();
    void mostrarInformacion();
    Dinero venderColones(const float &cantidad);
    Dinero comprarDolares(const float &cantidad);
    Dinero comprarDolares();
    Dinero comprarColones(const float &cantidad);
    Dinero venderDolares(const float &cantidad);
    Dinero venderDolares();
    Moneda obtenerMoneda() const;
    float obtenerMonto() const;
    Dinero operator+(const Dinero &otro);
    Dinero operator-(const Dinero &otro);
    friend std::ostream& operator<<(std::ostream &os, const Dinero &obj);
};

#endif