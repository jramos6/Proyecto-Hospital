#include "Personal.c"

void personal(){

	int opcion;
	do{


  printf("Bienvenido al menu del personal del hospital:");
  printf("01.Consultar Medicos");
  printf("02.Consultar enfermeros");

  	  switch(opcion){

  	  case '1': medico();
  	  break;
  	  case '2': enfermero();
  	  break;


  	  }

	}while(opcion!=2);
}
