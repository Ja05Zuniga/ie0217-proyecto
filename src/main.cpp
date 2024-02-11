#include "Banco.hpp"
#include "Dinero.hpp"
#include <iostream>
int main(int argc, char const *argv[])
{
    Banco banco;
    banco.obtenerInfoPrestamos(0);
    banco.obtenerInfoPrestamos(1);
    banco.obtenerInfoPrestamos(2);
    try
    {
        banco.buscarCliente(1);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    Cliente juan = banco.agregarCliente(119090852, "juan");
    banco.buscarCliente(119090852).obtenerInfo();
    Dinero monto(100, DOLARES);
    std::cout << juan.agregarPrestamo(banco.buscarPrestamo(0), 100, DOLARES);
    try
    {
        juan.buscarPrestamo(1).obtenerInfo();
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }

    juan.obtenerEstadoCuenta(DOLARES);
    return 0;
}
