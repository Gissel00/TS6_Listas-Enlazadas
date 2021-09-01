#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Nodo{
	int dato;
	Nodo* siguiente;
	Nodo* atras;
};

Nodo *primero;
Nodo *ultimo;

//Funciones
void insertarNodo();
void eliminarNodo();
void MostrarListaPU();
void MostrarListaUP();

int main(int argc, char** argv){
	int op=0;
	do
	{
		cout << "\n 1. Insertar";
		cout << "\n 2. Mostar del Primero al Ultimo";
		cout << "\n 3. Mostrar del Ultimo al Primero ";
		cout << "\n 4. Eliminar Nodo";
		cout << "\n 5. Salir";
		cout << "\n\n Elija una Opcion: ";
		cin >> op;
		switch(op){
			
		case 1:
			cout << "\n\n Insertar nodo a la Lista \n\n";
			insertarNodo();
			break;
		case 2:
			cout << "\n\n Mostrar Lista del Primero al Ultimo \n";
			MostrarListaPU();
			break;
		case 3:
			cout << "\n\n Mostrar Lista del Ultimo al Primero \n";
			MostrarListaUP();
			break;
		case 4:
			cout << "\n\n Elimar Nodo de la Lista \n\n";
			eliminarNodo();
			break;
			
		case 5:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (op != 5);
	
	return 0;
}

void insertarNodo(){
	Nodo* nuevo = new Nodo();
	cout << "Ingrese el dato:  ";
	cin >> nuevo->dato;
	
	if(primero==NULL){
		primero = nuevo;
		ultimo = nuevo;
		primero->siguiente = primero;
		primero->atras = ultimo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->atras = ultimo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
	cout << "\n Nodo Ingresado\n\n";
	
}

// lista circular doble  =  (12) <- 67 -> <- 45 -> <- 8 -> <- 12 -> (67)

void eliminarNodo(){
	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* anterior = new Nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a  Eliminar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato==nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado";
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = ultimo;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					ultimo = anterior;
					ultimo->siguiente = primero;
					primero->atras = ultimo;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				
				cout << "\n Nodo Eliminado\n\n";
				encontrado = true;				
			}
			
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}
		
	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

//De primero al ultimo

void MostrarListaPU(){
	Nodo* actual = new Nodo();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato; 
			actual = actual->siguiente;
		}while(actual!=primero);
		
	}else{
		cout << "\n La lista esta Vacia\n\n";
	}
	cout << "\n ";
}

//del ultimo al primero

void MostrarListaUP(){
	Nodo* actual = new Nodo();
	actual = ultimo;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato; 
			actual = actual->atras;
		}while(actual!=ultimo);
		
	}else{
		cout << "\n La lista esta Vacia\n\n";
	}
	
	cout << "\n ";
}


