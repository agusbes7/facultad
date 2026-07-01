#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 100
void cargarvector(int a[],int tl);
void cargarvectorR(int a[],int tl);
void mostrarvector(int a[],int tl);
void rotarder(int a[],int);
void rotarizq(int a[],int);
void eliminar(int a[],int& tl,int indice);
void agregar(int a[],int& tl,int indice,int valor);
void eliminarepetidos(int a[],int& tl);
void eliminaImparEntrePar(int a[],int& tl);
int busquedaBinaria(int [],int,int);
void mergesort(int [],int tl);
int main(int argc, char *argv[]) {
	int v[N] = {1, 2, 3, 4, 7, 9, 12, 14, 15, 20};
	int tl=10,x=12;
int y=busquedaBinaria(v,tl,x);
	cout<<"elemento: "<<x<<" indice: "<<y <<" - "<<v[y]<<endl;
	return 0;
}

void cargarvector(int a[],int tl){
	
	for(int i=0;i<tl;i++){
		cin>>a[i];}
	return ;}
void mostrarvector(int a[],int tl){
		for(int i=0;i<tl;i++){cout<<a[i]<<"-";}
		cout<<endl;
	return;}
		void cargarvectorR(int a[],int tl){
			srand(time(0));
			for(int i=0;i<tl;i++){
				a[i]=rand()%1000;}
			return ;}
int mayorRango(int a[],int tl,int inf,int sup){
	if(inf>sup or sup>tl){cout<<"fuera de rango"<<endl;
	return -1;}
	int mayor=a[inf];
	for(int i=inf+1;i<sup;i++){
mayor=(mayor<a[i])? a[i]:mayor;}
	return mayor;
	
}
	
void intercambiar(int &a,int &b){
	
int aux=a;
a=b;
b=aux;}

int pertenece(int a[],int tl,int x){
	
int j=0; 
int aux=-1;
while(j<tl  and aux==-1){
	if(a[j]==x){aux=j;}
	j++;
}
return j;}

void intercambio(int a[],int tl,int x,int y){
	
int c=pertenece(a,tl,x);
int d=pertenece(a,tl,y);
if(c!=-1 and d!=-1){
	intercambiar(a[c],a[d]);
}
else{
	cout<<"error al menos uno de los elementos no pertenece"<<endl;}
}
void rotarizq(int a[],int tl){
	
int aux=a[0];
for(int i=1;i<tl;i++){
	a[i-1]=a[i];
}
a[tl-1]=aux;}
void rotarder(int a[],int tl){
	int aux=a[tl-1];
for(int i=tl-1;i>0;i--){
	a[i]=a[i-1];
}
a[0]=aux;}

void eliminar(int a[],int& tl,int indice){
	for(int i=indice;i<tl;i++){
		a[i]=a[i+1];
	}
tl--;
}
void agregar(int a[],int& tl,int indice,int valor){
	
for(int i=tl;i>indice;i--){
	a[i]=a[i-1];}
a[indice]=valor;
tl++;
}
void eliminarepetidos(int a[],int& tl){
	
int i=0;
int suma=0,pares=0;
while(i<tl-1){
	if(a[i]==a[i+1]){ eliminar(a,tl,i);
	if(a[i]%2==0){pares++;}}
	else{
		suma+=a[i];
		i++;
	}
}
cout<<"pares eliminados: "<<pares<<endl;
cout<<"promedio de elementos:"<<float(suma)/tl<<endl;
}
void eliminaImparEntrePar(int a[],int& tl){
	int cantidadImpares=0, i=1;
	int mayorDiferencia=0;
	if((a[0]%2)==0 and (a[1]%2)==0){mayorDiferencia=a[1]-a[0];}
			
	while(i<tl){
		if(a[i]%2!=0){
			if(a[i-1]%2==0 and a[i+1]%2==0){
				eliminar(a,tl,i);
				mostrarvector(a,tl);
			cantidadImpares++;}
			else{i++;}}
		else{
			if(i+1<tl and a[i]%2==0){ 
				int aux=a[i+1]-a[i];
				mayorDiferencia=(mayorDiferencia<aux)?aux:mayorDiferencia;}
			i++;}
}
	cout<<"mayorDiferencia entre 2 pares sucesivos:" <<mayorDiferencia<<endl;
	cout<<"cantidad de impares eliminados: "<<cantidadImpares<<endl;
	}
	
int  busquedaBinaria(int a[],int tl,int x){
	int aux=-1;
	int izq=0;
	int der=tl-1;
	int medio=(izq+der)/2;
	while(izq<=der and a[medio]!=x){
		
		if(a[medio]>x){
			der=medio-1;
		}
		else{
			izq=medio+1;}
		medio=(izq+der)/2;
		}
	if(izq<der or izq==der){ aux=medio;}

return aux;}
	

	
}


void mezclar(int a[],int inicio1,int inicio2,int fin1,int fin2){
int j=inicio1, i=inicio2,k=0;

int c[N];
while(j<=fin1 and i<=fin2){
	
	if(a[j]<a[i]){ c[k++]=a[j++];}
	
	else{
		c[k++]=a[i++];}
	}
for(int h=j;h<fin1;h++){
	c[h]=a[
}
void merge(int a[],int inicio,int fin){
	if(fin<=inicio){return;}
	else{
		int medio=(inicio+fin)/2;
		merge(a,inicio,medio);
		merge(a,medio+1,fin);	}
	mezclar(a,inicio,medio+1,medio,fin);
}
void mergesort(int a[],int tl){
	
	int izq=0;
	int der=tl-1;
	merge(a,izq,der);
	}
