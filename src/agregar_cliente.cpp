#include <iostream>
#include <fstream>
#include "agregar_cliente.hpp"

//Constructor que recibe dos parametros tipo string
AgregarCliente::AgregarCliente(std::string& cedula, std::string& nombre) : cedula(cedula), nombre(nombre){}

void AgregarCliente::agregarA_CSV(const std::string& nombreArchivo){
    // Si el archivo existe, lo agrega al final
    //Si el archivo no existe, lo crea y agrega al final.
    std::ofstream archivo(nombreArchivo, std::ios::app);

    // Escribir los datos en el archivo CSV
    archivo<< "\n" << cedula << ", " << nombre;

    // Cerrar el archivo
    archivo.close();
}
