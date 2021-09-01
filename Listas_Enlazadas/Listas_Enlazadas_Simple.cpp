#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Nodo{
    private:
        string data;
    public:
        void insertarDatos();
        string mostrarDatos();
        Nodo *siguiente;
};
//FUNCIONES
void insertarLista(Nodo *&);
void mostrarLista(Nodo *);
void eliminarLista(Nodo *&);

//GLOBAL LISTA
Nodo *lista=NULL;

int main(int argc, char** argv) {
		
	int op=0;
	do
	{
		cout << "\n 1. Insertar Lista";
		cout << "\n 2. Mostrar Lista";
		cout << "\n 3. Eliminar Lista";
		cout << "\n 4. Salir";
		cout << "\n\n Elija una Opcion: ";
		cin >> op;
		
		switch(op){
		case 1:
			cout << "\n\n INSERTA EN LA LISTA \n\n";
			insertarLista(lista);
			break;
		case 2:
			cout << "\n\n MOSTRAR LISTA \n";
			mostrarLista(lista);
			break;
		case 3:
			cout << "\n\n ELIMINAR LISTA \n";
			 eliminarLista(lista);
			cout << "\nSe elimino de la lista \n";
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

void Nodo::insertarDatos(){
    cout<<"Ingrese la informacion: ";
    cin>>this->data;
    cout<<"Informacion registrada con exito!"<<endl;
}

string Nodo::mostrarDatos(){
    return this->data;
}

void insertarLista(Nodo *&lista){
    Nodo *nuevo_dato = new Nodo();
    nuevo_dato->insertarDatos();
    
    Nodo *a1 = lista;
    Nodo *a2;
    
    while(a1 != NULL){
        a2=a1;
        a1=a1-> siguiente;
    }
    
    if(lista == a1){
        lista=nuevo_dato;
    }else{
        a2->siguiente = nuevo_dato;
    }
    nuevo_dato->siguiente = a1;
    cout<<"Elemento insertado a la lista correctamente"<<endl;
}

void mostrarLista(Nodo *lista){
    Nodo *listado = new Nodo();
    listado =lista;
    int elemento=1;
    while(listado != NULL){
        cout<<elemento++<<"-"<<listado->mostrarDatos()<<endl;
        listado= listado->siguiente;
    }
    cout<<"\nFin de la lista"<<endl;
}

void eliminarLista(Nodo *&lista){
    Nodo *listado = lista;
    while(listado!=NULL){
        listado = lista->siguiente;
        delete lista;
        lista = listado;
    }
}

