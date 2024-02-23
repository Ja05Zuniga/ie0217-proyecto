#include "Certificado.hpp"
Certificado::Certificado() : Producto("Certificado") {}

/**
 * @brief Construct a new Certificado:: Certificado object
 *
 * @param id
 */

Certificado::Certificado(const float &tasaInteresAnual, const unsigned int &id, const int plazo) : Producto("Certificado", id), tasaInteresAnual(tasaInteresAnual), plazo(plazo)
{
    tasaInteresMensual = tasaInteresAnual / 12 / 100;
}
Certificado::Certificado(const Dinero &montoCertificado, const float &tasaInteresAnual, const unsigned int &id) : Producto("Certificado", id), montoCertificado(montoCertificado), tasaInteresAnual(tasaInteresAnual) {}
Certificado::Certificado(const Certificado &otro) : Producto("Certificado", otro.id), tasaInteresAnual(otro.tasaInteresAnual), tasaInteresMensual(otro.tasaInteresMensual), plazo(otro.plazo) {}
Certificado::~Certificado()
{
}

void Certificado::obtenerInfo()
{
    // Imprime la tabla con los valores con un formato establecido
    std::cout << std::setw(Constantes::COL_WIDTH) << std::left << id
              << std::setw(Constantes::COL_WIDTH) << std::left << plazo
              << std::setw(Constantes::COL_WIDTH) << std::left << tasaInteresAnual << std::endl;
}

void Certificado::obtenerInfoPersonal()
{
    // Imprime la tabla con los valores con un formato establecido
    std::cout << "ID: " << id << "\n"
              << "Plazo: " << plazo << "\n"
              << "Monto: " << montoCertificado.obtenerMoneda() << montoCertificado.obtenerMonto() << "\n"
              << "Interes: " << intereses.obtenerMoneda() << intereses.obtenerMonto() << std::endl;
}

void Certificado::acreditar(Dinero &monto) {}

void Certificado::debitar(Dinero &monto)
{
    montoCertificado = monto;
    intereses = calcularIntereses(monto);
}

void Certificado::verificarDebito(Dinero &monto)
{
    return;
}
void Certificado::verificarCredito(Dinero &monto)
{
    return;
}

int Certificado::solicitarIDcertificado()
{
    std::string input;
    int id;

    while (true)
    {
        try
        {
            std::cout << "Ingrese el ID del certificado o escriba 'cancelar' para cancelar: \n";
            std::cin >> input;

            if (input == "cancelar")
            {
                return -1;
            }

            std::stringstream ss(input);
            if (!(ss >> id) || !ss.eof())
            {
                throw std::invalid_argument("Entrada inválida: Debe ingresar un valor entero.");
            }

            if (id < 0 || id > std::numeric_limits<int>::max())
            {
                throw std::out_of_range("ID fuera de rango. El valor debe ser un número entero no negativo.");
            }

            return id;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

Dinero Certificado::calcularIntereses(Dinero &monto)
{
    float montoFloat = monto.obtenerMonto();
    float interes = montoFloat * tasaInteresMensual * plazo;
    return Dinero(interes, monto.obtenerMoneda());
}

void Certificado::asignarDueno(unsigned int id)
{
    idDueno = id;
}

unsigned int Certificado::obtenerDueno()
{
    return idDueno;
}
