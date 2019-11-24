//
// Created by Andres on 11/20/2019.
//
#include "ZonaPreferencial.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

ZonaPreferencial::ZonaPreferencial() : Numerado(){
    llenarReservas();
}

ZonaPreferencial::ZonaPreferencial(int pCantidadMaxima) : Numerado(pCantidadMaxima) {
    llenarReservas();
}

/*
 * =================
 * GETTER
 * =================
 */

const Reserva *ZonaPreferencial::getReservas() const {
    return reservas;
}

/*
 * =================
 * OVERWRITTEN
 * =================
 */

string ZonaPreferencial::mostrarEspacios() {
    string informacion = "";

    for(Reserva reserva: reservas){
        informacion.append(reserva.mostrarInformacion() + " ");
    }
    return informacion;
}

string ZonaPreferencial::agregarReserva(Reserva pReserva, int pAsiento) {
    if(validarEspacios() && validarAsiento(pAsiento)){
        reservas[pAsiento - 1] = pReserva;
        setCantidadReservada(getCantidadReservada() + 1);
        return "Reserva agregada correctamente";
    }
    else if(validarEspacios() && ! validarAsiento(pAsiento)){
        return "El asiento ingresado no se encuentra libre";
    }
    else{
        return "Error al agregar la reserva. Por favor verifique que haya espacios disponibles";
    }
}

string ZonaPreferencial::pagarReserva(int pAsiento) {
    if(getCantidadReservada() == 0) {
        return "No hay reservas pendientes en esta localidad";
    }
    else{
        if(validarPagoReserva(pAsiento)){
            reservas[pAsiento - 1].setPagada(true);
            setCantidadPagada(getCantidadPagada() + 1);
            setCantidadReservada(getCantidadReservada() - 1);
            return "Pago realizado";
        }
        else{
            return "El pago no pudo ser realizado. Favor revisar que hayan reservas pendientes";
        }
    }
}

bool ZonaPreferencial::validarEspacios() {
    return getCantidadReservada() + getCantidadPagada() < getCantidadMaxima();
}

bool ZonaPreferencial::validarPagoReserva(int pAsiento) {
    return getCantidadPagada() <= getCantidadMaxima() && reservas[pAsiento - 1].getLocalidad() != "Vacio";
}

/*
 * =================
 * FUNCIONES ESPECIFICAS
 * =================
 */

void ZonaPreferencial::llenarReservas() {
    for(int i = 0; i < 10; i++){
        reservas[i] = Reserva("Vacio",0,false);
    }
}

string ZonaPreferencial::mostrarEspaciosDisponibles() {
    string informacion;
    int posicion = 1;
    if(validarEspacios()){
        for(Reserva reserva: reservas){
            if(! reserva.getLocalidad().compare("Vacio")){
                informacion.append(to_string(posicion) + "  ");
            }
            posicion++;
        }
        return informacion;
    }
    else{
        return "La localidad se encuentra llena";
    }
}



bool ZonaPreferencial::validarAsiento(int pAsiento) {
    if(pAsiento > 10 || pAsiento < 1){
        return false;
    }
    else{
        return reservas[pAsiento - 1].getLocalidad() == "Vacio";
    }

}


