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
    std::cout << "Tipo de préstamo: " << tipo_str << "\n"
              << "Número de cuotas: " << cuotas << "\n"
              << "Tasa de interés anual: " << tasaInteresAnual << std::endl;
}
void Prestamo::acreditar() {}