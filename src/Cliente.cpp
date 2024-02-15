#include "Cliente.hpp"

Cliente::Cliente() {}

Cliente::Cliente(unsigned int userId, std::string nombre) : userId(userId), nombre(nombre)
{
    cuentaColones = Cuenta(0, COLONES);
    cuentaDolares = Cuenta(0, DOLARES);
}

Cliente::~Cliente()
{
}
void Cliente::obtenerInfo()
{
    std::cout << "Nombre: " << nombre << "\n"
              << "ID: " << userId << std::endl;
}
unsigned int Cliente::agregarPrestamo(Prestamo prestamo, const float &monto, Moneda moneda)
{
    Dinero dinero(monto, moneda);
    unsigned int id = prestamo.abrir(dinero);
    Cuenta *cuenta;
    switch (moneda)
    {
    case 0:
        cuenta = &cuentaColones;
        break;
    case 1:
        cuenta = &cuentaDolares;
        break;
    default:
        break;
    }
    Transaccion transaccion(&prestamo, cuenta, dinero);

    transaccion();
    prestamos[id] = prestamo;
    return id;
}

Prestamo Cliente::buscarPrestamo(const unsigned int &id)
{
    return prestamos.at(id);
}

void Cliente::obtenerInfoPrestamo(const unsigned int &id)
{
    Prestamo prestamo = this->buscarPrestamo(id);
    prestamo.obtenerInfoPersonal();
}
void Cliente::debitar() {}

void Cliente::obtenerInfoPrestamos()
{
    std::unordered_map<unsigned int, Prestamo>::iterator iter;
    for (iter = prestamos.begin(); iter != prestamos.end(); ++iter)
    {
        iter->second.obtenerInfo();
    }
}

void Cliente::obtenerEstadoCuenta(Moneda moneda)
{
    Cuenta *cuenta;
    switch (moneda)
    {
    case 0:
        cuenta = &cuentaColones;
        break;
    case 1:
        cuenta = &cuentaDolares;

    default:
        break;
    }
    cuenta->obtenerInfo();
}