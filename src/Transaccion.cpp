#include "Transaccion.hpp"
Transaccion::Transaccion() {}
Transaccion::Transaccion(Producto *pagador, Producto *receptor, Dinero monto) : pagador(pagador), receptor(receptor), monto(monto)
{
}

void Transaccion::operator()() const
{
    receptor->acreditar(monto);
    pagador->debitar(monto);
}

Transaccion::~Transaccion()
{
}
unsigned int Transaccion::generarId()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(NUM_PRESTAMOS, 999999999);
    id = distr(eng);
    return id;
}