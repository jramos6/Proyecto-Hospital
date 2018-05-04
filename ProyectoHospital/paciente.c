#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paciente.h"
#include "Medico.h"
#include "habitacion.h"
#include "habitacion.c"


void anaydirPacienteFichero(paciente p,char *filename){

	    FILE *pf;

		pf=fopen(filename,"a");
		if(pf != (FILE*)NULL)
		{

			fprintf(pf, "%d %s %s %s %c %s\n", p.dni,p.nombre, p.apellido2, p.apellido2,p.sexo,p.fechaNac);
			fclose(pf);
		}

}
int buscarPacienteEnFichero(char *filename, int dni)
{
	//Devuelve un 0 si no existe el paciente, un 1 si esta.
	paciente p;
	int resul,enc = 0;
	FILE *pf;

	pf=fopen(filename, "r");
	if(pf!=(FILE*)NULL)
	{
		while(fscanf(pf, "%d %s %s %s %c %s\n", p.dni,p.nombre, p.apellido2, p.apellido2,p.sexo,p.fechaNac) != EOF)
		{
			if(p.dni == dni){
				enc = 1;
			 printf("Paciente: %d %s %s %s %c %s\n",p.dni,p.nombre, p.apellido2, p.apellido2,p.sexo,p.fechaNac);
			}
		}
		fclose(pf);

	}
	else
	{
		resul = 0;
	}

	return resul;
}


void asignarHabitacion(paciente p,habitacion *h){

	if(comprobarHabitacionLibre(h)==1){
		h->pac=p;
	}else{
		printf("Error");
	}

}
void asignarMedico(paciente p,Medico *m){

    Medico house;
	house.numpaciente=m->numpaciente;
	house.aPaciente=(paciente*)malloc(m->numpaciente*sizeof(paciente));

	for (int i = 0; i < (m->numpaciente); ++i) {
		house.aPaciente[i] = m->aPaciente[i];
	}
	free(m->aPaciente);
	m->numpaciente=house.numpaciente+1;
	m->aPaciente=(paciente*)malloc(m->numpaciente*sizeof(paciente));
	for (int e = 0; e < (m->numpaciente); ++e) {
		m->aPaciente[e]	 = house.aPaciente[e];
		}
	m->aPaciente[m->numpaciente-1]=p;


}
void liberarMedico(paciente p,Medico* m){


}
void liberarHabitacion(paciente p, habitacion *h){

	h->disponibilidad='d';



}
