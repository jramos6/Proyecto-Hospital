typedef struct{
 int cod;
 char nombre[10];
 //float pri;
}TipoHabitacion;
//prueba
typedef struct{
 int num;
 struct TipoHabitacion tipo;
 char sta;
}Habitacion;

typedef struct {
 char cod[10];
 char nombre[15];
 char apellido[15];
 char sexo;
 //char blo[5];
 struct date birth;
 //char nat[20];
 char especialidad[20];
 //struct DateTime join;
 char telefono[20];
 char email[35];
 char direccion[40];
}Medico;

typedef struct {
 char cod[10];
 char nombre[15];
 char apellido[15];
 char sexo;
 //char blo[5];
 struct date birth;
 //char nat[20];
 char especialidad[20];
 //struct DateTime join;
 char telefono[20];
 char email[35];
 char direccion[40];
}Enfermero;

typedef struct {
 char cod[10];
 char nombre[15];
 char apellido[15];
 char sexo;
 //char blo[5];
 struct date birth;
 //char nat[20];
 char especialidad[20];
 //struct DateTime join;
 char telefono[20];
 char email[35];
 char direccion[40];
}Celador;





typedef struct {
	char cod[10];
	 char nombre[15];
	 char apellido[15];
	 char sexo;
	 //char blo[5];
	 struct date birth;
	 //char nat[20];
	 char especialidad[20];
	 //struct DateTime join;
	 char telefono[20];
	 char email[35];
	 char direccion[40];
	 char sintoma;
}Paciente;






void help();
int login(int);
int resetpwd(int);
int changepwd();
void box(int,int,int,int,int);
void updatedoc(int);
void sortroom(Room *ro,int n);

void sortpat(Patient *pat,int n);
void sortpatname(Patient *pat,int n);
void sortdoc(Doctor *doc,int n);
void sorttype(Types *type,int n);
int getFileElement(const char *name, int size);


void notice(char text[30],int x1,int y1,int x2,int y2);
void notice(char text[2][30],int x1,int y1,int x2,int y2);

int confirm(char str[15]);
void updatepat(int);
void welc();
void inputdat(int &day,int &mon,int &year,int c);
void createfile();
void addtype();
void checkoutinput(int opt);
int checkout(int id);
int selecttype();
char selectsex();
int selectblood();
int findroom(int no);
int finddocid(char id[10]);
int findpatid(char id[10]);
void addroom();
int addpatient(int);
void setroomEMPTY(int);
void setroomSTAY(int);
void patidetail(char id[10]);
void docdetail(char id[10]);
void adddoc();
void deletetype(int);
void deletetypeinput();
void deleteroom();
void deletepat(char id[10]);
int deletedoc(char id[10]);
void deletedocinput(int opt);
int viewpat(char head[30],Paciente *source,int n,int opt);
int viewdoc(char head[30],Medico *source,int n,int opt);
void findpat(int opt);
void finddoc(int opt);
void updateroom();
int viewroom(char head[30],Room *source,int n);
void allroom();
void allpat();
void alldoc();
void findviewroom();
void availroom();
void alltype();
int menu(int);
int doctor();
int patient();
int dropmenu(char menu[7][20],int x1,int y1,int x2,int y2,int opt);
void box(int x1,int y1,int x2,int y2,int c);

int program();
int about();
int room();
char *input(int,int,int);
float inputf(int,int);

