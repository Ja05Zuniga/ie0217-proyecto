#ifndef DINERO_HPP
#define DINERO_HPP
#include <string>
#include <iostream>
const int TASA_COMPRA = 500;
const int TASA_VENTA = 500;
enum Moneda
{
    COLONES,
    DOLARES
};
class Dinero
{
protected:
    float tasaCompra = TASA_COMPRA;
    float tasaVenta = TASA_VENTA;
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
};

#endif