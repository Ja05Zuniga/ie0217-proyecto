#include "Producto.hpp"
Producto::Producto(const std::string &nombre, const unsigned int &id) : nombre(nombre), id(id) {}
Producto::Producto(const std::string &nombre) : nombre(nombre) {}

void Producto::obtenerInfo() {}
void Producto::acreditar(const Dinero &monto) {}
void Producto::debitar(const Dinero &monto)
{
}
Producto::~Producto()
{
}

unsigned int Producto::generarId()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(NUM_PRESTAMOS, 999999999);
    id = distr(eng);
    return id;
}

unsigned int Producto::obtenerId() { return id; }