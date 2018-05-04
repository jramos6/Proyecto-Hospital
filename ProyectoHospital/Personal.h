#ifndef PERSONAL_H
#define PERSONAL_H



typedef struct {

	 char cod[10];
	 char profesion[15];
	 char nombre[15];
	 char apellido[15];
	 char sexo;
	 char telefono[20];
	 char email[35];
	 char direccion[40];


}Personal;


void personal();
