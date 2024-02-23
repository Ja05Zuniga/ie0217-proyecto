#include "Banco.hpp"

/**
 * @brief Constructor de un nuevo objeto Banco::Banco
 * @details Aquí se definen los préstamos ofrecidos por el usuario
 */
Banco::Banco()
{
    // Inicializacion de prestamos con valores predeterminados.
    /**
     * @note basados en aproximaciones a valores comerciales (en la tasa de interes)
     * los plazos se toman toman todos a un año
     */

    prestamosPredefinidos[PERSONAL] = Prestamo(PERSONAL, 36, 8, PERSONAL);
    prestamosPredefinidos[PERSONAL + 1] = Prestamo(PERSONAL, 48, 10, PERSONAL + 1);
    prestamosPredefinidos[PERSONAL + 2] = Prestamo(PERSONAL, 60, 12, PERSONAL + 2);
    prestamosPredefinidos[PRENDARIO] = Prestamo(PRENDARIO, 24, 6, PRENDARIO);
    prestamosPredefinidos[PRENDARIO + 1] = Prestamo(PRENDARIO, 36, 7.5, PRENDARIO + 1);
    prestamosPredefinidos[PRENDARIO + 2] = Prestamo(PRENDARIO, 48, 9, PRENDARIO + 2);
    prestamosPredefinidos[HIPOTECARIO] = Prestamo(HIPOTECARIO, 240, 3.5, HIPOTECARIO);
    prestamosPredefinidos[HIPOTECARIO + 1] = Prestamo(HIPOTECARIO, 360, 4, HIPOTECARIO + 1);
    prestamosPredefinidos[HIPOTECARIO + 2] = Prestamo(HIPOTECARIO, 480, 4.5, HIPOTECARIO + 2);

    cargarPrestamos("prestamos.csv");
    cargarCuentas("cuentas.csv");
}

/**
 * @brief Desconstructor de un nuevo objeto Banco::Banco
 */
Banco::~Banco()
{
}

void Banco::clean()
{
    registrarPrestamos("prestamos.csv");
    registrarCuentas("cuentas.csv");

    for (auto &entrada : prestamos)
    {
        if (entrada.second != nullptr)
        {
            delete entrada.second;
        }
    }

    prestamos.clear();
    for (auto &entrada : cuentasColones)
    {
        if (entrada.second != nullptr)
        {
            delete entrada.second;
        }
    }
    cuentasColones.clear();
    for (auto &entrada : cuentasDolares)
    {
        if (entrada.second != nullptr)
        {
            delete entrada.second;
        }
    }
    cuentasDolares.clear();
}

/**
 * @brief Busca el cliente por su ced (id) en el contenedor de clientes
 *
 * @param id numero de indentificacion del cliente
 * @return Cliente Una instancia del clase Cliente
 */
Cliente *Banco::buscarCliente(const unsigned int &id)
{
    auto it = clientes.find(id);

    if (it != clientes.end())
    {
        Cliente *ptrCliente = it->second;
        return ptrCliente;
    }
    else
    {
        return nullptr;
    }
}

/**
 * @brief Busca el cliente en el contenedor de prestamos
 *
 * @param id Identificacion unica del prestamo
 * @return Prestamo Una instancia del clase Prestamo
 */
Prestamo *Banco::buscarPrestamo(const int id)
{

    for (const auto &entry : prestamos)
    {
        const auto &idCompuesta = entry.first;
        const auto &prestamo = entry.second;

        if (idCompuesta.second == id)
        {
            return prestamo;
        }
    }

    return nullptr;
}

void Banco::obtenerInfoPrestamosCliente(const int id)
{
    std::cout << "\nInformación de préstamos:\n";
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "ID"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tipo"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Cuotas"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Tasa de interés"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Moneda"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Monto" << std::endl;
    for (const auto &entry : prestamos)
    {
        const auto &idCompuesta = entry.first;
        const auto &prestamo = entry.second;

        if (idCompuesta.first == id)
        {
            if (prestamo != nullptr)
            {
                prestamo->obtenerInfoPersonal(true);
            }
        }
    }
}

Prestamo Banco::buscarPrestamoOfrecido(const unsigned int id)
{

    return prestamosPredefinidos[id];
}

Prestamo *Banco::buscarPrestamo(const unsigned int &id, const unsigned int &idDueno)
{
    auto it = prestamos.find(std::make_pair(idDueno, id));

    if (it != prestamos.end())
    {
        Prestamo *ptrPrestamo = it->second;
        return ptrPrestamo;
    }
    else
    {
        return nullptr;
    }
}

/**
 * @brief Imprime en pantalla información del básica del préstamo
 *
 * @param id Identificacion unica del prestamo
 */
void Banco::obtenerInfoPrestamos(const unsigned int &id)
{
    std::cout << std::left << std::setw(Constantes::COL_WIDTH) << "ID"
              << std::setw(Constantes::COL_WIDTH) << "Tipo"
              << std::setw(Constantes::COL_WIDTH) << "Cuotas"
              << std::setw(Constantes::COL_WIDTH) << "Tasa de interés anual" << std::endl;

    Prestamo *prestamo = buscarPrestamo(id);
    if (prestamo != nullptr)
    {
        prestamo->obtenerInfo();
    }
    else
    {
        throw std::out_of_range("No se encontró el préstamo indicado");
    }
}

void Banco::obtenerInfoPrestamos(const unsigned int &id, const unsigned int &idDueno)
{
    Prestamo *prestamo = buscarPrestamo(id, idDueno);
    if (prestamo != nullptr)
    {
        prestamo->obtenerInfoPersonal();
    }
    else
    {
        throw std::out_of_range("No se encontró el préstamo indicado");
    }
}

void Banco::obtenerInfoPrestamos()
{
    std::cout << std::left << std::setw(Constantes::COL_WIDTH) << "ID"
              << std::setw(Constantes::COL_WIDTH) << "Tipo"
              << std::setw(Constantes::COL_WIDTH) << "Cuotas"
              << std::setw(Constantes::COL_WIDTH) << "Tasa de interés anual" << std::endl;

    for (auto prestamo : prestamosPredefinidos)
    {

        prestamo.obtenerInfo();
    }
}

/**
 * @brief Imprime en pantalla informacion basica del certificado
 *        Llama el metodo obtenerInfo de la clase certificado
 *
 * @param id Identificacion unica del certificado
 */
void Banco::obtenerInfoCertificados(const unsigned int &id)
{
    // Instancia del objeto de clase Certificado
    // se accede al elemento id del mapa certificados
    Certificado certificado = certificados.at(id);

    // Llamado del metodo obtenerInfo de la clase Certificado
    certificado.obtenerInfo();
}

/**
 * @brief Agrega un cliente nuevo al contenedor de clientes del Banco
 *
 * @param id cedula de identificacion del cliente
 * @param nombre Nombre del cliente a registrar
 * @return Cliente Una instancia del clase Cliente
 */
Cliente *Banco::agregarCliente(const unsigned int &id, const std::string &nombre)
{

    Cliente *ptrCliente = new Cliente(id, nombre);
    if (ptrCliente == nullptr)
    {
        throw std::bad_alloc();
    }
    else
    {
        return ptrCliente;
    }
}

void Banco::cargarPrestamos(const std::string &archivoCSV)
{
    try
    {
        std::ifstream in(archivoCSV);

        if (!in)
        {
            throw std::ios_base::failure("No se pudo abrir el archivo");
        }

        Prestamo temp;
        std::string line;

        while (std::getline(in, line))
        {
            // Verificar si la línea está vacía
            if (line.empty() || std::all_of(line.begin(), line.end(), ::isspace))
            {
                break;
            }

            std::istringstream iss(line);
            if (iss >> temp)
            {
                Prestamo *ptrPrestamo = new Prestamo(temp);
                if (ptrPrestamo != nullptr)
                {
                    agregarPrestamo(ptrPrestamo);
                    ptrPrestamo->calcularAmortizacion();
                }
                else
                {
                    throw std::bad_alloc();
                }
            }
            else
            {
                throw std::invalid_argument("Formato inválido");
            }
        }

        std::cout << "Préstamos cargados con éxito" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error al cargar préstamos: " << e.what() << '\n';
    }
}

void Banco::cargarCuentas(const std::string &archivoCSV)
{
    try
    {
        std::ifstream in(archivoCSV);

        if (!in)
        {
            throw std::ios_base::failure("No se pudo abrir el archivo");
        }

        Cuenta temp;
        std::string line;

        while (std::getline(in, line))
        {
            // Verificar si la línea está vacía
            if (line.empty() || std::all_of(line.begin(), line.end(), ::isspace))
            {
                break;
            }
            std::istringstream iss(line);
            if (iss >> temp)
            {
                Cuenta *ptrCuenta = new Cuenta(temp);
                if (ptrCuenta != nullptr)
                {
                    agregarCuenta(ptrCuenta);
                }
                else
                {
                    throw std::bad_alloc();
                }
            }
            else
            {
                throw std::invalid_argument("Formato inválido");
            }
        }

        std::cout << "Cuentas cargadas con éxito" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error al cargar cuentas: " << e.what() << '\n';
    }
}

void Banco::registrarPrestamos(const std::string &archivoCSV)
{

    std::ofstream of(archivoCSV);

    if (!of.is_open())
    {
        throw std::runtime_error("Error al abrir archivo de registro de préstamos");
    }
    for (const auto &prestamo : prestamos)
    {
        of << *prestamo.second << std::endl;
    }

    of.close();
}

void Banco::registrarCuentas(const std::string &archivoCSV)
{

    std::ofstream of(archivoCSV);

    if (!of.is_open())
    {
        throw std::runtime_error("Error al abrir archivo de registro de préstamos");
    }
    for (const auto &cuenta : cuentasColones)
    {
        of << *cuenta.second << std::endl;
    }
    for (const auto &cuenta : cuentasDolares)
    {
        of << *cuenta.second << std::endl;
    }

    of.close();
}

void Banco::cargarClientes(const std::string &archivoCSV)
{
    try
    {
        std::ifstream in(archivoCSV);

        if (!in)
        {
            throw std::ios_base::failure("No se pudo abrir el archivo");
        }
        Cliente temp;
        while (in >> temp)
        {

            clientes[temp.obtenerId()] = new Cliente(temp);
        }

        if (in.fail() && !in.eof())
        {
            throw std::invalid_argument("Formato inválido");
        }
        std::cout << "Clientes cargados con éxito" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error al cargar clientes: " << e.what() << '\n';
    }
}

/**
 * @details La verificación nos asegura que el contenedor nunca almacenará punteros nulos
 *
 * @param prestamo
 * @return void*
 */
void Banco::agregarPrestamo(Prestamo *prestamo)
{
    if (prestamo != nullptr)
    {
        prestamos[std::make_pair(prestamo->obtenerDueno(), prestamo->obtenerId())] = prestamo;
    }
}

/**
 * @details La verificación nos asegura que el contenedor nunca almacenará punteros nulos
 *
 * @param prestamo
 * @return void*
 */
void Banco::agregarCuenta(Cuenta *cuenta)
{
    if (cuenta != nullptr)
    {
        switch (cuenta->obtenerMoneda())
        {
        case COLONES:
            cuentasColones[cuenta->obtenerId()] = cuenta;
            /* code */
            break;
        case DOLARES:
            cuentasDolares[cuenta->obtenerId()] = cuenta;

        default:
            break;
        }
    }
}

Cuenta *Banco::buscarCuenta(const unsigned int id, Moneda moneda)
{
    std::unordered_map<unsigned int, Cuenta *>::iterator it;
    switch (moneda)
    {
    case COLONES:
        it = cuentasColones.find(id);
        if (it != cuentasColones.end())
        {
            return it->second;
        }
        break;
    case DOLARES:
        it = cuentasDolares.find(id);
        if (it != cuentasDolares.end())
        {
            return it->second;
        }
        break;
    default:
        break;
    }

    return nullptr;
}
