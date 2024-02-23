#include "Moneda.hpp"

std::istream &operator>>(std::istream &is, Moneda &moneda)
{
    std::string monedaStr;
    std::getline(is, monedaStr, ',');
    if (monedaStr == "CRC")
    {
        moneda = COLONES;
    }
    else if (monedaStr == "USD")
    {
        moneda = DOLARES;
    }
    else
    {

        is.setstate(std::ios::failbit);
    }

    return is;
}
