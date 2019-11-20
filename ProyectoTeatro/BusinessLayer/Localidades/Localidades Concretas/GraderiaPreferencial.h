//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_GRADERIAPREFERENCIAL_H
#define PROYECTOINDIVIDUAL_GRADERIAPREFERENCIAL_H


#include "../../Reservas/Nodos/NodoReserva.h"

class GraderiaPreferencial {

private:
    NodoReserva* tope;

public:
    GraderiaPreferencial();

    NodoReserva *getTope() const;

    void setTope(NodoReserva *tope);
};


#endif //PROYECTOINDIVIDUAL_GRADERIAPREFERENCIAL_H
