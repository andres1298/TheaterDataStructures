//
// Created by Andres on 11/20/2019.
//

#include "ConsGraderiaGeneral.h"


ConsGraderiaGeneral::ConsGraderiaGeneral() {}

void ConsGraderiaGeneral::construirLocalidad() {
    getReserva().setLocalidad("Graderia General");
}

void ConsGraderiaGeneral::construirPrecio() {
    getReserva().setPrecio(4000);
}

void ConsGraderiaGeneral::construirEstado() {
    getReserva().setPagada(false);
}
