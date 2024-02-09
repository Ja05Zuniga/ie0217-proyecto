#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <string>

class Cliente
{
private:
    unsigned int userId;
    std::string nombre;

public:
    Cliente(unsigned int userId, std::string nombre);
    ~Cliente();
    void obtenerInfo();
};



#endif