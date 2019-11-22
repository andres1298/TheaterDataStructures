//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_GRADERIAPREFERENCIAL_H
#define PROYECTOINDIVIDUAL_GRADERIAPREFERENCIAL_H


#include "../../Reservas/Nodos/NodoReserva.h"
#include "../Localidad Abstracta/Localidad.h"

class GraderiaPreferencial : public Localidad{

private:
    NodoReserva* tope;

public:
    GraderiaPreferencial();

    GraderiaPreferencial(int pCantidad);

    NodoReserva *getTope() const;

    void setTope(NodoReserva *tope);

    string agregarReserva(Reserva pReserva) override;

    string pagarReserva() override;

    bool validarEspacios() override;

    string mostrarEspacios() override;

    bool validarPagoReserva() override;
};


#endif //PROYECTOINDIVIDUAL_GRADERIAPREFERENCIAL_H
