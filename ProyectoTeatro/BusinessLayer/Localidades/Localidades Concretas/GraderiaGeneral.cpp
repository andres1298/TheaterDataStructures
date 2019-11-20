//
// Created by Andres on 11/20/2019.
//

#include "GraderiaGeneral.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

GraderiaGeneral::GraderiaGeneral() {
    setCabeza(nullptr);
}

/*
 * =================
 * GETTER
 * =================
 */

NodoReserva *GraderiaGeneral::getCabeza() const {
    return cabeza;
}

/*
 * =================
 * SETTER
 * =================
 */

void GraderiaGeneral::setCabeza(NodoReserva *cabeza) {
    GraderiaGeneral::cabeza = cabeza;
}
