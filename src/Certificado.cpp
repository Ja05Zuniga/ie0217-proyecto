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

void Certificado::acreditar(Dinero &monto) {}


void Certificado::debitar(Dinero &monto)
{

    dinero = monto;
}