//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_ZONAPREFERENCIAL_H
#define PROYECTOINDIVIDUAL_ZONAPREFERENCIAL_H


#include "../../Reservas/Reserva Concreta/Reserva.h"
#include "../Localidad Abstracta/Numerado.h"

class ZonaPreferencial : public Numerado{


private:
    Reserva reservas[10];

public:
    ZonaPreferencial();

    ZonaPreferencial(int pCantidadMaxima);

    const Reserva *getReservas() const;

    string mostrarEspacios() override;

    bool validarEspacios() override;

    bool validarPagoReserva(int pAsiento) override;

    void llenarReservas();

    string mostrarEspaciosDisponibles();

    bool validarAsiento(int pAsiento);

    string agregarReserva(Reserva pReserva, int pAsiento) override;

    string pagarReserva(int pAsiento) override;

    string liberarReservaciones() override;

    string liberarColaEspera() override;


};


#endif //PROYECTOINDIVIDUAL_ZONAPREFERENCIAL_H
