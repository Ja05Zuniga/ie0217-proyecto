#include "MetodoPago.hpp"

std::istream &operator>>(std::istream &is, MetodoPago &metodo)
{
    int metodoInt;
    if (!(is >> metodoInt))
    {
        return is;
    }

    switch (metodoInt)
    {
    case 1:
        metodo = EFECTIVO;
        break;
    case 2:
        metodo = CUENTA_COLONES;
        break;
    case 3:
        metodo = CUENTA_DOLARES;
        break;
    default:
        is.setstate(std::ios::failbit);
        break;
    }

    return is;
}

MetodoPago solicitarMetodoPago()
{
    MetodoPago metodo;

    while (true)
    {
        std::cout << "Ingrese el método de pago: \n"
                  << "1. Efectivo\n"
                  << "2. Cuenta colones\n"
                  << "3. Cuenta dolares" << std::endl;
        std::cin >> metodo;
        if (std::cin.fail())
        {
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    return metodo;
}

MetodoPago solicitarMetodoRecepcion()
{
    MetodoPago metodo;

    while (true)
    {
        std::cout << "Ingrese cómo desea recibir el dinero: \n"
                  << "1. Efectivo\n"
                  << "2. Deposito a cuenta en colones\n"
                  << "3. Deposito a cuenta en dolares" << std::endl;
        std::cin >> metodo;
        if (std::cin.fail())
        {
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    return metodo;
}