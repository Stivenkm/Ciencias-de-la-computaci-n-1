#include <iostream>
#include <time.h>
#include<stdlib.h>
void cambioresiduos(long long a[], int izq, int der, int b);
void mostrarArreglo(long long arreglo[], int tamano);
void llenarArreglo(long long  arreglo[], int tamano);
using namespace std;
int main(){
  int clave =0,tamano=0,cantNum=0;
	cout << "Tamanoo del arreglo: ";
	cin>>tamano;
  	long long a[tamano];	
  	llenarArreglo(a, tamano);
  	mostrarArreglo(a,tamano);
  	cambioresiduos(a,1,0, 4);
  	mostrarArreglo(a,tamano);

}

unsigned bits (long long x, int k, int j){
 return (x>>k)&~(~0<<j);
}
void  intercambio(long long a[],int i ,int j){
	int aux=a[i];
	a[i]=a[j];
	a[j]=aux;
}
void mostrarArreglo(long long arreglo[], int tamano){
  for (int i = 0 ; i < tamano ; i++)
    cout << "arreglo[" << i << "]=" << arreglo[i] << endl;
}
void llenarArreglo(long long arreglo[], int tamano) {
	srand(time(NULL));
	 for ( int i = 0; i < tamano; i++ ) { 
        arreglo[i] = rand() % 2 ;
        }
}
void cambioresiduos(long long a[], int izq, int der, int b)
{ int i,j;
   if (der>izq && b>0)
     {i= izq; j=der;
       while(j!=i)
          {while(!bits(a[i],b,1) && i<j)i++;
            while( bits(a[i],b,1) && j>i)j--;
             intercambio(a, i, j);
           }
        if (!bits(a[i],b,1)) j++;
            cambioresiduos(a, izq, j-1, b-1);
            cambioresiduos(a, j, der, b-1);
      }
}

