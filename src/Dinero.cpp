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
    float cantidad_dolares = monto / Constantes::TASA_COMPRA;
    Dinero dinero(cantidad_dolares, DOLARES);
    monto = 0;
    return dinero;
}
Dinero Dinero::comprarDolares(const float &cantidad_colones)
{
    float cantidad_dolares = cantidad_colones / Constantes::TASA_COMPRA;
    Dinero dinero(cantidad_dolares, DOLARES);
    monto -= cantidad_colones;
    return dinero;
}

Dinero Dinero::venderColones(const float &cantidad_dolares)
{
    float cantidad_colones = Constantes::TASA_VENTA * cantidad_dolares;
    Dinero dinero(cantidad_colones, COLONES);
    monto -= cantidad_colones;
    return dinero;
}

Dinero Dinero::comprarColones(const float &cantidad_colones)
{
    float cantidad_dolares = Constantes::TASA_COMPRA * cantidad_colones;
    Dinero dinero(cantidad_dolares, DOLARES);
    monto -= cantidad_dolares;
    return dinero;
}
Dinero Dinero::venderDolares(const float &cantidad_dolares)
{
    float cantidad_colones = cantidad_dolares / Constantes::TASA_VENTA;
    Dinero dinero(cantidad_colones, COLONES);
    monto -= cantidad_colones;
    return dinero;
}
Dinero Dinero::venderDolares()
{
    float cantidad_colones = monto / Constantes::TASA_VENTA;
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

/**
 * @details Suma los montos si el tipo de moneda es el mismo, si no es 
 * así retorna una excepción
 * 
 * @param otro 
 * @return Dinero 
 */
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

/**
 * @details Suma los montos si el tipo de moneda es el mismo, si no es 
 * así retorna una excepción
 * 
 * @param otro 
 * @return Dinero 
 */
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

/**
 * @brief Define como castear la clase a tipo string para su impresión en pantalla
 * 
 * @param os 
 * @param obj 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Dinero &obj)
{
    std::string prefix;
    switch (obj.moneda)
    {
    case 0:
        prefix = "CRC";
        break;
    case 1:
        prefix = "USD";
        break;
    default:
        break;
    }
    os << prefix << obj.monto;
    return os;
}