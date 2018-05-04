#ifndef HABITACION_H
#define	HABITACION_H
#include "paciente.h"

typedef struct{
	int num;
	paciente pac;
	char disponibilidad;// (d)disponible y (c)ocupado
}habitacion;

void visualizarPacienteHabitacion(int num,char *filename);
int comprobarHabitacionLibre(int num,char *filename);
void anadirHabitacionFichero(habitacion hab,char *filename);


#endif
