#include <iostream>
#include "../BusinessLayer/Reservas/Reserva Concreta/Reserva.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/GraderiaGeneral.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/GraderiaPreferencial.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/ZonaPreferencial.h"
#include "../BusinessLayer/Funcion/Funcion.h"
#include <string>

using namespace std;

Funcion funcion;

/*
 * =================
 * MENUS
 * =================
 */

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

/*
 * =================
 * LECTURA DATOS
 * =================
 */

int obtenerOpcion(){
    int opcion = 0;
    cin >> opcion;
    return opcion;
}

/*
 * =========================
 * CONFIRMACION OPERACIONES
 * =========================
 */

void mostrarEspaciosDisponiblesZonaPreferencial(){
    cout << "\nSeleccione uno de los siguientes asientos:" << endl;
    cout << funcion.getZonaPreferencial().mostrarEspaciosDisponibles() << endl;
    cout << "\nOpcion: ";
}

void mostrarEspaciosPorPagarZonaPreferencial(){
    cout << "\nSeleccione uno de los siguientes asientos:" << endl;
    cout << funcion.getZonaPreferencial().mostrarReservasPorPagar() << endl;
    cout << "\nOpcion: ";
}

bool confirmarCantidadReservas(int pCantidad){
    int opcion = 0;
    cout << "\nEsta seguro que desea " + to_string(pCantidad) + " reservaciones?\n";
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion:";

    opcion = obtenerOpcion();

    if(opcion == 1) {
        return true;
    }
    else{
        return false;
    }
}

bool confirmarPagoCantidadReservas(int pCantidad){
    int opcion = 0;
    cout << "\nEsta seguro que desea pagar " + to_string(pCantidad) + " reservaciones?\n";
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion:";

    opcion = obtenerOpcion();

    if(opcion == 1) {
        return true;
    }
    else{
        return false;
    }
}

/*
 * ======================
 * FUNCIONES PRINCIPALES
 * ======================
 */

void liberarReservaciones(){
    cout << funcion.liberarReservaciones() << endl;
}

void iniciarFuncion(){
    cout << "\n==========================" << endl;
    cout << "      Recaudacion " + funcion.getNombreObra() << endl;
    cout << "==========================\n" << endl;
    cout << funcion.iniciarObra() << endl;
}

void mostrarUbicaciones(){
    cout << "Mostrando ubicaciones" << endl;
}

/*
 * =====================
 * PROCESAMIENTO DATOS
 * =====================
 */

void procesarMenuReservacion(int pOpcion) {
    int opcionMenuReservacion = 0;
    int opcionSecundaria = 0;

    switch (pOpcion) {
        case 1:
            {
                mostrarEspaciosDisponiblesZonaPreferencial();
                opcionSecundaria = obtenerOpcion();
                cout << "\n" + funcion.procesarAgregarReserva(pOpcion, opcionSecundaria) << endl;
            }
            break;

        case 2:
            {
                cout << "\nDigite la cantidad de asientos que desea: ";
                opcionMenuReservacion = obtenerOpcion();
                if(confirmarCantidadReservas(opcionMenuReservacion)){
                    for(int i = 0; i < opcionMenuReservacion; i++){
                        cout << funcion.procesarAgregarReserva(pOpcion) << endl;
                    }
                }
                else{
                    cout << "\nGracias por su confirmacion" << endl;
                }
            }
            break;

        case 3:
            {
                cout << "\nDigite la cantidad de asientos que desea: ";
                opcionMenuReservacion = obtenerOpcion();
                if(confirmarCantidadReservas(opcionMenuReservacion)){
                    for(int i = 0; i < opcionMenuReservacion; i++){
                        cout << funcion.procesarAgregarReserva(pOpcion) << endl;
                    }
                }
                else{
                    cout << "\nGracias por su confirmacion" << endl;
                }
            }
            break;

        default:
            break;

    }
}

void procesarMenuPago(int pOpcion) {
    int opcionMenuReservacion = 0;
    int opcionSecundaria = 0;

    switch (pOpcion) {
        case 1:
        {
            mostrarEspaciosPorPagarZonaPreferencial();
            opcionSecundaria = obtenerOpcion();
            cout << "\n" + funcion.procesarPagarReserva(pOpcion, opcionSecundaria) << endl;
        }
            break;

        case 2:
        {
            cout << "\nDigite la cantidad de asientos que desea pagar: ";
            opcionMenuReservacion = obtenerOpcion();
            if(confirmarPagoCantidadReservas(opcionMenuReservacion)){
                for(int i = 0; i < opcionMenuReservacion; i++){
                    cout << funcion.procesarPagarReserva(pOpcion) << endl;
                }
            }
            else{
                cout << "\nGracias por su confirmacion" << endl;
            }
        }
            break;

        case 3:
        {
            cout << "\nDigite la cantidad de asientos que desea pagar: ";
            opcionMenuReservacion = obtenerOpcion();
            if(confirmarPagoCantidadReservas(opcionMenuReservacion)){
                for(int i = 0; i < opcionMenuReservacion; i++){
                    cout << funcion.procesarPagarReserva(pOpcion) << endl;
                }
            }
            else{
                cout << "\nGracias por su confirmacion" << endl;
            }
        }
            break;

        default:
            break;

    }
}

void procesarMenuPrincipal(int pOpcion){
    int opcionMenuPrincipal = 0;
    switch ( pOpcion ){
        case 1:
            {
                while(opcionMenuPrincipal != 4){
                    mostrarMenuReservacion();
                    opcionMenuPrincipal = obtenerOpcion();
                    procesarMenuReservacion(opcionMenuPrincipal);
                }
            }
            break;

        case 2:
            while(opcionMenuPrincipal != 4){
                mostrarMenuReservacion();
                opcionMenuPrincipal = obtenerOpcion();
                procesarMenuPago(opcionMenuPrincipal);
            }
            break;

        case 3:
            liberarReservaciones();
            break;

        case 4:
            iniciarFuncion();
            cout << "\n\nLa obra ha finalizado. Muchas gracias por su preferencia\n";
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

/*
 * =================
 * NUEVA OBRA
 * =================
 */

bool confirmarNuevaObra(){
    int opcion = 0;
    cout << "\nDesea iniciar una nueva obra?\n";
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion:";

    opcion = obtenerOpcion();

    if(opcion == 1) {
        return true;
    }
    else{
        return false;
    }
}

void crearNuevaObra(){
    string nombreObra;
    cout << "\n==========================" << endl;
    cout << "Teatro Datos Estructurados" << endl;
    cout << "==========================\n" << endl;
    cout << "Digite el nombre de la obra del dia:";
    cin >> nombreObra;

    funcion = Funcion(nombreObra,10,50,50);
}

/*
 * =================
 * MENU PRINCIPAL
 * =================
 */

int main() {
    int opcion = 0;

    crearNuevaObra();

    while( opcion != 6 && opcion != 4){
        mostrarMenuPrincipal();
        opcion = obtenerOpcion();
        procesarMenuPrincipal(opcion);
    }

    if(opcion == 4){
        if(confirmarNuevaObra()){
            main();
        }
        else{
            cout << "\nGracias por utilizar Datos Estructurados\n";
        }
    }
    return 0;
}

