#include "Efectivo.hpp"
Efectivo::Efectivo(/* args */) : Producto("Efectivo")
{
}

Efectivo::~Efectivo()
{
}

void Efectivo::obtenerInfo() {}

void Efectivo::acreditar(Dinero &monto)
{
}

void Efectivo::debitar(Dinero &monto)
{
    Moneda monedaPago = dinero.obtenerMoneda();
    if (monedaPago != monto.obtenerMoneda())
    {
        switch (monedaPago)
        {
        case COLONES:
            dinero = dinero.comprarDolares();
            break;
        case DOLARES:
            dinero = dinero.venderDolares();
        default:
            break;
        }
    }

    std::cout << "Cambio: " << dinero.obtenerMonto() - monto.obtenerMonto() << std::endl;
}

void Efectivo::solicitarPago()
{
    dinero.solicitarMonto();
    dinero.solicitarMoneda();
}

void Efectivo::verificarDebito(Dinero &monto)
{
    solicitarPago();

    if (dinero.obtenerMoneda() == monto.obtenerMoneda() && dinero.obtenerMonto() < monto.obtenerMonto())
    {
        throw EfectivoInsuficiente();
    }
    else if (dinero.obtenerMoneda() == DOLARES && dinero.venderDolares().obtenerMonto() < monto.obtenerMonto())
    {
        throw EfectivoInsuficiente();
    }
    else if (dinero.obtenerMoneda() == COLONES && dinero.comprarColones().obtenerMonto() < monto.obtenerMonto())
    {
        std::cout << dinero.comprarColones().obtenerMonto();
        throw EfectivoInsuficiente();
    }
    else
    {
        return;
    }
}

void Efectivo::verificarCredito(Dinero &monto) { return; }

const char *EfectivoInsuficiente::what() const noexcept
{
    return "Efectivo insuficiente!";
}