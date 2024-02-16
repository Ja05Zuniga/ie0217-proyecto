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
class Banco
{
    /**
     * @brief Clase para almacenar y manejar instancias de la clase Préstamo, Certificados y Clientes
     * 
     */
private:
    std::unordered_map<unsigned int, Cliente> clientes;
    std::array<Prestamo, 3> prestamos;
    std::unordered_map<unsigned int, Certificado> certificados;

public:
    /**
     * @brief Construct a new Banco object
     * 
     */
    Banco();
    ~Banco();
    /**
     * @brief Busca el cliente en el contenedor de clientes
     * 
     * @param id 
     * @return Cliente 
     */
    Cliente buscarCliente(const unsigned int &id);

    /**
     * @brief Busca el cliente en el contenedor de préstamos
     * 
     * @param id 
     * @return Prestamo 
     */
    Prestamo buscarPrestamo(const unsigned int &id);

    /**
     * @brief Imprime en pantalla información del básica del préstamo
     * 
     * @param id 
     */
    void obtenerInfoPrestamos(const unsigned int &id);

    /**
     * @brief Imprime en pantalla información básica del certificado
     * 
     * @param id 
     */
    void obtenerInfoCertificados(const unsigned int &id);

    /**
     * @brief Agrega un cliente al contenedor clientes
     * 
     * @param id 
     * @param nombre 
     * @return Cliente 
     */
    Cliente agregarCliente(const unsigned int &id, const std::string &nombre);
};

#endif