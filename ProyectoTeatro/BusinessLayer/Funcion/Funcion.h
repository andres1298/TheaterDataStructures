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
    ColaEspera colaEsperaZonaPreferencial;
    ColaEspera colaEsperaGraderiaPreferencial;
    ColaEspera colaEsperaGraderiaGeneral;
    bool haIniciado;

public:
    Funcion(string pNombreObra);

    Funcion();

    const string &getNombreObra() const;

    const ZonaPreferencial &getZonaPreferencial() const;

    const GraderiaPreferencial &getGraderiaPreferencial() const;

    const GraderiaGeneral &getGraderiaGeneral() const;

    DirectorConstruccion &getDirectorReservas();

     ColaEspera &getColaEsperaZonaPreferencial();

     ColaEspera &getColaEsperaGraderiaPreferencial() ;

     ColaEspera &getColaEsperaGraderiaGeneral() ;

    bool isHaIniciado() const;

    void setNombreObra(const string &nombreObra);

    void setZonaPreferencial(const ZonaPreferencial &zonaPreferencial);

    void setGraderiaPreferencial(const GraderiaPreferencial &graderiaPreferencial);

    void setGraderiaGeneral(const GraderiaGeneral &graderiaGeneral);

    void setDirectorReservas(const DirectorConstruccion &directorReservas);

    void setColaEsperaZonaPreferencial(const ColaEspera &colaEsperaZonaPreferencial);

    void setColaEsperaGraderiaPreferencial(const ColaEspera &colaEsperaGraderiaPreferencial);

    void setColaEsperaGraderiaGeneral(const ColaEspera &colaEsperaGraderiaGeneral);

    void setHaIniciado(bool haIniciado);

    Reserva procesarSolicitudReserva(int pOpcion);




};


#endif //PROYECTOINDIVIDUAL_FUNCION_H
