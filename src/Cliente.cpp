#include "Cliente.hpp"

/**
 * @brief Constructor de la clase Cliente
 */
Cliente::Cliente() {}

/**
 * @details El constructor automaticante asigna cuentas en dolares y en colones para
 * el usuario
*
* @param userId Identificador unico (cedula) del cliente.
* @param nombre Nombre del cliente.
 */
Cliente::Cliente(unsigned int userId, std::string nombre) : userId(userId), nombre(nombre)
{
    cuentaColones = Cuenta(0, COLONES);
    cuentaDolares = Cuenta(0, DOLARES);
}

/**
* @brief Destructor de la clase Cliente.
*/
Cliente::~Cliente()
{
}

/**
 * @brief Muestra la información básica del cliente
 */
void Cliente::obtenerInfo()
{
    std::cout << "Nombre: " << nombre << "\n"
              << "ID: " << userId << std::endl;
}

/**
 * @details Aquí se inicializan los atributos necesarios cuando se abre el préstamo,
 * se llama la clase transacción para mover el dinero y finalmente se devuelve el ID del préstamo 
 * creado
 *
* @param prestamos Objeto de Prestamo a agregar.
* @param monto Monto del prestamo.
* @param moneda Tipo  de moneda del prestamo.
* @return unsigned int Identificador unico del nuevo prestamo
 */
unsigned int Cliente::agregarPrestamo(Prestamo prestamo, const float &monto, Moneda moneda)
{
    // Instancia de objeto de la clase Dinero
    Dinero dinero(monto, moneda);
    // Instancia de un ptro de clase Cuenta
    Cuenta *cuenta;

    // Casos para los tipos de monedas
    switch (moneda)
    {
    case 0:
        cuenta = &cuentaColones;
        break;

    case 1:
        cuenta = &cuentaDolares;
        break;
    default:
        break;
    }

    // Instancia de objeto de la clase Transaccion
    Transaccion transaccion(&prestamo, cuenta, dinero);

    transaccion();
    // Llamado al metodo de obtenerId de clase Producto
    unsigned int id = prestamo.obtenerId();
    prestamos[id] = prestamo;

    return id;
}

/**
 * @details Busca un préstamo del usuario a partir de su ID
 *
 * @param id Identificador unico del prestamo a buscar
 * @return Prestamo El prestamo buscado
 */
Prestamo Cliente::buscarPrestamo(const unsigned int &id)
{
    return prestamos.at(id);
}

/**
 * @details Muestra información detallada de un préstamo específico por el ID del prestamo
 *
 * @param id Identificador unico del prestamo a buscar
 */
void Cliente::obtenerInfoPrestamo(const unsigned int &id)
{
    // Llamado al metodo de buscarPrestamo
    Prestamo prestamo = this->buscarPrestamo(id);
    prestamo.obtenerInfoPersonal();
}

/**
 * @details Itera sobre el contenedor préstamos para imprimir su información 
 * 
 */
void Cliente::obtenerInfoPrestamos()
{
    // Instanciando un objeto iterador
    std::unordered_map<unsigned int, Prestamo>::iterator iter;
    for (iter = prestamos.begin(); iter != prestamos.end(); ++iter)
    {
        iter->second.obtenerInfo();
    }
}

/**
 * @brief Muestra el estado de la cuenta del cliente en la moneda especificada.
 * 
 * @param moneda Tipo de moneda de la cuenta a consultar
 */
void Cliente::obtenerEstadoCuenta(Moneda moneda)
{   
    // Instancia de un ptro de clase Cuenta
    Cuenta *cuenta;

    // Casos
    switch (moneda)
    {
    case 0:
        cuenta = &cuentaColones;
        break;
    case 1:
        cuenta = &cuentaDolares;

    default:
        break;
    }
    cuenta->obtenerInfo();
}