#include <iostream>
#include "../BusinessLayer/Reservas/Reserva Concreta/Reserva.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/GraderiaGeneral.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/GraderiaPreferencial.h"

int main() {

    Reserva reserva1 = Reserva("Preferencial 1", 5000, false);
    Reserva reserva2 = Reserva("Preferencial 2", 5000, false);
    Reserva reserva3 = Reserva("Preferencial 3", 5000, false);
    GraderiaGeneral graderiaGeneral = GraderiaGeneral(3);
    GraderiaPreferencial graderiaPreferencial = GraderiaPreferencial(2);


    /*cout << graderiaGeneral.agregarReserva(reserva1) << endl;
    cout << graderiaGeneral.agregarReserva(reserva2) << endl;
    cout << graderiaGeneral.pagarReserva() << endl;
    cout << graderiaGeneral.pagarReserva() << endl;
    cout << graderiaGeneral.pagarReserva() << endl;
    cout << graderiaGeneral.pagarReserva() << endl;
    cout << graderiaGeneral.agregarReserva(reserva3) << endl;
    cout << graderiaGeneral.pagarReserva() << endl;
    cout << graderiaGeneral.mostrarEspacios() << endl;*/

    cout << graderiaPreferencial.agregarReserva(reserva1) << endl;
    cout << graderiaPreferencial.agregarReserva(reserva1) << endl;
    cout << graderiaPreferencial.pagarReserva() << endl;
    cout << graderiaPreferencial.pagarReserva() << endl;
    cout << graderiaPreferencial.pagarReserva() << endl;
    cout << graderiaPreferencial.agregarReserva(reserva1) << endl;
    cout << graderiaPreferencial.agregarReserva(reserva1) << endl;
    return 0;
}