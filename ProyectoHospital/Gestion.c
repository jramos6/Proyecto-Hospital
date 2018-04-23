
void main(){

printf("Bienvenido al sistema de gestión del hospital");
do{
  switch(menu(opt)){
   case 0:opt=program();break;
   case 1:opt=doctor();break;
   case 2:opt=patient();break;
   case 3:opt=room();break;
   case 4:opt=about();break;
  }

 }while(1);
}




int room(){
 char menu[4][20]={"All rooms","Available","Manage room >","Manage type >"};
 char menu1[4][20]={"Add new","Delete","Search","Update"};
 char menu2[3][20]={"Add new","Delete","All types"};
 int opt=0,close=1;
 do{

  switch(dropmenu(menu,22,3,39,8,opt)){
   case -2:close=0;break;
   case -1:close=0;break;
   case 0:allroom();opt=0;break;
   case 1:availroom();opt=1;break;
   case 2: switch(dropmenu(menu1,40,6,52,11,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=2;
        break;
      case 0: clrwin();addroom();opt=2;break;
      case 1: clrwin();deleteroom();opt=2;break;
      case 2: clrwin();findviewroom();opt=2;break;
      case 3: clrwin();updateroom();opt=2;break;
     }break;
   case 3: switch(dropmenu(menu2,40,7,54,11,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=3;
        break;
      case 0: clrwin();addtype();opt=3;break;
      case 1: clrwin();deletetypeinput();opt=3;break;
      case 2: clrwin();alltype();opt=3;break;
     }break;
  }
 }while(close);
 return 3;
}

int menu(int select){
 char ch, menu[5][20]={"\360","Doctor","Patient","Room","About"};
 int i;
 struct date da;
 textbackground(9);
 window(2,2,79,24);
 clrscr();
 getdate(&da);
 do{
  textbackground(11);
  textcolor(0);
  window(2,2,79,2);
  clrscr();
  for(i=0;i<5;i++)
   if(i==select){
    textbackground(2);
    textcolor(15);
    cprintf("  %s  ",menu[i]);
   }else
    printf(" %s ",menu[i]);
  gotoxy(68,1);printf("%02d/%02d/%d",da.da_day,da.da_mon,da.da_year);
  ch=getch();
  switch(ch){
   case 75:select--;
    if(select==-1) select=4;
    break;
   case 77:select++;
    if(select==5) select=0;
    break;
   case 80:if(select<4)
       ch=13;
    break;
   case 27:select=0;break;
  }

 }while(ch!=13);
 return select;
}
int doctor(){
 char menu[5][20]={"Add","Delete    >","Update    >","Search    >","View All"};
 char menu1[3][20]={"By ID","By First Name","By Last Name"};
 char menu2[3][20]={"All","Name","Specialty"};
 char menu3[4][20]={"By ID","By First Name","By Last Name","By Specialty"};
 int opt=0,close=1;
 do{

  switch(dropmenu(menu,5,3,20,9,opt)){
   case -2:close=0;break;
   case -1:close=0;break;
   case 0:adddoc();opt=0;break;
   case 1: switch(dropmenu(menu1,21,5,39,9,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=1;
        break;
      case 0: clrwin();deletedocinput(1);opt=1;break;
      case 1: clrwin();deletedocinput(2);opt=1;break;
      case 2: clrwin();deletedocinput(3);opt=1;break;
     }break;
   case 2:switch(dropmenu(menu2,21,6,39,10,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=2;
        break;
      case 0: clrwin();updatedoc(1);opt=2;break;
      case 1: clrwin();updatedoc(2);opt=2;break;
      case 2: clrwin();updatedoc(3);opt=2;break;
     }break;
   case 3: switch(dropmenu(menu3,21,7,38,12,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=3;
        break;
      case 0: clrwin();finddoc(1);opt=3;break;
      case 1: clrwin();finddoc(2);opt=3;break;
      case 2: clrwin();finddoc(3);opt=3;break;
      case 3: clrwin();finddoc(4);opt=3;break;
     }break;
   case 4:alldoc();opt=4;break;
  }
 }while(close);
 return 1;
}
int patient(){
 char menu[5][20]={"Check in","Check out by >","Update       >","Search by    >","View All"};
 char menu1[4][20]={"ID","First Name","Last Name","Room No."};
 char menu2[3][20]={"All","Name","Room No."};
 char menu3[4][20]={"ID","Name","Room No.","Check in Date"};

 int opt=0,close=1;
 do{
  clrwin();
  switch(dropmenu(menu,13,3,31,9,opt)){
   case -2:close=0;break;
   case -1:close=0;break;
   case 0:addpatient(0);opt=0;break;
   case 1: switch(dropmenu(menu1,32,5,47,10,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=1;
        break;
      case 0: clrwin();checkoutinput(1);opt=1;break;
      case 1: clrwin();checkoutinput(2);opt=1;break;
      case 2: clrwin();checkoutinput(3);opt=1;break;
      case 3: clrwin();checkoutinput(4);opt=1;break;
     }break;
   case 2: switch(dropmenu(menu2,32,6,45,10,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=2;
        break;
      case 0: clrwin();updatepat(1);opt=2;break;
      case 1: clrwin();updatepat(2);opt=2;break;
      case 2: clrwin();updatepat(3);opt=2;break;
     }break;
   case 3: switch(dropmenu(menu3,32,7,50,12,0)){
      case -2:close=0;opt=0;break;
      case -1:clrwin();
        opt=3;
        break;
      case 0: clrwin();findpat(1);opt=3;break;
      case 1: clrwin();findpat(2);opt=3;break;
      case 2: clrwin();findpat(3);opt=3;break;
      case 3: clrwin();findpat(4);opt=3;break;
     }break;
   case 4:clrwin();allpat();opt=4;break;
  }
 }while(close);
 return 2;
}
int dropmenu(char menu[7][20],int x1,int y1,int x2,int y2,int opt){
 int i,select;
 char ch;
 select=opt;
 if(opt==-1) goto end;
 do{
  textbackground(7);
  textcolor(0);
  window(x1,y1,x2,y2);
  clrscr();
  drawbox(1,1,x2-x1+1,y2-y1+1);
  gotoxy(3,2+select);
  textbackground(2);
  for(i=0; i<x2-x1-3; i++) {
   cprintf(" ");
  }
  for(i=0;i<y2-y1-1;i++){
   gotoxy(4,2+i);
   if(i==select){
   textcolor(15);
   cprintf("%s",menu[i]);
   }else
   printf("%s",menu[i]);
  }
  ch=getch();
  switch(ch){
   case 72:select--;
    if(select==-1) select=y2-y1-2;
    break;
   case 80:select++;
    if(select==y2-y1-1) select=0;
    break;
   case 8: ch=13;opt=-1;
    break;
   case 75:ch=13;opt=-1;
    break;
   case 13:opt=select;
    break;
   case 77:if(strstr(menu[select],">")!=0)
    opt=select,ch=13;
    break;
   case 27:ch=13;opt=-2;
    break;
  }

 }while(ch!=13);
end:
 return opt;
}
void clrwin(){
 textbackground(9);
 textcolor(WHITE);
 window(2,3,79,24);
 clrscr();
}
void sortroom(Room *ro,int n){
 int i,j;
 Room temp;
 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
   if(ro[i].no>ro[j].no){
    temp=ro[i];
    ro[i]=ro[j];
    ro[j]=temp;
   }
}
void sortpat(Patient *pat,int n){
 int i,j;
 Patient temp;
 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
   if(pat[i].ro>pat[j].ro){
    temp=pat[i];
    pat[i]=pat[j];
    pat[j]=temp;
   }
}
void sortpatname(Patient *pat,int n){
 int i,j;
 char *fullname[40];
 Patient temp;
 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++){
   strcpy(fullname[i],pat[i].fname);
   strcat(fullname[i]," ");
   strcat(fullname[i],pat[i].lname);
   strcpy(fullname[j],pat[j].fname);
   strcat(fullname[j]," ");
   strcat(fullname[j],pat[j].lname);
   if(stricmp(fullname[i],fullname[j])>1){
    temp=pat[i];
    pat[i]=pat[j];
    pat[j]=temp;
   }
  }
}
void sortdoc(Doctor *doc,int n){
 int i,j;
 Doctor temp;
 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
   if(stricmp(doc[i].id,doc[j].id)>1){
    temp=doc[i];
    doc[i]=doc[j];
    doc[j]=temp;
   }
}
void sorttype(Types *type,int n){
 int i,j;
 Types temp;
 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
   if(type[i].co>type[j].co){
    temp=type[i];
    type[i]=type[j];
    type[j]=temp;
   }
}
int getFileElement(const char *name, int size) {
 FILE *source = fopen(name,"rb+");
 fseek(source,0,SEEK_END);
 size = ftell(source)/size;
 fclose(source);
 return size;
}



int confirm(char str[15]){
 char conf[2][5]={"No","Yes"};
 int i,ch,select=0;
 textbackground(9);
 window(2,24,79,24);
 clrscr();
 textbackground(0);
 window(24,10,57,18);
 clrscr();
 textbackground(14);
 window(23,9,56,17);
 clrscr();
 drawbox(2,1,35,9);
 gotoxy((33-(11+strlen(str)))/2,3);textcolor(15);
 cprintf("<Confirm Your %s>",str);
 do{
  for(i=0;i<=1;i++){
   if(i==select)
     textbackground(2);
   else textbackground(14);
  textcolor(15);
  gotoxy(8+i*16,7);
  cprintf(" %s ",conf[i]);
  }
  ch=getch();
  switch(ch){
   case 75:select--;
     if(select==-1) select=1;break;
   case 77:select++;
     if(select==2) select=0; break;
  }

 }while(ch!=13);
 return select;
}

char *input(int type,int limit,int c){
 char result[50]="";
 char ch;
 int index = 0;
 _setcursortype(2);
 do {
  ch=getch();
  if((type==3||type==0)&&index<limit){
   if(isalpha(ch)||(ch>='!'&&ch<='@')||ch==95) {
    result[index++]=ch;
    if(type==0){
      textcolor(c);cprintf("*");
    }else{
      textcolor(c);cprintf("%c",ch);
    }
   }
  }
  if(type==1&&index<limit){
   if(ch>=40&&ch<=57) {
    result[index++] = ch;
    textcolor(c);cprintf("%c",ch);
   }
  }
  if(type==2&&index<limit)
   if(isalpha(ch)||ch==' ') {
    result[index++]=ch;
    textcolor(c);cprintf("%c",ch);
   }
  if(ch==8&&index>0) {
   result[index--]=NULL;
   printf("\b \b");
  }
  if(ch==94&&type==0&&index>0){
   _setcursortype(0);
   result[index]=0;
   for(int i=0;i<index;i++)
    printf("\b");
   textcolor(c);cprintf("%s",result);
   for(i=0;i<index;i++)
    printf("\b");
   delay(100);
   for(i=0;i<index;i++)
    textcolor(c),cprintf("*");
   _setcursortype(2);
  }
 } while((ch != 13||index<1)&&ch!=27);
 result[index] =0;
 _setcursortype(0);
 return ch==27?"00":result;
}
float inputf(int limit,int c){
int i=0,f=-1;
char result[50]="",ch;
 _setcursortype(2);
 do{
  ch=getch();
  if((ch>='0'&&ch<='9')||(ch=='.'&&f==-1)&&i<limit){
   if(ch=='.')
    f=i;
   result[i++]=ch;
   textcolor(c);cprintf("%c",ch);
  }
  if(ch==8&&i>0){
   result[--i]='\0';
   if(i==f)
    f=-1;
   printf("\b \b");
  }
 }while((ch!=13||i==0)&&ch!=27);
 result[i]='\0';
 _setcursortype(0);
return ch==27?0.0:atof(result);
}
void createfile(){
 f_doc=fopen(_doct,"rb");
 if(f_doc==NULL)
  f_doc=fopen(_doct,"wb");
 f_pat=fopen(_pati,"rb");
 if(f_pat==NULL)
  f_pat=fopen(_pati,"wb");
 f_ty=fopen(_type,"rb");
 if(f_ty==NULL)
  f_ty=fopen(_type,"wb");
 f_ro=fopen(_room,"rb");
 if(f_ro==NULL)
  f_ro=fopen(_room,"wb");
 fclose(f_doc);
 fclose(f_pat);
 fclose(f_ty);
 fclose(f_ro);
}
void addtype(){
 struct Types type;
 char ty[10];
 int code,i,n;
 float pri;
 char ch;
 char text[2][30]={"<Type added>","<<Enter to add another>>"};
 char head[30]="NEW TYPE";
 do{
 s: clrwin();
  help();
  drawwindow(head,22,7,57,17,12);
  gotoxy(10,3);textcolor(15);cprintf("Code: ");code=atoi(input(1,5,15));
  if(code==0) break;
  n=getFileElement(_type,sizeof(Types));
  f_ty=fopen(_type,"rb");
  rewind(f_ty);
  for(i=0;i<n;i++){
   fread(&type,sizeof(Types),1,f_ty);
   if(code==type.co){
    notice(">This code of type is exist<",24,10,55,15);
    blockey();
    fclose(f_ty);
    goto s;
   }
  }
  fclose(f_ty);
  gotoxy(10,5);textcolor(15);cprintf("Type: ");strcpy(ty,input(2,15,15));
  if(strcmp(ty,"00")==0) break;
  f_ty=fopen(_type,"rb");
  rewind(f_ty);
  for(i=0;i<n;i++){
   fread(&type,sizeof(Types),1,f_ty);
   if(stricmp(type.na,ty)==0){
    notice(">This name of type is exist<",24,10,55,15);
    blockey();
    fclose(f_ty);
    goto s;
   }
  }
  fclose(f_ty);
  gotoxy(10,7);textcolor(15);cprintf("Price: "); pri=inputf(10,15);  //problem with float
  if(pri==0.0) break;
  type.co=code;
  strcpy(type.na,ty);
  type.pri=pri;
  f_ty=fopen(_type,"ab");
  fwrite(&type,sizeof(Types),1,f_ty);
  fclose(f_ty);
  notice(text,24,10,55,15);
  ch=blockey();
  if(ch==27) break;
 }while(1);
}
int selecttype(){
 char ch;
 int n,i,index=0,result=-1;
 n=getFileElement(_type,sizeof(Types));
 f_ty=fopen(_type,"rb");
 struct Types *type=(Types*) calloc(n,sizeof(Types));
 for(i=0;i<n;i++){
  fread(&type[i],sizeof(Types),1,f_ty);
 }
 do {clrscr();
  textcolor(2);
  cprintf("%c %s %c",174,type[index].na,175);

  do{
   ch = getch();
  } while(ch!=75 && ch!=77 && ch!=13 && ch!=27);

  if(ch==77) {index++;if(index>n-1) index=0;}
  else if(ch==75){ index--;if(index<0) index=n-1;}

 } while(ch!=13 && ch!=27);

 if(ch==13) {
  result=type[index].co;
 }
 fclose(f_ty);
 return result;
}
char selectsex(){
 char sex[3]="FM";
 char ch,result='n';
 int n,i=0;
 do {clrscr();
  textcolor(2);
  cprintf("%c %c %c",174,sex[i],175);

  do{
   ch = getch();
  } while(ch!=75&&ch!=77&&ch!=13&&ch!=27);

  if(ch==77) {i++;if(i>=2) i=0;}
  else if(ch==75){ i--;if(i<=-1) i=1;}

 } while(ch!=13&&ch!=27);

 if(ch==13) {
  result=sex[i];
 }
 return result;
}
int selectblood(){
 char blood[8][4]={"O+","O-","A+","A-","B+","B-","AB+","AB-"};
 char ch;
 int result;
 int n,i=0;
 do {clrscr();
  textcolor(2);
  cprintf("%c %s %c",174,blood[i],175);
  do{
   ch=getch();
  }while(ch!=75&&ch!=77&&ch!=13&&ch!=27);
  if(ch==77) {i++;if(i>=8) i=0;}
  else if(ch==75){ i--;if(i<=-1) i=7;}
 } while(ch!=13&&ch!=27);

 if(ch==13) {
  result=i+1;
 }else{
  result=0;
 }
 return result;
}
int findroom(int no){
 struct Room ro;
 int i,n,f=0;
 n=getFileElement(_room,sizeof(Room));
 f_ro=fopen(_room,"rb+");
 rewind(f_ro);
 for(i=0;i<n;i++){
  fread(&ro,sizeof(Room),1,f_ro);
  if(no==ro.no){
   if(ro.sta==STAY){
    f=2;
   }else{
    f=1;
   }
  }
 }fclose(f_ro);
 return f;
}
int findpatid(char id[10]){
 struct Patient pat;
 int i,n,f=0;
 n=getFileElement(_pati,sizeof(Patient));
 f_pat=fopen(_pati,"rb+");
 rewind(f_pat);
 for(i=0;i<n;i++){
  fread(&pat,sizeof(Patient),1,f_pat);
  if(strcmp(id,pat.id)==0){
   f=1;
   break;
  }
 }fclose(f_pat);
 return f;
}
int finddocid(char id[10]){
 struct Doctor doc;
 int i,n,f=0;
 n=getFileElement(_doct,sizeof(Doctor));
 f_doc=fopen(_doct,"rb+");
 rewind(f_doc);
 for(i=0;i<n;i++){
  fread(&doc,sizeof(Doctor),1,f_doc);
  if(strcmp(id,doc.id)==0){
   f=1;
   break;
  }
 }fclose(f_doc);
 return f;
}
void addroom(){
 struct Room ro;
 struct Types type;
 int no,i,n,nt,ty;
 char ch;
 char text[2][30]={"<Room added>","<<Enter to add another>>"};
 char textt[2][30]={"<Do not have type of room>","<<Enter to add type>>"};
 char head[30]="NEW ROOM";
 do{
s:  clrwin();
  help();
  drawwindow(head,22,7,57,17,12);
  n=getFileElement(_type,sizeof(Types));
  if(n==0){
   notice(textt,24,10,55,15);
   if(getch()!=13) break;
   addtype();
   clrwin();
   drawwindow(head,22,7,57,17,12);
  }
  gotoxy(12,4);textcolor(15);cprintf("Room No.: ");no=atoi(input(1,5,15));
  if(no==0) break;
  if(findroom(no)!=0){
   notice(">This room is exist<",24,10,55,15);
   blockey();
   fclose(f_ro);
   goto s;
  }
  gotoxy(12,6);textcolor(15);cprintf("Type: ");
  window(39,12,51,12);
  ty=selecttype();
  if(ty==-1) break;
  else {
   nt=getFileElement(_type,sizeof(Types));
   f_ty=fopen(_type,"rb+");
   rewind(f_ty);
   for(i=0;i<nt;i++){
    fread(&type,sizeof(Types),1,f_ty);
    if(type.co==ty){
     ro.type.co=type.co;
     stpcpy(ro.type.na,type.na);
     ro.type.pri=type.pri;
    }
   }
   fclose(f_ty);
  }
  ro.no=no;
  ro.sta=EMPTY;
  f_ro=fopen(_room,"ab");
  fwrite(&ro,sizeof(Room),1,f_ro);
  fclose(f_ro);
  notice(text,24,10,55,15);
  ch=blockey();
  if(ch==27) break;
 }while(1);
}
void checkoutinput(int opt){
 struct Patient pat;
 char fname[20],lname[20];
 char id[10],ch,c;
 int i,n,f=0,nf=0,no;
 char head[30]="CHECKOUT PATIENT";

 do{ n=getFileElement(_pati,sizeof(Patient));
  f=0;nf=0;
  Patient *source =(Patient*) calloc(n,sizeof(Patient));
  clrwin();
  help();
  drawwindow("SEARCH PATIENT TO CHECKOUT",22,7,57,17,12);
  if(n==0){
   gotoxy(3,5);textcolor(15);
   cprintf("<There are no Patient to Checkout>");
   blockey();
   break;
  }
  if(opt==1){
   gotoxy(14,5);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
   if(strcmp(id,"00")==0) break;
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    if(strcmp(id,pat.id)==0){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
  }
  if(opt==2){
   gotoxy(10,5);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
   if(strcmp(fname,"00")==0) break;
   else strupr(fname);
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    if(strstr(pat.fname,fname)!=0||stricmp(pat.fname,fname)==0){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
   sortpatname(source,nf);
  }
  if(opt==3){
   gotoxy(10,5);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
   if(strcmp(lname,"00")==0) break;
   else strupr(fname);
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    if(strstr(pat.lname,lname)!=0||stricmp(pat.lname,lname)==0){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
   sortpatname(source,nf);
  }
  if(opt==4){
   gotoxy(12,5);textcolor(15);cprintf("Room No.: "); no=atoi(input(1,5,15));
   if(no==0) break;
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    if(pat.ro==no){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
   sortpat(source,nf);
  }
  if(f==1){
   if(viewpat(head,source,nf,0)==13)
    continue;
   else break;
  }

  if(f==0){
   notice("<Patient not found>",24,10,55,15);
   blockey();
   continue;
  }
  if(ch==27) break;
 }while(1);
}

int checkout(char id[10]){
 struct Room ro;
 struct Patient pat;
 struct date da;
 int n,i,j,nr;
 char ch;
 char head[30]="CHECKOUT PATIENT";
 char text[2][30]={"<Patient checked out>","<<Enter to checkout another>>"};
 float paid=0,pay=0;

 //Get period of staying.
 double second;
 int tperiod;
 time(&current);
 struct tm period;
 gt = localtime(&current);
 n=getFileElement(_pati,sizeof(Patient));
 f_pat=fopen(_pati,"rb+");
 rewind(f_pat);
 for(i=0; i<n; i++) {
  fread(&pat,sizeof(Patient),1,f_pat);
  if(strcmp(id,pat.id)==0)
   break;
 }fclose(f_pat);
 nr=getFileElement(_room,sizeof(Room));
 f_ro=fopen(_room,"rb");
 rewind(f_ro);
 for(j=0;j<nr;j++){
  fread(&ro,sizeof(Room),1,f_ro);
  if(ro.no==pat.ro)
   break;
 }fclose(f_ro);

 period.tm_hour = pat.regi.hour;
 period.tm_min = pat.regi.min;
 period.tm_sec = 0;
 period.tm_year = pat.regi.year-1900;
 period.tm_mon = pat.regi.mon-1;
 period.tm_mday = pat.regi.day;
 second = difftime(current,mktime(&period));

 time(&current);
 gt = localtime(&current);

 if(pat.regi.day==gt->tm_mday || (gt->tm_mday - pat.regi.day==1 && gt->tm_hour <= 12)){
  tperiod=1;
 } else tperiod = 1+((second/60)/60)/24;

 paid=(tperiod*ro.type.pri);
 clrwin();
 help();
 drawwindow(head,12,7,69,20,5);
 getdate(&da);
 textcolor(14);
 gotoxy(1,1);printf("Name     : ");cprintf("%s %s",pat.fname,pat.lname);
 gotoxy(1,3);printf("Sex      : ");cprintf("%c",pat.sex);
 gotoxy(1,5);printf("Room No. : ");cprintf("%03d",ro.no);
 gotoxy(1,7);printf("Type     : ");cprintf("%s",ro.type.na);
 gotoxy(1,9);printf("Price    : ");cprintf("$%.2f/day",ro.type.pri);
 gotoxy(1,11);printf("Date in  : ");cprintf("%02d/%02d/%d",pat.regi.day,pat.regi.mon,pat.regi.year);
 gotoxy(1,13);printf("Date Out : ");cprintf("%02d/%02d/%d",gt->tm_mday,gt->tm_mon+1,gt->tm_year+1900);
 drawwindow("PAYMENT",45,11,64,16,3);
 gotoxy(1,2);printf("Other pay = $ "); pay=inputf(10,15);  //problem with float
 if(pay==0.0){ goto end;}
 gotoxy(1,4);printf("Total pay = ");printf("$%.2f",paid+pay);
 deletepat(id);
 setroomEMPTY(pat.ro);
 blockey();
 notice(text,20,10,60,15);
 ch=blockey();
end: return ch;
}

int addpatient(int no){
 struct Room ro;
 struct Patient pat;
 struct date dai;
 int i,n,nav=0,nr,opt,s=0;
 int day=0,mon=0,year=0;
 char ch;
 char id[10],fname[15],lname[15],sex,blo[5],prob[20],nat[20],tel[20],addr[40];
 char text[2][30]={"<Patient added>","<<Enter to add another>>"};
 char blood[9][4]={"00","O+","O-","A+","A-","B+","B-","AB+","AB-"};
 char head[30]="NEW PATIENT";
 opt=no;
 do{
  getdate(&dai);
  clrwin();
  help();
  drawwindow(head,12,7,69,20,12);
  nr=getFileElement(_room,sizeof(Room));
  f_ro=fopen(_room,"rb");
  rewind(f_ro);
  for(i=0; i<nr; i++) {
   fread(&ro,sizeof(Room),1,f_ro);
   if(ro.sta==EMPTY){
    nav++;
   }
  }fclose(f_ro);
  if(nav==0){
   gotoxy(14,7);textcolor(15);cprintf("<There are no available rooms>");
   blockey();
   s=0;
   break;
  }

  if(no==0){
   gotoxy(1,1);textcolor(15);cprintf("Room No.: ");no=atoi(input(1,5,15));
   if(no==0) {s=0;break;}
   if(findroom(no)!=1){
    notice("<Unavailable Room>",24,10,55,15);
    blockey();
    no=0;
    continue;
   }
  }else{
   gotoxy(1,1);textcolor(15);cprintf("Room No.: %03d",no);
  }
  gotoxy(1,3);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
  if(strcmp(id,"00")==0) {s=0;break;}
  if(finddocid(id)==1||findpatid(id)==1){
   notice("<This ID is exist>",24,10,55,15);
   ch=blockey();
   if(ch==27){s=0;break;}
   else continue;
  }
  gotoxy(1,5);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
  if(strcmp(fname,"00")==0) {s=0;break;}
  else strupr(fname);
  gotoxy(1,7);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
  if(strcmp(lname,"00")==0) {s=0;break;}
  else strupr(lname);
  gotoxy(1,9);textcolor(15);cprintf("Sex: "); window(17,15,23,15);sex=selectsex();
  if(sex=='n'){s=0;break;}
  window(12,7,69,20);
date:  gotoxy(1,11);textcolor(15);cprintf("Date of Birth: "); gotoxy(16,11);inputdat(day,mon,year,15);
  if(day==0||mon==0||year==0) {s=0;break;}
  else if(day>31||mon>12||year<1900||year>dai.da_year||(mon>dai.da_mon&&year>=dai.da_year)||(day>dai.da_day&&mon>=dai.da_mon&&year>=dai.da_year)){
   gotoxy(16,11);printf("DD/MM/YYYY");
   day=0;mon=0;year=0;
   goto date;
  }
  gotoxy(1,13);textcolor(15);cprintf("Address: "); strcpy(addr,input(3,39,15));
  if(strcmp(addr,"00")==0) {s=0;break;}
  gotoxy(30,1);textcolor(15);cprintf("Blood Group: ");window(54,7,61,7); strcpy(blo,blood[selectblood()]);
  if(strcmp(blo,"00")==0) {s=0;break;}
  window(12,7,69,20);
  gotoxy(30,3);textcolor(15);cprintf("Problem: ");strcpy(prob,input(2,19,15));
  if(strcmp(prob,"00")==0) {s=0;break;}
  gotoxy(30,5);textcolor(15);cprintf("Tel: "); strcpy(tel,input(1,19,15));
  if(strcmp(tel,"00")==0) {s=0;break;}
  gotoxy(30,7);textcolor(15);cprintf("Nationality: "); strcpy(nat,input(2,19,15));
  if(strcmp(nat,"00")==0) {s=0;break;}

  f_ro=fopen(_room,"rb+");
  rewind(f_ro);
  for(i=0; i<nr; i++) {
   fread(&ro,sizeof(Room),1,f_ro);
   if(ro.no==no){
    ro.sta=STAY;
    fseek(f_ro,-(int)sizeof(Room),SEEK_CUR);
    fwrite(&ro,sizeof(Room),1,f_ro);
   }
  }fclose(f_ro);

  time(&current);
  gt = localtime(&current);

  pat.ro=no;
  strcpy(pat.id,id);
  strcpy(pat.fname,fname);
  strcpy(pat.lname,lname);
  pat.sex=sex;
  pat.birth.da_day=day;
  pat.birth.da_mon=mon;
  pat.birth.da_year=year;
  strcpy(pat.addr,addr);
  strcpy(pat.blo,blo);
  strcpy(pat.prob,prob);
  strcpy(pat.nat,nat);
  strcpy(pat.tel,tel);
  pat.regi.sec = gt->tm_sec;
  pat.regi.min = gt->tm_min;
  pat.regi.hour = gt->tm_hour;
  pat.regi.day=gt->tm_mday;
  pat.regi.mon=gt->tm_mon+1;
  pat.regi.year=gt->tm_year+1900;
  f_pat=fopen(_pati,"ab");
  fwrite(&pat,sizeof(Patient),1,f_pat);
  fclose(f_pat);
  s=1;
  if(opt!=0){
   notice("<Patient added>",24,10,55,15);
   blockey();
   break;
  }
  notice(text,24,10,55,15);

  ch=blockey();
  if(ch==13)no=0;
  if(ch==27)break;
 }while(1);
 return s;
}
void welc(){
 textcolor(11);
 textbackground(BLUE);
 window(1,1,80,25);
 clrscr();
 gotoxy(23,3);printf("\x20\x5f\x20\x20\x20\x5f\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x20\x5f\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x20");
 gotoxy(23,22);printf("\x20\x20\x20\x20\x20\x20\x20\x7c\x5f\x5f\x5f\x2f");delay(100);
 gotoxy(23,4);printf("\x7c\x20\x7c\x20\x7c\x20\x7c\x20\x5f\x5f\x5f\x20\x20\x5f\x5f\x5f\x5f\x20\x5f\x20\x5f\x5f\x20\x7c\x5f\x7c\x20\x7c\x5f\x20\x5f\x5f\x20\x5f\x7c\x20\x7c");
 gotoxy(23,21);printf("\x7c\x5f\x5f\x5f\x5f\x2f\x20\x5c\x5f\x5f\x2c\x20\x7c\x5f\x5f\x5f\x5f\x2f\x5c\x5f\x5f\x5c\x5f\x5f\x5f\x5f\x7c\x5f\x7c\x20\x7c\x5f\x7c\x20\x7c\x5f\x7c");delay(100);
 gotoxy(23,5);printf("\x7c\x20\x7c\x5f\x7c\x20\x7c\x2f\x20\x5f\x20\x5c\x2f\x20\x5f\x5f\x5f\x7c\x20\x27\x5f\x20\x5c\x7c\x20\x7c\x20\x5f\x5f\x2f\x20\x5f\x60\x20\x7c\x20\x7c");
 gotoxy(23,20);printf("\x20\x5f\x5f\x5f\x29\x20\x7c\x20\x7c\x5f\x7c\x20\x5c\x5f\x5f\x5f\x20\x5c\x20\x7c\x7c\x20\x20\x5f\x5f\x5f\x2f\x20\x7c\x20\x7c\x20\x7c\x20\x7c\x20\x7c");delay(100);
 gotoxy(23,6);printf("\x7c\x20\x20\x5f\x20\x20\x7c\x20\x28\x5f\x29\x20\x5c\x5f\x5f\x5f\x20\x5c\x20\x7c\x5f\x29\x20\x7c\x20\x7c\x20\x7c\x7c\x20\x28\x5f\x29\x20\x7c\x20\x7c");
 gotoxy(23,19);printf("\x5c\x5f\x5f\x5f\x20\x5c\x7c\x20\x7c\x20\x7c\x20\x2f\x20\x5f\x5f\x5f\x7c\x20\x5f\x5f\x2f\x20\x5f\x5f\x20\x5c\x20\x27\x5f\x20\x60\x20\x5f\x20\x5c\x20");delay(100);
 gotoxy(23,7);printf("\x7c\x5f\x7c\x20\x7c\x5f\x7c\x5c\x5f\x5f\x5f\x2f\x7c\x5f\x5f\x5f\x5f\x2f\x20\x20\x5f\x5f\x2f\x7c\x5f\x7c\x5c\x5f\x5f\x5c\x5f\x5f\x2c\x5f\x7c\x5f\x7c");
 gotoxy(23,18);printf("\x2f\x20\x5f\x5f\x5f\x7c\x20\x5f\x20\x20\x20\x5f\x20\x5f\x5f\x5f\x5f\x7c\x20\x7c\x5f\x20\x5f\x5f\x5f\x5f\x20\x5f\x20\x5f\x5f\x20\x5f\x5f\x5f\x20\x20");delay(100);
 gotoxy(23,8);printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7c\x5f\x7c");
 gotoxy(23,17);printf("\x20\x5f\x5f\x5f\x5f\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20");delay(100);
 gotoxy(9,10);printf("\x20\x5f\x5f\x20\x20\x5f\x5f\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x5f\x20\x20\x20");
 gotoxy(9,15);printf("\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x7c\x5f\x5f\x5f\x2f");delay(100);
 gotoxy(9,11);printf("\x7c\x20\x20\x5c\x2f\x20\x20\x7c\x20\x5f\x5f\x20\x5f\x20\x5f\x20\x5f\x5f\x20\x20\x20\x5f\x5f\x20\x5f\x20\x20\x5f\x5f\x20\x5f\x20\x20\x5f\x5f\x5f\x5f\x20\x5f\x20\x5f\x5f\x20\x5f\x5f\x5f\x20\x20\x20\x5f\x5f\x5f\x5f\x20\x5f\x20\x5f\x5f\x20\x7c\x20\x7c\x5f\x20");
 gotoxy(9,14);printf("\x7c\x5f\x7c\x20\x20\x7c\x5f\x7c\x5c\x5f\x5f\x2c\x5f\x7c\x5f\x7c\x20\x7c\x5f\x7c\x5c\x5f\x5f\x2c\x5f\x7c\x5c\x5f\x5f\x2c\x20\x7c\x5c\x5f\x5f\x5f\x5f\x7c\x5f\x7c\x20\x7c\x5f\x7c\x20\x7c\x5f\x7c\x5c\x5f\x5f\x5f\x5f\x7c\x5f\x7c\x20\x7c\x5f\x7c\x5c\x5f\x5f\x7c");delay(100);
 gotoxy(9,12);printf("\x7c\x20\x7c\x5c\x2f\x7c\x20\x7c\x2f\x20\x5f\x60\x20\x7c\x20\x27\x5f\x20\x5c\x20\x2f\x20\x5f\x60\x20\x7c\x2f\x20\x5f\x60\x20\x7c\x2f\x20\x5f\x5f\x20\x5c\x20\x27\x5f\x20\x60\x20\x5f\x20\x5c\x20\x2f\x20\x5f\x5f\x20\x5c\x20\x27\x5f\x20\x5c\x7c\x20\x5f\x5f\x7c");
 gotoxy(9,13);printf("\x7c\x20\x7c\x20\x20\x7c\x20\x7c\x20\x28\x5f\x7c\x20\x7c\x20\x7c\x20\x7c\x20\x7c\x20\x28\x5f\x7c\x20\x7c\x20\x28\x5f\x7c\x20\x7c\x20\x20\x5f\x5f\x5f\x2f\x20\x7c\x20\x7c\x20\x7c\x20\x7c\x20\x7c\x20\x20\x5f\x5f\x5f\x2f\x20\x7c\x20\x7c\x20\x7c\x20\x7c\x5f\x20");delay(100);
 textbackground(15);
 window(7,3,10,8);
 clrscr();
 window(4,5,13,6);
 clrscr();
 window(71,3,74,8);
 clrscr();
 window(68,5,77,6);
 clrscr();
 window(1,1,80,25);
 do{
  gotoxy(30,24); printf("  < Press any key >  ");
  delay(500);if(kbhit()){getch();break;}
  gotoxy(30,24); printf(" << Press any key >> ");
  delay(500);if(kbhit()){getch();break;}
  gotoxy(30,24); printf("<<< Press any key >>>");
  delay(500);if(kbhit()){getch();break;}
 }while(1);
}


void setroomEMPTY(int no){
  int n,i;
  struct Room ro;
  n=getFileElement(_room,sizeof(Room));
  f_ro=fopen(_room,"rb+");
  rewind(f_ro);
  for(i=0; i<n; i++) {
   fread(&ro,sizeof(Room),1,f_ro);
   if(ro.no==no){
    ro.sta=EMPTY;
    fseek(f_ro,-(int)sizeof(Room),SEEK_CUR);
    fwrite(&ro,sizeof(Room),1,f_ro);
   }
  }fclose(f_ro);
}
void setroomSTAY(int no){
  int n,i;
  struct Room ro;
  n=getFileElement(_room,sizeof(Room));
  f_ro=fopen(_room,"rb+");
  rewind(f_ro);
  for(i=0; i<n; i++) {
   fread(&ro,sizeof(Room),1,f_ro);
   if(ro.no==no){
    ro.sta=STAY;
    fseek(f_ro,-(int)sizeof(Room),SEEK_CUR);
    fwrite(&ro,sizeof(Room),1,f_ro);
   }
  }fclose(f_ro);
}
void patidetail(char id[10]){
 struct Room ro;
 struct Patient pat;
 struct date da;
 int n,i;
 char head[30]="PATIENT DETAIL";
 clrwin();
 help();
 drawwindow(head,12,7,69,20,12);
 getdate(&da);
 n=getFileElement(_pati,sizeof(Patient));
 f_pat=fopen(_pati,"rb+");
 rewind(f_pat);
 for(i=0; i<n; i++) {
  fread(&pat,sizeof(Patient),1,f_pat);
  if(strcmp(id,pat.id)==0){
   textcolor(14);
   gotoxy(1,1);printf("Room No.: ");cprintf("%03d",pat.ro);
   gotoxy(1,3);printf("ID: ");cprintf("%s",pat.id);
   gotoxy(1,5);printf("First Name: ");cprintf("%s",pat.fname);
   gotoxy(1,7);printf("Last Name: ");cprintf("%s",pat.lname);
   gotoxy(1,9);printf("Sex: ");cprintf("%c",pat.sex);
   gotoxy(1,11);printf("Date of Birth: ");cprintf("%02d/%02d/%d",pat.birth.da_day,pat.birth.da_mon,pat.birth.da_year);
   gotoxy(1,13);printf("Address: ");cprintf("%s",pat.addr);
   gotoxy(30,2);printf("Age: ");cprintf("%d",(da.da_mon>=pat.birth.da_mon&&da.da_day>=pat.birth.da_day)?(da.da_year-pat.birth.da_year):(da.da_year-pat.birth.da_year-1));
   gotoxy(30,4);printf("Blood Group: ");cprintf("%s",pat.blo);
   gotoxy(30,6);printf("Problem: ");cprintf("%s",pat.prob);
   gotoxy(30,8);printf("Tel: ");cprintf("%s",pat.tel);
   gotoxy(30,10);printf("Nationality: ");cprintf("%s",pat.nat);
   gotoxy(30,12);printf("Date register :");cprintf("%02d/%02d/%d",pat.regi.day,pat.regi.mon,pat.regi.year);
   break;
  }
 }fclose(f_pat);
}

void help(){
 textcolor(0);
 textbackground(7);
 window(2,24,79,24);
 clrscr();
 printf(" ESC TO GO BACK.");
}
int about() {
 char ch;
 clrwin();
 help();
 drawwindow("ABOUT PROGRAM",13,7,67,20,RED);
 gotoxy(15,1); printf("HOSPITAL MANAGEMENT SYSTEM");
 gotoxy(15,2);printf("==========================");
 gotoxy(13,4);textcolor(YELLOW); cprintf("Lecturer    : Heng Soman");

 gotoxy(13,7);textcolor(9); cprintf("Created by  : SRUN VITOU");
 gotoxy(13,9);textcolor(9); cprintf("Started     : Friday,3,April,2015");
 gotoxy(13,11);textcolor(9); cprintf("Finished    : Monday,13,April,2015");
 gotoxy(13,13);textcolor(9); cprintf("Version     : 1.0");
 while(blockey()==13);
 return 4;
}
void docdetail(char id[10]){
 struct Doctor doc;
 struct date da;
 int n,i;
 char head[30]="DOCTOR DETAIL";
 clrwin();
 help();
 drawwindow(head,12,7,69,20,12);
 getdate(&da);
 n=getFileElement(_doct,sizeof(Doctor));
 f_doc=fopen(_doct,"rb+");
 rewind(f_doc);
 for(i=0; i<n; i++) {
  fread(&doc,sizeof(Doctor),1,f_doc);
  if(strcmp(id,doc.id)==0){
   gotoxy(1,1);textcolor(14);printf("ID: ");cprintf("%s",doc.id);
   gotoxy(1,3);textcolor(14);printf("First Name: ");cprintf("%s",doc.fname);
   gotoxy(1,5);textcolor(14);printf("Last Name: ");cprintf("%s",doc.lname);
   gotoxy(1,7);textcolor(14);printf("Sex: ");cprintf("%c",doc.sex);
   gotoxy(1,9);textcolor(14);printf("Date of Birth: ");cprintf("%02d/%02d/%d",doc.birth.da_day,doc.birth.da_mon,doc.birth.da_year);
   gotoxy(1,11);textcolor(14);printf("E-mail: ");cprintf("%s",doc.email);
   gotoxy(1,13);textcolor(14);printf("Address: ");cprintf("%s",doc.addr);
   gotoxy(30,2);textcolor(14);printf("Age: ");cprintf("%d",(da.da_mon>=doc.birth.da_mon&&da.da_day>=doc.birth.da_day)?(da.da_year-doc.birth.da_year):(da.da_year-doc.birth.da_year-1));
   gotoxy(30,4);textcolor(14);printf("Blood Group: ");cprintf("%s",doc.blo);
   gotoxy(30,6);textcolor(14);printf("Tel: ");cprintf("%s",doc.tel);
   gotoxy(30,8);textcolor(14);printf("Specialty: ");cprintf("%s",doc.spec);
   gotoxy(30,10);textcolor(14);printf("Nationality: ");cprintf("%s",doc.nat);
   gotoxy(30,12);textcolor(14);printf("Date of joining: ");cprintf("%02d/%02d/%d",doc.join.day,doc.join.mon,doc.join.year);
   break;
  }
 }fclose(f_pat);
}
void adddoc(){
 struct Doctor doc;
 struct date dai;
 int day=0,mon=0,year=0;
 char ch;
 char id[10],fname[15],lname[15],sex,blo[5],spec[20],nat[20],tel[20],email[35],addr[40];
 char text[2][30]={"<Doctor added>","<<Enter to add another>>"};
 char blood[9][4]={"00","O+","O-","A+","A-","B+","B-","AB+","AB-"};
 char head[30]="NEW DOCTOR";
 do{
  getdate(&dai);
  clrwin();
  help();
  drawwindow(head,12,7,69,20,12);
  gotoxy(1,1);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
  if(strcmp(id,"00")==0) break;
  if(finddocid(id)==1||findpatid(id)==1){
   notice("<This ID is exist>",24,10,55,15);
   blockey();
   continue;
  }
  gotoxy(1,3);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
  if(strcmp(fname,"00")==0) break;
  else strupr(fname);
  gotoxy(1,5);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
  if(strcmp(lname,"00")==0) break;
  else strupr(lname);
  gotoxy(1,7);textcolor(15);cprintf("Sex: "); window(17,13,23,13);sex=selectsex();
  if(sex=='n')break;
  window(12,7,69,20);
date:  gotoxy(1,9);textcolor(15);cprintf("Date of Birth: "); gotoxy(16,9);inputdat(day,mon,year,15);
  if(day==0||mon==0||year==0) break;
  else if(day>31||mon>12||year<1900||year>dai.da_year||(mon>dai.da_mon&&year>=dai.da_year)||(day>dai.da_day&&mon>=dai.da_mon&&year>=dai.da_year)){
   gotoxy(16,9);printf("DD/MM/YYYY");
   day=0;mon=0;year=0;
   goto date;
  }
  gotoxy(1,11);textcolor(15);cprintf("E-mail: "); strcpy(email,input(3,34,15));
  if(strcmp(email,"00")==0) break;
  gotoxy(1,13);textcolor(15);cprintf("Address: "); strcpy(addr,input(3,39,15));
  if(strcmp(addr,"00")==0) break;
  gotoxy(30,1);textcolor(15);cprintf("Blood Group: ");window(54,7,61,7); strcpy(blo,blood[selectblood()]);
  if(strcmp(blo,"00")==0) break;
  window(12,7,69,20);
  gotoxy(30,3);textcolor(15);cprintf("Tel: "); strcpy(tel,input(1,19,15));
  if(strcmp(tel,"00")==0) break;
  gotoxy(30,5);textcolor(15);cprintf("Specialty: ");strcpy(spec,input(2,17,15));
  if(strcmp(spec,"00")==0) break;
  else strupr(spec);
  gotoxy(30,7);textcolor(15);cprintf("Nationality: "); strcpy(nat,input(2,15,15));
  if(strcmp(nat,"00")==0) break;

  time(&current);
     gt = localtime(&current);

  strcpy(doc.id,id);
  strcpy(doc.fname,fname);
  strcpy(doc.lname,lname);
  doc.sex=sex;
  doc.birth.da_day=day;
  doc.birth.da_mon=mon;
  doc.birth.da_year=year;
  strcpy(doc.blo,blo);
  strcpy(doc.addr,addr);
  strcpy(doc.nat,nat);
  strcpy(doc.tel,tel);
  strcpy(doc.email,email);
  strcpy(doc.spec,spec);
  doc.join.sec = gt->tm_sec;
  doc.join.min = gt->tm_min;
  doc.join.hour = gt->tm_hour;
  doc.join.day=gt->tm_mday;
  doc.join.mon=gt->tm_mon+1;
  doc.join.year=gt->tm_year+1900;
  f_doc=fopen(_doct,"ab");
  fwrite(&doc,sizeof(Doctor),1,f_doc);
  fclose(f_doc);
  notice(text,24,10,55,15);
  ch=blockey();
  if(ch==27) break;
 }while(1);
}
void deletetypeinput(){
 struct Types type;
 char t[20],ty[10],ch;
 int code,i,n,f;
 float pri;
 char text[2][30]={"<Type Deleted>","<<Enter to Delete another>>"};
 char head[30]="DELETE TYPE";
 do{
 s: clrwin();
  help();
  drawwindow(head,22,7,57,17,12);
  n=getFileElement(_type,sizeof(Types));
  if(n==0){
   gotoxy(5,5);textcolor(15);
   cprintf("<There are no type to delete>");
   blockey();
   break;
  }
  gotoxy(10,5);textcolor(15);cprintf("Code: ");code=atoi(input(1,5,15));
  if(code==0) break;
  f_ty=fopen(_type,"rb+");
  rewind(f_ty);
  for(i=0;i<n;i++){
   fread(&type,sizeof(Types),1,f_ty);
   if(code==type.co){
    f=1;
    break;
   }else{
    f=0;
   }
  }fclose(f_ty);
  if(f==0){
   notice("<Type not found>",24,10,55,15);
   blockey();
   goto s;
  }
  if(f==1) {
   if(confirm("Delete Type")==0)
    continue;
   else{
    deletetype(code);
    notice(text,24,10,55,15);
   }

  }
  ch=blockey();
  if(ch==27) break;
 }while(1);
}
void deletetype(int code){
 int i,n;
 struct Types type;
 n=getFileElement(_type,sizeof(Types));
 f_ty=fopen(_type,"rb+");
 rewind(f_ty);
 //Temporary file.
 FILE *temp = fopen("TEMP","wb+");
 for(i=0; i<n; i++) {
  fread(&type,sizeof(Types),1,f_ty);
  if(type.co!=code) {
   fwrite(&type,sizeof(Types),1,temp);
  }
 }
 fclose(temp);
 fclose(f_ty);
 remove(_type);
 rename("TEMP",_type);
}

void deleteroom(){
 struct Room ro;
 char t[20],ty[10],ch;
 int no,i,n,f;
 float pri;
 char text[2][30]={"<Room Deleted>","<<Enter to Delete another>>"};
 char head[30]="DELETE ROOM";
 do{
  clrwin();
  help();
  drawwindow(head,22,7,57,17,12);
  n=getFileElement(_room,sizeof(Room));
  if(n==0){
   gotoxy(5,5);textcolor(15);
   cprintf("<There are no room to delete>");
   blockey();
   break;
  }
  gotoxy(12,5);textcolor(15);cprintf("Room No.: ");no=atoi(input(1,5,15));
  if(no==0) break;
  f=findroom(no);
  if(f==1) {
   f_ro=fopen(_room,"rb+");
   rewind(f_ro);
   if(confirm("Deleting")==0){ fclose(f_ro);continue;}
   else{
    FILE *temp = fopen("TEMP","wb+");
    for(i=0; i<n; i++) {
     fread(&ro,sizeof(Room),1,f_ro);
     if(ro.no!=no) {
      fwrite(&ro,sizeof(Room),1,temp);
     }
    }
    fclose(temp);
   }
   fclose(f_ro);
   remove(_room);
   rename("TEMP",_room);
   notice(text,24,10,55,15);
  }
  if(f==2){
   notice("<This room has Patient>",24,10,55,15);
  }
  if(f==0){
   notice("<Room not found>",24,10,55,15);
  }
  ch=blockey();
  if(ch==27) break;
 }while(1);
}
int deletedoc(char id[10]){
 struct Doctor doc;
 int n,i,y;
 n=getFileElement(_doct,sizeof(Doctor));
 f_doc=fopen(_doct,"rb+");
 rewind(f_doc);
 FILE *temp = fopen("TEMP","wb+");
 for(i=0; i<n; i++) {
  fread(&doc,sizeof(Doctor),1,f_doc);
  if(strcmp(doc.id,id)!=0) {
   fwrite(&doc,sizeof(Doctor),1,temp);
  }
 }
 fclose(temp);
 fclose(f_doc);
 remove(_doct);
 rename("TEMP",_doct);
 y=1;
end:
 return y;
}
void deletepat(char id[10]){
 struct Patient pat;
 int n,i;
 n=getFileElement(_pati,sizeof(Patient));
 f_pat=fopen(_pati,"rb+");
 rewind(f_pat);

 FILE *temp = fopen("TEMP","wb+");
 for(i=0; i<n; i++) {
  fread(&pat,sizeof(Patient),1,f_pat);
  if(strcmp(pat.id,id)!=0) {
   fwrite(&pat,sizeof(Patient),1,temp);
  }
 }
 fclose(temp);
 fclose(f_pat);
 remove(_pati);
 rename("TEMP",_pati);
}
void deletedocinput(int opt){
 struct Doctor doc;
 char fname[20],lname[20];
 char id[10],ch;
 int i,n,f,nf;
 char head[30]="DELETE DOCTOR";
 do{
  f=0;nf=0;
  n=getFileElement(_doct,sizeof(Doctor));
  Doctor *source =(Doctor*) calloc(n,sizeof(Doctor));
  clrwin();
  help();
  drawwindow("SEARCH DOCTOR TO DELETE",22,7,57,17,12);

  if(n==0){
   gotoxy(4,5);textcolor(15);
   cprintf("<There are no Doctor to delete>");
   blockey();
   break;
  }
  if(opt==1){
   gotoxy(14,5);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
   if(strcmp(id,"00")==0) break;

   f_doc=fopen(_doct,"rb");
   for(i=0;i<n;i++){
    fread(&doc,sizeof(Doctor),1,f_doc);
    if(strcmp(doc.id,id)==0){
     fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
     fread(&source[nf],sizeof(Doctor),1,f_doc);
     nf++;
     f=1;
    }
   }
   fclose(f_doc);
  }
  if(opt==2){
   gotoxy(10,5);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
   if(strcmp(fname,"00")==0) break;
   else strupr(fname);

   f_doc=fopen(_doct,"rb");
   for(i=0;i<n;i++){
    fread(&doc,sizeof(Doctor),1,f_doc);
    if(strstr(doc.fname,fname)!=0||strcmp(doc.fname,fname)==0){
     fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
     fread(&source[nf],sizeof(Doctor),1,f_doc);
     nf++;
     f=1;
    }
   }
   fclose(f_doc);
  }
  if(opt==3){
   gotoxy(10,5);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
   if(strcmp(lname,"00")==0) break;
   else strupr(lname);
   f_doc=fopen(_doct,"rb");
   for(i=0;i<n;i++){
    fread(&doc,sizeof(Doctor),1,f_doc);
    if(strstr(doc.lname,lname)!=0||strcmp(doc.lname,lname)==0){
     fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
     fread(&source[nf],sizeof(Doctor),1,f_doc);
     nf++;
     f=1;
    }
   }
   fclose(f_doc);
  }
  if(f==1) {
    if(viewdoc(head,source,nf,0)==27)break;
    else continue;
  }
  if(f==0){
   notice("<Doctor not found>",24,10,55,15);
  }
  ch=blockey();
  if(ch==27) break;
 }while(1);
}
int viewpat(char head[30],Patient *source,int n,int opt){
 int i,temp=0,s=0,back=1,j=0;
 char ch,c;
 do{
  clrwin();
  help();
  drawwindow(head,20,7,60,20,12);
  gotoxy(1,1);printf("Room");gotoxy(11,1);printf("Name");
  gotoxy(24,1);printf("Sex");gotoxy(31,1);printf("Tel");
  if(n>13)temp=13;
  else temp =n;
  gotoxy(1,back+1);
  textbackground(2);
  for(j=0;j<41;j++)
   cprintf(" ");
  for(i=0;i<temp;i++){
   gotoxy(1,i+2);printf("%03d",source[i+s].ro);gotoxy(9,i+2);printf("%s %s",source[i+s].fname,source[i+s].lname);
   gotoxy(25,i+2);printf("%c",source[i+s].sex);gotoxy(31,i+2);printf("%s",source[i+s].tel);
  }
ch:  ch=getch();
  switch(ch){
   case 72:back--;if(back<1){back=1;s--;if(s<0){back=temp;s=n-temp;}}break;
   case 80:back++;if(back>=temp+1){back=temp;s++;if(s>n-temp){back=1;s=0;}}break;
   case 27:break;
   case 13:break;
   default:goto ch;
  }
  if(ch==13){
   if(opt==1)patidetail(source[back-1+s].id);
   else if(confirm("Checkout")==1){
     ch=checkout(source[back-1+s].id);
     if(ch==13||ch==27){
      break;
     }else continue;
   }else continue;
   blockey();
   continue;
  }
  if(ch==27)break;
 }while(1);
 return ch;
}
int viewdoc(char head[30],Doctor *source,int n,int opt){
 char text[2][30]={"<Doctor Deleted>","<<Enter to Delete another>>"};
 int i,temp=0,s=0,back=1,j=0;
 char ch,c;
 do{
  clrwin();
  help();
  drawwindow(head,20,7,60,20,12);
  gotoxy(1,1);printf("ID");gotoxy(12,1);printf("Name");
  gotoxy(24,1);printf("Sex");gotoxy(30,1);printf("Specialty");
  if(n>13)temp=13;
  else temp =n;
  gotoxy(1,back+1);
  textbackground(2);
  for(j=0;j<41;j++)
   cprintf(" ");
  for(i=0;i<temp;i++){
   gotoxy(1,i+2);printf("%s",source[i+s].id);gotoxy(9,i+2);printf("%s %s",source[i+s].fname,source[i+s].lname);
   gotoxy(25,i+2);printf("%c",source[i+s].sex);gotoxy(31,i+2);printf("%s",source[i+s].spec);
  }
ch:  ch=getch();
  switch(ch){
   case 72:back--;if(back<1){back=1;s--;if(s<0){back=temp;s=n-temp;}}break;
   case 80:back++;if(back>=temp+1){back=temp;s++;if(s>n-temp){back=1;s=0;}}break;
   case 27:break;
   case 13:break;
   default:goto ch;
  }
  if(ch==13){
   if(opt==1){
    docdetail(source[back-1+s].id);
    blockey();
    continue;
   }else if(confirm("Deleting")==1)
    if(deletedoc(source[back-1+s].id)==1){
     notice(text,24,10,55,15);
     ch=blockey();
     if(ch==27||ch==13)break;
    }else continue;

  }
  if(ch==27)break;
 }while(1);
 return ch;
}
void findpat(int opt){
 struct Patient pat;
 char fullname1[40],fullname2[40],namef[40];
 char id[10],ch,c;
 int i,n,f=0,nf=0,no,day=0,mon=0,year=0;
 char head[30]="SEARCH PATIENT";

 do{
  n=getFileElement(_pati,sizeof(Patient));
  f=0;nf=0;day=0;mon=0;year=0;
  Patient *source =(Patient*) calloc(n,sizeof(Patient));
  clrwin();
  help();
  drawwindow(head,22,7,57,17,12);
  if(n==0){
   gotoxy(3,5);textcolor(15);
   cprintf("<There are no Patient to search>");
   blockey();
   break;
  }
  if(opt==1){
   gotoxy(14,5);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
   if(strcmp(id,"00")==0) break;
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    if(strcmp(id,pat.id)==0){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
  }
  if(opt==2){
   gotoxy(10,5);textcolor(15);cprintf("Name: "); strcpy(namef,input(2,35,15));
   if(strcmp(namef,"00")==0) break;
   else strupr(namef);
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    strcpy(fullname1,pat.fname);
    strcat(fullname1," ");
    strcat(fullname1,pat.lname);
    strcpy(fullname2,pat.lname);
    strcat(fullname2," ");
    strcat(fullname2,pat.fname);
    if(strstr(fullname1,namef)!=0||strstr(fullname2,namef)!=0){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
   sortpatname(source,nf);
  }
  if(opt==4){
   gotoxy(5,5);textcolor(15);cprintf("Date of Check in: ");inputdat(day,mon,year,15);
   if(day==0||mon==0||year==0) break;
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    if(pat.regi.day==day&&pat.regi.mon==mon&&pat.regi.year==year){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
   sortpat(source,nf);
  }
  if(opt==3){
   gotoxy(12,5);textcolor(15);cprintf("Room No.: "); no=atoi(input(1,5,15));
   if(no==0) break;
   f_pat=fopen(_pati,"rb");
   rewind(f_pat);
   for(i=0; i<n; i++) {
    fread(&pat,sizeof(Patient),1,f_pat);
    if(pat.ro==no){
     fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
     fread(&source[nf],sizeof(Patient),1,f_pat);
     nf++;
     f=1;
    }
   }fclose(f_pat);
   sortpat(source,nf);
  }
  if(f==1){
   viewpat(head,source,nf,1);
   continue;
  }

  if(f==0){
   notice("<Patient not found>",24,10,55,15);
   ch=blockey();
   if(ch==13)
    continue;
  }
  if(ch==27) break;
 }while(1);
}
void finddoc(int opt){
 struct Doctor doc;
 char fname[20],lname[20],spec[20];
 char id[10],ch,c;
 int i,n,f=0,nf=0;
 char head[30]="SEARCH DOCTOR";

 do{ n=getFileElement(_doct,sizeof(Doctor));
  f=0;nf=0;
  Doctor *source =(Doctor*) calloc(n,sizeof(Doctor));
  clrwin();
  help();
  drawwindow(head,22,7,57,17,12);
  if(n==0){
   gotoxy(4,5);textcolor(15);
   cprintf("<There are no Doctor to search>");
   blockey();
   break;
  }
  if(opt==1){
   gotoxy(14,5);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
   if(strcmp(id,"00")==0) break;
   f_doc=fopen(_doct,"rb");
   rewind(f_doc);
   for(i=0; i<n; i++) {
    fread(&doc,sizeof(Doctor),1,f_doc);
    if(strcmp(id,doc.id)==0){
     fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
     fread(&source[nf],sizeof(Doctor),1,f_doc);
     nf++;
     f=1;
    }
   }fclose(f_doc);
  }
  if(opt==2){
   gotoxy(10,5);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
   if(strcmp(fname,"00")==0) break;
   else strupr(fname);
   f_doc=fopen(_doct,"rb");
   rewind(f_doc);
   for(i=0; i<n; i++) {
    fread(&doc,sizeof(Doctor),1,f_doc);
    if(strstr(doc.fname,fname)!=0||stricmp(doc.fname,fname)==0){
     fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
     fread(&source[nf],sizeof(Doctor),1,f_doc);
     nf++;
     f=1;
    }
   }fclose(f_doc);
  }
  if(opt==3){
   gotoxy(10,5);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
   if(strcmp(lname,"00")==0) break;
   else strupr(lname);
   f_doc=fopen(_doct,"rb");
   rewind(f_doc);
   for(i=0; i<n; i++) {
    fread(&doc,sizeof(Doctor),1,f_doc);
    if(strstr(doc.lname,lname)!=0||stricmp(doc.lname,lname)==0){
     fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
     fread(&source[nf],sizeof(Doctor),1,f_doc);
     nf++;
     f=1;
    }
   }fclose(f_doc);
  }
  if(opt==4){
   gotoxy(11,5);textcolor(15);cprintf("Specialty: "); strcpy(spec,input(2,19,15));
   if(strcmp(spec,"00")==0) break;
   else strupr(spec);
   f_doc=fopen(_doct,"rb");
   rewind(f_doc);
   for(i=0; i<n; i++) {
    fread(&doc,sizeof(Doctor),1,f_doc);
    if(strstr(doc.spec,spec)!=0||stricmp(doc.spec,spec)==0){
     fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
     fread(&source[nf],sizeof(Doctor),1,f_doc);
     nf++;
     f=1;
    }
   }fclose(f_doc);
  }
  if(f==1){
   sortdoc(source,nf);
   viewdoc(head,source,nf,1);
   continue;
  }

  if(f==0){
   notice("<Doctor not found>",24,10,55,15);
   blockey();
   continue;
  }
  if(ch==27) break;
 }while(1);
}
void updatedoc(int opt){
 struct Doctor doc;
 struct date dai;
 int day=0,mon=0,year=0,i,n,f;
 char ch,c;
 char id[10],idf[10],fname[15],lname[15],sex,blo[5],spec[20],nat[20],tel[20],email[35],addr[40];
 char text[2][30]={"<Doctor updated>","<<Enter to update another>>"};
 char blood[9][4]={"00","O+","O-","A+","A-","B+","B-","AB+","AB-"};
 char head[30]="UPDATE DOCTOR";
 do{
  getdate(&dai);
  f=0;
  clrwin();
  drawwindow("SEARCH DOCTOR TO UPDATE",22,7,57,17,12);
  n=getFileElement(_doct,sizeof(Doctor));
  if(n==0){
   gotoxy(4,5);textcolor(15);
   cprintf("<There are no Doctor to update>");
   blockey();
   break;
  }
  gotoxy(14,5);textcolor(15);cprintf("ID: "); strcpy(idf,input(3,9,15));
  if(strcmp(idf,"00")==0) break;
  f=finddocid(idf);
  if(f==0)
   notice("<Doctor not found>",24,10,55,15);
  if(f==1){
   clrwin();
   drawwindow(head,12,7,69,20,12);
   if(opt==1){
    gotoxy(1,1);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
    if(strcmp(id,"00")==0) break;
    if((finddocid(id)==1||findpatid(id)==1)&&strcmp(idf,id)!=0){
     notice("<This ID is exist>",24,10,55,15);
     blockey();
     continue;
    }

    gotoxy(1,3);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
    if(strcmp(fname,"00")==0) break;
    else strupr(fname);
    gotoxy(1,5);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
    if(strcmp(lname,"00")==0) break;
    else strupr(lname);
    gotoxy(1,7);textcolor(15);cprintf("Sex: "); window(17,13,23,13);sex=selectsex();
    if(sex=='n')break;
    window(12,7,69,20);
date:   gotoxy(1,9);textcolor(15);cprintf("Date of Birth: "); gotoxy(16,9);inputdat(day,mon,year,15);
    if(day==0||mon==0||year==0) break;
    else if(day>31||mon>12||year<1900||year>dai.da_year||(mon>dai.da_mon&&year>=dai.da_year)||(day>dai.da_day&&mon>=dai.da_mon&&year>=dai.da_year)){
     gotoxy(16,9);printf("DD/MM/YYYY");
     day=0;mon=0;year=0;
     goto date;
    }
    gotoxy(1,11);textcolor(15);cprintf("E-mail: "); strcpy(email,input(3,34,15));
    if(strcmp(email,"00")==0) break;

    gotoxy(1,13);textcolor(15);cprintf("Address: "); strcpy(addr,input(3,39,15));
    if(strcmp(addr,"00")==0) break;

    gotoxy(30,1);textcolor(15);cprintf("Blood Group: ");window(54,7,61,7); strcpy(blo,blood[selectblood()]);
    if(strcmp(blo,"00")==0) break;
    window(12,7,69,20);
    gotoxy(30,3);textcolor(15);cprintf("Tel: "); strcpy(tel,input(1,19,15));
    if(strcmp(tel,"00")==0) break;
    gotoxy(30,5);textcolor(15);cprintf("Specialty: ");strcpy(spec,input(2,17,15));
    if(strcmp(spec,"00")==0) break;
    else strupr(spec);
    gotoxy(30,7);textcolor(15);cprintf("Nationality: "); strcpy(nat,input(2,15,15));
    if(strcmp(nat,"00")==0) break;
    f_doc=fopen(_doct,"rb+");
    rewind(f_doc);
    for(i=0;i<n;i++){
     fread(&doc,sizeof(Doctor),1,f_doc);
     if(strcmp(idf,doc.id)==0){
      time(&current);
      gt = localtime(&current);
      strcpy(doc.id,id);
      strcpy(doc.fname,fname);
      strcpy(doc.lname,lname);
      doc.sex=sex;
      doc.birth.da_day=day;
      doc.birth.da_mon=mon;
      doc.birth.da_year=year;
      strcpy(doc.blo,blo);
      strcpy(doc.addr,addr);
      strcpy(doc.nat,nat);
      strcpy(doc.tel,tel);
      strcpy(doc.email,email);
      strcpy(doc.spec,spec);
      doc.join.sec = gt->tm_sec;
      doc.join.min = gt->tm_min;
      doc.join.hour = gt->tm_hour;
      doc.join.day=gt->tm_mday;
      doc.join.mon=gt->tm_mon+1;
      doc.join.year=gt->tm_year+1900;
      fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
      fwrite(&doc,sizeof(Doctor),1,f_doc);
     }
    }fclose(f_doc);
    notice(text,24,10,55,15);
   }
   if(opt==2){
    gotoxy(10,6);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
    if(strcmp(fname,"00")==0) break;
    else strupr(fname);
    gotoxy(10,8);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
    if(strcmp(lname,"00")==0) break;
    else strupr(lname);
    f_doc=fopen(_doct,"rb+");
    rewind(f_doc);
    for(i=0;i<n;i++){
     fread(&doc,sizeof(Doctor),1,f_doc);
     if(strcmp(idf,doc.id)==0){
      strcpy(doc.fname,fname);
      strcpy(doc.lname,lname);
      fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
      fwrite(&doc,sizeof(Doctor),1,f_doc);
      notice(text,24,10,55,15);
     }
    }fclose(f_doc);

   }
   if(opt==3){
    gotoxy(11,7);textcolor(15);cprintf("Specialty: ");strcpy(spec,input(2,17,15));
    if(strcmp(spec,"00")==0) break;
    else strupr(spec);
    f_doc=fopen(_doct,"rb+");
    rewind(f_doc);
    for(i=0;i<n;i++){
     fread(&doc,sizeof(Doctor),1,f_doc);
     if(strcmp(doc.id,idf)==0){
      strcpy(doc.spec,spec);
      fseek(f_doc,-(int)sizeof(Doctor),SEEK_CUR);
      fwrite(&doc,sizeof(Doctor),1,f_doc);
      notice(text,24,10,55,15);
     }
    }
    fclose(f_doc);
   }


  }
  ch=blockey();
  if(ch==27) break;
 }while(1);
}
void updatepat(int opt){
 struct Patient pat;
 struct Room ro;
 struct date dai;
 int day=0,mon=0,year=0,i,n,f,no,nr,nav=0;
 char ch;
 char idf[10],id[10],fname[15],lname[15],sex,blo[5],prob[20],nat[20],tel[20],addr[40];
 char text[2][30]={"<Patient updated>","<<Enter to update another>>"};
 char blood[9][4]={"00","O+","O-","A+","A-","B+","B-","AB+","AB-"};
 char head[30]="UPDATE PATIENT";
 do{
  getdate(&dai);
  f=0;
  clrwin();
  drawwindow("SEARCH PATIENT TO UPDATE",22,7,57,17,12);
  n=getFileElement(_pati,sizeof(Patient));
  if(n==0){
   gotoxy(4,5);textcolor(15);
   cprintf("<There are no Patient to update>");
   blockey();
   break;
  }
  if(opt==3){
   nr=getFileElement(_room,sizeof(Room));
   f_ro=fopen(_room,"rb");
   rewind(f_ro);
   for(i=0; i<nr; i++) {
    fread(&ro,sizeof(Room),1,f_ro);
    if(ro.sta==EMPTY){
     nav++;
    }
   }fclose(f_ro);
   if(nav==0){
    gotoxy(5,5);textcolor(15);
    cprintf("<There are no available rooms>");
    blockey();
    break;
   }
  }
  gotoxy(14,5);textcolor(15);cprintf("ID: "); strcpy(idf,input(3,9,15));
  if(strcmp(idf,"00")==0) break;
  f=findpatid(idf);
  if(f==0)
   notice("<Patient not found>",24,10,55,15);
  if(f==1){
  f1: f_pat=fopen(_pati,"rb+");
   rewind(f_pat);
   for(i=0;i<n;i++){
    fread(&pat,sizeof(Patient),1,f_pat);
    if(strcmp(id,pat.id)==0){
     break;
    }
   }fclose(f_pat);
   clrwin();
   drawwindow(head,12,7,69,20,12);
   if(opt==1){
    gotoxy(1,1);textcolor(15);cprintf("Room No.: ");no=atoi(input(1,5,15));
    if(no==0) break;
    if(findroom(no)!=1&&no!=pat.ro){
     notice("<Unavailable Room>",24,10,55,15);
     blockey();
     continue;
    }
    gotoxy(1,3);textcolor(15);cprintf("ID: "); strcpy(id,input(3,9,15));
    if(strcmp(id,"00")==0) break;
    if((finddocid(id)==1||findpatid(id)==1)&&strcmp(id,pat.id)!=0){
     notice("<This ID is exist>",24,10,55,15);
     ch=blockey();
     if(ch==27)break;
     else continue;
    }
    gotoxy(1,5);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
    if(strcmp(fname,"00")==0) break;
    else strupr(fname);
    gotoxy(1,7);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
    if(strcmp(lname,"00")==0) break;
    else strupr(lname);
    gotoxy(1,9);textcolor(15);cprintf("Sex: "); window(17,15,23,15);sex=selectsex();
    if(sex=='n')break;
    window(12,7,69,20);
date:    gotoxy(1,11);textcolor(15);cprintf("Date of Birth: "); gotoxy(16,11);inputdat(day,mon,year,15);
    if(day==0||mon==0||year==0) break;
    else if(day>31||mon>12||year<1900||year>dai.da_year||(mon>dai.da_mon&&year>=dai.da_year)||(day>dai.da_day&&mon>=dai.da_mon&&year>=dai.da_year)){
     gotoxy(16,11);printf("DD/MM/YYYY");
     day=0;mon=0;year=0;
     goto date;
    }
    gotoxy(1,13);textcolor(15);cprintf("Address: "); strcpy(addr,input(3,39,15));
    if(strcmp(addr,"00")==0) break;
    gotoxy(30,1);textcolor(15);cprintf("Blood Group: ");window(54,7,61,7); strcpy(blo,blood[selectblood()]);
    if(strcmp(blo,"00")==0) break;
    window(12,7,69,20);
    gotoxy(30,3);textcolor(15);cprintf("Problem: ");strcpy(prob,input(2,19,15));
    if(strcmp(prob,"00")==0) break;
    gotoxy(30,5);textcolor(15);cprintf("Tel: "); strcpy(tel,input(1,19,15));
    if(strcmp(tel,"00")==0) break;
    gotoxy(30,7);textcolor(15);cprintf("Nationality: "); strcpy(nat,input(2,19,15));
    if(strcmp(nat,"00")==0) break;
    setroomEMPTY(pat.ro);
    setroomSTAY(no);
    f_pat=fopen(_pati,"rb+");
    rewind(f_pat);
    for(i=0;i<n;i++){
     fread(&pat,sizeof(Patient),1,f_pat);
     if(strcmp(idf,pat.id)==0){
      pat.ro=no;
      strcpy(pat.id,id);
      strcpy(pat.fname,fname);
      strcpy(pat.lname,lname);
      pat.sex=sex;
      pat.birth.da_day=day;
      pat.birth.da_mon=mon;
      pat.birth.da_year=year;
      strcpy(pat.addr,addr);
      strcpy(pat.blo,blo);
      strcpy(pat.prob,prob);
      strcpy(pat.nat,nat);
      strcpy(pat.tel,tel);
      fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
      fwrite(&pat,sizeof(Patient),1,f_pat);
     }
    }fclose(f_pat);
    notice(text,24,10,55,15);
   }
   if(opt==2){
    gotoxy(10,4);textcolor(15);cprintf("First Name: "); strcpy(fname,input(2,14,15));
    if(strcmp(fname,"00")==0) break;
    else strupr(fname);
    gotoxy(10,6);textcolor(15);cprintf("Last Name: "); strcpy(lname,input(2,14,15));
    if(strcmp(lname,"00")==0) break;
    else strupr(lname);
    f_pat=fopen(_pati,"rb+");
    rewind(f_pat);
    for(i=0;i<n;i++){
     fread(&pat,sizeof(Patient),1,f_pat);
     if(strcmp(idf,pat.id)==0){
      strcpy(pat.fname,fname);
      strcpy(pat.lname,lname);
      fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
      fwrite(&pat,sizeof(Patient),1,f_pat);
      notice(text,24,10,55,15);
     }
    }fclose(f_pat);

   }
   if(opt==3){
    gotoxy(11,7);textcolor(15);cprintf("Room No.: ");no=atoi(input(1,5,15));
    if(no==0) break;
    if(findroom(no)!=1){
     notice("<Unavailable Room>",24,10,55,15);
     blockey();
     goto f1;
    }
    setroomEMPTY(pat.ro);
    setroomSTAY(no);
    f_pat=fopen(_pati,"rb+");
    rewind(f_pat);
    for(i=0;i<n;i++){
     fread(&pat,sizeof(Patient),1,f_pat);
     if(strcmp(pat.id,idf)==0){
      pat.ro=no;
      fseek(f_pat,-(int)sizeof(Patient),SEEK_CUR);
      fwrite(&pat,sizeof(Patient),1,f_pat);
      notice(text,24,10,55,15);
     }
    }
    fclose(f_pat);
   }


  }
  ch=blockey();
  if(ch==27) break;
 }while(1);
}

void updateroom(){
 struct Room ro;
 struct Types type;
 char ch,c;
 int no,nof,i,n,f,ty,it,nt;
 char text[2][30]={"<Room Updated>","<<Enter to Update another>>"};
 char head[30]="UPDATE ROOM";
 do{ f=0;
  clrwin();
  help();
  drawwindow("SEARCH ROOM TO UPDATE",22,7,57,17,12);
  n=getFileElement(_room,sizeof(Room));
  if(n==0){
   gotoxy(5,5);textcolor(15);
   cprintf("<There are no room to update>");
   blockey();
   break;
  }
  gotoxy(12,5);textcolor(15);cprintf("Room No.: ");nof=atoi(input(1,5,15));
  if(nof==0) break;
  f=findroom(nof);
  if(f==0)
   notice("<Room not found>",24,10,55,15);
  if(f==2)
   notice("<This room has Patient>",24,10,55,15);

  if(f==1) {
   if(confirm("Updating")==0){ fclose(f_ro);continue;}
   else{
   s: clrwin();
    drawwindow(head,22,7,57,17,12);
    gotoxy(12,4);textcolor(15);cprintf("Room No.: ");no=atoi(input(1,5,15));
    if(no==0) break;
    f_ro=fopen(_room,"rb+");
    rewind(f_ro);
    for(i=0;i<n;i++){
     fread(&ro,sizeof(Room),1,f_ro);
     if(no==ro.no&&no!=nof){
      notice(">This room is exist<",24,10,55,15);
      blockey();
      fclose(f_ro);
      goto s;
     }
    }
    fclose(f_ro);

    gotoxy(12,6);textcolor(15);cprintf("Type: ");
    window(39,12,51,12);
    ty=selecttype();
    if(ty==-1) break;
    f_ro=fopen(_room,"rb+");
    rewind(f_ro);
    for(i=0; i<n; i++) {
     fread(&ro,sizeof(Room),1,f_ro);
     if(ro.no==nof) {
      fseek(f_ro,-(int)sizeof(Room),SEEK_CUR);
      nt=getFileElement(_type,sizeof(Types));
      f_ty=fopen(_type,"rb+");
      rewind(f_ty);
      for(it=0;it<nt;it++){
       fread(&type,sizeof(Types),1,f_ty);
       if(type.co==ty){
        ro.type.co=type.co;
        stpcpy(ro.type.na,type.na);
        ro.type.pri=type.pri;
       }
      }
      fclose(f_ty);
      ro.no=no;
      ro.sta=EMPTY;
      fwrite(&ro,sizeof(Room),1,f_ro);
     }
    }
    fclose(f_ro);
    notice(text,24,10,55,15);
   }
  }
 ch=blockey();
 if(ch==27) break;
 }while(1);
}
int viewroom(char head[30],Room *source,int n){
 struct Patient pat;
 int i,temp=0,s=0,back=1,j=0,nl,l,f=0,index=0;
 char ch;
 do{
  clrwin();
  help();
  drawwindow(head,20,7,60,20,12);
  gotoxy(1,1);printf("No.");gotoxy(8,1);printf("Type");
  gotoxy(18,1);printf("Price");gotoxy(30,1);printf("Status");
  if(n>13)temp=13;
  else temp =n;
  gotoxy(1,back+1);
  textbackground(2);
  for(j=0;j<41;j++)
   cprintf(" ");
  for(i=0;i<temp;i++){
   gotoxy(1,i+2);printf("%03d",source[i+s].no);gotoxy(8,i+2);printf("%s",source[i+s].type.na);
   gotoxy(18,i+2);printf("%.2f",source[i+s].type.pri);gotoxy(30,i+2);printf("%s",source[i+s].sta=='n'?"Available":"Unavailable");
  }
ch:  ch=getch();
  switch(ch){
   case 72:back--;if(back<1){back=1;s--;if(s<0){back=temp;s=n-temp;}}break;
   case 80:back++;if(back>=temp+1){back=temp;s++;if(s>n-temp){back=1;s=0;}}break;
   case 27:break;
   case 13:break;
   default:goto ch;
  }
  if(ch==13){
   if(source[back-1+s].sta==EMPTY)
    if(confirm("Add Patient")==1){
     if(addpatient(source[back-1+s].no)==1){
      if(strstr(head,"ALL")!=0)
       source[back-1+s].sta=STAY;
      else{
       index=back-1+s;
       n--;
       while(index<n){
        source[index]=source[index+1];
        index++;
       }
       s=0;back=1;
      }
     }
    }else continue;
   else if(confirm("Checkout")==1){
    nl=getFileElement(_pati,sizeof(Patient));
    f_pat=fopen(_pati,"rb");
    for(l=0;l<nl;l++){
     fread(&pat,sizeof(Patient),1,f_pat);
     if(source[back-1+s].no==pat.ro){
      f=1;
      break;
     }
    }fclose(f_pat);
    if(f==1){

     ch=checkout(pat.id);
     if(ch==27||ch==13)
      break;
     else {f=0;continue;}
     }

   }else continue;
  }
  if(ch==27)break;
 }while(1);
 return ch;
}
void allroom(){
 int i,n;
 char head[30]="ALL ROOM";
 char ch;
start:
 n=getFileElement(_room,sizeof(Room));
 Room *source =(Room*) calloc(n,sizeof(Room));
 f_ro=fopen(_room,"rb");
 rewind(f_ro);
 for(i=0; i<n; i++) {
  fread(&source[i],sizeof(Room),1,f_ro);
 }fclose(f_ro);
 clrwin();
 help();
 drawwindow(head,20,7,60,20,12);
 if(n==0){
  gotoxy(12,7);textcolor(15);
  cprintf("<There are no room>");
  blockey();
  goto end;
 }
 sortroom(source,n);
 if(viewroom(head,source,n)==13)
  goto start;
end:
}
void allpat(){
 int i,n;
 char head[30]="ALL PATIENT";
 char ch;
 n=getFileElement(_pati,sizeof(Patient));
 Patient *source =(Patient*) calloc(n,sizeof(Patient));
 f_pat=fopen(_pati,"rb");
 rewind(f_ro);
 for(i=0; i<n; i++) {
  fread(&source[i],sizeof(Patient),1,f_pat);
 }fclose(f_pat);
 clrwin();
 help();
 drawwindow(head,20,7,60,20,12);
 if(n==0){
  gotoxy(12,7);textcolor(15);
  cprintf("<There are no Patient>");
  blockey();
  goto end;
 }
 sortpat(source,n);
 viewpat(head,source,n,1);
end:
}
void alldoc(){
 int i,n;
 char ch;
 char head[30]="ALL DOCTOR";
 n=getFileElement(_doct,sizeof(Doctor));
 Doctor *source =(Doctor*) calloc(n,sizeof(Doctor));
 f_doc=fopen(_doct,"rb");
 rewind(f_doc);
 for(i=0; i<n; i++) {
  fread(&source[i],sizeof(Doctor),1,f_doc);
 }fclose(f_doc);
 clrwin();
 help();
 drawwindow(head,20,7,60,20,12);
 if(n==0){
  gotoxy(12,7);textcolor(15);
  cprintf("<There are no Doctor>");
  blockey();
  goto end;
 }
 sortdoc(source,n);
 viewdoc(head,source,n,1);
end:
}
void findviewroom(){
 struct Room ro;
 int i,n,nf,no;
 char head[30]="SEARCH ROOM";
 char ch,c;
 do{ n=getFileElement(_room,sizeof(Room));
  nf=0;
  Room *source =(Room*) calloc(n,sizeof(Room));
  clrwin();
  help();
  drawwindow(head,22,7,57,17,12);
  clrscr();
  if(n==0){
   gotoxy(5,5);textcolor(15);cprintf("<There are no rooms to search>");
   blockey();
   break;
  }
  gotoxy(12,5);textcolor(15);cprintf("Room No.: ");no=atoi(input(1,5,15));
  if(no==0) break;
  if(findroom(no)!=0){
   f_ro=fopen(_room,"rb");
   rewind(f_ro);
   for(i=0; i<n; i++) {
    fread(&ro,sizeof(Room),1,f_ro);
    if(ro.no==no){
     fseek(f_ro,-(int)sizeof(Room),SEEK_CUR);
     fread(&source[nf],sizeof(Room),1,f_ro);
     nf++;
    }
   }fclose(f_ro);
  }
  if(nf==0){
   notice("<Room not found>",24,10,55,15);
   blockey();
   continue;
  }
  sortroom(source,nf);
  ch=viewroom(head,source,nf);
  if(ch==27) break;
  else continue;
 }while(1);
}
void availroom(){
 struct Room ro;
 char ch;
 int i,n,nav=0;
 char head[30]="AVAILABLE ROOM";
 n=getFileElement(_room,sizeof(Room));
 Room *source =(Room*) calloc(n,sizeof(Room));
 f_ro=fopen(_room,"rb");
 rewind(f_ro);
 for(i=0; i<n; i++) {
  fread(&ro,sizeof(Room),1,f_ro);
  if(ro.sta==EMPTY){
   fseek(f_ro,-(int)sizeof(Room),SEEK_CUR);
   fread(&source[nav],sizeof(Room),1,f_ro);
   nav++;
  }
 }fclose(f_ro);
 clrwin();
 help();
 drawwindow(head,20,7,60,20,12);
 if(nav==0){
  gotoxy(6,7);textcolor(15);
  cprintf("<There are no available rooms>");
  blockey();
  goto end;
 }
 sortroom(source,nav);
 viewroom(head,source,nav);
end:
}
void alltype(){
 struct Types type;
 char ch,c;
 int i,n,temp,s,back,j;
 char head[30]="ALL TYPE";
start:
 temp=0;s=0;back=1;j=0;
 n=getFileElement(_type,sizeof(Types));
 Types *source =(Types*) calloc(n,sizeof(Types));
 f_ty=fopen(_type,"rb");
 rewind(f_ty);
 for(i=0; i<n; i++) {
  fread(&source[i],sizeof(Types),1,f_ty);
 }fclose(f_ty);
 sorttype(source,n);
 do{
  clrwin();
  help();
  drawwindow(head,20,7,60,20,12);
  if(n==0){
   gotoxy(12,7);textcolor(15);
   cprintf("<There are no type>");
   blockey();
   break;

  }
  gotoxy(1,1);printf("Code");gotoxy(19,1);printf("Type");
  gotoxy(33,1);printf("Price");
  if(n>13)temp=13;
  else temp=n;
  gotoxy(1,back+1);
  textbackground(2);
  for(j=0;j<41;j++)
   cprintf(" ");
  for(i=0;i<temp;i++){
   gotoxy(1,i+2);printf("%03d",source[i+s].co);gotoxy(19,i+2);printf("%s",source[i+s].na);
   gotoxy(33,i+2);printf("%.2f",source[i+s].pri);
  }
ch:  ch=getch();
  switch(ch){
   case 72:back--;if(back<1){back=1;s--;if(s<0){back=temp;s=n-temp;}}break;
   case 80:back++;if(back>=temp+1){back=temp;s++;if(s>n-temp){back=1;s=0;}}break;
   case 27:break;
   case 13:break;
   default:goto ch;
  }
  if(ch==13){
   if(confirm("Delete Type")==1){
    deletetype(source[back-1+s].co);
    notice("<Type Deleted>",24,10,55,15);
    blockey();
    goto start;
   }else continue;
  }
  if(ch==27)break;
 }while(1);
}

//prueba

}
