#ifndef EFECTIVO_HPP
#define EFECTIVO_HPP
#include "Producto.hpp"

class Efectivo : public Producto
{
private:
    Dinero dinero;

public:
    Efectivo(/* args */);
    ~Efectivo();
    /**
     * @brief Imprime información básica del pago
     *
     */
    void obtenerInfo() override;

    /**
     * @brief Método para recibir efectivo
     *
     * @param monto
     */
    void acreditar(Dinero &monto) override;

    /**
     * @brief Método para pagar con efectivo
     *
     * @param monto
     */
    void debitar(Dinero &monto) override;
    void solicitarPago();
};

#endif