/*Problema#4. Diseñar un programa en el cual se muestre un menú 
con los siguientes puntos para una COLA:
1ro. Insertar un elemento a una cola
2do. Mostrar los elementos de la cola.
Ejecutar el programa e insertar los siguientes datos:1, 2, 3, 4, 5*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>//Para usar la funcion "new"
using namespace std;
//Comenzamos creando el nodo
struct Nodo{
	int dato;
	Nodo *siguiente;	
};

//Prototipos de Funciones
void menu();
void insertarCola(Nodo *&,Nodo *&,int);//para insertar un elem. a la cola
bool cola_vacia(Nodo *);//para saber si la cola esta o no vacia
void quitarCola(Nodo *&,Nodo *&,int &);//para quitar elementos de la cola
//Ponemos la funcion principal
int main(){
	menu();
	getch();
	return 0;
}
//Aqui desarrollamos el menu
void menu(){
	int opcion;
	int dato;
	Nodo *frente = NULL;//Nodo para el inicio de la cola
	Nodo *fin = NULL;//Nodo para el fin de la cola
	do{
		cout<<"                 OPERACIONES EN UNA COLA                  "<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"Que operacion decea realizar en la cola?"<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"1. Insertar un numero a una cola"<<endl;
		cout<<"2. Mostrar todos los elementos de la cola"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion; 
		
		switch(opcion){
			case 1: cout<<"Ingrese el numeroque se ingresara a la cola: ";
					cin>>dato;
					insertarCola(frente,fin,dato);
					break;
			case 2: cout<<"Mostrando los elementos de la cola: ";
					while(frente != NULL){
						quitarCola(frente,fin,dato);
						if(frente != NULL){
							cout<<dato<<" , ";
						}
						else{
							cout<<dato<<".";
						}
					}
					cout<<"\n";
					system("pause");
					break;
			case 3: break;
		}
		system("cls");
	}while(opcion != 3);
}

//Función para insertar elementos en la cola
void insertarCola(Nodo *&frente,Nodo *&fin,int n){
	//1er paso:Crear espacio en memoria para almacenar el nodo
	Nodo *nuevo_nodo = new Nodo();
	//2do paso:Asignar a ese nuevo nodo al dato que queremos ingresar
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	//3er paso:Asignar los punteros "frente" y "fin" hacia el nuevo nodo
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

//Función para saber si la cola está vacia o no
bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false; 
}

//Función para eliminar elementos de una cola
void quitarCola(Nodo *&frente,Nodo *&fin,int &n){
	//1er paso: Obtener el valor del nodo
	n = frente->dato;
	//2do paso: Crear un nodo auxiliar (aux) y asignarle el frente de la cola
	Nodo *aux = frente;
	//3er paso: Eliminar el nodo del frente de la cola
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}
//Fin del programa 
