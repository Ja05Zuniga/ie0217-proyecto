/**
 * @file Cliente.hpp
 * @authors J. Zuñiga, A. Franchi, G. Escobar
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

/**
 * @class Cliente
 * @brief Gestiona la informacion y las operaciones financieras de un cliente.
 *
 * La clase Cliente se encarga de almacenar los detalles del cliente, como prestamos y
 * cuentas bancarias en diferentes monedas. Proporciona metodos para agregar y consultar
 * prestamos
 */
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

    /**
     * @brief Obtiene la cuenta del cliente segun la moneda
     * 
     * @param moneda Tipo  de moneda del prestamo.
     * @return Cuenta* 
     */
    Cuenta *obtenerCuenta(Moneda moneda);

    /**
    * @brief Agrega un nuevo prestamo al cliente.
    * 
    * @param *prestamo Puntero de Prestamo a agregar.
    * @param metodo Tipo  de metodo de pago del prestamo.
    */ 
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
     * @param moneda Tipo de moneda de la cuenta a consultar
     */
    void obtenerEstadoCuenta(Moneda moneda);

        
    void activacionCuenta(Moneda moneda, bool activacion);

    friend std::istream &operator>>(std::istream &in, Cliente &Cliente);
    unsigned int obtenerId();
    Cliente(const Cliente &otro);

};

#endif