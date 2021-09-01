#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;
};

nodo *primero;
nodo *ultimo;

void insertarNodo();
void MostrarLista();
void eliminarNodo();

int main(){
	
	int op=0;
	do
	{
		cout << "\n 1. Insertar";
		cout << "\n 2. Mostrar Lista";
		cout << "\n 3. Eliminar Nodo";
		cout << "\n 4. Salir";
		cout << "\n\n ELija una Opcion: ";
		cin >> op;
		
		switch(op){
		case 1:
			cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
			insertarNodo();
			break;
		case 2:
			cout << "\n\n MOSTRAR LISTA";
			MostrarLista();
			break;
		case 3:
			cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
			eliminarNodo();
			break;
		case 4:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (op != 4);
	
	return 0;
}
				
 
void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato nuevo: ";
	cin >> nuevo->dato; 
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	cout << "\n Dato Ingresado\n\n";
}

// lista circular simple                    45 -> 15 -> 89 -> 12 -> primero  

void MostrarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato;
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
	cout << "\n ";
}


void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "\n Ingrese el dato del nodo a Eliminar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato == nodoBuscado){
				cout << "\n El nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				
				if(actual==primero){
					primero = primero->siguiente;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					anterior->siguiente = primero;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				cout << "\n Nodo Eliminado\n\n";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}




