/**
 * @file Moneda.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MONEDA_HPP
#define MONEDA_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

/**
 * @brief Enumeracion para representar tipos de moneda
 *
 */
enum Moneda
{
    COLONES = 1,
    DOLARES
};

std::istream &operator>>(std::istream &is, Moneda &moneda);

#endif