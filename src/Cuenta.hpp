/**
 * @file Cuenta.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CUENTA_HPP
#define CUENTA_HPP
#include <iostream>
#include <iomanip>
#include "constants.hpp"
#include "Producto.hpp"
#include "Dinero.hpp"

/**
 * @brief Enumerador para representar el estado de la cuenta
 * 
 */
enum Estado
{
    ACTIVA,
    INACTIVA
};

/**
 * @brief Clase para realizar operaciones sobre las cuentas y obtener su información 
 * 
 */
class Cuenta : public Producto
{
private:
    // Por defecto las cuentas están activas
    Estado estado = ACTIVA;
    Dinero ahorros;
    Moneda moneda;

public:
    Cuenta(/* args */);
    Cuenta(const float &monto, Moneda moneda);
    ~Cuenta();
    /**
     * @brief Imprime información básica de la cuenta
     * 
     */
    void obtenerInfo() override;

    /**
     * @brief Método para acreditar dinero a la cuenta
     * 
     * @param monto 
     */
    void acreditar(const Dinero &monto) override;

    /**
     * @brief Método para debitar dinero de la cuenta
     * 
     * @param monto 
     */
    void debitar(const Dinero &monto) override;

    /**
     * @brief Devuelve un enumerador indicando el estado de la cuenta
     * 
     * @return Estado 
     */
    Estado obtenerEstado();
};

#endif