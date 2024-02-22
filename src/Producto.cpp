/**
 * @file Producto.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Producto.hpp"
Producto::Producto(const std::string &nombre, const unsigned int &id) : nombre(nombre), id(id)
{
}
Producto::Producto(const std::string &nombre) : nombre(nombre) {}

void Producto::obtenerInfo() {}
void Producto::acreditar(Dinero &monto) {}
void Producto::debitar(Dinero &monto)
{
}
Producto::~Producto()
{
}

/**
 * @details Los números del 1 al 9 están reservados para préstamos ofrecidos por el banco
 * No hay problema si productos de clases distintas tienen el mismo ID ya que se almacenan
 * en mapas distintos. Por ejemplo, un préstamo y certificado pueden tener el mismo ID.
 */
void Producto::generarId()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(Constantes::NUM_PRESTAMOS, 999999999);
    id = distr(eng);
}

unsigned int Producto::obtenerId() { return id; }

std::ostream &operator<<(std::ostream &out, const Producto &producto)
{
    out << producto.nombre << "," << producto.id;
    return (out);
}

std::string Producto::obtenerNombre()
{
    return nombre;
}
