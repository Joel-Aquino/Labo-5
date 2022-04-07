/*Problema#1.Diseñe un programa tal que, dado un número entero, lo muestre
 en pantalla y además muestre la ubicación en memoria en la que se almaceno
  dicho número*/
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int Numero; //Declaramos una variable tipo entera
	int *Direc_Numero; //Como la variable aterior es entera, el puntero tambien lo será
	cout<<"Digite un numero entero"<<endl;
	cin>>Numero;
	Direc_Numero = &Numero; //Aqui almacenamos el número dentro del puntero
	cout<<"El numero que ingreso es:  "<<*Direc_Numero<<endl;
	cout<<"La posicion del numero en la memoria es:  "<<Direc_Numero<<endl;
	
	getch();
	return 0;
}
