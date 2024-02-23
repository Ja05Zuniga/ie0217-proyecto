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

void Efectivo::verificarDebito(const Dinero &monto)
{
    solicitarPago();
    if (dinero.obtenerMonto() < monto.obtenerMonto())
    {
        throw EfectivoInsuficiente();
    }
}

void Efectivo::verificarCredito(const Dinero &monto) { return; }

const char *EfectivoInsuficiente::what() const noexcept
{
    return "Efectivo insuficiente!";
}