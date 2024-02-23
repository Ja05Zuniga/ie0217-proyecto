/**
 * @file Transaccion.hpp
 * @authors J. Zuñiga, A. Franchi, G. Escobar
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
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

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
    char fechaHora[100];

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
    void operator()();
    void registrarFechaHora();
    friend std::ostream &operator<<(std::ostream &out, const Transaccion &obj);
    void registrarTransaccion(const std::string &archivoCSV);
};

/**
 * @brief Excepción para indicar transacción fallida
 *
 */
class TransaccionFallida : public std::exception
{
public:
    const char *what() const noexcept override;
};

#endif