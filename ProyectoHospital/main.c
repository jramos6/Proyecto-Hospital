#include "habitacion.h"
#include "Enfermero.h"
#include "Medico.h"
#include "paciente.h"
#include "Personal.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{


paciente p1,p2,p3,p4,p5;
paciente p1={"joan","garcia","iturrioz",2121233,"M","01/03/2000"};
paciente p2={"peter","parker","parker",2121233,"M","01/03/2000"};
paciente p3={"willy","rex","tim",2121233,"M","01/03/2000"};
paciente p4={"jonh","cena","jonhson",2121233,"M","01/03/2000"};

habitacion h1,h2,h3,h4,h5,h6;
habitacion h2={201,p1,"d"};
habitacion h3={212,p2,"d"};
habitacion h4={231,p3,"d"};
habitacion h5={232,p4,"d"};
habitacion h6={123,NULL,"d"};

Medico m1;
paciente aPac[3];
aPac[1]=p1;
aPac[2]=p2;
aPac[3]=p3;
Medico m1={14314344,"inigo","santa cruz",3,aPac};

printf("hola");
    return 0;


}
