#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//EJERCICIOS DE LA GUIAS 3 y 4 estructuras de control seleccion y repeticion 

void problema1Nivel();
void capicuaTresCifras(int );
//-------------Recursivo-----------------
int cifras(int a);
//-----------Iterativo-----------
int cifrasItera(int );
//---------------problema 3----------------------
void sistemaDepago();
//----------problema 6------------------
bool alternante(int x);
//----------problema 8------------------

void shopCompras();

void perimetro();
//----------------------------
//----------------------------
int main(int argc, char *argv[]) {
/*problema1Nivel();
system("Pause");
system("cls");
//---------------------------------------------
	int x;
cout<<"ingresa un numero:" ;
cin>>x;
cout<<endl;
capicuaTresCifras(x);
system("Pause");
system("cls");
//---------------------------------------------
cout<<cifrasItera(1);
cout<<cifrasItera(20);
cout<<cifrasItera(123);
cout<<cifrasItera(12345);
cout<<cifrasItera(00123);
system("Pause");
system("cls");
//---------------------------------------------
	sistemaDepago();
system("Pause");
system("cls");	
//---------------------------------------------
	cout<<"Numero alternante: "<<boolalpha<<alternante(1234)<<endl;
	cout<<"Numero alternante: "<<boolalpha<<alternante(122)<<endl;
	system("Pause");
	system("cls");
	//---------------------------------------------*/
//	shopCompras();
	perimetro();
	return 0;
}
void forma1(float prom){
	
cout<<((prom<50 or prom>100)?
	"fuera de nivel":
	(prom>=50 and prom<75)? 
	"Nivel regular":
	(prom>=75 and prom<90)?	"nivel medio":	"Nivel maximo")<<endl;
	
	
}
void forma2(float prom){
	
	if(prom>=90){cout<<"Nivel maximo";}
	else{
		if(prom<90 and prom>=75){cout<<"Nivel medio";}
		else{
			if(prom<75 and prom>=50){cout<<"nivel regular";}
			else{
				cout<<"fuera de nivel";}
			}
		}
	}


void problema1Nivel(){
	int preguntas,correcta;
	cout<<"Cantidad de preguntas:";
	cin>>preguntas;
	cout<<" correctas? :";
	cin>>correcta;
	float porcentaje= correcta*100/(float)preguntas;
	forma1(porcentaje);
cout<<endl<<"forma 2 de resolver con if else"<<endl;
	forma2(porcentaje);
}
	void capicuaTresCifras(int a){
		int cifras=log10(a)+1;
		if(cifras!=3){cout<<"debe ser un numero de 3 cifras por favor"<<endl; 
		return;}
		int unidad=a%10;
		int centena=a/100;
cout<<((unidad==centena)? "capicua": "no es capicua")<<endl;
	}
//-----------------------------------------------
		int cifras(int a){
	if(a<10){return 1;}
	else{
		return 1 + cifras(a/10);
	}
}
int cifrasItera(int a){
	int cifras=0;
	while(a>0){
		cifras++;
		a/=10;
	}
return cifras;}
//------------------problema 3-------------------
	void sistemaDepago(){
		int monto;
		char pago;
		cout<<"ingresa el monto a pagar:";
		cin>>monto;
		cout<<endl;
		cout<<"t o T credito"<<endl;
		cout<<"c o C contando"<<endl;
		cout<<"ingrega el medio de pago:";
		cin>>pago;
		cout<<endl<<"total: ...";
		float descuento;
		bool mayor=(monto>100)? true:false;
		pago=tolower(pago);
		if(pago!='c' and pago!='t'){cout<<"medio de pago inexistente";}
		else{
			switch(pago){
			case 'c':
				{
				if(mayor){
				descuento=5;}
				else{
					descuento=3;}
				break;}
			case 't':
				{
					if(mayor){
						descuento=2.5;}
					else{
						descuento=2;}
					break;}
			}
			
			cout<<(float)(monto- monto*descuento/100)<<endl;
		}
	}
bool alternante(int x){
	int guia=(x%10)%2;
	bool alterna=true;
x/=10;
while(alterna and x>0){
	if(guia!=(x%10)%2){
		guia=(x%10)%2;
		x/=10;}
	else{alterna=false;}
	}
return alterna;}
	//	-----------------------PROBLEMA 8-----------------
	void shopCompras(){
		int edad,categoria;
		cout<<"ingresa tu edad:";
		cin>>edad;
		cout<<endl<<"ingresa tu categoria:";
		cin>>categoria;
		int costo,descuento;
		if(edad<25){cout<<"No tenes la edad suficiente para acceder a la tarjeta de compra"<<endl;
		return ;}
		if(edad>25){
			costo=35;
			switch(categoria){
			case 1:
				descuento=40;
				break;
			case 2:
				descuento=30;
				break;
				
			case 3:
				descuento=15;
				break;
			default: descuento=0;
			}
		}
		else{
			if(edad==25){
			costo=20;
			switch(categoria){
			case 1:
				descuento=60;
				break;
			case 2: 
				descuento=40;
				break;
			case 3: 
				descuento=20;
				break;
			default: descuento=0;
			
			}}}
		cout<<"costo de la tarjeta:" <<fixed<<setprecision(2)<<costo- (float)costo*descuento/100<<endl;
	}
	
void perimetro(){
	int tipo;
	float perimetro;
	cout<<"1 Equilatero"<<endl;
	cout<<"2 isosceles"<<endl;
	cout<<"3 Escaleno"<<endl;
	cout<<"tipo: ";
	cin>>tipo;
	cout<<endl;
	
	int lado;
	
	switch(tipo){
	case 1:
	{
		cout<<"lado: ";
		cin>>lado;
		perimetro=3*lado;
		
		break;
	}
	case 2:
	{
		cout<<"primero ingrese el lado distinto"<<endl;
		cout<<"lado a: ";
		cin>>lado;
		perimetro+=lado;
		cout<<"lado b: ";
		cin>>lado;
		perimetro+=2*lado;
		break;
	}
	case 3:{
		for(int i=0;i<3;i++){cout<<"lado: ";
		cin>>lado;
		perimetro+=lado;}
		break;
	}
	default:
	{cout<<"opcion incorrecta";
	return;}
		
	}
cout<<"perimetro: "<<perimetro;

}
