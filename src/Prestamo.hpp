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
#include <cmath>
#include <list>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <regex>
#include "Producto.hpp"
#include "Dinero.hpp"
#include "constants.hpp"
#include "Amortizacion.hpp"
/**
 * @brief Enumeración para representar tipos de préstamo
 *
 */
enum TipoPrestamo
{
    PERSONAL,
    PRENDARIO = 3,
    HIPOTECARIO = 6
};
std::istream &operator>>(std::istream &is, TipoPrestamo &tipo);
/**
 * @brief Clase para manipular préstamo y obtener información
 *
 */
class Prestamo : public Producto
{
private:
    unsigned int idDueno;
    TipoPrestamo tipo;
    int cuotas;
    unsigned int numCuota;
    float tasaInteresAnual;
    float tasaInteresMensual;
    Dinero montoInicial;
    Dinero cuotaMensual;
    std::vector<Amortizacion> amortizacion;

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
    void acreditar(Dinero &monto) override;
    /**
     * @brief Aquí se define como actualizar el objeto cada vez que un usuario
     * abre el préstamo
     *
     * @param monto
     */
    void debitar(Dinero &monto) override;
    /**
     * @brief Imprime información más detallada del préstamo
     *
     */
    void obtenerInfoPersonal(bool reducida = false);
    /**
     * @brief Método para inicializar el atributo amortización
     * el cual contiene el desglose de los pagos mensuales.
     *
     */
    void calcularAmortizacion();
    /**
     * @brief Imprime en pantalla la tabla de pago del préstamo
     *
     */
    void obtenerAmortizacion();
    Dinero obtenerCuotaMensual();
    void imprimirDesglosePago();
    void imprimirDesglosePago(unsigned int id);
    friend std::istream &operator>>(std::istream &in, Prestamo &prestamo);
    static int solicitarIDprestamo();
    Prestamo(const Prestamo &otro);
    void asignarDueno(const unsigned int id);
    unsigned int obtenerDueno();
    void calcularCuotaMensual();
};

#endif