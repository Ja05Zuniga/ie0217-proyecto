#include "Dinero.hpp"
Dinero::Dinero() {}
Dinero::Dinero(const float &monto, Moneda moneda) : monto(monto), moneda(moneda)
{
}

Dinero::~Dinero()
{
}

void Dinero::mostrarInformacion()
{
    std::cout << "Monto: " << monto << "Moneda: " << std::endl;
}

Dinero Dinero::comprarDolares()
{
    float cantidad_dolares = monto / TASA_COMPRA;
    Dinero dinero(cantidad_dolares, DOLARES);
    monto = 0;
    return dinero;
}
Dinero Dinero::comprarDolares(const float &cantidad_colones)
{
    float cantidad_dolares = cantidad_colones / TASA_COMPRA;
    Dinero dinero(cantidad_dolares, DOLARES);
    monto -= cantidad_colones;
    return dinero;
}

Dinero Dinero::venderColones(const float &cantidad_dolares)
{
    float cantidad_colones = TASA_VENTA * cantidad_dolares;
    Dinero dinero(cantidad_colones, COLONES);
    monto -= cantidad_colones;
    return dinero;
}

Dinero Dinero::comprarColones(const float &cantidad_colones)
{
    float cantidad_dolares = TASA_COMPRA * cantidad_colones;
    Dinero dinero(cantidad_dolares, DOLARES);
    monto -= cantidad_dolares;
    return dinero;
}
Dinero Dinero::venderDolares(const float &cantidad_dolares)
{
    float cantidad_colones = cantidad_dolares / TASA_VENTA;
    Dinero dinero(cantidad_colones, COLONES);
    monto -= cantidad_colones;
    return dinero;
}
Dinero Dinero::venderDolares()
{
    float cantidad_colones = monto / TASA_VENTA;
    Dinero dinero(cantidad_colones, COLONES);
    monto = 0;
    return dinero;
}

Moneda Dinero::obtenerMoneda() const
{
    return this->moneda;
}

float Dinero::obtenerMonto() const
{
    return this->monto;
}

Dinero Dinero::operator+(const Dinero &otro)
{
    if (moneda == otro.obtenerMoneda())
    {
        Dinero resultado(monto + otro.obtenerMonto(), moneda);
        return resultado;
    }
    else
    {
        throw std::runtime_error("No se puede combinar dinero de monedas distintas");
    }
}

Dinero Dinero::operator-(const Dinero &otro)
{
    if (moneda == otro.obtenerMoneda())
    {
        Dinero resultado(monto - otro.obtenerMonto(), moneda);
        return resultado;
    }
    else
    {
        throw std::runtime_error("No se puede combinar dinero de monedas distintas");
    }
}