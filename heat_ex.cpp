#include <iostream.h>
#include <windows.h>
#include <math.h>
void muros();
void muros_cil();
void resop();
void resop_cil();
void temp();
void resist_k(float, float);
float resist_h();
float sol(float, float, float);
float Q=0,T1=0,T2=0,T,R=0,tx,Rsum,Rconv,Rtot,h1,h2,k_x,L_x,A_x,rk,A,B,C;
char m,n,o,op1;


int main ()
{
 do
 {
 cout<<"Asegurese de que todos sus datos son cuengruentes"<<endl;
 cout<<"          dimensionalmente."<<endl<<endl;
 cout<<"     Pared [p]          Cilindro [c]"<<endl;
 cin>>n;
 cout<<"seleccione la variable que quiere resolver"<<endl;
 cout<<"Flujo de calor [Q]  Temperatura[T]  Resistencia [R]"<<endl;
 cin>>m;
 if (m=='q')               //1- muros(devuelve Rtot)
  {                        
  cout<<"Tiene la resistencia total?"<<endl;
  cout<<"        SI [s]         NO [n]"<<endl;
  cin>>op1;
  if(op1=='s')
   {
   cout<<"introduzca la resistencia total:"<<endl;
   cin>>R;
   }
  else if (op1=='n')
   {
   if(n=='p')
    {
    muros();
    R=Rtot;
    }
   else if(n=='c')
    {
    muros_cil();
    R=Rtot;
    }    
   }
  temp();            //2- temp(devuelve tx como diferencia de T)
  T=tx;
  Q=0;                     //3- Q (se pide directo)
  sol(Q,T,R);
  }
 else if (m=='t') 
  {
  cout<<"introduzca el flujo de calor Q"<<endl;
  cin>>Q;
  cout<<"Tiene la resistencia total?"<<endl;
  cout<<"        SI [s]         NO [n]"<<endl;
  cin>>op1;
  if(op1=='s')
   {
   cout<<"introduzca la resistencia total:"<<endl;
   cin>>R;
   }
  else if (op1=='n')
   {
   if(n=='p')
    {
    muros();
    R=Rtot;
    }
   else if(n=='c')
    {
    muros_cil();
    R=Rtot;
    }
   }
  T=0;
  temp();
  if(tx==T1){T=((-1)*(sol(Q, T, R))+tx);cout<<"la temperatura del punto 2 es: "<<T<<" grados"<<endl;}
  else if(tx==T2){T=((-1)*(sol(Q, T, R))-tx)*(-1);cout<<"la temperatura del punto 1 es: "<<T<<" grados"<<endl;}
  else if(tx==(-1)){sol(Q, T, R);}
  }
 else if(m=='r')
  {
  cout<<"introduzca el flujo de calor Q:"<<endl;
  cin>>Q;
  cout<<"introduzca la diferencia de temperaturas entre los puntos:"<<endl;
  cin>>T;
  R=0;
  R=sol(Q, T, R);
  if(n=='p')
    {
    resop();
    }
   else if(n=='c')
    {
    resop_cil();
    }
  }
cout<<"Calcular de nuevo?     SI [s]    NO [n]"<<endl;
cin>>o;
cout<<"ESPERE...";
system("cls");
}
while (o!='n'); 
return 0;
}

            float sol(float A, float B, float C)
{

if(A !=0 && B !=0)
 {
 C=B/A;
 cout<<"la resistencia total entre dos puntos es: "<<C<<endl;
 return C;
 }
else if(A !=0 && C !=0)
 {
 B=A*C;
 cout<<"la diferencia de temperaturas: "<<B<<" grados"<<endl;
 return B;
 }
else if(B != 0 && C !=0)
 {
 A=B/C;
 cout<<"El flujo de calor es: "<<A<<endl;
 }

}   

            void muros()    //devuelve resistencia total de todas las paredes
{
int i;
cout<<"cuantas paredes son?"<<endl;
cin>>i;
float Rmuros[i];
for(int j=1;j<=i;j++)
 {
 cout<<"Constante conductiva k del muro "<<j<<endl;
 cin>>k_x;
 cout<<"Espesor del muro "<<j<<endl;
 cin>>L_x;  
 resist_k(k_x, L_x);           // resist_k entra k y L (devuelve resistencia conductiva)
 Rmuros[j]=rk;
 cout<<"Resitencia en muro "<<j<<" es: "<<Rmuros[j]<<endl;
 Rsum=Rsum+Rmuros[j];
 }
 cout<<"Area de los muros "<<endl;
 cin>>A_x;
 Rconv=resist_h();             // resist h declara variable interna (devuelve resistenvia conv.)
 Rtot=(Rconv+Rsum)/A_x;
 cout<<"la resistencia total es: "<<Rtot<<endl;
}



                                   
            void resist_k(float k, float L)    //devuelve resistencia CONDUCTIVA por unidad de area
{
rk=L/k;
}



            float resist_h()                    //devuelve resistencia CONVECTIVA por unidad de area
{
float rc;
cout<<"tiene resistencias convectivas h?"<<endl;
cout<<" SI [s]   NO [n]"<<endl;
cin>>op1;
if(op1=='s')
 {
 cout<<"UNA [a]   DOS [b]"<<endl;
 cin>>op1;
 if(op1=='a')
  {
  cout<<"constante de conveccion h"<<endl;
  cin>>h1;
  if(n=='p')
   {
   rc=1/h1;
   }
  else if(n=='c')
   {
   float r;
   cout<<"Ingrese radio de contacto:"<<endl;
   cin>>r;
   rc=1/(h1*r);
   }
  }
 if(op1=='b')
  {
  cout<<"constante de conveccion h 1"<<endl;
  cin>>h1;
  cout<<"constante de conveccion h 2"<<endl;
  cin>>h2;
  if(n=='p')
   {
   rc=(1/h1)+(1/h2);
   }
  else if(n=='c')
   {
   float r1,r2;
   cout<<"Ingrese radio de contacto int.:"<<endl;
   cin>>r1;
   cout<<"Ingrese radio de contacto ext.:"<<endl;
   cin>>r2;
   rc=(1/(h1*r1))+(1/(h2*r2));
   }
  }     
 }
else if(op1=='n')
 {
 
 rc=0;
 }
return (rc);
}

            void temp()
{
int op;
 if (m=='q' || m=='r')
  {
  cout<<"diferencia de temperaturas: "<<endl<<endl;
  cout<<"temperatura del punto 1: "<<endl;
  cin>>T1;
  cout<<"temperatura del punto 2: "<<endl;
  cin>>T2;
  tx=T1-T2;
  }
else if (m=='t')
 {
 cout<<"Que temperatura tiene?"<<endl;
 cout<<"Temperatura del punto 1 [1]    Temperatura del punto 2 [2]    NINGUNA [3]"<<endl;
 cin>>op;
 if(op==1)
  {
  cout<<"Temperatura del punto 1: "<<endl;
  cin>>T1;
  tx=T1;
  }
 else if(op==2)
  {
  cout<<"Temperatura del punto 2 "<<endl;
  cin>>T2;
  tx=T2;
  }
 else if(op==3)
 {
 tx=(-1);
 }
 }
}



void resop()
{
int op;
cout<<"seleccione la parte de la resistencia que busca:"<<endl;
cout<<"Factor de conductividad k         [1]"<<endl;
cout<<"Factor de conductividad h         [2]"<<endl;
cout<<"Espesor de muro                   [3]"<<endl;
cout<<"Area de muro                      [4]"<<endl;
cin>>op;
if(op==1)
 {
 cout<<"Area de los muros "<<endl;
 cin>>A_x;
 cout<<"Espesor del muro "<<endl;
 cin>>L_x;
 k_x=L_x/(A_x*R);
 cout<<"La condictividad k del muro es:"<<k_x<<endl;
 }
else if(op==2)
 {
 float h;
 cout<<"Desechar resistencias conductivas?"<<endl;
 cout<<"         SI [s]       NO [n]"<<endl;
 cin>>n;
 if(n=='s')
  {
  cout<<"Introduzca resistencia CONDUCTIVA TOAL L/k*A"<<endl;
  cout<<"(si no la tiene, ayudese del programa para obtenerla)"<<endl;
  cin>>rk;
  cout<<"Area del muro que toca el fluido "<<endl;
  cin>>A_x;
  h=1/((R-rk)*A_x);
  cout<<"El factor convectivo h TOTAL es: "<<h<< endl;
  }
 else if(n=='n')
  {
  cout<<"Area del muro que toca el fluido "<<endl;
  cin>>A_x;
  h=1/(R*A_x);
  cout<<"El factor convectivo h TOTAL es: "<<h<< endl;
  }
 }
else if(op==3)
 {
 cout<<"Area de los muros "<<endl;
 cin>>A_x;
 cout<<"Conductividad k del muro "<<endl;
 cin>>k_x;
 L_x=k_x*A_x*R;
 cout<<"El espesor del muro es:"<<L_x<<endl;
 }
else if(op==4)
 {
 cout<<"Conductividad k del muro "<<endl;
 cin>>k_x;
 cout<<"Espesor del muro "<<endl;
 cin>>L_x;
 A_x=L_x/(k_x*R);
 cout<<"El area del muro es:"<<A_x<<endl;
 }
}



void resop_cil()
{
int op;
cout<<"seleccione la parte de la resistencia que busca:"<<endl;
cout<<"Factor de conductividad k         [1]"<<endl;
cout<<"Factor de conductividad h         [2]"<<endl;
cout<<"Longitud del tubo                 [3]"<<endl;
cout<<"Relacion de diametros             [4]"<<endl;
cin>>op;
if(op==1)
 {
 cout<<"Relacion de radios (radio ext. entre radio int.) "<<endl;
 cin>>A_x;
 cout<<"Longitud del cilindro "<<endl;
 cin>>L_x;
 k_x=(exp(A_x))/(2*3.1416*L_x);
 cout<<"La condictividad k del muro es:"<<k_x<<endl;
 }
else if(op==2)
 {
 float h;
 cout<<"      (Solo un factor h por vez)"<<endl;
 cout<<"Desechar resistencias conductivas?"<<endl;
 cout<<"         SI [s]       NO [n]"<<endl;
 cin>>n;
 if(n=='s')
  {
  cout<<"Introduzca resistencia CONDUCTIVA TOTAL"<<endl;
  cout<<"ln(r2/r1)/2*pi*k*L"<<endl;
  cout<<"(si no la tiene, ayudese del programa para obtenerla)"<<endl;
  cin>>rk;
  cout<<"Radio de la pared de contacto "<<endl;
  cin>>A_x;
  cout<<"Longitud del tubo "<<endl;
  cin>>L_x;
  h=1/((R-rk)*2*3.1416*A_x*L_x);
  cout<<"El factor convectivo h de LA PARED es: "<<h<< endl;
  }
 else if(n=='n')
  {
  cout<<"Radio en contacto con el fluido "<<endl;
  cin>>A_x;
  cout<<"Longitud del tubo "<<endl;
  cin>>L_x;
  h=1/(R*2*3.1416*L_x*A_x);
  cout<<"El factor convectivo h de LA PARED es: "<<h<< endl;
  }
 }
else if(op==3)
 {
 cout<<"Relacion de diametros r2/r1 "<<endl;
 cin>>A_x;
 cout<<"Conductividad k del muro "<<endl;
 cin>>k_x;
 L_x=(log(A_x))/(2*3.1416*k_x*R);
 cout<<"La longitud del tubo es:"<<L_x<<endl;
 }
else if(op==4)
 {
 cout<<"Conductividad k del muro "<<endl;
 cin>>k_x;
 cout<<"Espesor del muro "<<endl;
 cin>>L_x;
 A_x=exp(R*2*3.1416*k_x*L_x);
 cout<<"La relacion de diametros r2/r1 es:"<<A_x<<endl;
 }
}





void muros_cil()    
{
int i,j;
cout<<"cuantas capas son?"<<endl;
cin>>i;
float Rmuros[i]; float r[i+1];
for (j=0;j<=i;j++)
 {
 cout<<"Radio "<<j<<endl;
 cin>>r[j];  
 if (j>=1)  
  {
  cout<<"Constante conductiva k del muro "<<j<<endl;
  cin>>k_x;
  Rmuros[j]=((log (r[j]/r[j-1]))/k_x);
  Rsum=Rmuros[j]+Rsum;
  }
 cout<<"Resitencia en muro "<<j<<" es: "<<Rmuros[j]<<endl;
 } 
cout<<"Longitud del tubo: "<<endl;
cin>>L_x;
Rconv=resist_h();     // resist h declara variable interna (devuelve resistenvia conv.)
Rtot=((Rsum+Rconv)/(L_x*2*3.1416));
cout<<"la resistencia total es: "<<Rtot<<endl;
}
