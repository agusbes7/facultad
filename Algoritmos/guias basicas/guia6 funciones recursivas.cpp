#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//EJERCICIOS DE LA GUIAS 4 estructuras de control seleccion y repeticion 
int menor(int x,int y){return (x<y)? x:y;}
int mayor(int x,int y){return (x>y)? x:y;}
void kasteriscos(int x,char y){cout<<setfill(y)<<setw(x)<<y<<endl;}
//---------------------------------------------------------------------
int unidad(int x){return x%10;}
int decena(int x){return unidad(x/10);}
int centena(int x){return decena(x/10);}
int udeMil(int x){return x/1000;}
int invertir(int);

void intercambiar(int&,int&);
int cifras(int x){
	if(x<10){return 1;}
	else{return 1+cifras(x/10);}}
int cifrasPares(int x){

		if(x<10){ return (x%2==0)? 1:0;}
		else{
			
		return ((x%10)%2==0)? 1+cifrasPares(x/10):0+cifrasPares(x/10); 
		}
	}

int inverso(int );
int potencia(int,int);
bool capicua(int x){

	if(x<10){return true;}
	else{
	if(x<100){ return(x/10==x%10)? true:false;}
	else{
		int cifra=cifras(x);
		int primero=x%10;
		int ultimo=x/potencia(10,cifra-1);
		if(primero ==ultimo){
x=x%potencia(10,cifra-1);
x/=10;
		return capicua(x);
		}
		else{
			return false;
		}
	}
}}
	int maxdigito(int x){
		if (x<10){return x;}
		else{
			int actual=x%10;
			return (actual>maxdigito(x/10))? actual:maxdigito(x/10);
		}
	}
		int ent_bin(int x);
		int bin_ent(int x);
//_----------------------------------------------------------------
//----------------------------
//----------------------------
int main(int argc, char *argv[]) {
kasteriscos(5,'#');
cout<<bin_ent(10000);
return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++
void kasteriscos2(int x){
		for(int i=0;i<x;i++){cout<<"*";}
	}
		//++++++++++++++++++++++++++++++++++++++++++++++++++
int potencia(int base ,int exponente){
	if(exponente==0){return 1;}
	else{
		return base*potencia(base,exponente-1);
	}}
	
	int invertir(int x){
		int aux=cifras(x);
		if(aux==1){return x;}
		return (x%10)*
		   potencia(10,aux-1)
		   +invertir(x/10);}
int inverso(int x){
	int aux=cifras(x);
	if(aux==1){return x;}
	else{
		return (x%10)*potencia(10,cifras(x)-1)+inverso(x/10);}
	}
int ent_bin(int x){
		if(x==1){ return  1;}
	else{
		return (x%2)+10*ent_bin(x/2);}
}
int bin_ent(int x){
	int cifra=cifras(x);
	if(cifra==1){return x;}
	else{
		return x%10+2*bin_ent(x/10);
	}
}
