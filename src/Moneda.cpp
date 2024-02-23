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

std::ostream &operator<<(std::ostream &os, const Moneda &obj)
{
    std::string monedaStr;
    switch (obj)
    {
    case COLONES:
        monedaStr = "CRC";
        break;
    case DOLARES:
        monedaStr = "USD";
        break;
    default:
        break;
    }
    os << monedaStr;
    return os;
}