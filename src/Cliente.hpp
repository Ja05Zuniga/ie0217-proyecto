/**
 * @file Cliente.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>
#include <iostream>
#include <unordered_map>
#include "Prestamo.hpp"
#include "Dinero.hpp"
#include "Transaccion.hpp"
#include "Cuenta.hpp"

class Cliente
{
/**
 * @brief Clase para gestionar tramites del cliente
 * 
 */
private:
    unsigned int userId;
    std::string nombre;
    std::unordered_map<unsigned int, Prestamo> prestamos;
    Cuenta cuentaColones;
    Cuenta cuentaDolares;

public:
    /**
     * @brief Construct a new Cliente object
     * 
     */
    Cliente();
    /**
     * @brief Construct a new Cliente object
     * 
     * @param userId 
     * @param nombre 
     */
    Cliente(unsigned int userId, std::string nombre);
    ~Cliente();
    /**
     * @brief Muestra la información básica del cliente
     * 
     */
    void obtenerInfo();

    /**
     * @brief Permite agregar un nuevo préstamo al cliente
     * 
     * @param prestamos 
     * @param monto 
     * @param moneda 
     * @return unsigned int 
     */
    unsigned int agregarPrestamo(Prestamo prestamos, const float &monto, Moneda moneda);

    /**
     * @brief Busca un préstamo del usuario a partir de su ID
     * 
     * @param id 
     * @return Prestamo 
     */
    Prestamo buscarPrestamo(const unsigned int &id);
    void obtenerInfoPrestamo(const unsigned int &id);
    void obtenerInfoPrestamos();
    void obtenerEstadoCuenta(Moneda moneda);
    void debitar();
};

#endif