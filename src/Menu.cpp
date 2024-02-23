#include "Menu.hpp"

// Constructor de la clase
Menu::Menu(Banco &banco) : banco(banco) {}

// Destructor de la clase
// Menu::~Menu() {}

// Manejo de excepciones completa
void Menu::iniciarMenu()
{
    int cedula = obtenerIdentidad(); 
    /** 
    * @note Si la cedula se ecuentra en la base de datos. Entonces crea el objeto Cliente
    * En el caso de que no. Pide el nombre del usuario, agrega la cedula y el nombre a la base de datos y
    * crea el objeto cliente
    */

    std::string cedulaString = std::to_string(cedula); // Pasar cedula a string

    if (Identidad(cedulaString).verificarCedulaEnCSV("cedulas.csv"))
    {

        std::string nombreEncontrado = Identidad(cedulaString).extraerNombre("cedulas.csv");

        cliente = banco.agregarCliente(cedula, nombreEncontrado);

        std::cout << "Bienvenido" << nombreEncontrado << ". Numero de cédula: " << cedula << std::endl;
    }
    else
    {   
        // Etiqueta que la cedula ingresada no se encuentra en el .csv
        std::cout << "No se encontró el usuario." << '\n'; 

        // nombre ya está validado y listo para ser añadido al .csv y crear el objeto
        std::string nombre = obtenerNombre();

        // Crea el objeto cliente
        cliente = banco.agregarCliente(cedula, nombre); 

        std::cout << "Bienvenido " << nombre << ". Numero de cédula: " << cedula << std::endl; // Da la bienvenida
        // std::string cedula_string = std::to_string(cedula); //Transforma cedula a string para poder ser agregado al .csv
        AgregarCliente(cedulaString, nombre).agregarA_CSV("cedulas.csv"); // Agrega cedula y nombre al .csv
    }

    // El menu de opciones
    displayOpcionesPrincipales();
}

// Manejo de excepciones incompleta. No acepta las tildes y ñ.
std::string Menu::obtenerNombre()
{
    std::string nombre;

    while (true)
    {
        std::cout << "La primera letra de cada 'nombre' debe iniciar con mayúscula.\nIngrese su nombre de usuario: ";
        std::getline(std::cin, nombre);

        /**
         * @note Expresión regular para validar el nombre de usuario
         * 
         * @details El nombre del usuario tiene que iniciar con mayuscula, el resto del nombre tiene que ir en minuscula.
         * Tiene que ingresar como mínimo dos nombres: unNombre + unApellido
        *  Tiene que ingresar como máximo cuatro nombres: dosNombres + dosApellidos
        *  El nombre no puede poseer signos especiales
        *  Los nombres no pueden superar los 15 caracteres
        *  Los nombres no pueden tener menos de dos caracteres
         */
        std::regex regexNombre("^[A-ZÁÉÍÓÚÑ][a-záéíóúñ]{1,14}(\\s[A-ZÁÉÍÓÚÑ][a-záéíóúñ]{0,13}){0,2}(\\s[A-ZÁÉÍÓÚÑ][a-záéíóúñ]{1,14})?$");
        
        // Manejo de excepciones
        try
        {
            if (nombre.empty())
            {
                throw std::invalid_argument("Error: No se ha ingresado ninguna opción");
            }
            if (nombre.find('.') != std::string::npos)
            {
                throw std::invalid_argument("Error. Por favor digite su nombre sin puntos '.'.");
            }
            if (!std::regex_match(nombre, regexNombre))
            {

                throw std::invalid_argument("El formato del nombre de usuario no es válido.");
            }

            return nombre;
        }

        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

// Manejo de excepciones completa
/**
 * @brief Metodo que supervisa la entrada del número de cedula.
 * 
 * @details El número de cédula no puede contener letras.
 *   El número de cédula no puede empezar con cero.
 *   Debe ingresar un número de cédula de nueve dígitos.
 */
int Menu::obtenerIdentidad()
{

    std::string numCedulaStr;

    while (true)
    {
        try
        {
            std::cout << "Ingrese su número de cédula (deben ser nueve dígitos): ";
            std::getline(std::cin, numCedulaStr);
            // Para el caso de que el usuario ingrese solo enter.
            if (numCedulaStr.empty())
            {
                throw std::invalid_argument("Error: No se ha ingresado ninguna opción");
            }

            if (numCedulaStr.find('-') != std::string::npos)
            {
                throw std::invalid_argument("Error. Ingrese el número de cedula sin '-'.");
            }

            if (numCedulaStr.find('.') != std::string::npos)
            {
                throw std::invalid_argument("Error. Ingrese el número de cedula sin puntos '.'.");
            }

            // Verificar si la entrada contiene letras en lugar de números
            for (char c : numCedulaStr)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Entrada no válida. El número de cédula no puede contener letras.");
                }
            }

            if (numCedulaStr[0] == '0')
            {
                throw std::invalid_argument("Entrada no válida. El número de cédula no puede empezar con cero.");
            }

            if (numCedulaStr.length() != 9)
            {
                throw std::invalid_argument("Entrada no válida. Debe ingresar un número de cédula de nueve dígitos.");
            }

            // Convertir la cadena a un entero
            int num_cedula = std::stoi(numCedulaStr);
            // Retornar el número de cédula convertido a int
            return num_cedula;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

/**
 * @brief 
 * 
 * @param cedula 
 * @return true 
 * @return false 
 */
bool Menu::verificarCliente(int cedula)
{
    bool status = true;
    // Falta implementar codigo basado de la clase Identidad
    return status;
}


void Menu::crearCliente(int cedula) {} 

// Manejo de excepciones completa
/**
 * @brief Metodo que maneja el menu principal
 * Verifica si los datos ingresados son validos (int) y se encuentra dentro de las opciones
 * 
 */
void Menu::displayOpcionesPrincipales()
{

    /*Metodo que maneja el menu principal
    Verifica si los datos ingresados son validos (int) y se encuentra dentro de las opciones*/
    std::string menuOpciones =

        "\n--- Menu de opciones ---\n"
        "1. Atencion al cliente\n"
        "2. Informacion\n"
        "3. Solicitar préstamo\n"
        "4. Volver al inicio de sesión\n"
        "5. Salir\n";
    bool continuar = true;
    while (continuar)
    {
        std::cout << menuOpciones;
        std::string opcion = obtenerOpcion();
        int opcionInt = std::stoi(opcion);

        try
        {
            // Casos
            switch (opcionInt) // Pasamos opcion a tipo int
            {
            case 1: //  Atencion al cliente
                gestionarCliente(); // Llamado de metodo
                break;

            case 2: // Informacion
                displayInformacion(); // Llamado de metodo
                break;

            case 3: // Solicitud de préstamo
                agregarPrestamo(); // Llamado de metodo

                agregarPrestamo();
                break;
            case 4: // Volver al inicio de sesión
                iniciarMenu(); // Llamado de metodo

                break;
            case 5: // Salir por completo del programa
                std::cout << "Saliendo del programa...\n";
                banco.clean();
                exit(0);
                break;
            default:
                std::cout << "Opcion fuera de rango. Intente de nuevo...\n";
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

/**
 * @brief Este metodo se encarga de manejar las excepciones donde se tiene que ingresar un solo valor tipo int
 *
 * @return std::string 
 */
std::string Menu::obtenerOpcion()
{
    /*Este metodo se encarga de manejar las excepciones donde se tiene que ingresar un solo valor tipo int
    Return: un valor tipo string -> Cuidado
    */
    std ::string opcion;

    while (true)
    {
        try
        {
            // Solicitar la opción al usuario
            std::cout << "opción: ";
            std::getline(std::cin, opcion);

            // Verificar si la opción es un entero
            for (char c : opcion)
            {
                if (!std::isdigit(c))
                {
                    throw std::invalid_argument("Error: No se permiten letras");
                }
            }

            std::cout << "La opción ingresada fue: " << opcion << std::endl;
            return opcion;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

// Manejo de excepciones completa
/**
 * @brief Metodo encargado de gestionar los prestamos.
 * 
 * @details El metodo solicita los datos y se encarga de crear el objeto dedicado para generar el prestamo solicitado.
*  Los datos solicitados tienen que seguir ciertos lineamientos para poder gestionar el prestamo.
*  En el caso de que se ingrese un dato que no sigue estos lineamientos, el sistema posee excepciones que ayudarán
*  al operador a ingresar un dato valido.
*  El metodo por último muestra los detalles del prestamo tramitado
 */
void Menu::agregarPrestamo()
{
    /*Metodo encargado de gestionar los prestamos.
    El metodo solicita los datos y se encarga de crear el objeto dedicado para generar el prestamo solicitado.
    Los datos solicitados tienen que seguir ciertos lineamientos para poder gestionar el prestamo.
    En el caso de que se ingrese un dato que no sigue estos lineamientos, el sistema posee excepciones que ayudarán
    al operador a ingresar un dato valido.
    El metodo por último muestra los detalles del prestamo tramitado*/
    try
    {
        std::cout << "El banco ofrece las siguientes opciones de préstamos: " << std::endl;
        banco.obtenerInfoPrestamos();
        std::cout << "\nDebe ingresar el ID del préstamo que desea solicitar según lo mostrado en la tabla.\n";
        if (confirmarTransaccion())
        {
            int id;
            while (true)
            {
                /* code */
                id = Prestamo::solicitarIDprestamo();
                if (id < Constantes::NUM_PRESTAMOS)
                {
                    break;
                }
                else
                {
                    std::cout << "El ID no corresponde a ningún préstamo ofrecido. Intente nuevamente." << std::endl;
                }
            }

            Dinero dinero;
            dinero.solicitarMonto();
            dinero.solicitarMoneda();
            MetodoPago metodo = solicitarMetodoRecepcion();

            Prestamo *prestamo = new Prestamo(banco.buscarPrestamoOfrecido(id));
            prestamo->asignarDueno(cliente->obtenerId());
            prestamo->generarId();
            if (prestamo != nullptr)
            {
                banco.agregarPrestamo(prestamo);
            }
            else
            {
                throw std::bad_alloc();
            }
            Producto *pago;
            switch (metodo)
            {
            case EFECTIVO:
                pago = new Efectivo();
                break;
            case CUENTA_COLONES:
                pago = cliente->obtenerCuenta(COLONES);
                break;
            case CUENTA_DOLARES:
                pago = cliente->obtenerCuenta(DOLARES);
                break;
            default:
                break;
            }
            if (pago != nullptr)
            {
                Transaccion transaccion(prestamo, pago, dinero);
                transaccion();
                std::cout << "Transacción realizada con éxito\n";
                std::cout << "Detalles del préstamo: \n";
                banco.obtenerInfoPrestamos(prestamo->obtenerId(), cliente->obtenerId());
            }
            else
            {
                throw std::runtime_error("Ocurrió un problema al establecer método de pago");
            }
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "No se pudo agregar el préstamo";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayOpcionesPrincipales();
}

// Manejo de excepciones completas
/**
 * @brief Metodo que maneja el sub menu dedicado a gestionar los clientes
 * Verifica si el dato ingresado es valido y se encuentra dentro de las opciones
 * 
 */
void Menu::gestionarCliente()
/*Metodo que maneja el sub menu dedicado a gestionar los clientes
Verifica si el dato ingresado es valido y se encuentra dentro de las opciones*/
{
    
    std::string opciones =
        "\n--- Menu de Atencion al Cliente ---\n"
        "1. Tipos de Prestamos\n"
        "2. Gestion de Ahorros\n"
        "3. Operaciones\n"
        "4. Regresar\n";

    while (true)
    {
        try
        {
            std::cout << opciones;

            std::string opcion = obtenerOpcion();
            int opcionInt = std::stoi(opcion);

            // Casos
            switch (opcionInt)
            {
            case 1: //  Tipos de Prestamos
                displayTipoPrestamos(); // Llamado del metodo
                break;
            case 2: // Gestion de Ahorros
                gestionarAhorros(); // Llamado del metodo
                break;
            case 3: // Operaciones
                realizarOperaciones(); // Llamado del metodo
            case 4: // Regresar
                displayOpcionesPrincipales(); // Llamado del metodo
            default:
                std::cout << "Opcion no es valida. Intente de nuevo...\n";
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    // Llamado del metodo para regresar al menu inicial
    displayOpcionesPrincipales();
}



// Manejo de excepciones completa
/**
 * @brief Metodo encargado de gestionar un sub menu
 * donde se puede obtener informarción de las cuentas de ahorros y prestamos
 * que el usuario tiene. El metodo es capaz de manejar los datos no validos. Pide la opción hasta que se ingrese un valor valido
 * 
 */
void Menu::displayInformacion()
{
    /*Metodo encargado de gestionar un sub menu donde se puede obtener informarción de las cuentas de ahorros y prestamos
    que el usuario tiene.
    El metodo es capaz de manejar los datos no validos. Pide la opción hasta que se ingrese un valor valido*/
    std::string opciones =
        "\n--- Menu de Información ---\n"
        "1. Información general del usuario\n"
        "2. Información de préstamo\n"
        "3. Regresar\n";

    while (true)
    {
        std::cout << opciones;

        try
        {
            std::string opcion = obtenerOpcion();
            int opcionInt = std::stoi(opcion);

            switch (opcionInt)
            {
            case 1: // Información general del usuario
                displayInformacionGeneral();    // Llamado del metodo
                break;
            case 2: // Información de préstamo
                displayInformacionPrestamo(); // Llamado del metodo
                break;
            case 3: // Regresar al menu principal
                displayOpcionesPrincipales(); // Llamado del metodo
                break;
            default:
                std::cout << "Opción fuera de rango. Intente de nuevo...\n";
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

// Manejo de excepciones completa
/**
 * @brief Metodo donde se puede obtener información especifica de un prestamo ingresando el ID del prestamo.
 *  El metodo es capaz de manejar los datos no validos. Pide la opción hasta que se ingrese un valor valido
 * 
 */
void Menu::displayInformacionPrestamo()
{
    /*Metodo donde se puede obtener información especifica de un prestamo ingresando el ID del prestamo.
   El metodo es capaz de manejar los datos no validos. Pide la opción hasta que se ingrese un valor valido*/

    try
    {
        int id = Prestamo::solicitarIDprestamo();
        banco.obtenerInfoPrestamos(id, cliente->obtenerId());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    displayOpcionesPrincipales();
}

/**
 * @brief Imprime en pantalla la informacion general de las cuentas del
 * 
 */
void Menu::displayInformacionGeneral()
{
    cliente->obtenerInfo();

    std::cout << "\nInformación de cuentas:\n";
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Estado"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Moneda"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Ahorros" << std::endl;

    cliente->obtenerEstadoCuenta(COLONES);
    cliente->obtenerEstadoCuenta(DOLARES);

    banco.obtenerInfoPrestamosCliente(cliente->obtenerId());

    displayOpcionesPrincipales();
}

void Menu::gestionarAhorros()
{
    
}

// Manejo de excepciones incompleta
/**
 * @brief Metodo que maneja el menu de operaciones
 * Ademas imprime en pantalla el submenu de las operaciones disponibles
 * 
 */
void Menu::realizarOperaciones()
{

    /*Metodo que maneja el menu de operaciones
    Verifica si los datos ingresados son validos (int) y se encuentra dentro de las opciones*/
    std::string menuOpciones =

        "\n--- Menu de opciones ---\n"
        "1. Pagar préstamo\n"
        "2. Activar Cuenta\n"
        "3. Desactivar Cuenta\n"
        "4. Transferencia\n"
        "5. Cambio de moneda\n"
        "6. Regresar\n";

    while (true)
    {
        std::cout << menuOpciones;
        std::string opcion = obtenerOpcion();
        int opcionInt = std::stoi(opcion);

        try
        {
            // Casos
            switch (opcionInt) // Pasamos opcion a tipo int
            {
            case 1: //  Pagar préstamo
                pagarPrestamo();
                break;
            case 6:
                displayOpcionesPrincipales();
            default:
                std::cout << "Opcion fuera de rango. Intente de nuevo...\n";
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Menu::pagarPrestamo()
{

    try
    {
        Producto *pago;
        int id = Prestamo::solicitarIDprestamo();

        if (id == -1)
        {
            std::cout << "Operación cancelada" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            displayOpcionesPrincipales();
            return;
        }

        Prestamo *prestamo = banco.buscarPrestamo(id);
        if (prestamo != nullptr)
        {
            std::cout << "Desglose del pago: " << std::endl;
            prestamo->imprimirDesglosePago();
            MetodoPago metodo = solicitarMetodoPago();
            switch (metodo)
            {
            case CUENTA_COLONES:
                pago = cliente->obtenerCuenta(COLONES);
                break;
            case CUENTA_DOLARES:
                pago = cliente->obtenerCuenta(DOLARES);
                break;
            case EFECTIVO:
                pago = new Efectivo();
            default:
                break;
            }

            if (pago != nullptr)
            {
                Transaccion transaccion(pago, prestamo, prestamo->obtenerCuotaMensual());
                transaccion();
                std::cout << "Transacción realizada con éxito\n";
            }
        }
        else
        {
            throw std::out_of_range("No se encontró el préstamo");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayOpcionesPrincipales();
}

void Menu::displayTipoPrestamos()
{
    banco.obtenerInfoPrestamos();
    displayOpcionesPrincipales();
}

bool Menu::confirmarTransaccion()
{
    std::string opcion;
    std::cout << "Desea continuar con el trámite (s/n): ";
    std::cin >> opcion;

    return (opcion == "s");
}