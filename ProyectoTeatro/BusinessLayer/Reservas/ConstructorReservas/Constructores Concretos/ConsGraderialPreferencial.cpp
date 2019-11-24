//
// Created by Andres on 11/20/2019.
//

#include "ConsGraderialPreferencial.h"

ConsGraderialPreferencial::ConsGraderialPreferencial() {}

void ConsGraderialPreferencial::construirLocalidad() {
    getReserva().setLocalidad("Graderia Preferencial");
}

void ConsGraderialPreferencial::construirPrecio() {
    getReserva().setPrecio(5500);
}

void ConsGraderialPreferencial::construirEstado() {
    getReserva().setPagada(false);
}
