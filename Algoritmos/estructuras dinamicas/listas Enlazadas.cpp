#include <iostream>
using namespace std;
//USAREMOS UNA ESTRUCTURA SIMPLE PARA PONER A PRUEBA TODAS LAS OPERACIONES
#define tam 20
struct Nodo{
	int dato;
	Nodo * sig;
};
typedef Nodo *ptr;

void agregarInicio(ptr * L,int valor);
void agregarFinal(ptr * L,int valor);
void insercionOrdenada(ptr * L,int valor);
void mostrarTodos(ptr L);
void borraFinal(ptr *L);
void borraInicio(ptr *L);
void borrarL(ptr * L,int valor);
int menor(ptr L);
void imprimirInverso(ptr L);
void borrarL(ptr *L);

//---------------------------------------------
int main(int argc, char *argv[]) {
	ptr L=NULL, aux,nuevo;
	agregarInicio(&L,8);
	insercionOrdenada(&L,6);
	mostrarTodos(L);
	insercionOrdenada(&L,65);
	insercionOrdenada(&L,25);
	mostrarTodos(L);
	insercionOrdenada(&L,10);
	mostrarTodos(L);
	insercionOrdenada(&L,32);

/*	agregarInicio(&L,5);
	agregarFinal(&L,6);
	agregarInicio(&L,3);
	agregarInicio(&L,2);
	agregarInicio(&L,1);
	agregarFinal(&L,7);
	agregarFinal(&L,8);
	agregarInicio(&L,4);
	insercionOrdenada(&L,3);
	borraFinal(&L);*/

	mostrarTodos(L);
	borrarL(&L,10);	
	mostrarTodos(L);
	cout<<"menor: "<<menor(L)<<endl;
/*imprimirInverso(L);
borrarL(&L);
mostrarTodos(L);*/
	return 0;
}
//---------------------------------------------
void agregarInicio(ptr * L,int valor){
	ptr aux=*L;
	(*L)=new Nodo;
	if((*L)==NULL){
		cout<<"Error..."<<endl;}
	else{
	(*L)->dato=valor;
	(*L)->sig= aux;
	}}
	//---------------------------------------------	
void agregarFinal(ptr *L,int valor){
	ptr aux=*L;
	while(aux->sig!=NULL){
		aux=aux->sig;}
	ptr nuevo=new Nodo;
	if(nuevo!=NULL){
		nuevo->dato=valor;
		nuevo->sig=NULL;
		aux->sig=nuevo;
	}
	else{cout<<"error...";}}
	
//---------------------------------------------
void borraInicio(ptr *L){
ptr aux=(*L)->sig;
delete *L;
(*L)=aux;}
//---------------------------------------------
void borraFinal(ptr *L){
ptr aux=*L,anterior;
while(aux->sig!=NULL){
anterior=aux;			aux=aux->sig;}
anterior->sig=NULL;
delete aux;}
//---------------------------------------------	
void mostrarTodos(ptr L){
	if(L==NULL){cout<<"lista vacia..."<<endl; return ;}
	while(L!=NULL){
		cout<<L->dato<<" - ";
		L=L->sig;	}
cout<<endl;}
//---------------------------------------------
int menor(ptr L){
	int menor=L->dato;
	ptr aux=L->sig;
	while(aux!=NULL){
		if(menor>aux->dato){menor=aux->dato;}
		aux=aux->sig;
	}
return menor;}
	

//-----------------------------------
	void imprimirInverso(ptr L){
		
	if(L->sig==NULL){ cout<<L->dato<<"-";}
	else{
		imprimirInverso(L->sig);
		cout<<L->dato<<"-";
	}}

void borrarL(ptr *L){
	ptr aux=*L;
	while(aux!=NULL){
		aux=(*L)->sig;
		delete *L;
		*L=aux;
	}
}
	void borrarL(ptr *L, int valor){
		ptr aux=*L;
		if(aux->dato==valor){borraInicio(L);}
		ptr anterior=aux,temporal;
		while(aux!=NULL and aux->dato!=valor){
			anterior=aux;
			aux=aux->sig;}
		
			if(aux->dato==valor){
				anterior->sig=aux->sig;
				delete aux;
				aux=NULL;}
			else{cout<<"no existe el dato";}
				
			}
		
		
		
		
	
void insercionOrdenada(ptr *L,int valor){
	ptr aux=*L;
	ptr anterior=aux,tmpr;
	if(aux->dato>=valor){
	agregarInicio(&(*L),valor);
		return;}
	

	int insercion=-1;
	aux=aux->sig;
	while(aux!=NULL  and insercion==-1){
		if(aux->dato>=valor){
			insercion=1;
			tmpr=new Nodo;
			tmpr->dato=valor;
			anterior->sig=tmpr;
			tmpr->sig=aux;
			
		}
		else{
			anterior=aux;
			aux=aux->sig;
		}
	}
	if(aux==NULL){
		tmpr=new Nodo;
		tmpr->dato=valor;
		anterior->sig=tmpr;
		tmpr->sig=NULL;
	}

}
		
