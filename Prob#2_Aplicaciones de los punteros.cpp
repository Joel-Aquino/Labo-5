/*Problema#2 1.	2.	Diseñar un programa, tal que dado un numero entero. 
Escriba en pantalla si el mismo es par o impar además mostrar su ubicación 
en memoria. (Usando punteros)*/
 #include<iostream>
 #include<conio.h>
 using namespace std;
 
 int main(){
 	int Num, *direc_Num; //declaramos variables
 	cout<< "                   APLICACION DE LOS PUNTEROS          "<<endl;
 	cout<<"\n";
	cout<<"\n";
	cout<<    "                 MOSTRAR SI UN NUMERO ES PAR O IMPAR            "<<endl;
	cout<<"\n";
	cout<<"\n";
	cout<<"Digite un numero"<<endl;
	cin>>Num;
	direc_Num = &Num;
	if(*direc_Num%2 == 0){
		cout<<"El numero que digito es par y su posicion en memoria es: "<<direc_Num<<endl;
	
	} else{
		cout<<"El numero que digito es impar y su posicion en memoria es: "<<direc_Num<<endl;
	}
	
 	
 	
 	getch();
 	return 0;
 	
 }
