//
// Created by Andres on 11/20/2019.
//

#include "DirectorConstruccion.h"

DirectorConstruccion::DirectorConstruccion() {}

void DirectorConstruccion::construirReserva(ConstructorAbstracto *constructor) {
    constructor->construirReserva();
    constructor->construirLocalidad();
    constructor->construirPrecio();
    constructor->construirEstado();
}
