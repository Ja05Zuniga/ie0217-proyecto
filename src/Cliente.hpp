#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <iostream>
#include <unordered_map>
#include "Prestamo.hpp"
#include "Dinero.hpp"
#include "Transaccion.hpp"
#include "Cuenta.hpp"

class Cliente
{
private:
    unsigned int userId;
    std::string nombre;
    std::unordered_map<unsigned int, Prestamo> prestamos;
    Cuenta cuentaColones;
    Cuenta cuentaDolares;

public:
    Cliente();
    Cliente(unsigned int userId, std::string nombre);
    ~Cliente();
    void obtenerInfo();
    unsigned int agregarPrestamo(Prestamo prestamos, const float &monto, Moneda moneda);
    Prestamo buscarPrestamo(const unsigned int &id);
    void obtenerInfoPrestamo(const unsigned int &id);
    void obtenerInfoPrestamos();
    void obtenerEstadoCuenta(Moneda moneda);
    void debitar();
};

#endif