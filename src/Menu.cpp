#include "Menu.hpp"

// Constructor de la clase
Menu::Menu(Banco banco) : banco(banco) {}

// Destructor de la clase
// Menu::~Menu() {}

void Menu::iniciarMenu()
{

    int cedula = obtenerIdentidad(); // Falta implentar el uso de la clase Cliente
    try
    {
        cliente = banco.buscarCliente(cedula);
    }
    catch (const std::out_of_range &e)
    {
        std::string nombre;
        std::cout << "No se encontró el usuario." << '\n';
        std::cout << "Ingrese su nombre para ser registrado en el sistema: " << std::endl;
        std::cin >> nombre;

        cliente = banco.agregarCliente(cedula, nombre);
    }

    // El menu de opciones
    displayOpcionesPrincipales();
}

int Menu::obtenerIdentidad()
{
    int num_cedula;
    std::cout << "Ingrese su numero de cedula: ";
    std::cin >> num_cedula;

    return num_cedula;
}

bool Menu::verificarCliente(int cedula)
{
    bool status = true;
    // Falta implementar codigo basado de la clase Identidad
    return status;
}

void Menu::crearCliente(int cedula) {} // Falta implementar codigo basado de la clase AgregarCliente con cedula y nombre

void Menu::displayOpcionesPrincipales()
{
    int opcion;
    std::cout << "\n--- Menu de opciones ---\n";
    std::cout << "1. Atencion al cliente\n";
    std::cout << "2. Informacion\n";
    std::cout << "3. Salir\n";

    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;

    // Casos
    switch (opcion)
    {
    case 1: //  Atencion al cliente
        gestionarCliente();
        // Falta implementar codigo basado
        break;
    case 2: // Informacion
        displayInformacion();
        // Falta implementar codigo basado
        break;
    case 3: // Salir
        std::cout << "Saliendo del programa...\n";
        exit(0);
    default:
        std::cout << "Opcion no es valida. Intente de nuevo...\n";
    }
}

void Menu::gestionarCliente()
{
    // Falta implementar logica de codigo basado para manejar las operaciones de cliente
    // de ejecutarOperaciones() con el uso de Prestamo, Producto, etc
    int opcion;
    std::cout << "\n--- Menu de Atencion al Cliente ---\n";
    std::cout << "1. Tipos de Prestamos\n";
    std::cout << "2. Gestion de Ahorros\n";
    std::cout << "3. Operaciones\n";

    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;

    // Casos
    switch (opcion)
    {
    case 1: //  Tipos de Prestamos
        displayTipoPrestamos();
        // Falta implementar codigo basado ...
        break;
    case 2: // Gestion de Ahorros
        gestionarAhorros();
        // Falta implementar codigo basado
        break;
    case 3: // Operaciones
        realizarOperaciones();
    default:
        std::cout << "Opcion no es valida. Intente de nuevo...\n";
    }
}

/************************************
 * Metodos que faltan implentar
 *************************************/

void Menu::displayInformacion()
{
    int opcion;
    std::cout << "\n--- Menu de Información ---\n";
    std::cout << "1. Información general del usuario\n";
    std::cout << "2. Información de préstamo\n";
    std::cout << "3. Regresar\n";

    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;

    // Casos
    switch (opcion)
    {
    case 1:
        displayInformacionGeneral();
        break;
    case 2:
        displayInformacionPrestamo();
        break;
    case 3:
        displayOpcionesPrincipales();
    default:
        std::cout << "Opcion no es valida. Intente de nuevo...\n";
    }
}

void Menu::displayInformacionPrestamo()
{
    int id;
    std::cout << "Ingrese el ID del préstamo que desea consultar:\n";
    std::cin >> id;
    try
    {
        cliente.obtenerInfoPrestamo(id);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "No se encontró el préstamo con el ID ingresado.\n"
                  << '\n';
    }
    displayOpcionesPrincipales();
}

void Menu::displayInformacionGeneral()
{
    cliente.obtenerInfo();

    std::cout << "\nInformación de cuentas:\n";
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Estado"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Moneda"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Ahorros" << std::endl;
    cliente.obtenerEstadoCuenta(COLONES);
    cliente.obtenerEstadoCuenta(DOLARES);

    std::cout << "\nInformación de préstamos:\n";
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tipo"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Cuotas"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tasa de interés"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Moneda"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Monto" << std::endl;
    cliente.obtenerInfoPrestamos();
    
    displayOpcionesPrincipales();
    // Falta implementar logica de codigo basado para mostrar informacion general
}

void Menu::gestionarAhorros()
{
    // Falta implementar logica de codigo basado ...
}

void Menu::realizarOperaciones()
{
    // Falta implementar logica de codigo basado ...
}

void Menu::displayTipoPrestamos()
{
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tipo"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Cuotas"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tasa de interés anual" << std::endl;

    this->banco.obtenerInfoPrestamos(PERSONAL);
    this->banco.obtenerInfoPrestamos(PERSONAL + 1);
    this->banco.obtenerInfoPrestamos(PERSONAL + 2);
}
/**
 * @note Estos Metodos quiza no son necesarios implementarlos como metodos individuales
 *
 */
// void Menu::escogerMoneda() {
//     // Falta implementar logica de codigo basado ...
// }

// void Menu::displayMontoDesglosado() {
//     // Falta implementar logica de codigo basado ...
// }
