/**
 * @file Banco.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef BANCO_HPP
#define BANCO_HPP
#include "Cliente.hpp"
#include "Prestamo.hpp"
#include "Certificado.hpp"
#include <unordered_map>
#include <map>
#include <array>

/**
 * @class Banco
 * @brief Clase que gestiona los clientes, prestamos y certificados del banco en el sistema financiero.
 *
 * La clase permite almacenar y manejar informacion sobre los clientes, prestamos y certificados. 
 */
class Banco
{
<<<<<<< HEAD
// Atributos privados de la clase Banco
private:
    // Instancia de la clase Cliente relacionada a la Banco
    std::unordered_map<unsigned int, Cliente> clientes;
    // Instancia de la clase Prestamos relacionada a la Banco (3 tipos)
    std::array<Prestamo, 3> prestamos;
    // Instancia de la clase Ccertificado relacionada a la Banco
=======
    /**
     * @brief Clase para almacenar y manejar instancias de la clase Préstamo, Certificados y Clientes
     *
     */
private:
    std::unordered_map<unsigned int, Cliente *> clientes;
    // ID dueño, luego ID propio
    std::map<std::pair<int, int>, Prestamo *> prestamos;
>>>>>>> 1c211b2b0e820185541ffa1c69879a58a32f6075
    std::unordered_map<unsigned int, Certificado> certificados;
    std::array<Prestamo, Constantes::NUM_PRESTAMOS> prestamosPredefinidos;

public:
    /**
<<<<<<< HEAD
     * @brief Constructor de la clase Banco
=======
     * @brief Construct a new Banco object
     *
>>>>>>> 1c211b2b0e820185541ffa1c69879a58a32f6075
     */
    Banco();

    /**
<<<<<<< HEAD
     * @brief Destructor de la clase Banco
     */
    ~Banco();

    /**
     * @brief Busca el cliente por su ced (id) en el contenedor de clientes
     * 
     * @param id numero de indentificacion del cliente
     * @return Cliente Una instancia del clase Cliente
=======
     * @brief Busca el cliente en el contenedor de clientes
     *
     * @param id
     * @return Cliente
>>>>>>> 1c211b2b0e820185541ffa1c69879a58a32f6075
     */
    Cliente *buscarCliente(const unsigned int &id);

    /**
<<<<<<< HEAD
     * @brief Busca el cliente en el contenedor de prestamos
     * 
     * @param id Identificacion unica del prestamo
     * @return Prestamo Una instancia del clase Prestamo
=======
     * @brief Busca el préstamo en el contenedor de préstamos
     *
     * @param id
     * @return Prestamo
>>>>>>> 1c211b2b0e820185541ffa1c69879a58a32f6075
     */
    Prestamo *buscarPrestamo(const int id);

    /**
     * @brief Busca el préstamo en el contenedor de préstamos
     *
     * @param id
     * @return Prestamo
     */
    Prestamo *buscarPrestamo(const unsigned int &id, const unsigned int &idDueno);

    /**
     * @brief Imprime en pantalla información del básica del préstamo
<<<<<<< HEAD
     * 
     * @param id Identificacion unica del prestamo
=======
     *
     * @param id
>>>>>>> 1c211b2b0e820185541ffa1c69879a58a32f6075
     */
    void obtenerInfoPrestamos(const unsigned int &id);

    /**
<<<<<<< HEAD
     * @brief Imprime en pantalla informacion basica del certificado
     * 
     * @param id Identificacion unica del certificado
=======
     * @brief Imprime en pantalla información del básica del préstamo
     *
     * @param id
     */
    void obtenerInfoPrestamos();

    /**
     * @brief Imprime en pantalla información básica del certificado
     *
     * @param id
>>>>>>> 1c211b2b0e820185541ffa1c69879a58a32f6075
     */
    void obtenerInfoCertificados(const unsigned int &id);

    /**
     * @brief Agrega un cliente al contenedor clientes
<<<<<<< HEAD
     * 
     * @param id cedula de identificacion del cliente
     * @param nombre Nombre del cliente a registrar
     * @return Cliente Una instancia del clase Cliente
=======
     *
     * @param id
     * @param nombre
     * @return Cliente
>>>>>>> 1c211b2b0e820185541ffa1c69879a58a32f6075
     */
    Cliente *agregarCliente(const unsigned int &id, const std::string &nombre);
    void cargarPrestamos(const std::string &archivoCSV);
    void cargarClientes(const std::string &archivoCSV);
    void agregarPrestamo(Prestamo *prestamo);
    void obtenerInfoPrestamos(const unsigned int &id, const unsigned int &idDueno);
    Prestamo buscarPrestamoOfrecido(const unsigned int id);
    void obtenerInfoPrestamosCliente(const int id);
};

#endif