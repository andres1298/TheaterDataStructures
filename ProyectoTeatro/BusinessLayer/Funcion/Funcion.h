//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_FUNCION_H
#define PROYECTOINDIVIDUAL_FUNCION_H

#include <string>
#include "../Localidades/Localidades Concretas/GraderiaGeneral.h"
#include "../Localidades/Localidades Concretas/ZonaPreferencial.h"
#include "../Localidades/Localidades Concretas/GraderiaPreferencial.h"
#include "../Reservas/ConstructorReservas/Director/DirectorConstruccion.h"
#include "../Localidades/Colas Espera Concretas/ColaEspera.h"

using namespace std;

class Funcion {

private:
    string nombreObra;
    ZonaPreferencial zonaPreferencial;
    GraderiaPreferencial graderiaPreferencial;
    GraderiaGeneral graderiaGeneral;
    DirectorConstruccion directorReservas;
    bool haIniciado;

public:
    Funcion(string pNombreObra, int pCantidadZonaPreferencial, int pCantidadGraderiaPreferencial,
            int pCantidadGraderiaGeneral);

    Funcion();

    const string &getNombreObra() const;

     ZonaPreferencial &getZonaPreferencial() ;

     GraderiaPreferencial &getGraderiaPreferencial() ;

    GraderiaGeneral & getGraderiaGeneral() ;

    DirectorConstruccion &getDirectorReservas();

    bool isHaIniciado() const;

    void setNombreObra(const string &nombreObra);

    void setZonaPreferencial(const ZonaPreferencial &zonaPreferencial);

    void setGraderiaPreferencial(const GraderiaPreferencial &graderiaPreferencial);

    void setGraderiaGeneral(const GraderiaGeneral &graderiaGeneral);

    void setDirectorReservas(const DirectorConstruccion &directorReservas);

    void setHaIniciado(bool haIniciado);

    string liberarReservaciones();

    Reserva procesarSolicitudReserva(int pOpcion);




};


#endif //PROYECTOINDIVIDUAL_FUNCION_H
