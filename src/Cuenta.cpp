#include "Cuenta.hpp"
Cuenta::Cuenta(/* args */) : Producto("Cuenta")
{
}
Cuenta::Cuenta(const Cuenta &otro) : Producto(std::string("Cuenta") + std::string(otro.ahorros.obtenerMoneda() == COLONES ? " Colones" : " Dolares"), otro.id), estado(otro.estado), ahorros(otro.ahorros), moneda(otro.ahorros.obtenerMoneda()) {}

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
              << std::setw(Constantes::COL_WIDTH) << std::left << ahorros.obtenerMoneda() << ahorros.obtenerMonto() << std::endl;
}

/**
 * @details actualiza los ahorros del usuario
 *
 * @param monto
 */
void Cuenta::acreditar(Dinero &monto)
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

std::istream &operator>>(std::istream &in, Cuenta &cuenta)
{
    char delimitador;
    in >> cuenta.id >> delimitador >> cuenta.estado >> delimitador >> cuenta.ahorros;

    return in;
}

std::ostream &operator<<(std::ostream &os, Cuenta &cuenta)
{
    // char delimitador = ',';
    // os << prestamo.idDueno << delimitador << prestamo.id << delimitador << prestamo.tipo << delimitador << prestamo.cuotas << delimitador << prestamo.tasaInteresAnual << delimitador << prestamo.montoInicial << delimitador << prestamo.numCuota;
    // return os;
}

/**
 * @details actualiza los ahorros del usuario
 *
 * @param monto
 */
void Cuenta::debitar(Dinero &monto)
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

void Cuenta::cambiarEstado(bool nuevoEstado) { estado = nuevoEstado; }

const char *CuentaInactiva::what() const noexcept
{
    return "Cuenta inactiva!";
}

const char *FondosInsuficientes::what() const noexcept
{
    return "Fondos insuficientes!";
}

void Cuenta::verificarDebito(Dinero &monto)
{

    if (!estado)
    {
        throw CuentaInactiva();
    }
    if (moneda == monto.obtenerMoneda())
    {
        if (ahorros.obtenerMonto() < monto.obtenerMonto())
        {
            throw FondosInsuficientes();
        }
    }
    else
    {

        if (moneda == COLONES && ahorros.obtenerMonto() < monto.venderColones().obtenerMonto())
        {
            return;
        }
        else if (moneda == DOLARES && ahorros.obtenerMonto() < monto.comprarColones().obtenerMonto())
        {
            return;
        }
    }
}

void Cuenta::verificarCredito(Dinero &monto)
{
    if (!estado)
    {
        throw CuentaInactiva();
    }
}