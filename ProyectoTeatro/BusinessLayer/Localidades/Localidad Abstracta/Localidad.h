//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_LOCALIDAD_H
#define PROYECTOINDIVIDUAL_LOCALIDAD_H

#include "../../Reservas/Nodos/NodoReserva.h"

class Localidad {
private:
    int cantidadReservada;
    int cantidadMaxima;
    int cantidadPagada;

public:
    Localidad();

    Localidad(int pCantidadMaxima);

    int getCantidadReservada() const;

    int getCantidadMaxima() const;

    int getCantidadPagada() const;

    void setCantidadReservada(int cantidadReservada);

    void setCantidadMaxima(int cantidadMaxima);

    void setCantidadPagada(int cantidadPagada);

    virtual string agregarReserva(Reserva pReserva) = 0;

    virtual string pagarReserva() = 0;

    virtual string mostrarEspacios() = 0;

    virtual bool validarEspacios() = 0;

    virtual bool validarPagoReserva() = 0;

};


#endif //PROYECTOINDIVIDUAL_LOCALIDAD_H
