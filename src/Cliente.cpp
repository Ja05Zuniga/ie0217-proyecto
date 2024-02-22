#include "Cliente.hpp"

Cliente::Cliente() {}

/**
 * @details El constructor automaticante asigna cuentas es dolares y en colones para
 * el usuario
 *
 * @param userId
 * @param nombre
 */
Cliente::Cliente(unsigned int userId, std::string nombre) : userId(userId), nombre(nombre)
{
    cuentaColones = Cuenta(0, COLONES, userId);
    cuentaDolares = Cuenta(0, DOLARES, userId);
}

Cliente::~Cliente()
{
}

void Cliente::obtenerInfo()
{
    std::cout << "Nombre: " << nombre << "\n"
              << "ID: " << userId << std::endl;
}

Cuenta *Cliente::obtenerCuenta(Moneda Moneda)
{
    switch (Moneda)
    {
    case COLONES:
        return &cuentaColones;
        break;
    case DOLARES:
        return &cuentaDolares;
        break;
    default:
        return nullptr;
        break;
    }
}

void Cliente::pagarPrestamo(Prestamo *prestamo, MetodoPago metodo)
{

    // Dinero cuotaMensual = prestamo->obtenerCuotaMensual();

    // Producto *pago = nullptr;
    // switch (metodo)
    // {
    // case CUENTA_COLONES:
    //     pago = &cuentaColones;
    //     break;
    // case CUENTA_DOLARES:
    //     pago = &cuentaDolares;
    //     break;
    // case EFECTIVO:
    //     Efectivo efectivo;
    //     efectivo.solicitarPago();
    //     pago = &efectivo;
    //     break;
    // }
    // Transaccion transaccion(pago, prestamo, cuotaMensual);
    // transaccion();
}

Prestamo Cliente::buscarPrestamo(const unsigned int id) const
{
    try
    {
        return prestamos.at(id);
    }
    catch (const std::out_of_range &)
    {
        throw std::out_of_range("No se pudo encontrar el préstamo.");
    }
}

/**
 * @details Itera sobre el contenedor préstamos para imprimir su información
 *
 */
void Cliente::obtenerInfoPrestamos()
{
    std::cout << "\nInformación de préstamos:\n";
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tipo"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Cuotas"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tasa de interés"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Moneda"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Monto" << std::endl;

    std::unordered_map<unsigned int, Prestamo>::iterator iter;
    for (iter = prestamos.begin(); iter != prestamos.end(); ++iter)
    {
        iter->second.obtenerInfo();
    }
}

void Cliente::obtenerEstadoCuenta(Moneda moneda)
{
    Cuenta cuenta;
    switch (moneda)
    {
    case COLONES:
        cuenta = cuentaColones;
        break;
    case DOLARES:
        cuenta = cuentaDolares;

    default:
        break;
    }
    cuenta.obtenerInfo();
}

std::istream &operator>>(std::istream &in, Cliente &cliente)
{
    char delimitador;
    in >> cliente.userId >> delimitador;
    std::getline(in, cliente.nombre);
    return in;
}

unsigned int Cliente::obtenerId() { return userId; }

Cliente::Cliente(const Cliente &otro) : userId(otro.userId), nombre(otro.nombre) {}