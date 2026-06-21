#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
#define cad 80

void practica(){
	char cadena[cad];
	string cadena2;
	char c;
	//FORMA  para cadenas TIPO C
	int i=0;
	//while((c=getchar())!='\n' and i<cad-1){		/*aritmetica de punteros*/	*(cadena+i)=c;
	//	i++;}
	/*
	ultimo caracter de cadenas   (cadena+i)='\0';
	vaciar el buffer para proximas lecturas
	cin.ignore(1000,'\n');
	cin>>ws;
	*/
	//-----------------------------------------------------------------------
	//METODO 2  libreria cstdio
	
	//gets(cadena);   
	//FORMA 3
	//cin.getline(cadena,cad);
	//	cout<<"cadena: "<<cadena;
	
	//puts(cadena);
	//-----------------------------------------------------------------------	
	//METODOS PARA STRINGS	
	getline(cin,cadena2);
	
	cout<<"cadena2: "<<cadena2+"?";

	char a[]="hola mundo como estas";
	cout<<a[strlen(a)-1];
}
	void correoString();
void correoTradicional();
void usuariovalido();
void palindromo();
void comboString(string , string );
	int main(int argc, char *argv[]) {
//correoString();
//		correoTradicional();
//usuariovalido();
	//	palindromo();
comboString("Hi","Hello");
		return 0;
}
void correoString(){
	string datos;
	getline(cin,datos,'\n');
	string correo="@frsf.utn.edu.ar";
	int nombre=datos.find(" ")+1;
	correo=datos.at(nombre)+datos.substr(0,nombre-1)+correo;
	cout<<correo;
}
void correoTradicional(){
	char cadena[cad];
	char dominio[]="@frsf.utn.eda.ar";
	
cin.getline(cadena,cad,'\n');
int i=0;
char correo[cad];
while(cadena[i]!=' ' and i<cad){
correo[i+1]=cadena[i];	
i++;}
correo[0]=cadena[i+1];
strcat(correo,dominio);
puts(correo);
}
void usuariovalido(){
	string cadena1="1erez123";
	char cadena2[]="pjperez12";
cout<<"tipo string"<<endl;

bool letra= isalpha(cadena1.at(0));
if(cadena1.size()!=8 or !letra){cout<<"false"<<endl;
}
else{cout<<"true!";}
cout<<"tipo c"<<endl;
int aux=strlen(cadena2);
int c=cadena2[0];
if(aux!=8  or  ((c>122 or c<97) and (c<65 or c>90 ))){cout<<"false";
}
else{cout<<"true!";}
}
void palindromo(){
	char cadena[cad];
	string cadena2;
	
	//CADENAS TIPO C
	/*cin.getline(cadena,cad,'\n');
	int aux=strlen(cadena);
	int i=0;
	bool bandera=true;
	while(bandera and i<aux){
	if(cadena[i]!=' '){
		if(cadena[aux-1]!=' '){
			if(cadena[i]!=cadena[aux-1]){ bandera=false;}
			else{
				i++;
				aux--;}
			}
		else{ aux--;}
		}
	else{i++;}
	}
	cout<<cadena<<" palindroma?: "<<boolalpha<<bandera<<endl;
*/
//TIPO string
	
	getline(cin,cadena2,'\n');
	int i=0;
	int cantidad=cadena2.length()-1;
	bool bandera=true;
	while(i<cantidad and  bandera){
		if(cadena2[i]!=' '){
			if(cadena2.at(cantidad)!=' '){
				if(cadena2.at(i)==cadena2.at(cantidad)){
					i++;
					cantidad--;}
				else{ bandera=false;}
			}
			else{cantidad--;}
		}
		else{i++;}
	}
	cout<<"cadena2: "<<cadena2<<" palindromo: "<<boolalpha<<bandera<<endl;}
void comboString(string a, string b){
int longitudA=a.length()-1,longitudB=b.length()-1;
string aux;
if(longitudA>longitudB){
	aux=b+a+b;}
else{
	aux=a+b+a;}

cout<<"cadena final: "<<aux<<endl;}
