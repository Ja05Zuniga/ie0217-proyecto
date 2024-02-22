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
    std::unordered_map<unsigned int, Cliente> clientes;
    // Instancia de la clase Prestamos relacionada a la Banco (3 tipos)
    std::array<Prestamo, 3> prestamos;
    // Instancia de la clase Ccertificado relacionada a la Banco
    std::unordered_map<unsigned int, Certificado> certificados;

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
    Cliente buscarCliente(const unsigned int &id);

    /**
     * @brief Busca el cliente en el contenedor de prestamos
     * 
     * @param id Identificacion unica del prestamo
     * @return Prestamo Una instancia del clase Prestamo
     */
    Prestamo buscarPrestamo(const unsigned int &id);

    /**
     * @brief Imprime en pantalla información del básica del préstamo
     * 
     * @param id Identificacion unica del prestamo
     */
    void obtenerInfoPrestamos(const unsigned int &id);

    /**
     * @brief Imprime en pantalla informacion basica del certificado
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
    Cliente agregarCliente(const unsigned int &id, const std::string &nombre);
};

#endif