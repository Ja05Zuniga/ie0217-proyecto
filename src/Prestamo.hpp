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
#include "Producto.hpp"
#include "Dinero.hpp"
#include "constants.hpp"
#include "Amortizacion.hpp"

/**
* @enum TipoPrestamo
 * @brief Enumeración para representar los distintos tipos de préstamos disponibles
 *
 */
enum TipoPrestamo
{
    PERSONAL,
    PRENDARIO,
    HIPOTECARIO
};

/**
 * @class Prestamo
 * @brief Clase para manipular informacion de prestamos y calcular amortizaciones.
 *
 * Extiende la clase Producto para gestionar los detalles y operaciones de un prestamo,
 * incluyendo el calculo de la amortizacion y llevar la cuenta del saldo restante.
 */
class Prestamo : public Producto
{

// Atributos privados de la clase 
private:
    TipoPrestamo tipo;              // Tipo de prsstamo.
    int cuotas;                     // Numero total de cuotas.
    unsigned int numCuota;          // Numero de la cuota actual.
    float tasaInteresAnual;         // Tasa de interes anual del prestamo.
    float tasaInteresMensual;       // Tasa de interes mensual del prestamo (calc. a partir de la anual).
    Dinero montoInicial;            // Monto inicial del prestamo.
    Dinero saldoRestante;           // Saldo restante del prestamo
    Dinero cuotaMensual;            // Monto de la cuota mensual
    std::vector<Amortizacion> amortizacion;     // Lista de amortizaciones para el prestamo

public:

    /**
     * @brief Constructor de la clase Prestamo
     */
    Prestamo();

    /**
     * @brief Construct a new Prestamo object
     *
     * @param tipo Tipo del prestamo
     * @param cuotas Numero total de cuotas para el prestamo
     * @param tasaInteresAnual Tasa de interes anual del prestamo.
     * @param id Identificador unico del prestamo
     */
    Prestamo(const TipoPrestamo &tipo, const unsigned int &cuotas, const float &tasaInteresAnual, const unsigned int &id);
    
    
    /**
     * @brief Destructor de la clase Prestamo
     */
    ~Prestamo();

    /**
     * @brief Imprime en pantalla información del préstamo
     *
     */
    void obtenerInfo() override;

    /**
     * @brief Actualiza el saldo del préstamo al acreditar un pago.
     * @param monto Monto del pago realizado.
     */
    void acreditar(const Dinero &monto) override;

    /**
     * @brief Inicializa el prestamo y calcula la amortizacion al abrir el prestamo.
     * 
     *  Se define como actualizar el objeto cada vez que un usuario
     * abre el préstamo
     *
     * @param monto Monto inicial del prestamo
     */
    void debitar(const Dinero &monto) override;

    /**
     * @brief Imprime información más detallada del préstamo
     *
     */
    void obtenerInfoPersonal();

    /**
     * @brief Método para inicializar el atributo amortización
     * 
     * El atributo amortizacion contiene el desglose de los pagos mensuales en una tabla
     *
     */
    void calcularAmortizacion();
};

#endif