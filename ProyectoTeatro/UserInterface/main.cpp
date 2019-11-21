#include <iostream>
#include "../BusinessLayer/Reservas/Reserva Concreta/Reserva.h"
#include "../BusinessLayer/Localidades/Localidades Concretas/GraderiaGeneral.h"

int main() {

    Reserva reserva1 = Reserva("Preferencial 1", 5000, false);
    Reserva reserva2 = Reserva("Preferencial 2", 5000, false);
    Reserva reserva3 = Reserva("Preferencial 3", 5000, false);
    NodoReserva* node1 = new NodoReserva(reserva1);
    NodoReserva* node2 = new NodoReserva(reserva2);
    NodoReserva* node3 = new NodoReserva(reserva3);
    GraderiaGeneral graderiaGeneral = GraderiaGeneral(2);


    cout << graderiaGeneral.agregarReserva(node1) << endl;
    cout << graderiaGeneral.agregarReserva(node2) << endl;
    cout << graderiaGeneral.agregarReserva(node3) << endl;
    cout << graderiaGeneral.mostrarEspacios() << endl;
    return 0;
}