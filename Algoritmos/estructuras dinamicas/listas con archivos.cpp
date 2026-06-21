#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
#define tam 25
struct persona{
	int edad;
	persona *sig;
	persona *ant;
};
typedef persona * p;
//-------------------------------
	void crear(p *L);
	void crear(p *L,int e);
void mostrar(p L);
void cargarArchivo(p L);
void descargarArchivo(p *L)	;					
void prueba();
void prueba2();
void cambiar(char x[]);
void cargarBinario(p L);
void leerBinario();
void ejemplos(){
		p L=NULL;
				for(int i=0;i<5;i++){crear(&L);}
				cargarArchivo(L);
				descargarArchivo(&L);
				mostrar(L);
	prueba();
	prueba2();
	char a[]="kvothe y denna historia inconclusa";
	cambiar(a);
	prueba2();
	}
//-------------------------------
//-------------------------------
int main(int argc, char *argv[]) {
	p L=NULL;
	for(int i=0;i<30;i=i+5){crear(&L);}
	cargarBinario(L);
	leerBinario();
	return 0;
}
//-------------------------------------------------------
//-------------------------------	
	void cargarArchivo(p L){
	ofstream f;
	f.open("persona.txt",ios::app);
	if(f.fail()){
		cout<<"error";}
	else{
	while(L!=NULL){
		f<<L->edad<<" -";
		L=L->sig;}
	f.close();
	}}
	void descargarArchivo(p *L) {
		ifstream f("persona.txt", ios::in);
		if (!f.is_open()) {
			cout << "error";
			return;
		}
		int num;
		while (f >> num) {   // lee enteros completos
			crear(L, num);
		}
		f.close();
	}
void prueba(){
	
	char aux[]="texto.txt";
	ofstream f;
	f.open(aux);
	if(!f){cout<<"error";}
	char cadena[]="Para poder pagar la matrícula del segundo bimestre, Kvothe busca a un prestamista en Imre. Así conoce a Devi, quien le presta dinero para poder pagarla.";
	
	
	f<<cadena;
	f.close();}
	
	void prueba2(){
		
		char aux[]="texto.txt";
		ifstream f;
		f.open(aux);
		char c;
		while(f.get(c)){
			cout<<c;
		}
		f.close();}
	
		void cambiar(char x[]){
			
			char aux[]="texto.txt";
			ofstream f;
			f.open(aux,ios::trunc);
			if(!f){cout<<"error";}
			f<<x;
			f.close();}
			
			void inicializarPersona(persona& x){
				cin>>x.edad;
				x.sig=NULL;
				x.ant=NULL;
			}
				void crear(p * L){
					int e=0;
					cout<<"edad: ";
					cin>>e;
					if(*L==NULL){
						*L=new persona;
						
						(*L)->edad=e;
						(*L)->sig=NULL;
						(*L)->ant=NULL;
					}
					else{
						p aux=*L;
						while(aux->sig!=NULL){
							aux=aux->sig;}
						p tmpr=new persona;
						
						tmpr->edad=e;
						aux->sig=tmpr;
						tmpr->ant=aux;
						tmpr->sig=NULL;
					}
					
				}
					
					void crear(p * L, int e){
						if(*L==NULL){
							*L=new persona;
							
							(*L)->edad=e;
							(*L)->sig=NULL;
							(*L)->ant=NULL;
						}
						else{
							p aux=*L;
							while(aux->sig!=NULL){
								aux=aux->sig;}
							p tmpr=new persona;
							
							tmpr->edad=e;
							aux->sig=tmpr;
							tmpr->ant=aux;
							tmpr->sig=NULL;
						}
						
					}
						void mostrar(p L){
							for(p h=L;h!=NULL;h=h->sig){
								cout<<h->edad<<" - ";}
							cout<<endl;}
							
void cargarBinario(p L){
	char bin[]="numeros.bin";
	ofstream f;
	f.open(bin,ios::binary);
	
	if(!f){
		cout<<"error";
		}
	else{
		while(L!=NULL){
		persona h;
		h=(*L);
		f.write((char *)(&h),sizeof(h));
		L=L->sig;
			
		}
		f.close();
		
	}
}
	void leerBinario(){
		ifstream f;
		char bin[]="numeros.bin";

		f.open(bin,ios::binary);
		
		if(!f){
			cout<<"error";
		}
		else{
			persona h;
			f.seekg(2*sizeof(h),ios::beg);
			f.read((char *)(&h),sizeof(h));
		//	while(!f.eof()){
			f.read((char *)(&h),sizeof(h));//
		cout<<h.edad<<endl;
			}
	f.clear();
		}
	
