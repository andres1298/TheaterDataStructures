//
// Created by Andres on 11/20/2019.
//

#include "Localidad.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

Localidad::Localidad() {
    setCantidadMaxima(0);
    setCantidadPagada(0);
    setCantidadReservada(0);
}

Localidad::Localidad(int pCantidadMaxima) {
    setCantidadMaxima(pCantidadMaxima);
    setCantidadReservada(0);
    setCantidadPagada(0);
}

/*
 * =================
 * GETTER
 * =================
 */

int Localidad::getCantidadReservada() const {
    return cantidadReservada;
}

int Localidad::getCantidadMaxima() const {
    return cantidadMaxima;
}

int Localidad::getCantidadPagada() const {
    return cantidadPagada;
}
/*
 * =================
 * SETTER
 * =================
 */

    void Localidad::setCantidadReservada(int cantidadReservada) {
        Localidad::cantidadReservada = cantidadReservada;
    }

    void Localidad::setCantidadMaxima(int cantidadMaxima) {
        Localidad::cantidadMaxima = cantidadMaxima;
    }

    void Localidad::setCantidadPagada(int cantidadPagada) {
        Localidad::cantidadPagada = cantidadPagada;
    }