/*Problema#1.Dise�e un programa tal que, dado un n�mero entero, lo muestre
 en pantalla y adem�s muestre la ubicaci�n en memoria en la que se almaceno
  dicho n�mero*/
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int Numero; //Declaramos una variable tipo entera
	int *Direc_Numero; //Como la variable aterior es entera, el puntero tambien lo ser�
	cout<<"Digite un numero entero"<<endl;
	cin>>Numero;
	Direc_Numero = &Numero; //Aqui almacenamos el n�mero dentro del puntero
	cout<<"El numero que ingreso es:  "<<*Direc_Numero<<endl;
	cout<<"La posicion del numero en la memoria es:  "<<Direc_Numero<<endl;
	
	getch();
	return 0;
}
