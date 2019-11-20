//
// Created by Andres on 11/20/2019.
//

#include "GraderiaPreferencial.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

GraderiaPreferencial::GraderiaPreferencial() {
    setTope(nullptr);
}

/*
 * =================
 * GETTER
 * =================
 */

NodoReserva *GraderiaPreferencial::getTope() const {
    return tope;
}

/*
 * =================
 * SETTER
 * =================
 */

void GraderiaPreferencial::setTope(NodoReserva *tope) {
    GraderiaPreferencial::tope = tope;
}
