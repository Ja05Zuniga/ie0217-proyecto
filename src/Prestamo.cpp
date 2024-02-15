#include "Prestamo.hpp"

Prestamo::~Prestamo() {}

Prestamo::Prestamo() : Producto("Prestamo") {}

Prestamo::Prestamo(const TipoPrestamo &tipo, const unsigned int &cuotas, const float &tasaInteresAnual, const unsigned int &id) : Producto("Prestamo", id), tipo(tipo), cuotas(cuotas), tasaInteresAnual(tasaInteresAnual)
{
}

void Prestamo::obtenerInfo()
{
    std::string tipo_str;
    switch (tipo)
    {
    case 0:
        tipo_str = "Personal";
        break;
    case 1:
        tipo_str = "Prendario";
        break;
    case 2:
        tipo_str = "Hipotecario";

    default:
        break;
    }
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << id
              << std::setw(Constantes::COL_WIDTH) << std::left << tipo_str
              << std::setw(Constantes::COL_WIDTH) << std::left << cuotas
              << std::setw(Constantes::COL_WIDTH) << std::left << tasaInteresAnual
              << std::setw(Constantes::COL_WIDTH) << std::left << montoIncial << std::endl;
}

void Prestamo::obtenerInfoPersonal()
{
    std::string tipo_str;
    switch (tipo)
    {
    case 0:
        tipo_str = "Personal";
        break;
    case 1:
        tipo_str = "Prendario";
        break;
    case 2:
        tipo_str = "Hipotecario";

    default:
        break;
    }
    std::cout << "ID: " << id << "\n"
              << "Tipo de préstamo: " << tipo_str << "\n"
              << "Cuotas: " << cuotas << "\n"
              << "Monto de préstamo: " << montoIncial << "\n"
              << "Monto cancelado: " << montoPagado << "\n"
              << "Cuota actual: " << numCuota << "\n"
              << "Tasa de interés anual: " << tasaInteresAnual << std::endl;
}
void Prestamo::acreditar(const Dinero &monto)
{
    numCuota += 1;
}
void Prestamo::debitar(const Dinero &monto)
{
    montoIncial = monto;
    montoPagado = Dinero(0, monto.obtenerMoneda());
    numCuota = 0;
}

unsigned int Prestamo::abrir(const Dinero &dinero)
{
    unsigned int id = this->generarId();
    montoIncial = dinero;
    montoPagado = Dinero(0, dinero.obtenerMoneda());
    return id;
}