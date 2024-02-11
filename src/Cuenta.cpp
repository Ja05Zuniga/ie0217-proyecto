#include "Cuenta.hpp"
Cuenta::Cuenta(/* args */) : Producto("Cuenta")
{
}

Cuenta::Cuenta(const float &monto, Moneda moneda) : Producto("Cuenta"), ahorros(Dinero(monto, moneda)), moneda(moneda)
{
}

Cuenta::~Cuenta()
{
}

Estado Cuenta::obtenerEstado() { return estado; }

void Cuenta::obtenerInfo()
{
    std::cout << "Ahorros: " << ahorros.obtenerMonto() << "\n"
              << "Moneda: " << ahorros.obtenerMoneda() << std::endl;
}
void Cuenta::acreditar(const Dinero &monto)
{
    Moneda moneda_monto = monto.obtenerMoneda();
    if (moneda == moneda_monto)
    {
        std::cout << "holis";
        ahorros = ahorros + monto;
    }
}
void Cuenta::debitar(const Dinero &monto)
{
    if (moneda == monto.obtenerMoneda())
    {
        ahorros = ahorros - monto;
    }
}