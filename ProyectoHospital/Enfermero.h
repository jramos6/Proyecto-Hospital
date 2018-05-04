#ifndef MEDICO_H
#define MEDICO_H
#include "Personal.h"
#include "Medico.h"



typedef struct{

	 Personal *p;
	 char especialidad[20];
	 Medico m;

}Medico;

void anyadirEnfermero();
void eliminarEnfermero();
void mostrarEnfermeros();


