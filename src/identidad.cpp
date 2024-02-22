#include "identidad.hpp"
#include <fstream>
#include <sstream>

Identidad::Identidad(std::string id) : cedula(id) {}

bool Identidad::verificarCedulaEnCSV(const std::string& nombreArchivo) const {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        //En el caso de que el archivo no se pueda abrir, retorna false
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

    return true;
}

std::string Identidad::extraerNombre(const std::string& nombreArchivo) const {
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            // En el caso de que el archivo no se pueda abrir, retorna un string vacío
            return "";
        }

        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string campo;
            while (std::getline(ss, campo, ',')) {
                if (campo == cedula) {
                    archivo.close();
                    // Suponemos que el siguiente campo después de la cédula es el nombre
                    std::getline(ss, campo, ',');
                    return campo;
                }
            }
        }

        archivo.close(); // Cerrar el archivo
        return ""; // Si la cédula no se encuentra, retorna un string vacío
    }
