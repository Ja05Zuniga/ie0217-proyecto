#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <iostream>
#include "Prestamo.hpp"
#include <unordered_map>
class Cliente
{
private:
    unsigned int userId;
    std::string nombre;
    std::unordered_map<unsigned int, Prestamo> prestamos;

public:
    Cliente();
    Cliente(unsigned int userId, std::string nombre);
    ~Cliente();
    void obtenerInfo();
    unsigned int agregarPrestamo(Prestamo prestamos);
    Prestamo buscarPrestamo(const unsigned int id);
    void debitar();
};

#endif