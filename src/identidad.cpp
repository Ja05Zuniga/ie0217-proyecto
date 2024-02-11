#include "identidad.hpp"
#include <fstream>
#include <sstream>

Identidad::Identidad(std::string id) : cedula(id) {}

bool Identidad::verificarCedulaEnCSV(const std::string& nombreArchivo) const {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        //En el caso de que el archivo no se pueda abrir, retorna nu false
        return false;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string campo;
        while (std::getline(ss, campo, ',')) {
            if (campo == cedula) {
                archivo.close();
                return true;
            }
        }
    }

    archivo.close(); //Cerrar el archivo
}
