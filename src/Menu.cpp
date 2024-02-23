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

        std::cout
            << "Bienvenido" << nombreEncontrado << ". Numero de cédula: " << cedula << std::endl;
    }
    else
    {
        // Etiqueta que la cedula ingresada no se encuentra en el .csv
        std::cout << "No se encontró el usuario." << '\n';

        // nombre ya está validado y listo para ser añadido al .csv y crear el objeto
        std::string nombre = obtenerNombre();

        // Crea el objeto cliente
        cliente = banco.agregarCliente(cedula, nombre);

        // Crea sus cuentas
        Cuenta *cuentasColones = new Cuenta(0, COLONES, cedula);
        banco.agregarCuenta(cuentasColones);
        Cuenta *cuentasDolares = new Cuenta(0, DOLARES, cedula);
        banco.agregarCuenta(cuentasDolares);

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
        "4. Solicitar certificado\n"
        "5. Volver al inicio de sesión\n"
        "6. Salir\n";
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
            case 1:                 //  Atencion al cliente
                gestionarCliente(); // Llamado de metodo
                break;

            case 2:                   // Informacion
                displayInformacion(); // Llamado de metodo
                break;

            case 3:                // Solicitud de préstamo
                agregarPrestamo(); // Llamado de metodo

                break;
            case 4:
                agregarCertificado(); // Abre un certificado para el cliente

                break;
            case 5:            // Volver al inicio de sesión
                iniciarMenu(); // Llamado de metodo

                break;
            case 6: // Salir por completo del programa
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
    std::string opcionStr;

    while (true)
    {
        try
        {
            std::cout << "Opción: ";
            std::getline(std::cin, opcionStr);

            // Verificar si la cadena contiene solo dígitos
            if (opcionStr.find_first_not_of("0123456789") != std::string::npos)
            {
                throw std::invalid_argument("Error: La opción debe ser un número.");
            }

            // Convertir la opción a entero y devolverla
            return opcionStr;
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
                if (id == -1)
                {
                    throw std::runtime_error("Operación cancelada");
                }

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

void Menu::agregarCertificado()
{

    try
    {
        std::cout << "El banco ofrece las siguientes opciones de certificados: " << std::endl;
        banco.obtenerInfoCertificados();
        std::cout << "\nDebe ingresar el ID del certificado que desea solicitar según lo mostrado en la tabla.\n";
        int id;
        while (true)
        {
            /* code */
            id = Certificado::solicitarIDcertificado();
            if (id == -1)
            {
                std::cout << "Operación cancelada" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                displayOpcionesPrincipales();
                return;
            }

            if (id < Constantes::NUM_CERTIFICADOS)
            {
                break;
            }
            else
            {
                std::cout << "El ID no corresponde a ningún certificado ofrecido. Intente nuevamente." << std::endl;
            }
        }
        Dinero dinero;
        dinero.solicitarMonto();
        dinero.solicitarMoneda();

        Certificado *certificado = new Certificado(banco.buscarCertificadoOfrecido(id));
        if (certificado == nullptr)
        {
            throw std::bad_alloc();
        }

        Dinero intereses = certificado->calcularIntereses(dinero);
        std::cout << "El certificado le generará en intereses: " << intereses.obtenerMoneda() << intereses.obtenerMonto() << std::endl;

        if (confirmarTransaccion())
        {

            MetodoPago metodo = solicitarMetodoPago();
            certificado->asignarDueno(cliente->obtenerId());
            certificado->generarId();
            banco.agregarCertificado(certificado);

            Producto *pago;
            switch (metodo)
            {
            case EFECTIVO:
                pago = new Efectivo();
                break;
            case CUENTA_COLONES:
                pago = banco.buscarCuenta(cliente->obtenerId(), COLONES);
                break;
            case CUENTA_DOLARES:
                pago = banco.buscarCuenta(cliente->obtenerId(), DOLARES);
                break;
            default:
                break;
            }

            if (pago != nullptr)
            {
                Transaccion transaccion(pago, certificado, dinero);
                transaccion();
                std::cout << "Transacción realizada con éxito\n";
                std::cout << "Detalles del certificado: \n";
                banco.obtenerInfoCertificados(certificado->obtenerId(), cliente->obtenerId());
            }
            else
            {
                throw std::runtime_error("Ocurrió un problema al establecer método de pago");
            }
        }
        else
        {
            delete certificado;
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "No se pudo agregar el certificado";
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

    try
    {
        std::cout << opciones;

        std::string opcion = obtenerOpcion();
        int opcionInt = std::stoi(opcion);

        // Casos
        switch (opcionInt)
        {
        case 1:                     //  Tipos de Prestamos
            displayTipoPrestamos(); // Llamado del metodo
            break;
        case 2:                 // Gestion de Ahorros
            gestionarAhorros(); // Llamado del metodo
            break;
        case 3:                           // Operaciones
            realizarOperaciones();        // Llamado del metodo
        case 4:                           // Regresar
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

    std::cout << opciones;

    try
    {
        std::string opcion = obtenerOpcion();
        int opcionInt = std::stoi(opcion);

        switch (opcionInt)
        {
        case 1:                          // Información general del usuario
            displayInformacionGeneral(); // Llamado del metodo
            break;
        case 2:                           // Información de préstamo
            displayInformacionPrestamo(); // Llamado del metodo
            break;
        case 3:                           // Regresar al menu principal
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
    Cuenta *cuentaColones = banco.buscarCuenta(cliente->obtenerId(), COLONES);
    if (cuentaColones != nullptr)
    {
        cuentaColones->obtenerInfo();
    }
    Cuenta *cuentaDolares = banco.buscarCuenta(cliente->obtenerId(), DOLARES);
    if (cuentaDolares != nullptr)
    {
        cuentaDolares->obtenerInfo();
    }

    banco.obtenerInfoPrestamosCliente(cliente->obtenerId());
    banco.obtenerInfoCertificadosCliente(cliente->obtenerId());

    displayOpcionesPrincipales();
}

void Menu::gestionarAhorros()
{
    std::string opcion;
    try
    {
        std::cout << "1. Depositar en la cuenta\n2. Debitar\nIngrese una opcion\n";
        opcion = obtenerOpcion();

        switch (std::stoi(opcion))
        {
        case 1:
            acreditarCuenta();
            break;
        case 2:
            debitarCuenta();
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
void Menu::acreditarCuenta()
{
    // Obtener la cuenta en la que quieres depositar dinero
    Cuenta *cuentaCliente = nullptr;
    Moneda monedaDeposito;
    std::string tipoMoneda;

    // Solicitar al usuario que ingrese el tipo de moneda
    std::cout << "Ingrese el tipo de moneda (1.COLONES o 2.DOLARES)\n";
    tipoMoneda = obtenerOpcion();

    if (tipoMoneda == "1")
    {
        monedaDeposito = COLONES;
    }
    else if (tipoMoneda == "2")
    {
        monedaDeposito = DOLARES;
    }
    else
    {
        std::cerr << "Tipo de moneda inválido." << std::endl;
        return;
    }

    // Obtener la cuenta del cliente
    cuentaCliente = banco.buscarCuenta(cliente->obtenerId(), monedaDeposito);
    try
    {
        // Verificar si la cuenta se encontró correctamente
        if (cuentaCliente)
        {
            // Solicitar al usuario que ingrese el monto a depositar
            std::string montoString;
            float monto;
            std::cout << "Ingrese el monto a depositar\n";
            montoString = obtenerOpcion();
            monto = std::stof(montoString);
            // Manejar excepción en caso de que se ingrese un valor no válido para el monto

            // Crear un objeto Dinero con el monto ingresado y la moneda especificada
            Dinero montoADepositar(monto, monedaDeposito);

            // Depositar el dinero en la cuenta
            cuentaCliente->acreditar(montoADepositar);

            // Mostrar información actualizada de la cuenta
            std::cout << "\nInformación de la cuenta actualizada:\n";
            std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
                      << std::setw(Constantes::COL_WIDTH) << std::left << "Estado"
                      << std::setw(Constantes::COL_WIDTH) << std::left << "Moneda"
                      << std::setw(Constantes::COL_WIDTH) << std::left << "Ahorros" << std::endl;
            cuentaCliente->obtenerInfo();
        }
        else
        {
            std::cout << "El cliente no tiene una cuenta en " << tipoMoneda << "." << std::endl;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: El valor ingresado no es válido." << std::endl;
    }
}

void Menu::debitarCuenta()
{
    // Obtener la cuenta de la que quieres retirar dinero
    Cuenta *cuentaCliente = nullptr;
    Moneda monedaRetiro;
    std::string tipoMoneda;

    // Solicitar al usuario que ingrese el tipo de moneda
    std::cout << "Ingrese el tipo de moneda (1.COLONES o 2.DOLARES)\n";
    tipoMoneda = obtenerOpcion();

    if (tipoMoneda == "1")
    {
        monedaRetiro = COLONES;
    }
    else if (tipoMoneda == "2")
    {
        monedaRetiro = DOLARES;
    }
    else
    {
        std::cerr << "Tipo de moneda inválido." << std::endl;
        return;
    }

    // Obtener la cuenta del cliente
    cuentaCliente = banco.buscarCuenta(cliente->obtenerId(), monedaRetiro);

    // Verificar si la cuenta se encontró correctamente
    if (cuentaCliente)
    {
        try
        {
            std::string montoString;
            // Solicitar al usuario que ingrese el monto a retirar
            std::cout << "Ingrese el monto a retirar\n";
            montoString = obtenerOpcion();
            float monto = std::stof(montoString);

            // Manejar excepción en caso de que se ingrese un valor no válido para el monto

            // Crear un objeto Dinero con el monto ingresado y la moneda especificada
            Dinero montoARetirar(monto, monedaRetiro);

            // Retirar el dinero de la cuenta
            cuentaCliente->debitar(montoARetirar);

            // Mostrar información actualizada de la cuenta
            std::cout << "\nInformación de la cuenta actualizada:\n";
            std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
                      << std::setw(Constantes::COL_WIDTH) << std::left << "Estado"
                      << std::setw(Constantes::COL_WIDTH) << std::left << "Moneda"
                      << std::setw(Constantes::COL_WIDTH) << std::left << "Ahorros" << std::endl;
            cuentaCliente->obtenerInfo();
        }
        catch (const FondosInsuficientes &e)
        {
            std::cerr << "Error: Fondos insuficientes." << std::endl;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: El valor ingresado no es válido." << std::endl;
        }
    }
    else
    {
        std::cout << "El cliente no tiene una cuenta en " << tipoMoneda << "." << std::endl;
    }
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
        "5. Regresar\n";

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
        case 2:
            activarCuenta();
            break;
        case 3:
            desactivarCuenta();
            break;
        case 4:
            realizarTransferencia();
        case 5:
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

void Menu::desactivarCuenta()
{
    std::cout << "1. Desactivar cuenta COLONES\n2. Desactivar cuenta DOLARES" << std::endl;
    std::string opcion = obtenerOpcion();

    try
    {
        if (opcion == "1")
        {
            banco.buscarCuenta(cliente->obtenerId(), COLONES)->cambiarEstado(false);
            std::cout << "Cuenta de COLONES desactivada con exito" << std::endl;
        }
        else if (opcion == "2")
        {
            banco.buscarCuenta(cliente->obtenerId(), DOLARES)->cambiarEstado(false);
            std::cout << "Cuenta de DOLARES desactivada con exito" << std::endl;
        }

        else
        {
            throw std::invalid_argument("Opción inválida: " + opcion);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        // Manejo adicional de excepciones si es necesario
    }
}

void Menu::activarCuenta()
{
    std::cout << "1. Activar cuenta COLONES\n2. Activar cuenta DOLARES" << std::endl;
    std::string opcion = obtenerOpcion();

    try
    {
        if (opcion == "1")
        {
            banco.buscarCuenta(cliente->obtenerId(), COLONES)->cambiarEstado(true);
            std::cout << "Cuenta de COLONES activada" << std::endl;
        }
        else if (opcion == "2")
        {
            banco.buscarCuenta(cliente->obtenerId(), DOLARES)->cambiarEstado(true);
            std::cout << "Cuenta de DOLARES activada" << std::endl;
        }

        else
        {
            throw std::invalid_argument("Opción inválida: " + opcion);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        // Manejo adicional de excepciones si es necesario
    }
}

void Menu::realizarTransferencia()
{
    try
    {
        Producto *pago;
        int idCliente = Cliente::solicitarIDcliente();
        if (idCliente == -1)
        {
            throw std::runtime_error("Operación cancelada");
        }

        int moneda;
        while (true)
        {
            std::cout << "Ingrese la cuenta a la que desea tranferir: \n"
                      << "1. Cuenta colones\n"
                      << "2. Cuenta dolares" << std::endl;
            std::cin >> moneda;
            if (std::cin.fail() || moneda < 1, moneda > 2)
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
        Producto *cuentaDestino;

        switch (moneda)
        {
        case 1:
            cuentaDestino = banco.buscarCuenta(idCliente, COLONES);
            break;
        case 2:
            cuentaDestino = banco.buscarCuenta(idCliente, DOLARES);
        default:
            break;
        }

        if (cuentaDestino == nullptr)
        {
            throw std::out_of_range("No se encontró el cliente con ese ID");
        }

        MetodoPago metodo = solicitarMetodoPago();
        switch (metodo)
        {
        case CUENTA_COLONES:
            pago = banco.buscarCuenta(cliente->obtenerId(), COLONES);
            break;
        case CUENTA_DOLARES:
            pago = banco.buscarCuenta(cliente->obtenerId(), DOLARES);
            break;
        case EFECTIVO:
            pago = new Efectivo();
        default:
            break;
        }

        Dinero dinero;
        dinero.solicitarMonto();
        dinero.solicitarMoneda();

        if (pago != nullptr)
        {
            Transaccion transaccion(pago, cuentaDestino, dinero);
            transaccion();
            std::cout << "Transacción realizada con éxito\n";
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
                pago = banco.buscarCuenta(cliente->obtenerId(), COLONES);
                break;
            case CUENTA_DOLARES:
                pago = banco.buscarCuenta(cliente->obtenerId(), DOLARES);
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