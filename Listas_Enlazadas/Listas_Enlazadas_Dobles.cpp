#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{
	int dato;
	nodo* siguiente;
	nodo* atras;
};
nodo *primero;
nodo *ultimo;

//Funciones 

void insertarNodo();
void eliminarNodo();
void MostrarListaPU();
void MostrarListaUP();

int main(int argc, char** argv) {
	
		int op=0;
	do
	{
		cout << "\n 1. Insertar";
		cout << "\n 2. Mostrar del Primero al Ultimo";
		cout << "\n 3. Mostrar del Ultimo al Primero";
		cout << "\n 4. Eliminar ";
		cout << "\n 5. Salir";
		cout << "\n\n Elija una Opcion: ";
		cin >> op;
		
		switch(op){
			
		case 1:
			cout << "\n\n Insertar a la Lista \n\n";
			insertarNodo();
			break;
			
		case 2:
			cout << "\n\n Mostrar Lista del Primero al Ultimo \n";
			MostrarListaPU();
			break;
			
		case 3:
			cout << "\n\n Mostrar Lista del Ultimo al Primero\n";
			MostrarListaUP();
			break;
			
		case 4:
			cout << "\n\n Eliminar un Nodo de la Lista \n\n";
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
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato: ";
	cin >> nuevo->dato;
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}
	cout << "\n Dato Ingresado\n\n";
}


void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato a Eliminar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		
		while(actual!=NULL && encontrado!=true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado";
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				
				cout << "\n Nodo Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}
		
	}else{
		cout << "\n La listas se esta Vacia\n\n";
	}
}

//Del primero al ultimo
void MostrarListaPU(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		
		while(actual!=NULL){
			cout << "\n " << actual->dato; 
			actual = actual->siguiente;
		}
		
	}else{
		cout<< "\n La listas se encuentra Vacia\n\n";
	}
	cout<< "\n";
}


//Del ultimo al primero
void MostrarListaUP(){
	nodo* actual = new nodo();
	actual = ultimo;
	if(primero!=NULL){
		
		while(actual!=NULL){
			cout << "\n " << actual->dato; 
			actual = actual->atras;
		}
		
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	
	cout<< "\n";
}


