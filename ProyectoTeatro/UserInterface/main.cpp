#include <iostream>
#include "../BusinessLayer/Reservas/Reserva Concreta/Reserva.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/GraderiaGeneral.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/GraderiaPreferencial.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/ZonaPreferencial.h"
#include "../BusinessLayer/Funcion/Funcion.h"
#include <string>

using namespace std;

Funcion funcion = Funcion("NullPo", 10, 50, 50);

void mostrarMenuPrincipal(){
    cout << "\n==========================" << endl;
    cout << "Teatro Datos Estructurados" << endl;
    cout << "==========================\n" << endl;

    cout << "1. Reservar entradas" << endl;
    cout << "2. Pagar entradas" << endl;
    cout << "3. Liberar reservaciones" << endl;
    cout << "4. Iniciar funcion" << endl;
    cout << "5. Ver ubicaciones" << endl;
    cout << "6. Salir" << endl;
    cout << "Opcion: ";
}

void mostrarMenuReservacion(){
    cout << "\n==========================" << endl;
    cout << "  Seleccione la localidad" << endl;
    cout << "==========================\n" << endl;

    cout << "1. Zona Preferencial (7000 colones)" << endl;
    cout << "2. Graderia Preferencial (5500 colones)" << endl;
    cout << "3. Graderia General (4000 colones)" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
}

int obtenerOpcion(){
    int opcion = 0;
    cin >> opcion;
    return opcion;
}

void liberarReservaciones(){
    cout << "Liberando reservaciones" << endl;
}

void iniciarFuncion(){
    cout << "Iniciando funcion" << endl;
}

void mostrarUbicaciones(){
    cout << "Mostrando ubicaciones" << endl;
}

void procesarMenuPrincipal(int pOpcion){
    int opcionMenuPrincipal;
    switch ( pOpcion ){
        case 1:
            mostrarMenuReservacion();
            opcionMenuPrincipal = obtenerOpcion();

            break;

        case 2:
            mostrarMenuReservacion();
            opcionMenuPrincipal = obtenerOpcion();
            break;

        case 3:
            liberarReservaciones();
            break;

        case 4:
            iniciarFuncion();
            break;

        case 5:
            mostrarUbicaciones();
            break;

        case 6:
            cout << "\nGracias por visitarnos.";
            break;

        default:
            cout << "\n Por favor digite una opcion valida";
            break;
    }
}



int main() {
    int opcion = 0;/*
    while( opcion != 6){
        mostrarMenuPrincipal();
        opcion = obtenerOpcion();
        procesarMenuPrincipal(opcion);

    }*/
    Reserva reserva1 = Reserva("Preferencial 1", 5000, false);
    Reserva reserva2 = Reserva("Preferencial 2", 7000, false);

    for(int i = 1; i <= 10; i++){
        cout << funcion.getZonaPreferencial().agregarReserva(reserva1,i) << endl;
        if(i % 2 == 0){
            cout << funcion.getZonaPreferencial().pagarReserva(i) << endl;
        }
    }

    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;

    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;

    cout << funcion.liberarReservaciones() << endl;


    return 0;
}

/*Reserva reserva1 = Reserva("Preferencial 1", 5000, false);

    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaGeneral().agregarReserva(reserva1) << endl;
    cout << "\n" << endl;
    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;
    cout << funcion.getGraderiaPreferencial().agregarReserva(reserva1) << endl;
    cout << "\n" << endl;
    for(int i = 1; i <= 10; i++){
        cout << funcion.getZonaPreferencial().agregarReserva(reserva1,i) << endl;
    }
    cout << "\n" << endl;
    cout << funcion.getZonaPreferencial().agregarReserva(reserva1,10) << endl;

    cout << funcion.getZonaPreferencial().liberarReservaciones() << endl;

    for(int i = 1; i <= 10; i++){
        cout << funcion.getZonaPreferencial().agregarReserva(reserva1,i) << endl;
        if(i % 2 == 0){
            funcion.getZonaPreferencial().pagarReserva(i);
        }
    }
    */