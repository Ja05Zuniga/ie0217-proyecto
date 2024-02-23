/**
 * @file Producto.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include <string>
#include <iostream>
#include <random>
#include "Dinero.hpp"

/**
 * @brief Clase abstracta con métodos y atributos heredados por
 * las clases certificado, préstamo y cuenta
 *
 */
class Producto
{
protected:
    // Nombre del producto
    std::string nombre;
    // ID del producto
    unsigned int id;

public:
    /**
     * @brief Construct a new Producto object
     *
     * @param nombre
     */
    Producto(const std::string &nombre);
    /**
     * @brief Construct a new Producto object
     *
     * @param nombre
     * @param id
     */
    Producto(const std::string &nombre, const unsigned int &id);
    /**
     * @brief Destroy the Producto object
     *
     */
    virtual ~Producto();
    /**
     * @brief Genera un ID para el producto
     *
     */
    void generarId();
    /**
     * @brief Devuelve el ID del producto
     *
     * @return unsigned int
     */
    unsigned int obtenerId();
    /**
     * @brief Aquí se imprimirá información general del producto
     *
     */
    virtual void obtenerInfo();
    /**
     * @brief Aquí se define qué significa mover dinero hacia el producto
     *
     * @param monto
     */
    virtual void acreditar(Dinero &monto);
    /**
     * @brief Aquí se define qué significa mover diner desde el producto
     *
     * @param monto
     */
    virtual void debitar(Dinero &monto);
    friend std::ostream &operator<<(std::ostream &out, const Producto &producto);
    std::string obtenerNombre();
    virtual void verificarDebito(const Dinero &monto);
    virtual void verificarCredito(const Dinero &monto);
};

#endif