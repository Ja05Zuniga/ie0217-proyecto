/**
 * @file Cliente.hpp
 * @author J. Zuñiga, A. Franchi, G. Escobar
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

private:
    unsigned int userId;
    std::string nombre;
    std::unordered_map<unsigned int, Prestamo> prestamos;
    Cuenta cuentaColones;
    Cuenta cuentaDolares;

public:
    /**
     * @brief Constructor de la clase Cliente
     */
    Cliente();

    /**
     * @brief Constructor de la clase Cliente con ID de usuario y nombre.
     * @param userId Identificador unico (cedula) del cliente.
     * @param nombre Nombre del cliente.
     */
    Cliente(unsigned int userId, std::string nombre);

    /**
     * @brief Destructor de la clase Cliente.
     */
    ~Cliente();

    /**
     * @brief Muestra la información básica del cliente
     */
    void obtenerInfo();

    Cuenta *obtenerCuenta(Moneda moneda);
    void pagarPrestamo(Prestamo *prestamo, MetodoPago metodo);
    /**
     * @brief Busca un préstamo del usuario a partir de su ID
     *
     * @param id Identificador unico del prestamo a buscar
     * @return Prestamo El prestamo buscado
     */
    Prestamo buscarPrestamo(const unsigned int id) const;

    /**
     * @brief Permite consultar información detallada del préstamo por el ID 
     * a partir de su ID
     *
     * @param id Identificador unico del prestamo a consultar.
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