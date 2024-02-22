/**
 * @file MetodoPago.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef METODOPAGO_HPP
#define METODOPAGO_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
/**
 * @brief Enumeracion para representar métodos de pago
 *
 */
enum MetodoPago
{
    CUENTA_COLONES,
    CUENTA_DOLARES,
    EFECTIVO
};
std::istream &operator>>(std::istream &is, MetodoPago &metodo);

MetodoPago solicitarMetodoPago();
MetodoPago solicitarMetodoRecepcion();

#endif