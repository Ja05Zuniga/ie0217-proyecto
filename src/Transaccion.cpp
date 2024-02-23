/**
 * @file Transaccion.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Transaccion.hpp"
Transaccion::Transaccion() {}
Transaccion::Transaccion(Producto *pagador, Producto *receptor, Dinero monto) : pagador(pagador), receptor(receptor), monto(monto)
{
}

void Transaccion::operator()()
{
    receptor->verificarCredito(monto);
    pagador->verificarDebito(monto);
    try
    {
        receptor->acreditar(monto);
        pagador->debitar(monto);
        registrarFechaHora();
        registrarTransaccion("transacciones.csv");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ocurrió un error inesperado" << '\n';
    }
}

/**
 * @brief Destroy the Transaccion:: Transaccion object
 * @details Aquí nos aseguramos que se destroyan los objetos de 
 * la clase efectivo si fueron creados
 * 
 */
Transaccion::~Transaccion()
{
    if (pagador != nullptr && pagador->obtenerNombre() == "Efectivo")
    {
        delete pagador;
    }
    else if (receptor != nullptr && receptor->obtenerNombre() == "Efectivo")
    {
        delete receptor;
    }
}
unsigned int Transaccion::generarId()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(Constantes::NUM_PRESTAMOS, 999999999);
    id = distr(eng);
    return id;
}

void Transaccion::registrarFechaHora()
{
    auto ahora = std::chrono::system_clock::now();
    time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", localtime(&tiempoActual));
}

std::ostream &operator<<(std::ostream &out, const Transaccion &transaccion)
{
    char delimitador = ',';
    if (transaccion.pagador && transaccion.receptor)
    {
        out << transaccion.fechaHora << delimitador << *transaccion.pagador << delimitador << *transaccion.receptor << delimitador << transaccion.monto << std::endl;
    }
    else
    {
        throw std::invalid_argument("El objeto transacción debe estar inicializado antes de escribirlo");
    }

    return (out);
}

void Transaccion::registrarTransaccion(const std::string &archivoCSV)
{
    std::ofstream of(archivoCSV, std::ios::app);

    if (!of.is_open())
    {
        throw std::runtime_error("Error al abrir archivo de registro de transacciones");
    }

    of << *this;
    of.close();
}

const char *TransaccionFallida::what() const noexcept
{
    return "No se pudo realizar la transacción";
}