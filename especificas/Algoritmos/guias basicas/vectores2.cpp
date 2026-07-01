#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 100
void cargarvector(int a[],int tl);
void cargarvectorR(int a[],int tl);
void mostrarvector(int a[],int tl);
int busquedaBinaria(int [],int,int);
void mergesort(int [],int tl);
void mezclar(int[],int ,int,int,int);
void merge(int [],int,int);
int main(int argc, char *argv[]) {
	
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
int  busquedaBinaria(int a[],int tl,int x){
	
	int aux=-1;
	int izq=0;
	int der=tl-1;
	int medio=(izq+der)/2;
	while(izq<=der and a[medio]!=x){
		
		if(a[medio]>x){	der=medio-1;}
		else{izq=medio+1;}
		medio=(izq+der)/2;}
	
		if(izq<der or izq==der){ aux=medio;}

return aux;}


	void mergesort(int a[],int tl){
		merge(a,0,tl-1);
	}
	void mezclar(int a[],int inicio1 ,int inicio2 ,int fin1 ,int fin2){
		
		int i=inicio1,j=inicio2,k=0,c[N];
		
		while(i<=fin1 and j<=fin2){
			
			if(a[i]>a[j]){ c[k++]=a[j++];}
			else{
				c[k++]=a[i++];}
		}
		
		for(int h=k; h<=fin1;h++){
			c[h++]=a[i++];}
		for(int h=k; h<=fin2;h++){
			c[h++]=a[j++];}
		
		for(int i=inicio1;i<k;i++){
			a[i]=c[i];
		}
	}

	
	
	void merge(int a[],int izq,int der){
if(der<=izq){return;}
else{
	int medio=(izq+der)/2;
	merge(a,izq,medio);
	merge(a,medio+1,der);
	mezclar(a,izq, medio+1,medio,der);
	}}



