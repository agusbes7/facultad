#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;
#define n 50
struct Nodo{
	char nombre[50];
	int edad;
	Nodo* ptrSig=NULL;
	Nodo*ptrAnt=NULL;
};
struct list{
	list* ptrsig;
	int numero;
};

void mostrarNodo(Nodo a){
	cout<<"Nombre: "<<a.nombre<<endl;
	cout<<"Edad: "<<a.edad<<endl;
}
void agregarNodofinal(Nodo *P){
	Nodo *L=P;
	while(L->ptrSig!=NULL){L=L->ptrSig;}
	Nodo *s=NULL;
	s=new Nodo;
	if(s!=NULL){
	cout<<"edad: ";
	cin>>s->edad;
	s->ptrAnt=NULL;
	s->ptrSig=NULL;
	cout<<endl<<"nombre: ";
	cin>>ws;
	cin.getline(s->nombre,n);	
	L->ptrSig=s;
}
	else{
		cout<<"fallo la asignacion de memoria"<<endl;}
	}
	void agregarNodofinalRecursivo(Nodo *P){
		if(P->ptrSig==NULL){
			Nodo *ptr=new Nodo;
			ptr->edad=25;
			strcpy(ptr->nombre,"hola mundo");
			ptr->ptrSig=NULL;
			P->ptrSig=ptr;
		}
		else{
			agregarNodofinalRecursivo(P->ptrSig);
		}
		
	}
	void mostrarNodos(Nodo *P){
	Nodo *aux=P;
while(aux!=NULL){
	mostrarNodo(*aux);
	aux=aux->ptrSig;
}}

void agregarNodoinicio(Nodo ** L);
void insertarIndex(Nodo * L,int index);
void borrarFinal(Nodo *L);
void borrarInicio(Nodo **L);
void borrarIndex(Nodo *L,int index);
void imprimirInverso(Nodo *L);
void borrarLista(Nodo *L);
void borrarListaInverso(Nodo *L);
int menorLista(list *a);
void insertarOrden(Nodo **L,Nodo *a);
int main(int argc, char *argv[]) {
//Crear el nodo del primer elemento y su puntero maestro
	Nodo *L = NULL;
	
	// Agregar primer elemento
	L = new Nodo;
	L->edad = 23;
	strcpy(L->nombre, "Berso Roberto");
	L->ptrSig = NULL;
	
	// Agregar segundo elemento
	Nodo *ptr = new Nodo;
	if (ptr != NULL) {
		ptr->edad = 27;
		strcpy(ptr->nombre, "Ofman Juli");
		insertarOrden(&L, ptr);
	} else {
	cout << "Falla de asignacion" <<endl;
	}
	
	// Agregar tercer elemento
	Nodo *ptr2 = new Nodo;
	if (ptr2 != NULL) {
		ptr2->edad = 27;
		strcpy(ptr2->nombre, "Altman Juli");
		insertarOrden(&L, ptr2);
	} else {
		cout << "Falla de asignacion" <<endl;
	}
	
	// Mostrar los nodos
	cout << endl;
	imprimirInverso(L);
	
	return 0;}
//---------------------------------------------------------------			
void agregarNodoinicio(Nodo **L){
	
	Nodo *ptr = *L;
	*L = new Nodo;
	if(*L != NULL){
		cout << "edad: ";
		cin >> (*L)->edad;
		cout << endl << "nombre: ";
		cin >> ws;
		cin.getline((*L)->nombre, n);   
		(*L)->ptrSig = ptr;
	} else {
		cout << "fallo la asignacion de memoria" << endl;
	}
}
void borrarInicio(Nodo **L){
	
	Nodo *siguiente=(*L)->ptrSig;
	delete *L;
	*L=siguiente;
	
	
}
	void borrarFinal(Nodo *L){
		if (L == NULL) {
			cout << "La lista está vacía, no hay nada que borrar." << endl;
			return;}
		if (L->ptrSig == NULL) {
			// La lista tiene solo un nodo.
			delete L;
			L = NULL;
			return;}
		
		Nodo *ptr = L;
		Nodo *anterior = NULL;
		
		while (ptr->ptrSig != NULL) {
			anterior = ptr;
			ptr = ptr->ptrSig;}
		
		// En este punto, `ptr` apunta al último nodo y `anterior` al penúltimo nodo.
		anterior->ptrSig = NULL;
		delete ptr;
	}
		
bool orden(char a[],char b[]){
string c,d;
c=string(a);
d=string(b);
return (c>d);}

void insertarOrden(Nodo **L,Nodo * a){
	Nodo *aux=*L,*anterior=NULL;
	
if(aux==NULL){
		*L=a;
		(*L)->ptrSig=NULL;
return ;}

	while(aux!=NULL and orden(a->nombre,aux->nombre)){
		anterior=aux;
		aux=aux->ptrSig;}
if(anterior==NULL){ 
	a->ptrSig=*L;
	*L=a;
	}
else{
	anterior->ptrSig=a;
	a->ptrSig=aux;
}}
	
void borrarLista(Nodo **L){
	Nodo *aux=*L;
	
	while(aux!=NULL){
		aux=(*L)->ptrSig;
		delete (*L);
		(*L)=aux;
	}}
void borrarListaInverso(Nodo **L){
	
	if((*L)==NULL){return;}
	if((*L)->ptrSig==NULL){
		delete (*L);
		(*L)=NULL;
	}
	else{
		
		borrarListaInverso(&(*L)->ptrSig);
		delete (*L);
		(*L)=NULL;	}
}
void imprimirInverso(Nodo *L){
	
	if(L==NULL){return;}
	if(L->ptrSig==NULL){
		mostrarNodo(*L);}
	else{
		imprimirInverso(L->ptrSig);
		mostrarNodo(*L);
	}
}
void Borrar(Nodo **L,char nombre[]){
	Nodo *aux=*L,*anterior=NULL;
	if((*L)==NULL){return;}
	
	while(aux!=NULL and 0!=strcmp(nombre,aux->nombre)){
		anterior=aux;
		aux=aux->ptrSig;}
	if(aux==NULL){ cout<<"No existe el nombre a borrar"<<endl;
	return;}
	
	if(anterior==NULL and strcmp(nombre,aux->nombre)==0){
		delete aux;
		aux=NULL;}
	else{
		if(aux!=NULL and strcmp(nombre,aux->nombre)==0){
			anterior->ptrSig=aux->ptrSig;
			delete aux;
		aux=NULL;}
		}
	}
void cargar(Nodo **L){
	
	ifstream f;
	f.open("info.bin",ios::binary);
	if(!f.fail()){
	Nodo *aux=NULL, *guia=*L;
f.seekg(0,ios::beg);
bool r=true;
while(f.read((char *)L,sizeof(*L)) and r){
	aux=new Nodo;
	r=false;
	if(aux!=NULL}){
	aux=f;
	aux->ptrSig=NULL;
	guia->ptrSig=aux;
	guia=guia->ptrSig;
	r=true;}
	}
	else{cout<<"falla de apertura";
	
	
	
void nodo(Nodo **P){
		
	if((*P)==NULL){ cargar(P);}
	Nodo *anterior=aux;
	Nodo *aux=(*L);
	while(aux!=NULL){ cargar
		anterior=aux;
		aux=aux->ptrSig;}
	
	if(anterior==NULL){
		cargar(&aux);}
	else{
		cargar(&anterior);}}
#include <iostream>
#include <fstream>
	using namespace std;
	
	struct Turno {
		int numero;
		char tipo;
	};
	
	struct NodoTurno {
		Turno t;            // Información del turno
		NodoTurno* sig;     // Apuntador al siguiente nodo
	};
	
	// Función para crear una lista vacía
	NodoTurno* crearVacia() {
		return nullptr;  // Lista vacía
	}
	
	// Función para cargar los datos desde un archivo binario a una lista enlazada
	void cargar(NodoTurno** L) {
		ifstream f("info.bin", ios::binary);  // Abrir el archivo binario
		if (!f.fail()) {
			NodoTurno* aux = nullptr;
			NodoTurno* guia = *L;
			bool primerNodo = true;  // Para saber si es el primer nodo
			
			while (f.read((char*) &aux->t, sizeof(Turno))) {  // Leer un Turno
				aux = new NodoTurno;  // Crear un nuevo nodo
				aux->sig = nullptr;  // El nuevo nodo no tiene siguiente
				
				// Si es el primer nodo, lo asignamos a L
				if (primerNodo) {
					*L = aux;   // Apuntamos L al primer nodo
					primerNodo = false;
				} else {
					guia->sig = aux;  // Conectamos el nodo anterior con el nuevo
				}
				
				guia = aux;  // Desplazamos la guía al último nodo
			}
			
			f.close();  // Cerrar el archivo
		} else {
			cout << "Fallo la apertura del archivo" << endl;
		}
	}
	
	// Función para imprimir la lista (solo para verificar)
	void imprimirLista(NodoTurno* L) {
		while (L != nullptr) {
			cout << "Turno " << L->t.numero << " Tipo " << L->t.tipo << endl;
			L = L->sig;
		}
	}
	
	int main() {
		NodoTurno* lista = crearVacia();  // Crear una lista vacía
		cargar(&lista);  // Cargar datos desde el archivo
		imprimirLista(lista);  // Imprimir los datos cargados
		return 0;
	}
	
	
