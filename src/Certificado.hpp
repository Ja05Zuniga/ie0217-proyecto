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
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Producto.hpp"

/**
 * @brief Clase para realizar operaciones sobre certificados
 *
 */
class Certificado : public Producto
{

private:
    float tasaInteresAnual;
    float tasaInteresMensual;
    int plazo;
    Dinero montoCertificado;
    Dinero intereses;
    unsigned int idDueno;

public:
    /**
     * @brief Construct a new Certificado object
     *
     */
    Certificado();
    /**
     * @brief Construct a new Certificado object
     *
     * @param montoCertificado
     * @param tasaInteresAnual
     * @param id
     */
    Certificado(const Dinero &montoCertificado, const float &tasaInteresAnual, const unsigned int &id);
    ~Certificado();
    /**
     * @brief Método para mostrar información general del certificado
     *
     */
    void obtenerInfo() override;
    /**
     * @brief Método para mostrar información detallada del certificado
     *
     */
    void obtenerInfoPersonal(bool reducida = true);
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
    Certificado(const Certificado &otro);
    Certificado(const Certificado &otro, int idDueno);

    void debitar(Dinero &monto) override;
    void verificarDebito(Dinero &monto) override;
    void verificarCredito(Dinero &monto) override;
    Certificado(const float &tasaInteresAnual, const unsigned int &id, const int plazo);
    static int solicitarIDcertificado();
    Dinero calcularIntereses(Dinero &monto);
    void asignarDueno(unsigned int id);
    unsigned int obtenerDueno();
    friend std::istream &operator>>(std::istream &in, Certificado &certificado);
    friend std::ostream &operator<<(std::ostream &os, Certificado &certificado);
};

#endif