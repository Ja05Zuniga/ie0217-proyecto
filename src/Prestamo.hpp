/**
 * @file Prestamo.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP
#include <iomanip>
#include "Producto.hpp"
#include "Dinero.hpp"
#include "constants.hpp"
/**
 * @brief Enumeración para representar tipos de préstamo
 *
 */
enum TipoPrestamo
{
    PERSONAL,
    PRENDARIO,
    HIPOTECARIO
};
/**
 * @brief Clase para manipular préstamo y obtener información 
 * 
 */
class Prestamo : public Producto
{
private:
    TipoPrestamo tipo;
    unsigned int cuotas;
    unsigned int numCuota;
    float tasaInteresAnual;
    Dinero montoIncial;
    Dinero montoPagado;

public:
    /**
     * @brief Construct a new Prestamo object
     *
     */
    Prestamo();
    /**
     * @brief Construct a new Prestamo object
     *
     * @param tipo
     * @param cuotas
     * @param tasaInteresAnual
     * @param id
     */
    Prestamo(const TipoPrestamo &tipo, const unsigned int &cuotas, const float &tasaInteresAnual, const unsigned int &id);
    /**
     * @brief Destroy the Prestamo object
     *
     */
    ~Prestamo();
    /**
     * @brief Imprime en pantalla información del préstamo
     *
     */
    void obtenerInfo() override;
    /**
     * @brief Aquí se define como actualizar el objeto cada vez que el usuario paga
     *
     * @param monto
     */
    void acreditar(const Dinero &monto) override;
    /**
     * @brief Aquí se define como actualizar el objeto cada vez que un usuario
     * abre el préstamo
     *
     * @param monto
     */
    void debitar(const Dinero &monto) override;
    /**
     * @brief Imprime información más detallada del préstamo
     *
     */
    void obtenerInfoPersonal();
};

#endif