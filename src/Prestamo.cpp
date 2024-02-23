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

std::istream &operator>>(std::istream &is, TipoPrestamo &tipo)
{
    int tipoInt;
    is >> tipoInt;

    switch (tipoInt)
    {
    case 0:
        tipo = PERSONAL;
        break;
    case 3:
        tipo = PRENDARIO;
        break;
    case 6:
        tipo = HIPOTECARIO;
        break;
    default:
        is.setstate(std::ios::failbit);
        break;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, TipoPrestamo &tipo)
{
    int tipoInt;
    switch (tipo)
    {
    case PERSONAL:
        tipoInt = 0;
        break;
    case PRENDARIO:
        tipoInt = 3;
        break;
    case HIPOTECARIO:
        tipoInt = 6;
        break;
    default:
        break;
    }
    os << tipoInt;
    return os;
}

std::istream &operator>>(std::istream &in, Prestamo &prestamo)
{
    char delimitador;
    in >> prestamo.idDueno >> delimitador >> prestamo.id >> delimitador >> prestamo.tipo >> delimitador >> prestamo.cuotas >> delimitador >> prestamo.tasaInteresAnual >> delimitador >> prestamo.montoInicial >> delimitador >> prestamo.numCuota;
    return in;
}

std::ostream &operator<<(std::ostream &os, Prestamo &prestamo)
{
    char delimitador = ',';
    os << prestamo.idDueno << delimitador << prestamo.id << delimitador << prestamo.tipo << delimitador << prestamo.cuotas << delimitador << prestamo.tasaInteresAnual << delimitador << prestamo.montoInicial << delimitador << prestamo.numCuota;
    return os;
}

Prestamo::~Prestamo()
{
}

Prestamo::Prestamo() : Producto("Prestamo") {}

Prestamo::Prestamo(const TipoPrestamo &tipo, const unsigned int &cuotas, const float &tasaInteresAnual, const unsigned int &id) : Producto("Prestamo", id), tipo(tipo), cuotas(cuotas), tasaInteresAnual(tasaInteresAnual)
{
    numCuota = 0;
    tasaInteresMensual = tasaInteresAnual / 12 / 100;
}

void Prestamo::obtenerInfo()
{
    std::string tipo_str;
    switch (tipo)
    {
    case PERSONAL:
        tipo_str = "Personal";
        break;
    case PRENDARIO:
        tipo_str = "Prendario";
        break;
    case HIPOTECARIO:
        tipo_str = "Hipotecario";

    default:
        break;
    }

    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << id
              << std::setw(Constantes::COL_WIDTH) << std::left << tipo_str
              << std::setw(Constantes::COL_WIDTH) << std::left << cuotas
              << std::setw(Constantes::COL_WIDTH) << std::left << tasaInteresAnual << std::endl;
}

void Prestamo::obtenerInfoPersonal(bool reducida)
{
    std::string tipo_str;
    switch (tipo)
    {
    case PERSONAL:
        tipo_str = "Personal";
        break;
    case PRENDARIO:
        tipo_str = "Prendario";
        break;
    case HIPOTECARIO:
        tipo_str = "Hipotecario";

    default:
        break;
    }

    if (!reducida)
    {
        std::cout << "ID: " << id << "\n"
                  << "Tipo de préstamo: " << tipo_str << "\n"
                  << "Cuotas: " << cuotas << "\n"
                  << "Monto de préstamo: " << montoInicial.obtenerMoneda() << montoInicial.obtenerMonto() << "\n"
                  << "Cuota mensual: " << cuotaMensual.obtenerMoneda() << cuotaMensual.obtenerMonto() << "\n"
                  << "Mes: " << numCuota << "\n"
                  << "Tasa de interés anual: " << tasaInteresAnual << std::endl;
    }
    else
    {
        std::cout << std::setw(Constantes::COL_WIDTH) << std::left << id
                  << std::setw(Constantes::COL_WIDTH) << std::left << tipo_str
                  << std::setw(Constantes::COL_WIDTH) << std::left << cuotas
                  << std::setw(Constantes::COL_WIDTH) << std::left << tasaInteresAnual
                  << std::setw(Constantes::COL_WIDTH) << std::left << montoInicial.obtenerMoneda()
                  << std::setw(Constantes::COL_WIDTH) << std::left << montoInicial.obtenerMonto() << std::endl;
    }
}
void Prestamo::acreditar(Dinero &monto)
{
    numCuota += 1;
}

/**
 * @ Por debitar a un préstamo se entiende que este se está abriendo por un usuario y se le hará el
 * depósito respectivo. Por esta razón, aquí se incializa la información relacionada a un préstamo específico.
 *
 * @param monto
 */
void Prestamo::debitar(Dinero &monto)
{

    montoInicial = monto;
    numCuota = 0;

    calcularAmortizacion();
}

/**
 * @brief Los datos de la amortización se almacenan en una vector que alamcena
 * estructuras
 *
 */
void Prestamo::calcularAmortizacion()
{
    float montoCuotaMensual = (tasaInteresMensual * montoInicial.obtenerMonto()) / (1 - std::pow(1 + tasaInteresMensual, -cuotas));
    cuotaMensual = Dinero(montoCuotaMensual, montoInicial.obtenerMoneda());
    float montoSaldoRestante = montoInicial.obtenerMonto();
    amortizacion.clear();

    for (int cuota = 1; cuota <= cuotas + 1; ++cuota)
    {
        float interesPendiente = montoSaldoRestante * tasaInteresMensual;
        float amortizacionPrincipal = montoCuotaMensual - interesPendiente;

        montoSaldoRestante -= amortizacionPrincipal;

        Amortizacion pago = {cuota, interesPendiente, amortizacionPrincipal, montoSaldoRestante};
        amortizacion.push_back(pago);
    }
}

void Prestamo::obtenerAmortizacion()
{
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << "Cuota"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Intereses"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Amortización"
              << std::setw(Constantes::COL_WIDTH) << std::left << "Saldo restante" << std::endl;
    for (size_t i = 0; i < amortizacion.size(); i++)
    {
        imprimirDesglosePago(i);
    }
}

Dinero Prestamo::obtenerCuotaMensual() { return cuotaMensual; }

void Prestamo::imprimirDesglosePago()
{

    Amortizacion pago = amortizacion.at(numCuota);
    std::cout << std::left
              << std::setw(Constantes::COL_WIDTH) << "Cuota"
              << std::setw(Constantes::COL_WIDTH) << "Intereses"
              << std::setw(Constantes::COL_WIDTH) << "Amortización"
              << std::setw(Constantes::COL_WIDTH) << "Total"
              << std::setw(Constantes::COL_WIDTH) << "Moneda"
              << std::setw(Constantes::COL_WIDTH) << "Saldo restante" << std::endl;
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << pago.cuota
              << std::setw(Constantes::COL_WIDTH) << std::left << pago.intereses
              << std::setw(Constantes::COL_WIDTH) << std::left << pago.amortizacion
              << std::setw(Constantes::COL_WIDTH) << std::left << cuotaMensual.obtenerMonto()
              << std::setw(Constantes::COL_WIDTH) << std::left << cuotaMensual.obtenerMoneda()
              << std::setw(Constantes::COL_WIDTH) << std::left << pago.saldoRestante << std::endl;
}

void Prestamo::imprimirDesglosePago(unsigned int id)
{
    Amortizacion pago = amortizacion.at(id);
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << pago.cuota
              << std::setw(Constantes::COL_WIDTH) << std::left << pago.intereses
              << std::setw(Constantes::COL_WIDTH) << std::left << pago.amortizacion
              << std::setw(Constantes::COL_WIDTH) << std::left << pago.saldoRestante << std::endl;
}

int Prestamo::solicitarIDprestamo()
{
    std::string input;
    int id;

    while (true)
    {
        try
        {
            std::cout << "Ingrese el ID del préstamo o escriba 'cancelar' para cancelar: \n";
            std::cin >> input;

            if (input == "cancelar")
            {
                return -1;
            }

            std::stringstream ss(input);
            if (!(ss >> id) || !ss.eof())
            {
                throw std::invalid_argument("Entrada inválida: Debe ingresar un valor entero.");
            }

            if (id < 0 || id > std::numeric_limits<int>::max())
            {
                throw std::out_of_range("ID fuera de rango. El valor debe ser un número entero no negativo.");
            }

            return id;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

Prestamo::Prestamo(const Prestamo &otro) : Producto("Prestamo", otro.id), idDueno(otro.idDueno), tipo(otro.tipo), cuotas(otro.cuotas), tasaInteresAnual(otro.tasaInteresAnual)
{
    tasaInteresMensual = tasaInteresAnual / 12 / 100;
    if (otro.montoInicial.obtenerMonto() > 0)
    {
        idDueno = otro.idDueno;
        montoInicial = otro.montoInicial;
        numCuota = otro.numCuota;
        calcularAmortizacion();
    }
}

void Prestamo::asignarDueno(const unsigned int id)
{
    idDueno = id;
}

unsigned int Prestamo::obtenerDueno()
{
    return idDueno;
}

void Prestamo::verificarDebito(Dinero &monto)
{
    return;
}

void Prestamo::verificarCredito(Dinero &monto)
{
    if (numCuota >= cuotas)
    {
        throw PagoInvalido();
    }
    return;
}

const char *PagoInvalido::what() const noexcept
{
    return "El préstamo ya fue cancelado";
}