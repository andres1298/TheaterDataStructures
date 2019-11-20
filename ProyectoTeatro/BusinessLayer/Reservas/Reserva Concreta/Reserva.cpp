//
// Created by Andres on 11/20/2019.
//

#include "Reserva.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

Reserva::Reserva(string pLocalidad, double pPrecio, bool pPagada) {
    setLocalidad(pLocalidad);
    setPrecio(pPrecio);
    setPagada(pPagada);
}

Reserva::Reserva() {
    setLocalidad("");
    setPrecio(0);
    setPagada(false);
}

/*
 * =================
 * GETTERS
 * =================
 */

const string &Reserva::getLocalidad() const {
    return localidad;
}

double Reserva::getPrecio() const {
    return precio;
}

bool Reserva::isPagada() const {
    return pagada;
}

/*
 * =================
 * SETTERS
 * =================
 */

void Reserva::setLocalidad(const string &localidad) {
    Reserva::localidad = localidad;
}

void Reserva::setPrecio(double precio) {
    Reserva::precio = precio;
}

void Reserva::setPagada(bool pagada) {
    Reserva::pagada = pagada;
}