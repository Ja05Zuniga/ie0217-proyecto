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
    float montoEfectivo = dinero.obtenerMonto();
    float montoPorPagar = monto.obtenerMonto();

    if (montoEfectivo < montoPorPagar)
    {
        std::cout << "Fondos insuficientes";
    }
    else
    {
        std::cout << "Cambio: " << montoEfectivo - montoPorPagar;
    }
}

void Efectivo::solicitarPago()
{
    dinero.solicitarMonto();
    dinero.solicitarMoneda();
}

void Efectivo::verificarDebito(const Dinero &monto)
{
    
}
void Efectivo::verificarCredito(const Dinero &monto) { return; }