#include "Certificado.hpp"
Certificado::Certificado() : Producto("Certificado") {}

/**
 * @brief Construct a new Certificado:: Certificado object
 *
 * @param id
 */

Certificado::Certificado(const Dinero &montoCertificado, const float &tasaInteresAnual, const unsigned int &id) : Producto("Certificado", id), montoCertificado(montoCertificado), tasaInteresAnual(tasaInteresAnual) {}
Certificado::~Certificado()
{
}

void Certificado::obtenerInfo() {}

void Certificado::acreditar(Dinero &monto) {}

void Certificado::debitar(Dinero &monto)
{

    montoCertificado = monto;
}

void Certificado::verificarDebito(const Dinero &monto)
{
    return;
}
void Certificado::verificarCredito(const Dinero &monto) { return; }