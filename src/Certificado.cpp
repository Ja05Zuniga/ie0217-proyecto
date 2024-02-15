#include "Certificado.hpp"

/**
 * @brief Construct a new Certificado:: Certificado object
 * 
 * @param id 
 */
Certificado::Certificado(const unsigned int id) : Producto("Certificado", id)
{
}

Certificado::~Certificado()
{
}

void Certificado::obtenerInfo() {}

void Certificado::acreditar(const Dinero &monto) {}


void Certificado::debitar(const Dinero &monto)
{

    dinero = monto;
}