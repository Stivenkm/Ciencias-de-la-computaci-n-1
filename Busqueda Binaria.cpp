#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;
void llenarArreglo(int [], int ,int);
void mostrarArreglo(int[], int);
int busquedaBinaria(int[], int, int);
void ordenarArreglo(int[], int); 
void intercambiar(int&, int&); 
int main(){
  int clave =0,tamano=0,cantNum=0;
	cout << "Tamanoo del arreglo: ";
	cin>>tamano;
	cout << "Cantidad de numeros para llenar el arreglo de forma aleatoria: ";
	cin >> cantNum;
  	int arreglo[tamano];	
  	llenarArreglo(arreglo,tamano,cantNum);
  	ordenarArreglo(arreglo,tamano);
  	cout << "Elementos del arreglo: " << endl;
 	 mostrarArreglo(arreglo,tamano);
  	cout << "Indique un valor a buscar y se le devolvera el indice: ";
  	cin >> clave;
  	cout<< "Su valor se encuentra en arreglo["<<busquedaBinaria(arreglo,tamano,clave)<<"]" << endl;
  	cout << "Fin del programa :)" << endl;
  return 0;
}
void llenarArreglo(int arreglo[], int tamano,int canNum) {
	 srand(time(NULL));
	 for ( int i = 0; i < tamano; i++ ) { 
        arreglo[i] = 1 + rand() % (canNum +1 - 0) ;
        }
}
void mostrarArreglo(int arreglo[], int tamano){
  for (int i = 0 ; i < tamano ; i++)
    cout << "arreglo[" << i << "]=" << arreglo[i] << endl;
}
int busquedaBinaria(int arreglo[], int tamano, int clave){
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba){
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}
void ordenarArreglo(int arreglo[], int tamano){
  for (int i = 0; i< tamano -1 ; i++)
    for (int j = 0; j< tamano -1 ; j++)
      if (arreglo[j] > arreglo[j+1])
 intercambiar(arreglo[j],arreglo[j+1]);
}
void intercambiar(int &a, int &b){
  int tmp = b;
  b = a;
  a = tmp;
}
