#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paciente.h"
#include "Medico.h"
#include "habitacion.h"
#define HABITACION 100

void visualizarPacienteHabitacion(int num,char* filename){

	    habitacion habita;
		int resul=0;
		FILE * pf;
		pf=fopen(filename,"r");

		if(pf!=(FILE*)NULL){

			while(fscanf(pf,"%d %c %d \n", habita.num,habita.disponibilidad,habita.pac.dni)){
				if(habita.num==num){
					printf("Paciente de la habitacion %i es: ",num);
					buscarPacienteEnFichero("paciente.txt", habita.pac.dni);
				}
				}


}
int comprobarHabitacionLibre(int num,char *filename)
{

	habitacion habita;
	int resul=0;
	FILE * pf;
	pf=fopen(filename,"r");

	if(pf!=(FILE*)NULL){

		while(fscanf(pf,"%d %c %d \n", habita.num,habita.disponibilidad,habita.pac.dni)){
			if(habita.num==num){
				if(habita.disponibilidad=="d"){
					resul=1;
				}
			}else{
				resul=0;
			}
		}
		return resul;
	}



}
void anadirHabitacionFichero(habitacion hab,char *filename){

	    FILE *pf;

		pf=fopen(filename,"a");
		if(pf != (FILE*)NULL)
		{

			fprintf(pf, "%d %c %d \n", hab.num,hab.disponibilidad,hab.pac.dni);
			fclose(pf);
		}

}

