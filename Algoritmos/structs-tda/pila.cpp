#include <iostream>
#include "pila.h"
using namespace std;
//interfaz privada
pila crearPila(){
	pila p;
	p.TL=-1;
	return p;}
void mostrar(pila p){
	cout<<"[ ";
	for(int i=0;i<=p.TL;i++){ cout<<p.pila[i]<<" ";}
cout<<"]"<<endl;}

bool vacia(pila p){
	return (p.TL==-1)? true:false;}
bool llena(pila p){
	return (p.TL==TF)?true:false;}

bool apilar(pila & p,int valor){
	if(!llena(p)){
	p.pila[++p.TL]=valor;
	return true;}
	return false;
}
bool desapilar(pila & p,int& valor){
	if(!vacia(p)){
		valor=p.pila[p.TL--];
			return true;
	}
return false;
}
void invertir(pila& p){
	pila aux=crearPila();
	int x;
	while(!vacia(p)){
		desapilar(p,x);
		apilar(aux,x);
	}
	p=aux;
}
