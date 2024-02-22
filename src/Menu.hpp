#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <iostream>
#include <regex>
#include <stdexcept>
#include "Cliente.hpp"
#include "identidad.hpp"
#include "agregar_cliente.hpp"
#include "Banco.hpp"

/**
 * @class Menu
 * @brief Clase que gestiona el menu interactivo del sistema bancario.
 *
 * Esta clase se encarga de ser la interfaz del usuario del sistema bancario,
 * realiza la identificacion de usuario, verifica la existencia del cliente y 
 * brinda multiples funcionalidades del sistema como la informacion de la cuentas
 * del usuario, manejo de prestamos y distintas operaciones o transacciones bancarias.
 */
class Menu
{

public:
    /**
     * @brief Constructor para la clase Menu.
     * @param banco Instancia de la clase Banco asociado a este menu.
     */
    Menu(Banco banco);

    /**
     * @brief Inicia el menu interactivo para el usuario.
     *
     * Este metodo arranca el flujo del menu principal permitiendo al usuario realizar
     * diferentes acciones disponibles en el sistema.
     */
    void iniciarMenu();

protected:
    // Metodo para obtener la identidad del usario
    int obtenerIdentidad();
    //Metodo que valida el nombre de usuario.
    std::string obtenerNombre();
    //Metodo que maneja las excepciones de los valores ingresados de un solo número
    std::string obtenerOpcion();
    // Metodo para verificar si el cliente ya existe en el sistema
    bool verificarCliente(int cedula);
    // Metodo para crear un cliente
    void crearCliente(int cedula);
    // Metodo para mostrar el menu de opciones principales
    void displayOpcionesPrincipales();
    // Metodo para manejar las opciones del cliente
    void gestionarCliente();
    // Metodo para mostrar el submenu de la categoria de Informacion
    void displayInformacion();
    // Metodo para mostrar informacion general
    void displayInformacionGeneral();
    // Metodo para mostrar informacion de prestamos
    void displayInformacionPrestamo();
    // Metodo para
    void agregarPrestamo();
    // Metodo para
    void pagarPrestamo();
    // Metodos que deben ir dentro de gestionarCliente() y displayInformacion()
    // Metodo para gestionar los Ahorros
    void gestionarAhorros();
    // Metodo para realizar la operacion ingresada por el usuario
    void realizarOperaciones();
    // Metodo para mostrar los tipos de prestamos disponibles
    void displayTipoPrestamos();


private:
    // Instancia de la clase Banco relacionada al menu
    Banco banco;
    // Instancia de la clase Cliente relacionada al Menu
    Cliente cliente;
};

#endif