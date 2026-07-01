#include <iostream>
#include "cola.h"
using namespace std;
//interfaz privada
 cola crearCola(){
	 cola c;
	 c.primero=0;
	 c.ultimo=0;
	 return c; }
bool vacia(cola c){
	return (c.primero==c.ultimo)? true:false;}
	
	
bool agregarElem(cola & c,int elemento){
if((c.ultimo+1)%TF==c.primero){
	return false;}
	c.datos[c.ultimo]=elemento;
	c.ultimo=(c.ultimo+1)%TF;
return true;
}
bool desencolarElem(cola & c,int elemento){
	if(vacia(c)){
		return false;}
elemento=c.datos[c.primero];
	c.primero=(c.primero+1)%TF;
return true;
}
void mostraCola(cola c){
	cout<<"[ ";
	for(int i=c.primero;i<c.ultimo;i=(i+1)%TF) {
		cout<<c.datos[i]<<" - ";
		
	}
	cout<<"]"<<endl;
}
