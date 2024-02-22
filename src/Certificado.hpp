/**
 * @file Certificado.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CERTIFICADO_HPP
#define CERTIFICADO_HPP
#include "Producto.hpp"

/**
 * @brief Clase para realizar operaciones sobre certificados
 *
 */
class Certificado : public Producto
{

private:
    Dinero dinero;

public:
    Certificado(const unsigned int id);
    ~Certificado();
    /**
     * @brief Método para mostrar información general del certificado
     * 
     */
    void obtenerInfo() override;
    /**
     * @brief Método virtual heredado de la clase producto
     *
     * @param monto
     */
    void acreditar(Dinero &monto) override;

    /**
     * @brief Método para actualizar el estado del objeto una vez que el usario
     * abre un certificado
     *
     * @param monto
     */
    void debitar(Dinero &monto) override;
};

#endif