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
        //En caso de que no hayan espacios suficientes en la localidad, se agrega la reserva a la cola de espera
        return this->getColaEspera().agregarReserva(pReserva);
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

string ZonaPreferencial::liberarReservaciones() {
    string informacion;
    int contador = 0;

    if(getCantidadReservada() > 0){
        NodoReserva* aux;

        for(int i = 0; i < 10; i++){
           if(! reservas[i].isPagada()){
               reservas[i] = Reserva("Vacio",0,false);
               contador++;
               setCantidadReservada( getCantidadReservada() - 1);
           }
        }
        return "Fueron liberadas " + to_string(contador) + " reservas de la Zona Preferencial";
    }
    else{
        return "No hay reservaciones pendientes en la Zona Preferencial";
    }
}

//Se crea un ciclo para remover las reservas de la cola de espera y agregarlas a la localidad
string ZonaPreferencial::liberarColaEspera() {
    int cantidad = 0;
    int posicion = 1;

    //Se repite mientras hayan reservas pendientes en la cola

    while(getColaEspera().getCantidadReservas() > 0){

        //Se valida si aun hay espacio en la localidad para agregar mas reservas de la cola

        if(validarEspacios()){
            for(int i = 0; i < 10; i++){
                //Si hay espacios, se agrega la reserva proveniente de la cola
                if(reservas[i].getLocalidad() == "Vacio"){
                    this->agregarReserva(getColaEspera().removerReserva(),i+1);
                    cantidad++;
                    break;
                }
            }
        }
        else{

            //Si no hay mas espacios en la localidad, se retorna un string notificando la cantidad que pudieron ser agregadas y las que quedan pendientes
            return "Se han agregado " + to_string(cantidad) + " reservaciones de la cola de espera, pero se ha alcanzado el maximo de espacios. Pendientes: " + to_string(getColaEspera().getCantidadReservas());
        }
        posicion++;
    }

    // En caso de que se pudieran agregar todas las reservas de la cola de espera, se retorna un mensaje con esta informacion.

    return "Se han agregado " + to_string(cantidad) + " reservaciones de la cola de espera a la Zona Preferencial";
}


