/*Problema#3. Diseñar un programa en el cual se muestre un menú 
con los siguientes puntos para una PILA:
1ro. Insertar un elemento a la pila
2do. Mostrar los elementos de la pila.
Ejecutar el programa e insertar los siguientes datos: 
12, 15, 3, 10, 21, 57, luego mostrar el orden en el salen los mismos.*/
#include<iostream>
#include<conio.h>
#include<stdlib.h> //Para usar la funcion "new"
using namespace std;
//Comenzamos creando el nodo
struct Nodo{
	int dato;
	Nodo *siguiente;	
};

//Prototipos de funciones
void menu();
void agregarPila(Nodo *&,int);//para insertar elementos(nodos) a la pila
void sacarPila(Nodo *&,int &);//para quitar elementos(nodos) a la pila
//Ponemos la funcion principal
int main(){
	menu();
	getch();
	return 0;
}
//Aqui desarrollamos el menú
void menu(){
	Nodo *pila = NULL;
	int opcion;
	int dato;
	
	do{
		cout<<"                   OPERACIONES EN UNA PILA              "<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"Que operacion decea realizar en la pila?"<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"1. Insertar un numero a la pila"<<endl;
		cout<<"2. Mostrar todos los elementos de la pila"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"Digite el numero que se ingresara a la pila:  "<<endl;
					cin>>dato;
					agregarPila(pila,dato);
					break;
			case 2: cout<<"Mostrando todos los elementos de la pila: "<<endl;
					while(pila != NULL){
						sacarPila(pila,dato);
						if(pila != NULL){
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
		system("cls"); //limpiar pantalla
	}while(opcion != 3);
	
}
//Funcion para agregar elementos a la pila
void agregarPila(Nodo *&pila,int n){
	//1er paso: Crear un espacio en memoria para almacenar un nodo
	Nodo *nuevo_nodo = new Nodo();
	//2do paso: Cargar el valor dentro del nodo(dato)
	nuevo_nodo->dato = n;
	//3er paso: Cargar el puntero pila dentro del nodo(*siguiente)
	nuevo_nodo->siguiente = pila;
	//4to paso: Asignar un nuevo nodo a pila
	pila = nuevo_nodo;
}
//Funcion para quitar elements de la pila
void sacarPila(Nodo *&pila,int &n){
	//1er paso: Crear una variable auxiliar del tipo nodo (*aux)
	Nodo *aux = pila;
	//2do paso: Igualar el n a aux -> dato
	n = aux->dato;
	//3er paso: Pasar pila a siguiente nodo
	pila = aux->siguiente;
	//4to paso: Eliminar aux
	delete aux;
}
//Fin del programa
