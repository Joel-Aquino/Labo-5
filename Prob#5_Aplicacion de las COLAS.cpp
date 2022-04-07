/*Problema #5. Hacer un programa para almacenar los datos de una compra 
realizada de un electrodoméstico en una COLA, tal que se muestren el 
nombre del comprador, el producto que adquirió, la marca del producto, y el 
precio en Bs. Todos estos puntos deben ser mostrados en pantalla según 
el orden de compra que se realizaron.*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//Creamos el nodo para los datos del comprador
struct Comprador{
	char nombre_cliente[30];
	char tipo_de_producto[30];
	char marca[30];
	int precio;
};
//Creamos el nodo para la cola
struct Nodo{
	Comprador c;
	Nodo *siguiente;	
};

//Prototipos de Funciones
void cargar_comprador(Comprador &);
void insertarCola(Nodo *&,Nodo *&,Comprador);
bool cola_vacia(Nodo *);
void quitarCola(Nodo *&,Nodo *&,Comprador &);
//Ponemos la funcion principal
int main(){
	cout<<"         APLICACION DE LAS COLAS        "<<endl;
	cout<<"\n";
	cout<<"\n";
	Nodo *frente = NULL;//Nodo para el inicio de la cola
	Nodo *fin = NULL;//Nodo para el fin de la cola
	Comprador c;
	char rpt;
	
	do{
		cargar_comprador(c); //Cargamos los datos del comprador
		insertarCola(frente,fin,c); //luego lo agregamos a la cola
		cout<<"Desea agregar mas datos? (si/no): ";
		cin>>rpt;
		cout<<"\n";
	}while(rpt == 'S' || rpt == 's');
	
	cout<<"      MOTRANDO LOS DATOS DE LAS VENTAS REALIZADAS:     "<<endl;
	cout<<"\n";
	cout<<"\n";
	while(frente != NULL){
		quitarCola(frente,fin,c);
		//Mostramos los datos de una compra realizada
		cout<<"Nombre del Cliente:"<<c.nombre_cliente<<endl;
		cout<<"Tipo de producto adquirido: "<<c.tipo_de_producto<<endl;
		cout<<"Marca del producto: "<<c.marca<<endl;
		cout<<"Precio del producto: "<<c.precio<<"Bs."<<endl;
		cout<<"\n";		
	}	
	
	getch();
	return 0;
}

void cargar_comprador(Comprador &c){
	fflush(stdin);
	cout<<"Agregando nuevos datos de la compra:  "<<endl;
	cout<<"\n";
	cout<<"\n";
	cout<<"Nombre del cliente: "; cin.getline(c.nombre_cliente,30,'\n');
	cout<<"Tipo de producto adquirido: "; cin.getline(c.tipo_de_producto,30,'\n');
	cout<<"Marca del producto: "; cin.getline(c.marca,30,'\n');
	cout<<"Precio del producto en Bs.: "; cin>>c.precio;
	cout<<"\n";
} 

void insertarCola(Nodo *&frente,Nodo *&fin,Comprador c){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->c = c;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}

void quitarCola(Nodo *&frente,Nodo *&fin,Comprador &c){
	c = frente->c;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	
	delete aux;
}
