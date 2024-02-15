#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP
#include <iomanip>
#include "Producto.hpp"
#include "Dinero.hpp"
#include "constants.hpp"
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
    unsigned int numCuota;
    float tasaInteresAnual;
    Dinero montoIncial;
    Dinero montoPagado;

public:
    Prestamo();
    Prestamo(const TipoPrestamo &tipo, const unsigned int &cuotas, const float &tasaInteresAnual, const unsigned int &id);
    ~Prestamo();
    void obtenerInfo() override;
    void acreditar(const Dinero &monto) override;
    void debitar(const Dinero &monto) override;
    unsigned int abrir(const Dinero &dinero);
    void obtenerInfoPersonal();
};

#endif