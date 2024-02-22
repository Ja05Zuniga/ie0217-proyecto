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
#include "MetodoPago.hpp"
#include "Efectivo.hpp"

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

    Cuenta *obtenerCuenta(Moneda moneda);
    void pagarPrestamo(Prestamo *prestamo, MetodoPago metodo);
    /**
     * @brief Busca un préstamo del usuario a partir de su ID
     *
     * @param id
     * @return Prestamo
     */
    Prestamo buscarPrestamo(const unsigned int id) const;

    /**
     * @brief Permite consultar información detallada del préstamo
     * a partir de su ID
     *
     * @param id
     */
    void obtenerInfoPrestamo(const unsigned int &id);

    /**
     * @brief Imprime información general de todos los préstamos del usuario
     *
     */
    void obtenerInfoPrestamos();

    /**
     * @brief Imprime información detallada de la cuenta en la moneda ingresada
     *
     * @param moneda
     */
    void obtenerEstadoCuenta(Moneda moneda);

    friend std::istream &operator>>(std::istream &in, Cliente &Cliente);
    unsigned int obtenerId();
    Cliente(const Cliente &otro);
};

#endif