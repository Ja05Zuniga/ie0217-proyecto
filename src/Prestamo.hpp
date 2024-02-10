#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP
#include "Producto.hpp"

enum TipoPrestamo
{
    PERSONAL,
    PRENDARIO,
    HIPOTECARIO
};
class Prestamo : public Producto
{
private:
    TipoPrestamo tipo;
    unsigned int cuotas;
    float tasaInteresAnual;
    float montoIncial;
    float montoPagado;

public:
    Prestamo();
    Prestamo(const TipoPrestamo &tipo, const unsigned int &cuotas, const float &tasaInteresAnual, const unsigned int &id);
    ~Prestamo();
    void obtenerInfo() override;
    void acreditar() override;
};

#endif