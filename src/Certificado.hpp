#ifndef CERTIFICADO_HPP
#define CERTIFICADO_HPP
#include "Producto.hpp"

class Certificado : public Producto
{
private:
    /* data */
public:
    Certificado(const unsigned int id);
    ~Certificado();
    void obtenerInfo() override;
    void acreditar(const Dinero &monto) override;
    void debitar(const Dinero &monto) override;
};

#endif