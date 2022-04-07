/* Problema#6. Diseñar un programa en el cual se muestre un 
menú con los siguientes puntos para una LISTA:
1ro. Insertar un elemento a una lista
2do. Mostrar los elementos de la lista.
3ro. Buscar un elemento de la lista.
4to. Eliminar un elemento de la lista.
5to. Vaciar la lista
Ejecutar el programa e insertar los siguientes datos: 
12, 25, 3, 9, 10,33. Ejecutar el programa y mostrarlos en orden, luego 
buscar los números 12, 9, 100, 7. Eliminar los números 12, 33 y 60. 
Luego mostrar los que quedan en orden. 
Para finalizar mostrar la lista vacia.*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//Creamos el nodo
struct Nodo{
	int dato;
	Nodo *siguiente;
};
//Prototipos de funciones
void menu();
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void eliminarLista(Nodo *&, int&);

Nodo *lista = NULL;
//Ponemos la funcion principal
int main(){
	int dato;
	menu ();
	getch ();
	return 0;
}
//Desarrollamos el menu
void menu(){
	int opcion, dato;
	do{
		cout<<"                  OPERACIONES EN UNA LISTA              "<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"Que operacion decea realizar en una lista? "<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"1. Insertar elementos a una lista"<<endl;
		cout<<"2. Mostrar elementos de una lista"<<endl;
		cout<<"3. Buscar un elemento de la lista"<<endl;
		cout<<"4. Eliminar un elemento de la lista"<<endl;
		cout<<"5. Vaciar la lista"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"Opcion"<<endl;
		cin>>opcion;
		switch (opcion){
			case 1:
				cout<<"digite un numero"<<endl;
				cin>>dato;
				insertarLista(lista, dato);
				cout<<"\n";
				system ("pause");
				break;
			case 2:
			 	mostrarLista(lista);
			 	cout<<"\n";
				system ("pause");
				break;
			case 3:
				cout<<"digite el numero que desea buscar en la lista"<<endl;
				cin>>dato;
				buscarLista(lista, dato);
				cout<<"\n";
				system ("pause");
				break;
			case 4:
				cout<<"digite el numero que desea eliminar de la lista"<<endl;
				cin>>dato;
				eliminarNodo(lista, dato);
				cout<<"\n";
				system ("pause");
				break;
			case 5:
				while (lista != NULL){
					eliminarLista(lista, dato);
					cout<<dato<<" -> ";
				}
				cout<<"\n";
				system ("pause");
				break;
			
		}
		system ("cls");
	} while(opcion != 6);

}
//Funcion para insertar elementos a la lista
void insertarLista(Nodo *&lista, int n){
//1er paso: Crear un nuevo nodo
Nodo *nuevo_nodo = new Nodo();
//2do paso: Asignar a nuevo_nodo -> dato, el elemento que queremos incluir en la lista
nuevo_nodo -> dato = n;
//3er paso: Crear dos nodos auxiliares y asignar lista al primero de ellos
Nodo *aux1 = lista;
Nodo *aux2;
//4to paso: Insertar el elemento a la lista
while ((aux1 != NULL) && (aux1-> dato < n)){
	aux2 = aux1;
	aux1 = aux1 ->siguiente;
} if (lista == aux1){
	lista = nuevo_nodo;
} else{
	aux2 -> siguiente = nuevo_nodo;
}
	nuevo_nodo -> siguiente = aux1;	
	cout<<"Elemento: "<<n<<" insertado a lista correctamente"<<endl;
}
//funcion para mostrar los elementos de la lista.
void mostrarLista(Nodo *lista){
	//1er paso:Crear un nuevo nodo(actual)
	Nodo *actual = new Nodo();
	//2do paso: Igualar ese nuevo nodo(actual) a lista
		actual = lista;
	//3er paso: Recorrer la lista de inicio a fin.
	while (actual != NULL){
		cout<<actual->dato<<" -> ";
		actual = actual -> siguiente;
	}
}
//Funcion para buscar un elemento de la lista
void buscarLista(Nodo *lista, int n){
	bool band = false;
	//1er paso:Crear un nuevo nodo(actual)
	Nodo *actual = new Nodo();
	//2do paso : Igualar ese nuevo nodo(actual) a lista
		actual = lista;
	//3er paso : Recorrer la lista
	while ((actual != NULL) && (actual -> dato <= n)){
	//4to paso (dentro del paso 3): Determinar si el elemento existe o no en la lista.
		if (actual -> dato == n){
			band = true;
		}
		actual = actual -> siguiente;
	} if (band == true){
		cout<<"El numero "<<n<<" si se encuentra en la lista"<<endl;
	} else{
		cout<<"El numero "<<n<<" no se encuentra en la lista"<<endl;
	}
}
//Funcion para eliminar un elemento de la lista
void eliminarNodo(Nodo *&lista, int n){
	//1er paso: Preguntar si la lista "no" está vacía
	if(lista != NULL){
	//2do paso /dentro del paso 1):Crear un *aux_borrar y *anterior = NULL
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
	//3er paso: Igualar *aux_borrar al inicio de la lista
	    aux_borrar = lista;
	//4to paso: Recorrer la lista
		while ((aux_borrar != NULL) && (aux_borrar -> dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> siguiente;	
		}
	//5to paso: Eliminar el elemento
	//Caso de que el elemento no haya sido encontrado
		if (aux_borrar == NULL){
			cout<<"El elemento que digito no ha sido encontrado"<<endl;
		} else if (anterior == NULL){//Para cuando el elemento a eliminar sea el primero
			cout<<"El elemento que digito ha sido encontrado y eliminado exitosamente"<<endl;
			lista = lista -> siguiente;
			delete aux_borrar;
			
		} else {//para cuando el elemento a eliminar no sea el primero
			anterior -> siguiente = aux_borrar -> siguiente;
			delete aux_borrar;
		}
	}
}
//Funcion para eliminar todos los elementos de una lista.
void eliminarLista(Nodo *&lista, int &n){
	//1er paso: Crear un nodo *aux e igualarlo al inicio de la lista.
	Nodo *aux = lista;
	//2do paso: Guardar el dato que queremos eliminar dentro de *aux
	n = aux -> dato;
	//3er paso: Pasar lista a siguiente nodo
	lista = aux -> siguiente;
	//4to paso: Eliminar aux
	delete aux; 
	
}
