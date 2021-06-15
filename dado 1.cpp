#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <map>
#include <typeinfo>

using namespace std;

random_device rd;

//Objeto de tipo random_device para variar la semilla para generar aleatorios

mt19937 genMT19937(rd());

// Algoritmo generador de numeros aleatorios usando Mersene Twister
//se le pasa una instancia de tipo random device como semilla
//puede ser sustituido por tiempo actual ya que el tiempo cambia a cada momento usando time(0) en lugar de rd()

uniform_real_distribution<double> U(0,1);

//genera un numero aleatorio de doble precision entre 0 y 1 usando la semilla rd()
//se puede cambiar por uniform_int_distribution y es una funcion que cada que se invoque, genera un numero
//esto es el equivalente a un generador de probabilidad ya que el rango esta entre 0 y 1

inline dado(int num_caras){
	return floor(num_caras*U(genMT19937))+1; 
	
	//la funcion floor redondea hacia abajo el argumento
	//inline declara una funcion rapida (funcion de una linea) mejora el espacio que ocupa la funcion
	//esta parte se lee: redondea hacia abajo la probabilidad que tiene cada cara
}

int main(){
	int numero_selecciones, seleccion, n, m;
	map<string,int> dict; //es un diccionario de tipo clave,valor la clave es un string y el valor es un entero
	vector<string> vector_x;
	vector<string> vector_caras;
	cout<<"introduzca  NUMERO DE CARAS"<<endl;// 
	cin>>m;
	for (int cara=0;cara<m;cara++){
		vector_caras.insert(vector_caras.end(), "CARA "+to_string(cara+1));
	}

	cout<<"cuantas veces repetira el experimento?"<<endl;
	cin>>numero_selecciones;
	cout<<"introduzca  numero minimo de caras tal que sea menor que m"<<endl; //cuantos lanzamientos de dado por experimento
	cin>>n;
	if(n<m){

		for (int i=0; i<numero_selecciones; i++){   //NUMERO DE VECES QUE SE REPITE EL EXPERIMENTO
			vector_x=vector_caras; // cada principio de la iteracion se reinicia el vector_x

			for (int j=0; j<n; j++){
				
				seleccion=dado(m-j);  //se le pasa al dado el numero de caras menos el numero de iteraciones				
				dict[vector_x[seleccion-1]]++;
				vector_x.erase(vector_x.begin()+seleccion-1);
				
			}
			for (auto h : dict){ // for h in dict
			cout<<"SALIO "<<h.first<<endl;
			}
		
		}
		
		for (auto h : dict){ // for h in dict
			cout<<"NUMERO DE VECES QUE SALIO "<<h.first<<" = "<<h.second<<endl;
		}
	
}
	
	system("PAUSE");
	return 0;

}

