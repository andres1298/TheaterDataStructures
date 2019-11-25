//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_LOCALIDAD_H
#define PROYECTOINDIVIDUAL_LOCALIDAD_H

#include "../../Reservas/Nodos/NodoReserva.h"
#include "../Colas Espera Concretas/ColaEspera.h"

class Localidad {
private:
    int cantidadReservada;
    int cantidadMaxima;
    int cantidadPagada;
    ColaEspera colaEspera;

public:
    Localidad();

    Localidad(int pCantidadMaxima);

    int getCantidadReservada() const;

    int getCantidadMaxima() const;

    int getCantidadPagada() const;

    ColaEspera &getColaEspera();

    void setCantidadReservada(int cantidadReservada);

    void setCantidadMaxima(int cantidadMaxima);

    void setCantidadPagada(int cantidadPagada);

    void setColaEspera(const ColaEspera &colaEspera);

    virtual string mostrarEspacios() = 0;

    virtual bool validarEspacios() = 0;

    virtual string liberarReservaciones() = 0;

    virtual string liberarColaEspera() = 0;

    virtual string obtenerEstadisticas() = 0;

};


#endif //PROYECTOINDIVIDUAL_LOCALIDAD_H
