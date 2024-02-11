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
    //    Prestamo prestamo = this->buscarPrestamo(id);
    //    std::string tipo_str;
    //    switch (prestamo.tipo)
    //    {
    //    case 0:
    //        tipo_str = "Personal";
    //        break;
    //    case 1:
    //        tipo_str = "Prendario";
    //        break;
    //    case 2:
    //        tipo_str = "Hipotecario";
    //
    //    default:
    //        break;
    //    }
    //    std::cout << "Tipo de préstamo: " << tipo_str << "\n"
    //              << "Número de cuotas: " << prestamo.cuotas << "\n"
    //              << "Tasa de interés anual: " << prestamo.tasaInteresAnual << std::endl
    //              << "\n"
    //              << "Monto: " << prestamo.montoIncial << "\n"
    //              << "Monto pagado: " << prestamo.montoPagado << "\n";
}
void Cliente::debitar() {}

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