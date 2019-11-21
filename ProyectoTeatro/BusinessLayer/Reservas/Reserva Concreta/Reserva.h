//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_RESERVA_H
#define PROYECTOINDIVIDUAL_RESERVA_H

#include <string>

using namespace std;

class Reserva {

private:
    string localidad;
    double precio;
    bool pagada;

public:
    Reserva(string pLocalidad, double pPrecio, bool pPagada);

    Reserva();

    const string &getLocalidad() const;

    double getPrecio() const;

    bool isPagada() const;

    void setLocalidad(const string &localidad);

    void setPrecio(double precio);

    void setPagada(bool pagada);

    string mostrarInformacion() const;
};


#endif //PROYECTOINDIVIDUAL_RESERVA_H
