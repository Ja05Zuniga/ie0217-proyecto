/**
 * @file Transaccion.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef TRANSACCION_HPP
#define TRANSACCION_HPP
#include "Producto.hpp"
#include "Dinero.hpp"
#include "constants.hpp"
/**
 * @brief Clase para realizar transacciones y registrarlas
 * 
 */
class Transaccion
{
private:
    unsigned int id;
    Producto *pagador;
    Producto *receptor;
    Dinero monto;

public:
    /**
     * @brief Construct a new Transaccion object
     * 
     * @param pagador 
     * @param receptor 
     * @param monto 
     */
    Transaccion(Producto *pagador, Producto *receptor, Dinero monto);
    /**
     * @brief Construct a new Transaccion object
     * 
     */
    Transaccion();
    /**
     * @brief Destroy the Transaccion object
     * 
     */
    ~Transaccion();
    /**
     * @brief Genera un ID aleatorio
     * 
     * @return unsigned int 
     */
    unsigned int generarId();
    /**
     * @brief Realiza la transacción del pagador al receptor por el
     * monto especificado en el altributo monto
     * 
     */
    void operator()() const;
};

#endif