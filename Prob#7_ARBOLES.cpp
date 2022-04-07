//Problema# 7.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<iostream>
using namespace std;
//creamos el nodo
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
//Prototipos de las funciones
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void menu();
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *, int);	
Nodo *arbol =NULL;

//Ponemos la funcion principal
int main(){
	
	menu();
	getch();
	return 0;
	
}

//Desarrollamos el menu
void menu(){
	int dato, opcion, contador=0;
	
	do{
		cout<<"                OPERACIONES EN UN ARBOL           "<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"Que operacion decea realizar en el arbol? "<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar los elementos del arbol"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Opcion ";
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				printf("Digite un numero:");
					scanf("%d",&dato);
					insertarNodo(arbol,dato); //Insertamos un nuevo nodo
					printf("\n");
					system("pause");
					break;
			case 2:
			cout<<"El arbol que inserto es el siguiente: "<<endl;
			mostrarArbol(arbol,contador);
			printf("\n \n");
			system("pause");
			break;
			case 3:
				    cout<<"Digite el elemento que desea buscar"<<endl;
				    cin>>dato;
				    if(busqueda(arbol,dato)==true){
				    	cout<<"El elemento "<<dato<<" si se encuentra en el arbol"<<endl;
					} else{
						cout<<"El elemento "<<dato<<" no se encuentra en el arbol"<<endl;
					}
					cout<<"\n";
					system("pause");
					break;
					
					
		}
		system("cls");
	}while(opcion != 4);
}

//Funcion para crear un nuevo nodo

 Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
		
	nuevo_nodo->dato =n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;	
		
		return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n){
	if(arbol==NULL){ //Si el arbol esta vacio
		struct Nodo *nuevo_nodo = crearNodo(n);
		arbol=nuevo_nodo;
	}
	else{//Si el arbol tiene uno o mas de un nodo
	int valorRaiz = arbol ->dato; //Obtener valor de la raiz
	if(n<valorRaiz){ //Si el elemento es menor a la raiz, insertamos en la izq
		insertarNodo(arbol->izq,n);
	}
	else{ //sI EL ELEMENTO ES MAYOR A LA RAIZ
	insertarNodo(arbol->der,n);
	}
	
	}
}

//Funcion para mostrar arbolcompleto

void mostrarArbol(Nodo *arbol,int contador){
	if(arbol==NULL){
		return;
		
	}
	else{
		mostrarArbol(arbol ->der,contador+1);
		for(int i=0;i<contador;i++){
			printf("   ");
		}
		printf("%d     \n",arbol->dato);
		mostrarArbol(arbol->izq,contador+1);
	}
}
//Funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol, int n){
	if (arbol == NULL){ //para cuando el arbol este vacio
	 	return false;
	} else if(arbol ->dato == n){
		return true;
	} else if(n < arbol->dato){
		return busqueda(arbol->izq,n);
	} else{
		return busqueda(arbol->der,n);
	}
}

