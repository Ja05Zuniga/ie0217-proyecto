#include "Menu.hpp"

// Constructor de la clase
Menu::Menu(Banco banco) : banco(banco) {}

// Destructor de la clase
// Menu::~Menu() {}

//Manejo de excepciones completa
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
        
        //nombre ya está validado y listo para ser añadido al .csv y crear el objeto
        std::string nombre = obtenerNombre();

        cliente = banco.agregarCliente(cedula, nombre); //Crea el objeto cliente

        std::cout<<"Bienvenido "<< nombre <<". Numero de cédula: " << cedula << std::endl; //Da la bienvenida

        std::string cedula_string = std::to_string(cedula); //Transforma cedula a string para poder ser agregado al .csv
        AgregarCliente(cedula_string, nombre).agregarA_CSV("cedulas.csv"); //Agrega cedula y nombre al .csv
        }

    // El menu de opciones
    displayOpcionesPrincipales();
}

//Manejo de excepciones incompleta. No acepta las tildes y ñ.
std::string Menu::obtenerNombre(){
    std::string nombre;
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
            std::regex regexNombre("^[A-Za-zÁÉÍÓÚÜÑáéíóúüñ]+(?: [A-Za-zÁÉÍÓÚÜÑáéíóúüñ]+){1,4}$");
        try{
            if (nombre.empty()) {
                    throw std::invalid_argument("Error: No se ha ingresado ninguna opción");
            }
            if (!std::regex_match(nombre, regexNombre)) {
                throw std::invalid_argument("El formato del nombre de usuario no es válido.");
            }

            return nombre;

        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;

        }
    }

}

//Manejo de excepciones completa
int Menu::obtenerIdentidad(){
    /*Metodo que supervisa la entrada del numere de cedula.
    El número de cédula no puede contener letras.
    El número de cédula no puede empezar con cero.
    Debe ingresar un número de cédula de nueve dígitos.
    */
    std::string numCedulaStr;

    while (true) {
        try {
            std::cout << "Ingrese su número de cédula (deben ser nueve dígitos): ";
            std::getline(std::cin, numCedulaStr);
            //Para el caso de que el usuario ingrese solo enter.
            if (numCedulaStr.empty()) {
                throw std::invalid_argument("Error: No se ha ingresado ninguna opción");
            }

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

//Manejo de excepciones completa
void Menu::displayOpcionesPrincipales()
{
    std::string menuOpciones = 
        "\n--- Menu de opciones ---\n"
        "1. Atencion al cliente\n"
        "2. Informacion\n"
        "3. Solicitar préstamo\n"
        "4. Salir\n";

    while(true){
        std::cout<<menuOpciones;
        std ::string opcion = obtenerOpcion();
        int opcionInt = std::stoi(opcion);
            try{
                // Casos
                switch (opcionInt) //Pasamos opcion a tipo int
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
                    std::cout << "Opcion fuera de rango. Intente de nuevo...\n";
                }       
            }catch(const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
                } 
        }
}

std::string Menu::obtenerOpcion(){
    /*Este metodo se encarga de manejar las excepciones donde se tiene que ingresar un solo valor tipo int
    Return: un valor tipo string -> Cuidado
    */
    std ::string opcion;

    while(true) {
        try {
            // Solicitar la opción al usuario
            std::cout << "opción: ";
            std::getline(std::cin, opcion);

            // Verificar si la opción es un entero
            for (char c : opcion) {
                if (!std::isdigit(c)) {
                    throw std::invalid_argument("Error: No se permiten letras");
                }
            }

            //Verifica que se haya ingresada una opción
            if (opcion.empty()) {
                throw std::invalid_argument("Error: No se ha ingresado ninguna opción");
            }

            std::cout << "La opción ingresada fue: " << opcion << std::endl;
            return opcion;

        } catch(const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            }
        }
}

//Manejo de excepciones completa
void Menu::agregarPrestamo()
{
    std::string id/*int*/; 
    std::string monedaInt/*int*/; 
    std::string monto/*float*/; 
    
    int idInt;
    float montoFloat;

    Moneda moneda;

    bool terminar = false;
    while (!terminar) {
    try {
        std::cout << "Ingrese el ID del préstamo solicitado\n";
        id = obtenerOpcion();
        idInt = std::stoi(id);

        while (idInt > 3 || idInt < 1) {
            std::cerr << "Error. El ID debe ser un valor entre 1 y 3. Intente de nuevo.\n";
            std::cout << "Ingrese el ID del préstamo solicitado\n";
            id = obtenerOpcion();
            idInt = std::stoi(id);
        }

        std::cout << "Ingrese el monto del préstamo\n";
        monto = obtenerOpcion(); //monto es string
        montoFloat = std::stof(monto);

        std::cout << "Ingrese la moneda del préstamo: 1) Colones, 2) Dolares\n";
        monedaInt = obtenerOpcion();
        int monedaTransformada = std::stoi(monedaInt);

        while (monedaTransformada > 2 || monedaTransformada < 1) {
            std::cerr << "Error. La moneda debe ser 1 (Colones) o 2 (Dolares). Intente de nuevo.\n";
            std::cout << "Ingrese la moneda del préstamo: 1) Colones, 2) Dolares\n";
            monedaInt = obtenerOpcion();
            monedaTransformada = std::stoi(monedaInt);
        }

        // Asignación de moneda después de verificar que es válida
        switch (monedaTransformada) {
            case 1:
                moneda = COLONES;
                break;
            case 2:
                moneda = DOLARES;
                break;
        }

        terminar = true; // Establece terminar a verdadero si todos los valores son válidos
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}
    cliente.agregarPrestamo(banco.buscarPrestamo(idInt), montoFloat, moneda);
    displayOpcionesPrincipales();

}

//Manejo de excepciones completas
void Menu::gestionarCliente()
{
    // Falta implementar logica de codigo basado para manejar las operaciones de cliente
    // de ejecutarOperaciones() con el uso de Prestamo, Producto, etc
    std::string opciones =
        "\n--- Menu de Atencion al Cliente ---\n"
        "1. Tipos de Prestamos\n"
        "2. Gestion de Ahorros\n"
        "3. Operaciones\n"
        "4. Regresar\n";
    while (true){
        try{
            std::string opcion = obtenerOpcion();
            int opcionInt = std::stoi(opcion);

            // Casos
            switch (opcionInt)
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

        }catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

   
}

/************************************
 * Metodos que faltan implentar
 *************************************/

//Manejo de excepciones completa
void Menu::displayInformacion()
{   
    std::string opciones = 
                "\n--- Menu de Información ---\n"
                "1. Información general del usuario\n"
                "2. Información de préstamo\n"
                "3. Regresar\n";

    while (true) {
        std::cout<<opciones;

        try {
            std::string opcion = obtenerOpcion();
            int opcionInt = std::stoi(opcion);

            switch (opcionInt) {
                case 1:
                    displayInformacionGeneral();
                    break;
                case 2:
                    displayInformacionPrestamo();
                    break;
                case 3:
                    displayOpcionesPrincipales();
                    break;
                default:
                    std::cout << "Opción fuera de rango. Intente de nuevo...\n";
                    break;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

//Manejo de excepciones completa
void Menu::displayInformacionPrestamo()
{
    int id;
    bool terminar = false;

    while (!terminar) {
        try
        {
            std::cout << "Ingrese el ID del préstamo que desea consultar:\n";
            std::cin >> id;

            if (std::cin.fail()) {
                std::cin.clear(); // Restaura el estado del flujo de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada no válida
                throw std::invalid_argument("Entrada inválida: Debe ingresar un valor entero."); // Lanza una excepción si la entrada no es un entero
            }

            cliente.obtenerInfoPrestamo(id);
            terminar = true; // Si se llega hasta aquí, el ID fue válido, podemos salir del bucle

        }catch (const std::out_of_range &e){
            std::cout << "No se encontró el préstamo con el ID ingresado.\n"
                    << '\n';
            terminar = true; // No encontró el préstamo, podemos salir del bucle

        }catch (const std::invalid_argument &e){
            std::cerr << "Error: " << e.what() << '\n';
        }
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

//Manejo de excepciones incompleta
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
