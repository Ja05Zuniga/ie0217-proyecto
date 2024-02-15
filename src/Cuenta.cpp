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
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << id
              << std::setw(Constantes::COL_WIDTH) << std::left << estado
              << std::setw(Constantes::COL_WIDTH) << std::left << ahorros << std::endl;
}

/**
 * @details actualiza los ahorros del usuario
 * 
 * @param monto 
 */
void Cuenta::acreditar(const Dinero &monto)
{
    Moneda moneda_monto = monto.obtenerMoneda();
    if (moneda == moneda_monto)
    {
        ahorros = ahorros + monto;
    }
}

/**
 * @details actualiza los ahorros del usuario
 * 
 * @param monto 
 */
void Cuenta::debitar(const Dinero &monto)
{
    if (moneda == monto.obtenerMoneda())
    {
        ahorros = ahorros - monto;
    }
}