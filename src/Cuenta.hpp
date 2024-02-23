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

/**
 * @brief Clase para realizar operaciones sobre las cuentas y obtener su información
 *
 */
class Cuenta : public Producto
{
private:
    // Por defecto las cuentas están activas
    bool estado = true;
    Dinero ahorros;
    Moneda moneda;

public:
    Cuenta(/* args */);
    Cuenta(const Cuenta &otro);
    Cuenta(const float &monto, Moneda moneda, unsigned int id);
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
    void acreditar(Dinero &monto) override;

    /**
     * @brief Método para debitar dinero de la cuenta
     *
     * @param monto
     */
    void debitar(Dinero &monto) override;
    void verificarDebito(Dinero &monto) override;
    void verificarCredito(Dinero &monto) override;
    Moneda obtenerMoneda();

    friend std::istream &operator>>(std::istream &in, Cuenta &cuenta);
    friend std::ostream &operator<<(std::ostream &os, Cuenta &cuenta);

    /**
     * @brief Devuelve un booleano indicando el estado de la cuenta
     *
     * @return Estado
     */
    bool obtenerEstado();

    void cambiarEstado(bool nuevoEstado);
};
/**
 * @brief Excepción para lanzar en el caso de cuentas inactivas
 *
 */
class CuentaInactiva : public std::exception
{
public:
    const char *what() const noexcept override;
};
/**
 * @brief Excepción para lanzar en el caso fondos insuficientes
 *
 */
class FondosInsuficientes : public std::exception
{
public:
    const char *what() const noexcept override;
};
#endif