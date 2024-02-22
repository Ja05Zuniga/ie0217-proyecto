/**
 * @file Dinero.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DINERO_HPP
#define DINERO_HPP
#include <string>
#include <limits>
#include <iostream>
#include "constants.hpp"
#include "Moneda.hpp"
/**
 * @brief Clase necesaria para realizar transacciones, además posee métodos
 * para realizar cambios de moneda
 *
 */
class Dinero
{
protected:
    float tasaCompra = Constantes::TASA_COMPRA;
    float tasaVenta = Constantes::TASA_VENTA;
    float monto;
    Moneda moneda;

public:
    Dinero();
    Dinero(const float &monto, Moneda moneda);
    ~Dinero();
    /**
     * @brief Muestra información básica del dinero
     *
     */
    void mostrarInformacion();

    /**
     * @brief Nos dice cuantos colones ocupamos para comprar
     * la cantidad especificada de dolares
     *
     * @param cantidad dolares a comprar
     * @return Dinero
     */
    Dinero venderColones(const float &cantidad);

    /**
     * @brief Nos dice cuantos colones ocupamos para comprar
     * una cantidad de dolares igual al atributo monto
     *
     * @param cantidad dolares a comprar
     * @return Dinero
     */
    Dinero venderColones();

    /**
     * @brief Devuelve cuantos dolares se compran con la
     * cantidad especificada de colones
     *
     * @param cantidad
     * @return Dinero
     */
    Dinero comprarDolares(const float &cantidad);

    /**
     * @brief Devuelve cuantos dolares se pueden comprar asumiendo que
     * la cantidad de colones es igual al atributo monto
     *
     * @return Dinero
     */
    Dinero comprarDolares();

    /**
     * @brief Nos dice cuantos dolares ocupamos para que el banco nos
     * devuelva la cantidad especificada de colones al vender los dolares
     *
     * @param cantidad
     * @return Dinero
     */
    Dinero comprarColones(const float &cantidad);

    /**
     * @brief Nos dice cuantos dolares ocupamos para que el banco nos
     * devuelva una cantidad de colones igual al atributo monto al vender los dolares
     *
     * @param cantidad
     * @return Dinero
     */
    Dinero comprarColones();

    /**
     * @brief Devuelve cuantos colones nos da el banco al comprar la
     * vender la cantidad especificada de dolares
     *
     * @param cantidad
     * @return Dinero
     */
    Dinero venderDolares(const float &cantidad);

    /**
     * @brief Devuelve cuantos colones nos da el banco al comprar una cantidad
     * de dolares igual al atributo monto
     *
     * @return Dinero
     */
    Dinero venderDolares();

    /**
     * @brief Devuelve el tipo de moneda
     *
     * @return Moneda
     */
    Moneda obtenerMoneda() const;

    /**
     * @brief Devuelve el monto de dinero
     *
     * @return float
     */
    float obtenerMonto() const;

    /**
     * @brief Permite sumar objetos de la clase con el operador +
     *
     *
     * @param otro
     * @return Dinero
     */
    Dinero operator+(const Dinero &otro);

    /**
     * @brief Permite restar objetos de la clase con el operador -
     *
     * @param otro
     * @return Dinero
     */
    Dinero operator-(const Dinero &otro);
    friend std::ostream &operator<<(std::ostream &os, const Dinero &obj);
    void solicitarMoneda();
    void solicitarMonto();
    friend std::istream &operator>>(std::istream &in, Dinero &dinero);
};

#endif