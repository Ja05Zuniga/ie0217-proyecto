#include "Banco.hpp"

/**
 * @brief Construct a new Banco:: Banco object
 * @details Aquí se definen los préstamos ofrecidos por el usuario
 *
 */
Banco::Banco()
{
    prestamos[PERSONAL] = Prestamo(PERSONAL, 12, 5.5, PERSONAL);
    prestamos[PRENDARIO] = Prestamo(PRENDARIO, 12, 5.5, PRENDARIO);
    prestamos[HIPOTECARIO] = Prestamo(HIPOTECARIO, 12, 5.5, HIPOTECARIO);
}

Banco::~Banco()
{
}

Cliente Banco::buscarCliente(const unsigned int &id)
{
    return clientes.at(id);
}

Prestamo Banco::buscarPrestamo(const unsigned int &id)
{
    return prestamos.at(id);
}

/**
 * @details Llama el método obtenerInfo de la clase préstamo
 *
 * @param id
 */
void Banco::obtenerInfoPrestamos(const unsigned int &id)
{
    Prestamo prestamo = prestamos.at(id);
    prestamo.obtenerInfo();
}

/**
 * @details Llama el método obtenerInfo de la clase certificado
 *
 * @param id
 */
void Banco::obtenerInfoCertificados(const unsigned int &id)
{
    Certificado certificado = certificados.at(id);
    certificado.obtenerInfo();
}

Cliente Banco::agregarCliente(const unsigned int &id, const std::string &nombre)
{
    Cliente cliente(id, nombre);
    clientes[id] = cliente;
    return cliente;
}