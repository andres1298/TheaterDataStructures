//
// Created by Andres on 11/20/2019.
//

#include "ConsZonaPreferencial.h"

ConsZonaPreferencial::ConsZonaPreferencial() : ConstructorAbstracto() {}

void ConsZonaPreferencial::construirLocalidad() {
    getReserva().setLocalidad("Zona Preferencial");
}

void ConsZonaPreferencial::construirPrecio() {
    getReserva().setPrecio(7000);
}

void ConsZonaPreferencial::construirEstado() {
    getReserva().setPagada(false);
}
