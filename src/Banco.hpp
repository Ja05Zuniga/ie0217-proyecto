#ifndef BANCO_HPP
#define BANCO_HPP
#include "Cliente.hpp"
#include "Prestamo.hpp"
#include "Certificado.hpp"
#include <unordered_map>
#include <array>
class Banco
{
private:
    std::unordered_map<unsigned int, Cliente> clientes;
    std::array<Prestamo, 3> prestamos;
    std::unordered_map<unsigned int, Certificado> certificados;

public:
    Banco();
    ~Banco();
    Cliente buscarCliente(const unsigned int &id);
    Prestamo buscarPrestamo(const unsigned int &id);
    void obtenerInfoPrestamos(const unsigned int &id);
    void obtenerInfoCertificados(const unsigned int &id);
    Cliente agregarCliente(const unsigned int &id, const std::string &nombre);
};

#endif