//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_CONSGRADERIALPREFERENCIAL_H
#define PROYECTOINDIVIDUAL_CONSGRADERIALPREFERENCIAL_H


#include "../Constructor Abstracto/ConstructorAbstracto.h"

class ConsGraderialPreferencial : public ConstructorAbstracto {
public:
    ConsGraderialPreferencial();

    void construirLocalidad() override;

    void construirPrecio() override;

    void construirEstado() override;
};


#endif //PROYECTOINDIVIDUAL_CONSGRADERIALPREFERENCIAL_H
