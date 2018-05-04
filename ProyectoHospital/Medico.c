#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paciente.h"
#include "Medico.h"
#include "habitacion.h"

void listaDePacientes(Medico m){
	printf("Lista de pacientes del medico %s %s /n",m.nombre,m.apellido);
	for (int i= 0;i < m.numpaciente; ++i) {
		printf("PACIENTE: %s %s %s /n",m.aPaciente[i].nombre,m.aPaciente[i].apellido1,m.aPaciente[i].apellido2);
	}
}
void anaydirMedicoFichero(Medico p,char *filename){

	    FILE *pf;

		pf=fopen(filename,"a");
		if(pf != (FILE*)NULL)
		{

			fprintf(pf, "%d %s %s %s %c %s\n", p.dni,p.nombre, p.apellido, p.numpaciente);
			fclose(pf);
		}

}

