//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_GRADERIAGENERAL_H
#define PROYECTOINDIVIDUAL_GRADERIAGENERAL_H


#include "../../Reservas/Nodos/NodoReserva.h"

class GraderiaGeneral {
private:
    NodoReserva* cabeza;

public:
    GraderiaGeneral();

    NodoReserva *getCabeza() const;

    void setCabeza(NodoReserva *cabeza);
};


#endif //PROYECTOINDIVIDUAL_GRADERIAGENERAL_H
