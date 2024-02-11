#include "Banco.hpp"
Banco::Banco()
{
    prestamos[0] = Prestamo(PERSONAL, 12, 5.5, 1);
    prestamos[1] = Prestamo(PRENDARIO, 12, 5.5, 2);
    prestamos[2] = Prestamo(HIPOTECARIO, 12, 5.5, 3);
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

void Banco::obtenerInfoPrestamos(const unsigned int &id)
{
    Prestamo prestamo = prestamos.at(id);
    prestamo.obtenerInfo();
}

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