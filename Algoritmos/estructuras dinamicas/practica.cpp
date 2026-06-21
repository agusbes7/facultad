#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
struct Nodo{
	int edad;
	char nombre[20];
	Nodo * sig;
};
typedef Nodo * Nptr;

Nodo inicializar();
void mostra(Nodo p);
void mostrar2(Nptr p);
void mostrarTodos(Nodo L);
void arregloDinamico(int x);
void matrizDinamica(int x);
void nombreDinamico(int x);
int main(int argc, char *argv[]) {
/*	Nptr L=NULL;
L= new Nodo;
if(L!=NULL){
	*(L)=inicializar();}
L->sig=new Nodo;
*(L)->sig=inicializar();
mostrar(*L);
mostrar2(L);
mostrarTodos(*L);*/
	
//	arregloDinamico(20);
//	nombreDinamico(40);
	//matrizDinamica(25);
	return 0;
}

Nodo inicializar(){
	Nodo p;
	cin>>p.edad;
	cin>>ws;
	cin.getline(p.nombre,20,'\n');
	p.sig=NULL;
	return p;
}
	void mostrar(Nodo p){
		
		cout<<"nombre: "<<p.nombre<<" edad: "<<p.edad<<endl;}
		void mostrar2(Nptr p){
			cout<<"nombre: "<<p->nombre<<" edad: "<<p->edad<<endl;}
			
			void mostrarTodos(Nodo L){
				while(L.sig!=NULL){
					mostrar(L);
					
				}}
void arregloDinamico(int x){
	srand(time(NULL));

int *p=new int[x];
if(p!=NULL){
	for(int i=0;i<x;i++) { 
		p[i]=rand()%100;
	}
	
for(int j=0;j<x;j++) { cout<<p[j]<<"-"; }	
cout<<endl;

delete [] p;
p=NULL;

}}

void nombreDinamico(int x){
	char *p=new char[x];
	if(p!=NULL){
		cin.getline(p,x);
		puts(p);
		delete [] p;
		p=NULL;
	}
}
	void matrizDinamica(int x){
		srand(time(NULL));
		
		int **matriz=new int *[x];
		if(matriz!=NULL){
			for(int j=0;j<x;j++) { 
				matriz[j]=new int[x];
			
				if(matriz[j]!=NULL){
					
			for(int i=0;i<x;i++) { 
				matriz[j][i]=rand()%100;
			}}}
			for(int j=0;j<x;j++) {
				for(int i=0;i<x;i++) { cout<<matriz[j][i]<<"-";}
				cout<<endl;}
		
		for(int i=0;i<x;i++) {delete [] matriz[i];  }
		delete [] matriz;
		matriz=NULL;
		}}
						
			
