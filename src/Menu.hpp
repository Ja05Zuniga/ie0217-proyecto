#ifndef MENU_HPP
#define MENU_HPP
#include <string>

class Menu{

    public:
        // Constructor de la clase
        Menu();
        // Metodo iniciar el Menu
        void iniciarMenu();

    protected:
        // Metodo para obtener la identidad del usario
        int obtenerIdentidad();
        // Metodo para verificar si el cliente ya existe en el sistema
        bool verificarCliente(int cedula);
        // Metodo para crear un cliente
        void crearCliente(int cedula);
        // Metodo para mostrar el menu de opciones principales
        void displayOpcionesPrincipales();
        // Metodo para manejar las opciones del cliente
        void gestionarCliente();
        // Metodo para mostrar informacion general
        void displayInformacion();
        
        // Metodos que deben ir dentro de gestionarCliente() y displayInformacion()
        // Metodo para gestionar los Ahorros
        void gestionarAhorros();
        // Metodo para realizar la operacion ingresada por el usuario
        void realizarOperaciones();
        // Metodo para mostrar los tipos de prestamos disponibles
        void displayTipoPrestamos();

        // // Metodo para escoger el tipo de moneda para la transaccion
        // void escogerMoneda();
        // // Metodo para mostrar el monto y desglose de los prestamos
        // void displayMontoDesglosado();


};


#endif