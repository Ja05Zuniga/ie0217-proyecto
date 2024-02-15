#ifndef CUENTA_HPP
#define CUENTA_HPP
#include <iostream>
#include <iomanip>
#include "constants.hpp"
#include "Producto.hpp"
#include "Dinero.hpp"
enum Estado
{
    ACTIVA,
    INACTIVA
};
class Cuenta : public Producto
{
private:
    Estado estado = ACTIVA;
    Dinero ahorros;
    Moneda moneda;

public:
    Cuenta(/* args */);
    Cuenta(const float &monto, Moneda moneda);
    ~Cuenta();
    void obtenerInfo() override;
    void acreditar(const Dinero &monto) override;
    void debitar(const Dinero &monto) override;
    Estado obtenerEstado();
};

#endif