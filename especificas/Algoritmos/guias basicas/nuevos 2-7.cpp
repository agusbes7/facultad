#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//EJERCICIOS DE LA GUIAS 2-5/6 VARIADOS PARA REFRESCAR SOLO ALGUNOS Y ANALIZANDO EL NIVEL 

int mayor(int ,int );
int menor(int ,int );
int cifras(int);
int cifras2(int);
int invertirR(int);
int invertirI(int);
int exponente(int,int);
void calculadora();
bool alternante(int );
bool palindromo(int );
void linea(int,char);
void conversor(char );
void intercambio(int& a,int& b){ int aux=a; a=b; b=aux;}
int digitosP(int a);
int sumatoria(int);
void decimalbinario(int);
void binariodecimal(int);
void kcuadrados(int );
void ktriangulos(int );
int main(int argc, char *argv[]){
/*cout<<"cifras2 con log"<<cifras2(12345);
cout<<"exponente: "<<exponente(2,3);
cout<<"exponente: "<<exponente(2,4)<<endl;
cout<<"exponente: "<<exponente(4,3)<<endl;
cout<<"exponente: "<<exponente(9,3)<<endl;
cout<<"invertir 4321: ->"<<invertirI(4321)<<endl;
calculadora();
calculadora();
calculadora();
calculadora();
cout<<"alterna?: "<<12345<<" "<<alternante(12345)<<endl;
cout<<"alterna?: "<<1<<" "<<alternante(122)<<endl;
cout<<"palindromo? 123 :"<<boolalpha<<palindromo(123)<<endl;
cout<<"palindromo? 121 :"<<boolalpha<<palindromo(121)<<endl;
cout<<"palindromo? 12 :"<<boolalpha<<palindromo(12)<<endl;
cout<<"palindromo? 222 :"<<boolalpha<<palindromo(222)<<endl;

/cout<<"digitos pares: "<<digitosP(23456)<<endl;
cout<<"sumatoria: "<<sumatoria(100);
binariodecimal(11011);*/
	kcuadrados(5);
	ktriangulos(5);
return 0;}
	
	int mayor(int x,int y ){ return (x>=y)? x:y;}
	int menor (int x,int y){ return (x>=y)? y:x;}
	//--------------------------------------------------------
	int cifras(int x){
		if(x<10){return 1;}
		else{
			return 1 + cifras(x/10);}
	}
int cifras2(int x){
	int aux=log10(x)+1;
	return aux;}
	//--------------------------------------------------------
	int exponente(int a,int b){
	if(b==0){return 1;}
	else{
		return a*exponente(a,b-1);
	}}
	
	//--------------------------------------------------------
	int invertirR(int x){
int a=cifras(x);
	if(a==1){return x;}
	else{
		return (x%10)*exponente(10,a-1)+invertirR(x/10);
	}
}
int invertirI(int x){
	int aux=0;
	int y=x;
	for(int i=cifras(x);i>0;i--){
		aux+=(y%10)*exponente(10,i-1);
		y/=10;
	}
	return aux;}
	//--------------------------------------------------------
void calculadora(){
	int x,y,operacion;
cout<<"Nro 1:";
cin>>x;
cout<<endl<<"Nro 2:";
cin>>y;
cout<<endl<<"operacion"<<endl;
cout<<"1. suma"<<endl<<"2 resta"<<endl<<"3 multip"<<endl<<"4 divis"<<endl;
cout<<"opcion:" ;
cin>>operacion;

if(operacion==1){cout<<"suma: "<<x+y;}
else{
	if(operacion==2){cout<<"resta: "<<x-y;}
	else{
		if(operacion==3){cout<<"x: "<<x*y;}
		else{
			if(operacion==4){cout<<"div: "<<x/y;}
			else{cout<<"error no existe dicha operacion"<<endl;
		}
	}
}}}

bool alternante(int x){
	int paridad=(((x%10)%2)==0)?0:1;
	int aux=x/10;
	while(aux!=0 and paridad!=(aux%10)%2){
		paridad=(aux%10)%2;
		aux/=10;}
	cout<<aux;
return (aux==0)? true:false;}
	
	bool palindromo(int x){
		int aux=x, dig=cifras(x);
		int primero,ultimo,bandera=1;
		while(bandera and aux!=0){
			primero=aux%10;
			ultimo=aux/exponente(10,dig-1);
			if(primero==ultimo){
						aux=aux%exponente(10,dig-1);
						dig-=2;
						aux/=10;
			
		}
			else{ bandera=0;}
	}
return (aux==0)?true:false;}
void linearetruco(int x,char c){cout<<setfill(c)<<setw(x)<<c<<endl;}

void linea(int x,char c){

	linearetruco(10,'<');
	cout<<endl;
	for(int i=0;i<x;i++) cout<<c;
}
void conversor(char c){
	int aux=c;
	if(aux>=97 and aux<=122){cout<<char(aux-32)<<endl;}
	else{cout<<"no es una letra minuscula"<<endl;}}


	int digitosP(int a){
		if(a<10){
			return ((a%2)==0)? 1:0;}
		
		else{
						return digitosP(a/10)+ ((((a%10)%2)==0)? 1:0);
		}
	}
int sumatoria(int a){
	if(a==1){return 1;}
	else{
		return a+sumatoria(a-1);}
	}
void binariodecimal(int x){
	int dig=cifras(x);
	int y=x;
	int sum=0;
	for(int i=0;i<dig;i++){
	sum+=(y%10)*exponente(2,i);
	y/=10;}
cout<<"numero: "<<sum<<endl;	
}
void kcuadrados(int x){
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++) {  cout<<"*";}
		cout<<endl;
	}
}
	void ktriangulos(int x){
		for(int i=0;i<x;i++) {
			for(int j=x-1-i;j<x;j++) {cout<<"*";  }
		cout<<endl;
		}
	}
