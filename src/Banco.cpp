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
    prestamos[PERSONAL] = Prestamo(PERSONAL, 12, 15.95, PERSONAL);
    prestamos[PRENDARIO] = Prestamo(PRENDARIO, 12, 12.25, PRENDARIO);
    prestamos[HIPOTECARIO] = Prestamo(HIPOTECARIO, 12, 9.75, HIPOTECARIO);
}

/**
 * @brief Desconstructor de un nuevo objeto Banco::Banco 
 * 
 */
Banco::~Banco(){}

/**
 * @brief Busca el cliente por su ced (id) en el contenedor de clientes
 * 
 * @param id numero de indentificacion del cliente
 * @return Cliente Una instancia del clase Cliente
 */
Cliente Banco::buscarCliente(const unsigned int &id)
{
    return clientes.at(id);
}

/**
 * @brief Busca el cliente en el contenedor de prestamos
 * 
 * @param id Identificacion unica del prestamo
 * @return Prestamo Una instancia del clase Prestamo
 */
Prestamo Banco::buscarPrestamo(const unsigned int &id)
{
    return prestamos.at(id);
}

/**
 * @brief Imprime en pantalla información del básica del préstamo
 * 
 * @param id Identificacion unica del prestamo
 */
void Banco::obtenerInfoPrestamos(const unsigned int &id)
{
    Prestamo prestamo = prestamos.at(id);
    prestamo.obtenerInfo();
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
Cliente Banco::agregarCliente(const unsigned int &id, const std::string &nombre)
{
    Cliente cliente(id, nombre);
    clientes[id] = cliente;
    return cliente;
}