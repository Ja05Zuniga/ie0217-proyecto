#ifndef IDENTIDAD_HPP
#define IDENTIDAD_HPP

#include <string>

class Identidad {
    /*La clase 'Indetidad' recibe como parametro la cedula (ID) del cliente en formato string y verifica 
    si se encuentra en una archivo .csv que funciona como base de datos para este proyecto.

    La clase 'Indetidad' toma por sentado el correcto ingreso de los datos. Por lo que no posee excepciones.
    Esto se debe de tener en consideración a la hora de usar la clase.
    
    La clase 'Indetidad' solo posee un metodo tipo booleno que recibe como argumento el nombre del archivo .csv
    Este metodo busca en el archivo .csv si la cedula se encuetra. En el caso de que sí, retorna True.
    En el caso de que no retorna False*/
    
public:
    // Constructor que recibe el ID (cedula) del cliente.
    Identidad(std::string id);

    // Método para verificar si la cédula está en un archivo CSV
    bool verificarCedulaEnCSV(const std::string& nombreArchivo) const;

private:
    std::string cedula;
};

#endif // IDENTIDAD_HPP
