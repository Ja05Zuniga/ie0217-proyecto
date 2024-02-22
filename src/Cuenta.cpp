#include "Cuenta.hpp"
Cuenta::Cuenta(/* args */) : Producto("Cuenta")
{
}

Cuenta::Cuenta(const float &monto, Moneda moneda, unsigned int id) : Producto(std::string("Cuenta") + std::string(moneda == COLONES ? " Colones" : " Dolares"), id), ahorros(Dinero(monto, moneda)), moneda(moneda)
{
}

Cuenta::~Cuenta()
{
}

bool Cuenta::obtenerEstado() { return estado; }

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
void Cuenta::acreditar(Dinero &monto)
{
    if (estado)
    {
        Moneda monedaMonto = monto.obtenerMoneda();
        if (moneda == monedaMonto)
        {
            ahorros = ahorros + monto;
        }
        else
        {
            switch (monedaMonto)
            {
            case COLONES:
                ahorros = ahorros + monto.comprarDolares();
                break;
            case DOLARES:
                ahorros = ahorros + monto.venderDolares();

            default:
                break;
            }
        }
    }
    else
    {
        throw CuentaInactiva();
    }
}

/**
 * @details actualiza los ahorros del usuario
 *
 * @param monto
 */
void Cuenta::debitar(Dinero &monto)
{
    if (estado)
    {
        Moneda monedaMonto = monto.obtenerMoneda();
        if (moneda == monedaMonto)
        {
            ahorros = ahorros - monto;
        }
        else
        {
            switch (monedaMonto)
            {
            case COLONES:
                ahorros = ahorros - monto.comprarColones();
                break;
            case DOLARES:
                ahorros = ahorros - monto.venderColones();

            default:
                break;
            }
        }
    }
    else
    {
        throw CuentaInactiva();
    }
}

const char *CuentaInactiva::what() const noexcept
{
    return "Cuenta inactiva!";
}