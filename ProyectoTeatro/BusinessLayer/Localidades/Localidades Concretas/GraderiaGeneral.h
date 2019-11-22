//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_GRADERIAGENERAL_H
#define PROYECTOINDIVIDUAL_GRADERIAGENERAL_H

#include <string>
#include "../../Reservas/Nodos/NodoReserva.h"
#include "../Localidad Abstracta/Localidad.h"

using namespace std;


class GraderiaGeneral : public Localidad{
private:
    NodoReserva* cabeza;
    NodoReserva* cola;

public:
    GraderiaGeneral();

    GraderiaGeneral(int pCantidadMaxima);

    NodoReserva *getCabeza() const;

    NodoReserva *getCola() const;

    void setCabeza(NodoReserva *cabeza);

    void setCola(NodoReserva *cola);

    string agregarReserva(Reserva pReserva) override;

    string pagarReserva() override;

    bool validarEspacios() override;

    string mostrarEspacios() override;

    bool validarPagoReserva() override;
};


#endif //PROYECTOINDIVIDUAL_GRADERIAGENERAL_H
