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
    prestamosPredefinidos[PERSONAL] = Prestamo(PERSONAL, 12, 15.95, PERSONAL);
    prestamosPredefinidos[PERSONAL + 1] = Prestamo(PERSONAL, 12, 15.95, PERSONAL + 1);
    prestamosPredefinidos[PERSONAL + 2] = Prestamo(PERSONAL, 12, 15.95, PERSONAL + 2);
    prestamosPredefinidos[PRENDARIO] = Prestamo(PRENDARIO, 12, 12.25, PRENDARIO);
    prestamosPredefinidos[PRENDARIO + 1] = Prestamo(PRENDARIO, 12, 12.25, PRENDARIO + 1);
    prestamosPredefinidos[PRENDARIO + 2] = Prestamo(PRENDARIO, 12, 12.25, PRENDARIO + 2);
    prestamosPredefinidos[HIPOTECARIO] = Prestamo(HIPOTECARIO, 12, 9.75, HIPOTECARIO);
    prestamosPredefinidos[HIPOTECARIO + 1] = Prestamo(HIPOTECARIO, 12, 9.75, HIPOTECARIO + 1);
    prestamosPredefinidos[HIPOTECARIO + 2] = Prestamo(HIPOTECARIO, 12, 9.75, HIPOTECARIO + 2);
}

/**
 * @brief Desconstructor de un nuevo objeto Banco::Banco 
 */
Banco::~Banco()
{

    for (auto &entrada : prestamos)
    {
        delete entrada.second;
    }
    prestamos.clear();
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

Prestamo *Banco::
    buscarPrestamo(const unsigned int &id, const unsigned int &idDueno)
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
        // std::string encabezado;
        // std::getline(in, encabezado);

        Prestamo temp;
        while (in >> temp)
        {
            Prestamo *ptrPrestamo = new Prestamo(temp);
            if (ptrPrestamo != nullptr)
            {
                agregarPrestamo(ptrPrestamo);
                // Ya que no se incluye la cuota mensual en el archivo
                // csv es necesario calcularla al luego de crearlo
                ptrPrestamo->calcularAmortizacion();
            }
            else
            {
                throw std::bad_alloc();
            }
        }
        if (in.fail() && !in.eof())
        {
            throw std::invalid_argument("Formato inválido");
        }
        std::cout << "Préstamos cargados con éxito" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error al cargar préstamos: " << e.what() << '\n';
    }
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
