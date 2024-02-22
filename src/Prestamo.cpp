/**
 * @file Prestamo.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Prestamo.hpp"

Prestamo::~Prestamo() {}

/**
 * @brief Constructor por defecto de la clase Prestamo.
 * 
 * Se inicializa un prestamo con el arg. "Prestamo" por defecto.
 */
Prestamo::Prestamo() : Producto("Prestamo") {}

/**
 * @brief Constructor de la clase Prestamo con parametros especificos.
 * Inicializa un prestamo con valores especificos y calcula la tasa de interes mensual.
 * 
 * @param tipo Tipo de prestamo.
 * @param cuotas Numero de cuotas del prestamo.
 * @param tasaInteresAnual Tasa de interes anual del prestamo.
 * @param id Identificador unico del prestamo.
 * 
 */
Prestamo::Prestamo(const TipoPrestamo &tipo, const unsigned int &cuotas, const float &tasaInteresAnual, const unsigned int &id) : Producto("Prestamo", id), tipo(tipo), cuotas(cuotas), tasaInteresAnual(tasaInteresAnual)
{
}

/**
 * @brief Imprime en pantalla informacion basica del prestamo.
 */
void Prestamo::obtenerInfo()
{
    std::string tipo_str;
    
    // Casos para los prestamos
    switch (tipo)
    {
    case 0:
        tipo_str = "Personal";
        break;
    case 1:
        tipo_str = "Prendario";
        break;
    case 2:
        tipo_str = "Hipotecario";

    default:
        break;
    }

    // Imprime la tabla con los valores con un formato establecido
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << id
              << std::setw(Constantes::COL_WIDTH) << std::left << tipo_str
              << std::setw(Constantes::COL_WIDTH) << std::left << cuotas
              << std::setw(Constantes::COL_WIDTH) << std::left << tasaInteresAnual << std::endl;
}

/**
 * @brief Imprime información detallada del préstamo.
 */ 
void Prestamo::obtenerInfoPersonal()
{
    std::string tipo_str;
    switch (tipo)
    {
    case 0:
        tipo_str = "Personal";
        break;
    case 1:
        tipo_str = "Prendario";
        break;
    case 2:
        tipo_str = "Hipotecario";

    default:
        break;
    }

    std::cout << "ID: " << id << "\n"
              << "Tipo de préstamo: " << tipo_str << "\n"
              << "Cuotas: " << cuotas << "\n"
              << "Monto de préstamo: " << montoInicial << "\n"
              << "Saldo restante: " << saldoRestante << "\n"
              << "Cuota mensual: " << cuotaMensual << "\n"
              << "Mes: " << numCuota << "\n"
              << "Tasa de interés anual: " << tasaInteresAnual << std::endl;
}

/**
 * @details Aquí se define como actualizar el objeto cada vez que el usuario paga
 *
 * @param monto Monto del pago realizado.
 */
void Prestamo::acreditar(const Dinero &monto)
{
    numCuota += 1;
    // FIXME: Falta terminar de implementar logica necesaria
}

/**
 * @details Por debitar a un préstamo se entiende que este se está abriendo por un usuario y se le hará el
 * depósito respectivo. Por esta razón, aquí se incializa la información relacionada a un préstamo específico.
 *
 * @param monto Monto del prestamo al abrirlo.
 */
void Prestamo::debitar(const Dinero &monto)
{
    generarId();
    montoInicial = monto;
    saldoRestante = monto;
    numCuota = 0;
    tasaInteresMensual = tasaInteresAnual / 12 / 100;
    float montoCuotaMensual = (tasaInteresMensual * monto.obtenerMonto()) / (1 - std::pow(1 + tasaInteresMensual, -cuotas));
    cuotaMensual = Dinero(montoCuotaMensual, monto.obtenerMoneda());
}

/**
 * @details Calcula la tabla de amortización para el préstamo.
 * Genera el desglose de los pagos mensuales incluyendo interés y amortización principal.
 */
void Prestamo::calcularAmortizacion()
{
    float montoSaldoRestante = montoInicial.obtenerMonto();
    amortizacion.clear();
    float montoCuotaMensual = cuotaMensual.obtenerMonto();

    for (int cuota = 1; cuota <= cuotas + 1; ++cuota)
    {
        float interesPendiente = montoSaldoRestante * tasaInteresMensual;
        float amortizacionPrincipal = montoCuotaMensual - interesPendiente;

        montoSaldoRestante -= amortizacionPrincipal;

        // Usa un struct de tipo Amortizacion para almacenar info del pago
        Amortizacion pago = {cuota, interesPendiente, amortizacionPrincipal, montoSaldoRestante};
        amortizacion.push_back(pago);
    }
}
