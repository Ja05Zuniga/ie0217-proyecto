#include "Menu.hpp"

// Constructor de la clase
Menu::Menu(Banco banco) : banco(banco) {}

// Destructor de la clase
// Menu::~Menu() {}

void Menu::iniciarMenu()
{
    int cedula = obtenerIdentidad(); // Falta implentar el uso de la clase Cliente
    /*Si la cedula se ecuentra en la base de datos. Entonces crea el objeto cliente
    En el caso de que no. Pide el nombre del usuario, agrega la cedula y el nombre a la base de datos y
    crea el objeto cliente*/
    if (Identidad(std::to_string(cedula)).verificarCedulaEnCSV("cedulas.csv")){
        std::string nombreEncontrado = Identidad(std::to_string(cedula)).extraerNombre("cedulas.csv");
        cliente = banco.agregarCliente(cedula, nombreEncontrado);
        std::cout<<"Bienvenido"<< nombreEncontrado <<". Numero de cédula: " << cedula << std::endl;
        }

    else {
        std::cout << "No se encontró el usuario." << '\n'; //Etiqueta que la cedula ingresada no se encuentra en el .csv
        //Solicita el nombre del usuario
        std::string nombreValidacion;
        std::cout << "Ingrese su nombre de usuario: ";
        std::cin>> nombreValidacion;

        //nombre ya está validado y listo para ser añadido al .csv y crear el objeto
        std::string nombre = obtenerNombre(nombreValidacion);

        cliente = banco.agregarCliente(cedula, nombre); //Crea el objeto cliente

        std::cout<<"Bienvenido "<< nombre <<". Numero de cédula: " << cedula << std::endl; //Da la bienvenida

        std::string cedula_string = std::to_string(cedula); //Transforma cedula a string para poder ser agregado al .csv
        AgregarCliente(cedula_string, nombre).agregarA_CSV("cedulas.csv"); //Agrega cedula y nombre al .csv
        }

    // El menu de opciones
    displayOpcionesPrincipales();
}

std::string Menu::obtenerNombre(std::string nombre){
    while (true) {
            std::cout << "Ingrese su nombre de usuario: ";
            std::getline(std::cin, nombre);

            // Expresión regular para validar el nombre de usuario
            /*El nombre del usuario tiene que iniciar con mayuscula, el resto del nombre tiene que ir en minuscula.
            Tiene que ingresar como mínimo dos nombres: unNombre + unApellido
            Tiene que ingresar como máximo cuatro nombres: dosNombres + dosApellidos
            El nombre no puede poseer signos especiales
            Los nombres no pueden superar los 15 caracteres
            Los nombres no pueden tener menos de dos caracteres
            */
            std::regex regexNombre("^[A-Z][a-z]{1,14}(\\s[A-Z][a-z]{1,14}){1,3}(\\s[A-Z][a-z]{1,14})?$");
        try {
            if (!std::regex_match(nombre, regexNombre)) {
                throw std::invalid_argument("El formato del nombre de usuario no es válido.");
            }

            return nombre;

        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

}

int Menu::obtenerIdentidad(){
    /*Metodo que supervisa la entrada del numere de cedula.
    El número de cédula no puede contener letras.
    El número de cédula no puede empezar con cero.
    Debe ingresar un número de cédula de nueve dígitos.
    */
    std::string num_cedula;

    while (true) {
        try {
            std::cout << "Ingrese su número de cédula (deben ser nueve dígitos): ";
            std::string numCedulaStr;
            std::cin >> numCedulaStr;

            // Verificar si la entrada contiene letras en lugar de números
            for (char c : numCedulaStr) {
                if (!isdigit(c)) {
                    throw std::invalid_argument("Entrada no válida. El número de cédula no puede contener letras.");
                }}

            if (numCedulaStr[0] == '0') {
                throw std::invalid_argument("Entrada no válida. El número de cédula no puede empezar con cero.");
                }

            if (numCedulaStr.length() != 9) {
                throw std::invalid_argument("Entrada no válida. Debe ingresar un número de cédula de nueve dígitos.");
                }

            // Convertir la cadena a un entero
            int num_cedula = std::stoi(numCedulaStr);
            // Retornar el número de cédula convertido a int
            return num_cedula;
            
        } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
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
    std::cout << "3. Solicitar préstamo\n";
    std::cout << "4. Salir\n";

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
    case 3: // Solicitud de préstamo
        agregarPrestamo();
    case 4: // Salir
        std::cout << "Saliendo del programa...\n";
        exit(0);
    default:
        std::cout << "Opcion no es valida. Intente de nuevo...\n";
    }
}

void Menu::agregarPrestamo()
{
    int id;
    std::cout << "Ingrese el ID de préstamo solicitado: ";
    std::cin >> id;

    float monto;
    std::cout << "Ingrese el monto del préstamo: ";
    std::cin >> monto;

    int monedaInt;
    std::cout << "Ingrese la moneda del préstamo: 1) Colones, 2) Dolares: ";
    std::cin >> monedaInt;

    Moneda moneda;
    switch (monedaInt)
    {
    case 1:
        moneda = COLONES;
        break;
    case 2:
        moneda = DOLARES;
        break;

    default:
        break;
    }

    cliente.agregarPrestamo(banco.buscarPrestamo(id), monto, moneda);
    displayOpcionesPrincipales();
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
    std::cout << "4. Regresar\n";

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
    case 4: // Regresar
        displayOpcionesPrincipales();
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
    int opcion;
    std::cout << "\n--- Menu de Operaciones ---\n";
    std::cout << "1. Pagar préstamo\n";

    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;

    // Casos
    switch (opcion)
    {
    case 1:
        pagarPrestamo();
        break;
    default:
        std::cout << "Opcion no es valida. Intente de nuevo...\n";
    }
}

void Menu::pagarPrestamo()
{
    
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
    displayOpcionesPrincipales();
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
