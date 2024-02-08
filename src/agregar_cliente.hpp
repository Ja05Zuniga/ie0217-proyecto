#ifndef AGREGARCLIENTE__HPP
#define AGREGARCLIENTE__HPP

#include <string>

class AgregarCliente{
    /*La clase AgregarCliente recibe dos parametros tipo string que contienen el ID y nombre del cliente.
    Solo posee un metodo tipo void llamado agregarA_CSV que recibe el nombre de un archivo .csv
    En el caso de que el archivo .csv exista, agrega el nombre al final. 
    En el caso de que el archivo .csv no exista, crea el archivo .csv y agrega el nombre al final*/
    public:
    AgregarCliente(std::string& cedula, std::string& nombre);

    void agregarA_CSV(const std::string& nombreArchivo);
    
    private:
        std::string cedula;
        std::string nombre;
};

#endif