#ifndef BANCO_HPP
#define BANCO_HPP
#include "Cliente.hpp"
#include "Prestamo.hpp"
#include "Certificado.hpp"
#include <map>
class Banco
{
private:
    std::map<unsigned int, Cliente> clientes;
    std::map<unsigned int, Prestamo> prestamos;
    std::map<unsigned int, Certificado> certificados;

public:
    Banco(/* args */);
    ~Banco();
    Cliente buscarCliente(unsigned int id);
    void obtenerInfoPrestamos(unsigned int id);
    void obtenerInfoCertificados(unsigned int id);
};

#endif