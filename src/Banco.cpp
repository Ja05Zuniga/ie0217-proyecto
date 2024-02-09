#include "Banco.hpp"
Banco::Banco(/* args */)
{
}

Banco::~Banco()
{
}

Cliente Banco::buscarCliente(unsigned int id){
    return clientes.at(id);
}

void Banco::obtenerInfoPrestamos(unsigned int id){
    prestamos.at(id).obtenerInfo();
}

void Banco::obtenerInfoCertificados(unsigned int id){
    certificados.at(id).obtenerInfo();
}