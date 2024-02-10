#include "Cliente.hpp"

Cliente::Cliente() {}

Cliente::Cliente(unsigned int userId, std::string nombre) : userId(userId), nombre(nombre)
{
}

Cliente::~Cliente()
{
}
void Cliente::obtenerInfo()
{
    std::cout << "Nombre: " << nombre << "\n"
              << "ID: " << userId << std::endl;
}
unsigned int Cliente::agregarPrestamo(Prestamo prestamo)
{
    unsigned int id = prestamo.generarId();
    prestamos[id] = prestamo;
    return id;
}

Prestamo Cliente::buscarPrestamo(const unsigned int id)
{
    return prestamos.at(id);
}

void Cliente::debitar() {}