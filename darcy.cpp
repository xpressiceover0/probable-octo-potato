#include <iostream.h>
#include <fstream.h>
#include <windows.h>
#include <math.h>
#include <conio2.h>
#include<string.h>

using namespace std;
float const pi=3.1415926535897479;
float re1=0.0;
float re2=0.0;
float R,Pot,q,a1,a2,v1,v2,hv,d1,d2,L1,L2,f1,f2,hfl1,hfl2,e1,e2,den,visc,p1,p2,dp,hp,dhp,z1,z2,suma;
float n=1, g;
char op1,op2,op3,op4,op6,op8,op9;
string uni;
int op5,op7, i,j,k;
void fdarcy();
void caudal();
void accesorios();
void presion();
void altura();
float reynolds(float, float);
float cole(float,float,float);
float acces(float, float);
int main()
{
do
{
cout<<"Sistema Internacional [a]       Sistema Britanico [b] ";cin>>op1;
if(op1=='a'){g=9.81; uni="metros";}
else if(op1=='b'){g=32.2; uni="pies";}
clrscr();
cout<<"Asegurese que sus datos son congruentes dimensionalmente"<<endl;
cout<<"Potencia de Bomba  [p]    Seleccionar Funcion [s]";
cin>>op1;
clrscr();
if(op1=='s')
 {
 cout<<"Velocidad - Caudal     [1]    Perdidas secundarias    [5]"<<endl;
 cout<<"Presion                [2]    Ecuacion de Colebrook   [6]"<<endl;
 cout<<"Alturas                [3]    Numero de Reynolds      [7]"<<endl;
 cout<<"Perdidas primarias     [4]    SALIR                   [8]"<<endl;
 cin>>k;
 if(k==8){}
 else if(k==1){caudal();}
 else if(k==2){cout<<"Introduzca la densidad del fluido: ";cin>>den;presion();}
 else if(k==3){altura();}
 else if(k==4)
  {
  cout<<"Velocidad 1: ";cin>>v1;
  cout<<"Velocidad 2: ";cin>>v2;
  cout<<"Diametro 1: ";cin>>d1;
  cout<<"Diametro 2: ";cin>>d2;
  fdarcy();
  }
 else if(k==5){v1=0;v2=0;f1=0;f2=0;accesorios();}
 else if(k==6){re1=0;e1=0;d1=0; f1=cole(re1, e1, d1); cout<<f1<<endl;}
 else if(k==7){v1=0; d1=0; re1=reynolds(v1, d1); cout<<re1<<endl;}
 }
else if(op1=='p') 
 {
 caudal();
 fdarcy();
 accesorios();
 presion();
 altura();
 R=hfl2+hfl1+suma+hp+z2;
 cout<<"eficiencia de la bomba"<<endl;
 cin>>n;
 Pot=(den*g*q*R)/n;
 cout<<"las perdidas totales son: "<<R<<" Metros"<<endl;
 cout<<"la potencia de la bomba es: "<<Pot<<"  WATTS"<<endl;
 cout<<"la potencia de la bomba en HP: "<<Pot/745.7<<"  HP"<<endl;
 ofstream Resultados;
 Resultados.open("Resultados.txt");
 Resultados<<"Resultados del programa:"<<endl;
 Resultados<<"Velocidad 1:  "<<v1<<" "<<uni<<"/seg"<<endl;
 Resultados<<"Velocidad 2:  "<<v2<<" "<<uni<<"/seg"<<endl;
 Resultados<<"Diametro 1:  "<<d1<<" "<<uni<<endl;
 Resultados<<"Diametro 2:  "<<d2<<" "<<uni<<endl;
 Resultados<<"Area 1:  "<<a1<<" "<<uni<<" cuadrados"<<endl;
 Resultados<<"Area 2:  "<<a2<<" "<<uni<<" cuadrados"<<endl;
 Resultados<<"Longitud 1:  "<<L1<<" "<<uni<<endl;
 Resultados<<"Longitud 2:  "<<L2<<" "<<uni<<endl;
 Resultados<<"Perdidas primarias por ACCESORIOS: "<<hfl1+hfl2<<" "<<uni<<endl; 
 Resultados<<"Perdidas secundarias por ACCESORIOS:  "<<suma<<" "<<uni<<endl;
 Resultados<<" Numero de Reynolds tuberia 1:  "<<re1<<" adimensional"<<endl;
 Resultados<<" Numero de Reynolds tuberia 2:  "<<re2<<" adimensional"<<endl;
 Resultados<<" Rugosidad tuberia 1:  "<<e1<<" "<<uni<<endl;
 Resultados<<" Rugosidad tuberia 2:  "<<e2<<" "<<uni<<endl;
 Resultados<<" Factor de DARCY tuberia 1:  "<<f1<<" adimensional"<<endl;
 Resultados<<" Factor de DARCY tuberia 2:  "<<f2<<" adimensional"<<endl;
 Resultados<<"Carga TOTAL:  "<<R<<" "<<uni<<endl;
 Resultados<<"EFICIENCIA DE LA BOMBA:  "<<n*100<<" porciento"<<endl;
 Resultados<<"POTENCIA DE LA BOMBA:  "<<Pot<<" Unidades de potencia"<<endl;
 Resultados<<"POTENCIA DE LA BOMBA:  "<<Pot/745.7<<" HP"<<endl;
 Resultados.close();
 }
else {}
cout<<"Calcular otra vez?    SI [s]   NO [n]";
cin>>op9;
}
while (op9!='n');
getchar(); 
return 0;   
}

//EMPIEZAN FUNCIONES
                       
                       void caudal()




{
 cout<<"tiene el caudal o velocidad?"<<endl;
 cout<<"CAUDAL [c]   VELOCIDAD [V]"<<endl;
 cin>>op2;

 if (op2=='c')
  {
  cout<<endl<<"caudal: "<<endl;
  cin>>q;
  cout<<endl<<"diametro [1] o diametro [2]"<<endl;
  cin>>op5;
  if (op5==1)
   {
   cout<<"diametro 1"<<endl;
   cin>>d1;
   a1=(pi/4)*(d1*d1); v1=q/a1;
   cout<<endl<<"la velocidad 1 es: "<<v1<<endl;
   cout<<"el area 1 es: "<<a1<<endl;
   cout<<" velocidad 2 [v]         diametro 2 [d]"<<endl;
   cin>>op6;
   if (op6=='v')
    {
    cout<<endl<<"velocidad 2"<<endl;
    cin>>v2;
    a2=q/v2; d2=pow(((4*a2)/pi),0.5);
    cout<<endl<<"el area 2 es: "<<a2<<endl;
    cout<<"el diametro 2 es: "<<d2<<endl;
    }
   else if (op6=='d')
    {
    cout<<endl<<"diametro 2"<<endl;
    cin>>d2;
    a2=(pi/4)*(d2*d2); v2=q/a2;
    cout<<endl<<"el area 2 es: "<<a2<<endl;
    cout<<"la velocidad 2 es: "<<v2<<endl;
    }
   hv=((v2*v2)-(v1*v1))/(2*g);
   cout<<"la perdida por velocidades es:  "<<hv<<endl;
   }

  else if (op5==2)
   {
   cout<<"diametro 2"<<endl;
   cin>>d2;
   a2=(pi/4)*(d2*d2); v2=q/a2;
   cout<<endl<<"la velocidad 2 es: "<<v2<<endl;
   cout<<"el area es: "<<a2<<endl;
   cout<<" velocidad 1 [v]         diametro 1 [d]"<<endl;
   cin>>op6;
   if (op6=='v')
    {
    cout<<endl<<"velocidad 1"<<endl;
    cin>>v1;
    a1=q/v1; d1=pow(((4*a1)/pi),0.5);
    cout<<endl<<"area 1: "<<a1<<endl;
    cout<<"diametro 1: "<<d1<<endl;
    }
   else if (op6=='d')
    {
    cout<<endl<<"diametro 1"<<endl;
    cin>>d1;
    a1=(pi/4)*(d1*d1); v1=q/a1;
    cout<<endl<<"area 1: "<<a1<<endl;
    cout<<"velocidad 1: "<<v1<<endl;
    }
   hv=((v2*v2)-(v1*v1))/(2*g);
   cout<<"la carga por velocidades es:  "<<hv<<endl;
   }
  }
                     //se cierra Q
                    
                     //empieza vel
 if (op2=='v') 
  {
  cout<<"cuenta con las 2 velocidades?"<<endl;
  cout<<"SI [s]         NO [n]"<<endl;
  cin>>op8;
  if (op8=='n')
   {
   cout<<endl<<"velocidad 1 [1]          velocidad 2 [2]"<<endl;
   cin>>op7;
   if(op7==1)
    {
    cout<<endl<<"velocidad 1:"<<endl;
    cin>>v1;
    cout<<"diametro 1:"<<endl;
    cin>>d1;
    a1=(pi/4)*d1*d1; q=a1*v1;
    cout<<endl<<"area 1:  "<<a1<<endl;
    cout<<"caudal:  "<<q<<endl;
    cout<<"diametro 2:"<<endl;
    cin>>d2;
    a2=d2*d2*(pi/4); v2=q/a2;
    cout<<"la velocidad 2 es:"<<v2<<endl;
    }
   else if (op7==2)
    {
    cout<<"velocidad 2:"<<endl;
    cin>>v2;
    cout<<"diametro 2:"<<endl;
    cin>>d2;
    a2=(pi/4)*d2*d2; q=a2*v2;
    cout<<"area 2:  "<<a2<<endl;
    cout<<"caudal:  "<<q<<endl;
    cout<<"diametro 1:"<<endl;
    cin>>d1;
    a1=d1*d1*(pi/4); v1=q/a1;
    cout<<"la velocidad 1 es:"<<v1<<endl;
    }
   hv=((v2*v2)-(v1*v1))/(2*g);
   cout<<"la carga por velocidades es:  "<<hv<<endl;
   }
  else if(op8=='s')
   {
   cout<<"velocidad 1:"<<endl;
   cin>>v1;
   cout<<endl<<"velocidad 2"<<endl;
   cin>>v2;
   cout<<"tiene el caudal o el diametro?"<<endl;
   cout<<"CAUDAL [c]      DIAMETRO [d]"<<endl;
   cin>>op9;
   if(op9=='c')
    {
    cout<<"caudal:"<<endl;
    cin>>q;
    a1=q/v1; d1=pow(((a1*4)/pi),0.5);
    cout<<"el diametro 1 es: "<<d1<<endl;
    cout<<"el area 1 es: "<<a1<<endl;
    a2=q/v2; d2=pow(((a2*4)/pi),0.5);
    cout<<"el diametro 2 es: "<<d2<<endl;
    cout<<"el area 2 es: "<<a2<<endl;
    }
   else if(op9=='d')
    {
    cout<<"de que tuberia tiene el diametro?"<<endl;
    cout<<"tuberia 1 [1] tuberia 2 [2] ambas [3]"<<endl;
    cin>>op7;
    if(op7==1)
     {
     cout<<"diametro 1:"<<endl;
     cin>>d1;
     a1=d1*d1*(pi/4); q=v1*a1;
     cout<<"caudal es: "<<q<<endl;
     cout<<"el area 1 es: "<<a1<<endl;
     }
    if(op7==2)
     {
     cout<<"diametro 2:"<<endl;
     cin>>d2;
     a2=d2*d2*(pi/4); q=v2*a2;
     cout<<"caudal es: "<<q<<endl;
     cout<<"el area 1 es: "<<a2<<endl;
     }
     if(op7==3)
     {
     cout<<"diametro 1:"<<endl;
     cin>>d1;
     cout<<"diametro 2:"<<endl;
     cin>>d2;
     a1=d1*d1*(pi/4); q=v1*a1; a2=d2*d2*(pi/4);
     cout<<"caudal es: "<<q<<endl;
     cout<<"el area 1 es: "<<a1<<endl;
     cout<<"el area 2 es: "<<a2<<endl;
     }
    }
   }
   hv=((v2*v2)-(v1*v1))/(2*g);
   cout<<"la carga por velocidades es:  "<<hv<<endl;
   }
  }



  void fdarcy()




{
 cout<<"densidad del fluido"<<endl;
 cin>>den;
 cout<<"viscosidad dinamica"<<endl;
 cin>>visc;
 cout<<"Longitud de tuberia 1"<<endl;
 cin>>L1;
 cout<<"Longitud de tuberia 2"<<endl;
 cin>>L2;
 cout<<"tiene el factor de darcy?"<<endl;
 cout<<"SI [s]   NO [n]"<<endl;
 cin>>op1;
 if (op1=='s')
  {
  cout<<"factor tuberia 1"<<endl;
  cin>>f1;
  cout<<"factor tuberia 2"<<endl;
  cin>>f2;
  re1=reynolds(v1, d1);
  re2=reynolds(v2, d2);
  }
 
 else if (op1=='n')
  {
  cout<<"rugosidad en "<<uni<<" entrada: ";
  cin>>e1; cout<<endl;
  re1=reynolds(v1, d1);
  if(re1<=3000)
   {
   f1=64/re1;
   }
  else if(re1>=4000 )
   {
   f1=cole(re1, e1, d1);
   }
  
   cout<<"rugosidad en "<<uni<<" salida: ";
   cin>>e2; cout<<endl;
   re2=reynolds(v2, d2);
   if(re2<=3000)
    {
    f2=64/re2;
    }
   else if(re2>3000)
    {
    f2=cole(re2, e2, d2);
    }
  }
 cout<<"reynolds 1: "<<re1<<endl; 
 cout<<"reynolds 2: "<<re2<<endl;
 cout<<"factor de darcy 1: "<<f1<<endl;
 cout<<"factor de darcy 2: "<<f2<<endl;
 cout<<"V1: "<<v1<<"  V2: "<<v2<<"  L1: "<<L1<<"  L2: "<<L2<<"  D1: "<<d1<<"  D2: "<<d2<<endl;
 hfl1=f1*v1*v1*(L1/(2*g*d1));
 hfl2=f2*v2*v2*(L2/(2*g*d2));
 cout<<"perdidas primarias en tuberia 1: "<<hfl1<<endl;
 cout<<"perdidas primarias en tuberia 2: "<<hfl2<<endl;
}
                     
                     void accesorios()
{
 cout<<"tiene las perdidas por los accesorios en "<<uni<<"?"<<endl;
 cout<<"SI [s]   NO [n]"<<endl;
 cin>>op1;
 if (op1=='n')
   {
   if(v1==0){cout<<"Velocidad 1: "; cin>>v1;}
   if(f1==0){cout<<"Factor de darcy 1: "; cin>>f1;}
   if(v2==0){cout<<"Velocidad: "; cin>>v2;}  
   if(f2==0){cout<<"Factor de darcy: "; cin>>f2;} 
   cout<<"introduzca el numero de accesorios de la tuberia 1"<<endl;
   cin>>i;
   cout<<"introduzca el numero de accesorios de la tuberia 2"<<endl;
   cin>>j;
   float leq1[i];
   float leq2[j];
   cout<<"Accesorios de tuberia 1"<<endl;
   for(k=1;k<=i;k++)
    {
    leq1[k]= acces(f1, v1);
    suma=suma+leq1[k];
    }
   cout<<"Accesorios de tuberia 2"<<endl;
   for(k=1;k<=j;k++)
    {
    leq2[k]=acces(f2, v2);
    suma=suma+leq2[k];
    } 
   cout<<"Introducir mas perdidas "<<uni<<"?      SI[s]   NO[n] ";
   cin>>op1; k=1;
   } 
 if(op1=='n'){}
 else if (op1=='s')
  {
  float leq1[i];
  cout<<"Cuantas perdidas va a agregar? ";
  cin>>i;
  for(k=1;k<=i;k++)
   {
   cout<<"perdida en "<<uni<<" del accesorio: "<<k<<endl;
   cin>>leq1[k];
   suma=suma+leq1[k];
   }
  }
cout<<"perdidas totales secundarias "<<suma<<endl;
}  
                   

                   void presion()

{
 float denfm;
 cout<<"Tiene la presion en pascales o en altura?"<<endl;
 cout<<"Pascales o lbf/pie^2 [p]   Columna de iquido [a]"<<endl;
 cin>>op3;

 if(op3=='p')
  {
  cout<<"introduzca la lectura del manometro"<<endl;
  cout<<"presion de entrada (pascales o lbf/pie cuadrado)"<<endl;
  cin>>p1;
  cout<<"presion de salida (pascales o lbf/pie cuadrado)"<<endl;
  cin>>p2;
  dp=p2-p1;
  }
 else if(op3=='a')
  {
  cout<<"densidad absoluta[a]     densidad rel [r]"<<endl;
  cin>>op4;
  if(op4=='a')
   {
   cout<<"densidad manometrica absoluta:"<<endl;
   cin>>denfm;
   }
  else if(op4=='r')
   {
   cout<<"densidad manometrica relativa:"<<endl;
   cin>>denfm;
   denfm=denfm*1000;
   }
  cout<<"diferencia de altura"<<endl;
  cin>>dhp;
  dp=denfm*g*dhp;
  }
 hp=dp/(den*g);
 cout<<"carga por presion: "<<hp<<endl;
}



                  void altura()

{
cout<<"altura del punto 1"<<endl;
cin>>z1;
cout<<"altura del punto 2"<<endl;
cin>>z2;
z2=z2-z1;
cout<<"carga por altura: "<<z2<<endl;
}
              

              float cole(float re, float e, float d)

{
double t1,t2,f=0.008;
float I,D,R;
if(re==0)
 {
 cout<<"Reynolds: "<<endl;
 cin>>re;
 }
if(d==0)
 {
 cout<<"Diametro de la tuberia: "<<endl;
 cin>>d;
 }
if(e==0)
 {
 cout<<"Rugosidad de la tuberia: "<<endl;
 cin>>e;
 }
do
 {
 I=(1/(pow(f,0.5)));
 D=log10(pow(((e/(d*3.7))+(2.51/(re*f))),2))*(-1);
 R=I/D;
 cout<<"CALCULANDO... "<<R<<endl;
 cout<<"f: "<<f<<" t1: "<<t1<<" t2: "<<t2<<endl;
 clrscr();
 if (f<=0.1)
  {
  if(R>=1.01)
   {
   f=f+0.0001;
   }
  else if (R<=1.01 && R>=1.00001) 
   {
   f=f+0.000001;
   }
  }
 else if (f>0.1)
  {
  cout<<"valor no valido."<<endl;
  cout<<"Cambie el parametro de rugosidad y/o diametro"<<endl;
  getch();
  return 0;
  }
 }
while (R>=1.00001);
cout<<"factor encontrado: "<<endl;
return f;
}



              float reynolds(float v, float d)
              
{
float re;
if (v==0)
 {
 cout<<"Velocidad del fluido: "<<endl;
 cin>>v;
 }
if(d==0)
 {
 cout<<"Diametro de la tuberia: "<<endl;
 cin>>d;
 }
 if(den==0)
  {
  cout<<"densidad del fluido"<<endl;
  cin>>den;
  }
 if(visc==0)
  {
  cout<<"viscosidad dinamica"<<endl;
  cin>>visc;
  }
re=(den*v*d)/visc;
return (re);
}

                  float acces(float f, float v)
{ 
float h,rel;
clrscr();
cout<<"TIPO DE VALVULA                       [L/D]equivalente"<<endl;
cout<<"V.Globo abierta:                      [340]"<<endl;
cout<<"V.Angulo abierta:                     [150]"<<endl;
cout<<"V.Compuerta abierta:                  [8]           SI TIENE LA RELACION L/D"<<endl;
cout<<"V.Compuerta abierta a 3/4:            [35]          DE OTRO ACCESORIO"<<endl;
cout<<"V.Compuerta abierta a 1/2:            [160]         INTRODUZCALA."<<endl;
cout<<"V.Compuerta abierta a 1/4:            [900]         ESTA TABLA ES REFERENCIA!"<<endl;
cout<<"V.de Verificacion tipo Giratorio:     [100]"<<endl;
cout<<"V.de Verificacion tipo Bola:          [150]"<<endl;
cout<<"V.Mariposa abierta (2-8 pulgadas):    [45] "<<endl;
cout<<"V.Mariposa abierta (10-14 pulgadas):  [35]         EXPANDA ESTA VENTANA"<<endl;
cout<<"V.Mariposa abierta (16-24 pulgadas):  [25]         HACIA ABAJO."<<endl;
cout<<"V.de Pie tipo disco de Vastago:       [420]"<<endl;
cout<<"V.de Pie tipo disco de Bisagra:       [75] "<<endl;
cout<<"C. Estandar         90 grados:        [30] "<<endl;
cout<<"C. Radio Largo      90 grados:        [20] "<<endl;
cout<<"C. Roscado          90 grados:        [50] "<<endl;
cout<<"C. Estandar         45 grados:        [16] "<<endl;
cout<<"C. Roscado          45 grados:        [26] "<<endl;
cout<<"Vuelta cerrada de Retorno:            [50] "<<endl;
cout<<"T. Estandar con flujo directo:        [20] "<<endl;
cout<<"T. Estandar con flujo en el ramal:    [60] "<<endl;
cout<<"Introduzca la relacion [L/D] Equivalente del accesorio "<<k<<" ";
cin>>rel;
h=rel*f*(v*v/19.62);
return (h);
}
