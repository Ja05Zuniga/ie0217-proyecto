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

void Certificado::acreditar(const Dinero &monto) {}

void Certificado::debitar(const Dinero &monto)
{

    montoCertificado = monto;
}