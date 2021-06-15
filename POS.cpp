#include <windows.h>
#include <iostream>
#include <ctime>
#include <vector>
#include <thread>
using namespace std; 

//Variables POS
int *cuentamenus, mns, i=0, j=0, nventas=0, n, auxmenu[20], menusel;
float *menusprice, totalg=0, cuenta=0, pago=0, extras;
char nombre[30], direccion[50], plat[20], pass[15], access[15], op;
bool check=false;
vector<string> platillos;

//Variables TIMER
int tiempo,P=0, h_ent, m_ent, s_ent;
vector <int> v1;

//Métodos POS
void passw(), defpassword(), gotoxy(int, int), cancela(float _menusprice[], int _cuentamenus[]);
void nuevaord(), defplat(), menudia(), cortecaja();

//Métodos TIMER
void reqtime(), tiempox(), contador();
int checador();

//---------------------------------------INICIA MAIN------------------

int main()
{
//PRINCIPAL-------------------------POS
thread (contador).detach();
for (i=0;i<15;i++)
   {
   pass[i]='0';
   access[i]='0';
   }
tiempox();
system("color 0A");defpassword();system("CLS");
defplat();
menudia();
//Menu Principal-----------------------------------------------------------------------------------------
while (true)
{
system("color 8E");
cout<<endl<<"                      PANTALLA PRINCIPAL"<<endl<<endl;
cout<<"               [presione el numero de la opcion]"<<endl<<endl<<endl<<endl;
cout<<"ORDEN NUEVA -----  [1]                   DEFINIR PRECIOS ----  [2]"<<endl<<endl<<endl;
cout<<"CORTE DE CAJA ---  [3]                   VER MENU DE HOY ----  [4]"<<endl<<endl<<endl;
cout<<"CANCELACION -----  [5]"<<endl;
cout<<"\n\n\n\nSALIR -----------  [S]\n\n\n\n                              ";
cin>>op;
if (op=='1') {system("CLS"); nuevaord();}
else if (op=='2'){system("CLS"); defplat();}
else if (op=='3'){system("CLS"); cortecaja();}
else if (op=='4'){system("CLS"); menudia();}
else if (op=='5'){system("CLS"); cancela(menusprice,cuentamenus);cuentamenus[mns+1]++;}
else if ((op=='q')||(op=='Q')){system("CLS"); system("color 0A");getchar();defpassword();system("CLS");system("color F0");}
else if (op=='0'){system("CLS"); system("color 0A");passw();system("CLS");system("color F0");}
else if ((op=='S')||(op=='s')) {cout<<"\n\n\n\t\tESTA SEGURO?\tSI  [S]\t\tNO  [N]\n\n\n\n\t\t\t\t\t "; cin>>op;if ((op=='S')||(op=='s')) {break;}}
else {cout<<"OPCION NO VALIDA";Sleep(500); system("CLS");}
}

system("CLS");system("color 0A");gotoxy(30,10);cout<<"CERRANDO SISTEMA...";
Sleep(800);getchar();delete[] menusprice; delete[] cuentamenus;
return 0;
}
//---------------------------------------TERMINA MAIN------------------


//METODOS POS******************************************************************************************************************************
//--------------------------------------GOTOXY------------------------------------------------------
void gotoxy(int x, int y)
{
HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X=x;
dwPos.Y=y;
SetConsoleCursorPosition(hCon,dwPos);
}

//------------------------------------DEFINIRPASSWORD---------------------------------------------------
void defpassword()
{
ini:
for(i=0;i<15;i++)
 {
 access[i]='0';
 pass[i]='0';
 }
check=false;
cout<<"\n\n\n\n\n\n\t\t\t     DEFINIR CLAVE DE ACCESO:\n\n\n                                      ";
cin.getline(pass,15,'\n');
system("CLS");
cout<<"\n\n\n\n\n\n\t\t\tVUELVA A ESCRIBIR LA CLAVE DE ACCESO:\n\n\n                                      ";
cin.getline(access,15,'\n');
for(i=0;i<15;i++)
 {
 if(pass[i]==access[i])
  {access[i]='0';if(i==14){ check=true; system("cls"); gotoxy(35,10); cout<<"BIENVENIDO"; Sleep(800);}}
 else if(pass[i]!=access[i])
  {gotoxy(35,10);cout<<"ERROR\n ";i=15;Sleep(800);system("CLS");goto ini;}
 }
}

//---------------------------------------PASSWORD---------------------------------------------------
void passw()
{
getchar();
ini:
for(i=0;i<15;i++)
 {access[i]='0';}
if(check=true)
 {
 cout<<"\n\n\n\n\n\t\t\t\tCLAVE DE ACCESO ?\n\n\n                                     ";
 cin.getline(access,15,'\n');
 for(i=0;i<15;i++)
 {
  if(pass[i]==access[i])
   {access[i]='0';}
  else if(pass[i]!=access[i])
   {gotoxy(37,13);cout<<"ERROR\n ";i=15;Sleep(800);system("CLS");goto ini;}
 }
if(check==false)
  {defpassword();}
 }
system("cls"); gotoxy(35,10);cout<<"BIENVENIDO";Sleep(800);
}

//------------------------------------------CANCELACION---------------------------------------------
void cancela(float _menusprice[], int _cuentamenus[])
{
passw();
cuenta=0;
system("CLS");
cout<<"\n               Cuantos menus va a CANCELAR?    :(  ";
cin>>n;
for(i=0;i<mns;i++)
{
gotoxy(2,3+(i*2));
cout<<"$ "<<_menusprice[i]<<"  platillos[i]";
gotoxy(20,3+(i*2));
cout<<" ---> ["<<i+1<<"]";
}
cout<<endl<<endl;
for (i=0;i<n;i++)
{
auxmenu[i]=0;
gotoxy(40,6+(2*i));
cout<<" Cancelacion "<<i+1<<":  ";
cin>>auxmenu[i];
cuenta+=_menusprice[auxmenu[i]-1];
menusel=auxmenu[i];auxmenu[i]=0;_cuentamenus[menusel-1]--;
}
totalg-=cuenta;
gotoxy(25,7+(2*i));
cout<<"MONTO CANCELADO: $ "<<cuenta<<endl<<endl;
char motivo[30];
  getchar();
  cout<<endl<<"INGRESE MOTIVO DE CANCELACION: ";
  cin.getline(motivo,30,'\n');
(25,10+(2*i));
cout<<"CANCELACION REALIZADA";
Sleep(800);system("cls");
}


//-------------------------------------------DEFINIR PLATILLOS----------------------------------------------
void defplat()
{
defprice:
mns=0; delete[] menusprice; delete[] cuentamenus;
platillos.clear();
system("color 8E");
cout<<endl<<endl<<endl<<"\tCuantos menus para hoy?   ";
cin>>op;
if (isalpha(op)==0)
 { 
	mns=op-48;
	menusprice=new float [mns];
   cuentamenus=new int [mns+2];
	for (i=0;i<=mns+1;i++){cuentamenus[i]=0;}
	system("CLS");
	for(i=0;i<mns;i++)
	{
	cout<<endl<<endl<<endl<<"        NOMBRE platillo "<<i+1<<":   ";getchar();
	cin.getline(plat,20,'\n'); platillos.push_back(plat);
	cout<<endl<<endl<<endl<<"                              PRECIO "<<": ";
	cout<<"$ ";cin>> menusprice[i];
	system("CLS");
	}
 }
else 
 {cout<<"Opcion no valida "; Sleep(500); system("cls"); goto defprice;}
}

//------------------------------------------MOSTRAR MENU---------------------------------------------------
void menudia()
{
for(i=0;i<mns;i++)
{
gotoxy(5,2+(i*2));
cout<<"$ "<<menusprice[i]<<" --->";
gotoxy(15,2+(i*2));
cout<<platillos[i];
}
cout<<endl<<endl<<endl;
system("PAUSE");
system("CLS");
}

//-----------------------------------------NUEVA ORDEN---------------------------------------------------
void nuevaord()
{
ordennueva:
cuenta=0;
cout<<endl<<"                         Orden de venta nueva"<<endl<<endl<<endl;
cout<<"               Cuantos menus lleva?     ";
cin>>n;
system("CLS");
for(i=0;i<mns;i++)
{
gotoxy(2,2+(i*2));
cout<<"$ "<<menusprice[i]<<"  "<<  platillos[i];
gotoxy(20,2+(i*2));
cout<<" ---> ["<<i+1<<"]";
}
cout<<endl<<endl;
for (i=0;i<n;i++)
{
auxmenu[i]=0;
gotoxy(40,5+(2*i));
cout<<"Pedido "<<i+1<<":  ";
cin>>auxmenu[i];
cuenta+=menusprice[auxmenu[i]-1];
gotoxy(60,6+(2*i));
cout<<"SUBTOTAL: $ "<<cuenta;
}
gotoxy(5,20);
cout<<"ES CORRECTO EL PEDIDO?? --->        Si [S]        No [N]\n\n";
cin>>op; if ((op=='n')||(op=='N')) {system("cls");goto ordennueva;}
for (i=0;i<n;i++){menusel=auxmenu[i];auxmenu[i]=0;cuentamenus[menusel-1]++;}
system("CLS");
getchar();
gotoxy(60,3);
cout<<"SUBTOTAL: $ "<<cuenta;
cout<<"\n\n\n                     Nombre del cliente:        ";
cin.getline(nombre,30,'\n');
cout<<endl<<"                     Direccion del cliente:     ";
cin.getline(direccion,50,'\n');
cout<<endl<<"                     Tiempo de espera:          ";
cin>>tiempo;
if (tiempo>0){reqtime(); cout<<"tiempo: "<<tiempo<<" "<<P; tiempo=0;}
cout<<endl<<endl<<"                         MONTO EXTRA?"<<endl<<endl;
cout<<"                    SI ----- [S]               NO ----- [N]"<<endl;
cin>>op;
if((op=='s')||(op=='S'))
{
  char motivo[30];
  getchar();
  cout<<endl<<"INGRESE MOTIVO: ";
  cin.getline(motivo,30,'\n');
  cout<<"\nINGRESE MONTO EXTRA: $ ";
  cin>>extras;cuenta+=extras;
  cuentamenus[mns]++;
}

system("CLS");
system("color 0A");
cout<<"\n---------------------------------- PAGO $$$$ ----------------------------------"<<endl<<endl;
cout<<endl<<"\n                    TOTAL: $ "<<cuenta<<endl<<endl;
cout<<"\n                    PAGO:  $ ";
cin>>pago;
pago=pago-cuenta;
cout<<"\n\n\n***************     CAMBIO: $ "<<pago<<endl<<endl;
getchar();
MessageBox(HWND_DESKTOP, "PEDIDO GUARDADO ", "NUEVO PEDIDO", MB_OK+MB_ICONEXCLAMATION);
nventas += 1;
totalg=totalg+cuenta;
system("CLS");
}
//-----------------------------------------CORTE DE CAJA---------------------------------------------------
void cortecaja()
{
system("color 8B");
cout<<endl<<"**************************************  HORA DE INICIO DE SESION: "<<h_ent<<" : "<<m_ent<<" : "<<s_ent<<endl;
tiempox();
cout<<endl<<"**************************************  HORA DE  CORTE DE SESION: "<<h_ent<<" : "<<m_ent<<" : "<<s_ent<<endl<<endl;
cout<<" NUMERO TOTAL DE PEDIDOS: --- "<<nventas;
extras=0;
for (i=0;i<mns;i++)
{
 gotoxy(2,8+i*2);
 cout<<"VENTAS DE "<<platillos[i];
 gotoxy(32,8+i*2);
 cout<<cuentamenus[i];
 gotoxy(37,8+i*2);
 cout<<cuentamenus[i]*menusprice[i]<<" pesos"<<endl<<endl;
 extras+=cuentamenus[i]*menusprice[i];
}
cout<<"  EXTRAS: \t\t\t"<<cuentamenus[mns]<<"    "<<totalg-extras<<" pesos"<<endl<<endl;
cout<<"  CANCELACIONES: \t\t\t"<<cuentamenus[mns+1]<<endl<<endl<<endl;
cout<<"  TOTAL DE VENTAS: ---- $ "<<totalg<<endl<<endl;
for (i=0;i<=mns;i++){cuentamenus[i]=0;}
totalg=0; nventas=0; extras=0; cuentamenus[mns+1]=0;
system("PAUSE");
system("CLS");

}
//METODOS TIMER****************************************************************************************************************************

//-----------------------------------------ALMACENAR TIEMPO---------------------------------------------------
void reqtime()
{
 fflush(stdin);
 static int H,M,S,h,m,s;
 time_t now=time(0);
 tm *time=localtime(&now);
 
 H=time->tm_hour; M=time->tm_min; S=time->tm_sec;
 h=H; m=M; s=S;
 m+=tiempo;
 if(m>=60) {h++; m-=60;}
 h=(h-H)*3600; m=(m-M)*60; s-=S;
 tiempo=h+m+s;
 v1.push_back(tiempo);
 P=P+1; 
}

//----------------------------------CONTADOR---------------------
void contador()
{
 while (true)
 {
cout<<"estado de p: "<<P;
if (P<=0)
 {
	gotoxy(40,0);
	cout<<"NO HAY PEDIDOS PENDIENTES  :)"<<endl;
   
 }
else
 {
 gotoxy(40,0);
 cout<<"segundos restantes:";
 P=checador();
 }
  
Sleep(1000);
}
}


//----------------------------------CHECADOR-----------------------------
int checador()
{
static int i,j;
for (i=0;i<P;i++)
 {
  cout<<v1[i]<<endl;
  v1[i]--; 
  if (v1[i]<=0)
  {   
	 Beep(740,250);
	 Beep(660,250);
	 Beep(740,250);
	 Beep(830,250);
	 cout<<"ENTREGAR PEDIDO "<<i<<endl;
	 cout<<"PEDIDOS RESTANTES: "<<P-1<<endl;
	 v1[i]=0;
	 for (j=i;j<=P-1;j++)
	 { 
	   v1[j]=v1[j+1];
	   v1[j]-=2;
	   if(j==P-2) {v1[j+1]=0;}
	 }
	 if (P>0){P--;}
	 else {P=0;}
  }
 }
return P;

}

//-----------------------------------TIEMPOX-----------------------------
void tiempox()
{
time_t now = time(0);
tm *time = localtime(&now);
h_ent=time->tm_hour;m_ent=time->tm_min;s_ent=time->tm_sec;
}.
