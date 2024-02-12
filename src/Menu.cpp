#include "Menu.hpp"
// #include "Cliente.hpp"
// #include "Identidad.hpp"
// #include "agregar_cliente.hpp"
#include <string>
#include <iostream>


// Constructor de la clase
Menu::Menu() {}

// Destructor de la clase
// Menu::~Menu() {}


void Menu::iniciarMenu(){

    int cedula = obtenerIdentidad(); // Falta implentar el uso de la clase Cliente 

    // Condicion de verificacion de cliente
    if (!verificarCliente(cedula)){
        crearCliente(cedula);   // Se crea cliente en caso de que no exista
    }
    // El menu de opciones
    displayOpcionesPrincipales();
}

int Menu::obtenerIdentidad(){
    int num_cedula;
    std::cout << "Ingrese su numero de cedula: ";
    std::cin >> num_cedula;

    return num_cedula;
}

bool Menu::verificarCliente(int cedula){
    bool status = true;
    // Falta implementar codigo basado de la clase Identidad
    return status;
}

void Menu::crearCliente(int cedula){} // Falta implementar codigo basado de la clase AgregarCliente con cedula y nombre

void Menu::displayOpcionesPrincipales(){
    int opcion;
    std::cout << "\n--- Menu de opciones ---\n";
    std::cout << "1. Atencion al cliente\n";
    std::cout << "2. Informacion\n";
    std::cout << "3. Salir\n";

    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;

    // Casos
    switch(opcion){
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


void Menu::gestionarCliente() {
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
    switch(opcion){
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

void Menu::displayInformacion() {
    // Falta implementar logica de codigo basado para mostrar informacion general
}

void Menu::gestionarAhorros() {
    // Falta implementar logica de codigo basado ...
}

void Menu::realizarOperaciones() {
    // Falta implementar logica de codigo basado ...
}

void Menu::displayTipoPrestamos() {
    // Falta implementar logica de codigo basado ...
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

