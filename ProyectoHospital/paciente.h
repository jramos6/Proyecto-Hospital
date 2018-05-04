#ifndef PACIENTE_H
#define	PACIENTE_H
#include "habitacion.h"
#include "Medico.h"

typedef struct{
	char nombre[20];
	char apellido1[20];
	char apellido2[20];
	int dni;
	char sexo;
	char fechaNac[11];

}paciente;

void anaydirPacienteFichero(paciente p,char *filename);
int buscarPacienteEnFichero(char *filename, int dni);
void asignarHabitacion(paciente p,habitacion *h);
void asignarMedico(paciente p,Medico m);


#endif

