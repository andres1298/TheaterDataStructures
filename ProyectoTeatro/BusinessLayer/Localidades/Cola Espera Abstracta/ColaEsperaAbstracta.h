//
// Created by Andres on 11/23/2019.
//

#ifndef PROYECTOINDIVIDUAL_COLAESPERAABSTRACTA_H
#define PROYECTOINDIVIDUAL_COLAESPERAABSTRACTA_H

#include <string>

#include "../../Reservas/Nodos/NodoReserva.h"

using namespace std;

class ColaEsperaAbstracta {
private:
    NodoReserva* frente;
    NodoReserva* final;
    int cantidadReservas;

public:
    ColaEsperaAbstracta();

    NodoReserva *getFrente() const;

    NodoReserva *getFinal() const;

    int getCantidadReservas() const;

    void setFrente(NodoReserva *frente);

    void setFinal(NodoReserva *final);

    void setCantidadReservas(int cantidadReservas);

    virtual string agregarReserva(Reserva reserva) = 0;

    virtual string removerReserva() = 0;
};


#endif //PROYECTOINDIVIDUAL_COLAESPERAABSTRACTA_H
