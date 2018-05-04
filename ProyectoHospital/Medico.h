#ifndef MEDICO_H
#define	MEDICO_H
#include "paciente.h"



typedef struct{
	int dni;
	char nombre[30];
	char apellido[30];
	int numpaciente;
	paciente * aPaciente;



}Medico;

void listaDePacientes(Medico m);
void anaydirMedicoFichero(Medico p,char *filename);


#endif
