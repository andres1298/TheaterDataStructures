//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_CONSGRADERIAGENERAL_H
#define PROYECTOINDIVIDUAL_CONSGRADERIAGENERAL_H


#include "../Constructor Abstracto/ConstructorAbstracto.h"

class ConsGraderiaGeneral : public ConstructorAbstracto{
public:
    ConsGraderiaGeneral();

    void construirLocalidad() override;

    void construirPrecio() override;

    void construirEstado() override;
};


#endif //PROYECTOINDIVIDUAL_CONSGRADERIAGENERAL_H
