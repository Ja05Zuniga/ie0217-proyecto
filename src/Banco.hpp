/**
 * @file Banco.hpp
 * @authors J. Zuñiga, A. Franchi, G. Escobar
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
    // Atributos privados de la clase Banco
private:
    // Instancia de la clase Cliente relacionada a la Banco
    std::unordered_map<unsigned int, Cliente *> clientes;
    std::unordered_map<unsigned int, Cuenta *> cuentasColones;
    std::unordered_map<unsigned int, Cuenta *> cuentasDolares;
    // ID dueño, luego ID propio
    std::map<std::pair<int, int>, Prestamo *> prestamos;
    std::unordered_map<unsigned int, Certificado> certificados;
    std::array<Prestamo, Constantes::NUM_PRESTAMOS> prestamosPredefinidos;

public:
    /**
     * @brief Constructor de la clase Banco
     */
    Banco();

    /**
     * @brief Destructor de la clase Banco
     */
    ~Banco();

    /**
     * @brief Busca el cliente por su ced (id) en el contenedor de clientes
     *
     * @param id numero de indentificacion del cliente
     * @return Cliente Una instancia del clase Cliente
     */
    Cliente *buscarCliente(const unsigned int &id);

    /**
     * @brief Busca el cliente en el contenedor de prestamos
     *
     * @param id Identificacion unica del prestamo
     * @return Prestamo Una instancia del clase Prestamo
     */
    Prestamo *buscarPrestamo(const int id);

    /**
     * @brief Busca el préstamo en el contenedor de préstamos
     *
     * @param &id
     * @param &idDueno
     * @return Prestamo
     */
    Prestamo *buscarPrestamo(const unsigned int &id, const unsigned int &idDueno);

    /**
     * @brief Busca la cuenta en el contenedor de cuentas apropiado
     * 
     * @param id 
     * @param moneda 
     * @return Cuenta* 
     */
    Cuenta *buscarCuenta(const unsigned int id, Moneda moneda);

    /**
     * @brief Imprime en pantalla información del básica del préstamo
     *
     * @param id Identificacion unica del prestamo
     */
    void obtenerInfoPrestamos(const unsigned int &id);

    /**
     * @brief Imprime en pantalla información del básica del préstamo
     *
     * @param id
     */
    void obtenerInfoPrestamos();

    /**
     * @brief Imprime en pantalla información básica del certificado
     *
     * @param id Identificacion unica del certificado
     */
    void obtenerInfoCertificados(const unsigned int &id);

    /**
     * @brief Agrega un cliente al contenedor clientes
     *
     * @param id cedula de identificacion del cliente
     * @param nombre Nombre del cliente a registrar
     * @return Cliente Una instancia del clase Cliente
     */
    Cliente *agregarCliente(const unsigned int &id, const std::string &nombre);

    // Heredando metodos de la clase Banco
    void cargarPrestamos(const std::string &archivoCSV);
    void cargarCuentas(const std::string &archivoCSV);
    void registrarPrestamos(const std::string &archivoCSV);
    void registrarCuentas(const std::string &archivoCSV);
    void cargarClientes(const std::string &archivoCSV);
    void agregarPrestamo(Prestamo *prestamo);
    void agregarCuenta(Cuenta *cuenta);
    void obtenerInfoPrestamos(const unsigned int &id, const unsigned int &idDueno);
    Prestamo buscarPrestamoOfrecido(const unsigned int id);
    void obtenerInfoPrestamosCliente(const int id);
    void clean();
};

#endif