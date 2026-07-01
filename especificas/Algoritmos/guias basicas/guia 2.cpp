#include <iostream>
#include <iomanip>
using namespace std;
//EJERCICIOS DE LA GUIAS 2-5/6 VARIADOS PARA REFRESCAR SOLO ALGUNOS Y ANALIZANDO EL NIVEL 

void guia2Porcentaje();
void mostrar(int,int,int);
void ejemplos(int ,int ,int );
void operadorPrefijoPostfijo(int ,int ,int );
void dobleAsignacion(int ,int ,int );
void examen();
int main(int argc, char *argv[]) {
examen();
//	guia2Porcentaje();
	int a=2,b=1,c=3;
	
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	cout<<"c:"<<c<<endl;
	cout<<"cambios en las variables solo dentro de la funcion son pasadas por copia"<<endl;
	guia2Porcentaje();
	/*ejemplos(a,b,c);
	operadorPrefijoPostfijo(a,b,c);
	dobleAsignacion(a,b,c);
	*/
	

	return 0;
}
//-----------------------------------------------------------
void guia2Porcentaje(){
	int m,f;
	
	cout<<"Ingrese el numero de mujeres en el curso:";
	cin>>f;
	cout<<endl<<"Ingrese el numero de hombres en el curso:";
	cin>>m;
	if(m<0 and f<0){
		cout<<"error de ingreso o no hay personas en el curso"<<endl;}
	else{
		float aux=m*100/(float)(m+f);
		cout<<"Porcentaje de varones en el curso"<< aux<<"<%"<<endl;
		cout<<"Porcentaje de mujeres en el curso"<<100-aux<<" %"<<endl;
	}
}
	//-----------------------------------------------------------
	void mostrar(int a,int b,int c){
		cout<<"a:"<<a<<endl;
		cout<<"b:"<<b<<endl;
		cout<<"c:"<<c<<endl;
	}
		void ejemplos(int a,int b,int c){
			b+=(a>0)? c: -1;
			a=(b>c)? b:c;
			c=a+b;
			mostrar(a,b,c);
		}
void operadorPrefijoPostfijo(int a,int b,int c){
	cout<<"operadores de pre y postincremento "<<endl;
	a-=--c;
	b+=c;
	cout<<"a - c decrementa con operador de predecremento :"<<a<<endl;
	cout<<"b sumarle c :"<<b<<endl;
	cout<<"c:"<<c<<endl;
	}
void dobleAsignacion(int a,int b,int c){
	
	cout<<"caso particular estudiar bien asociatividad"<<endl;
	cout<<"expresion a=b=a+3*c+50"<<endl;
	a=b=a+3*c+50;
mostrar(a,b,c);}
void examen(){
	int preguntas=0,correctas=0;
		
		cout<<"ingrese el numero total de preguntas: ";
	cin>>preguntas;
	cout<<"ingrese el numero respuestas correctas: ";
	cin>>correctas;
	if(correctas>preguntas or (preguntas<=0)){ cout<<"error datos incorrectos"<<endl;}
	else{
		float nivel= correctas*100/(float) preguntas;
		cout<<"NIVEL ";
	if(nivel>=90){cout<<"maximo"<<endl;}
	else{
		if(nivel<90 and nivel>=75){ cout<<"medio";}
		else{
			if(nivel<75 and nivel>=50){cout<<"regular";}
			else{cout<<"fuera de nivel";}
		}
	}
}}
