#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//EJERCICIOS DE LA GUIAS 4 estructuras de control seleccion y repeticion 
int menor(int x,int y){return (x<y)? x:y;}
int mayor(int x,int y){return (x>y)? x:y;}
void impares(int ,int);
void kasteriscos(int x){cout<<setfill('*')<<setw(x)<<"*"<<endl;}
void kasteriscos2(int x);
void cuadradoAsteriscos(int x){for(int i=0;i<x;i++){cout<<setfill('*')<<setw(x)<<"*"<<endl;}}
void cuadradoAsteriscos2(int x);
void trianguloAsteriscos(int x);
void futbol();
//_---------------------------------------------------------------------
int unidad(int x){return x%10;}
int decena(int x){return unidad(x/10);}
int centena(int x){return decena(x/10);}
int udeMil(int x){return x/1000;}
int invertir(int);
int ent_bin(int);
int bin_ent(int);
void intercambiar(int&,int&);
int cifras(int x){
	if(x<10){return 1;}
	else{return 1+cifras(x/10);}
}
//_----------------------------------------------------------------
void problema6();
void curiosos(int);
//----------------------------
//----------------------------
int main(int argc, char *argv[]) {
/*impares(37,52);
kasteriscos(5);
kasteriscos2(5);
cuadradoAsteriscos(3);
cout<<endl;
cuadradoAsteriscos2(4);
cout<<endl;
trianguloAsteriscos(5);
problema6();*/
	
curiosos(9);
return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++
void impares(int x ,int y){
	
	int men=menor(x,y);
	int may=mayor(x,y);
	
for(int i=(men%2==0)?men+1:men;i<=may;i++){
	if(i%2!=0){cout<<i<<endl;}
}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++
void kasteriscos2(int x){
		for(int i=0;i<x;i++){cout<<"*";}
	}
		//++++++++++++++++++++++++++++++++++++++++++++++++++
void cuadradoAsteriscos2(int x){
for(int i=0;i<x;i++){
				for(int j=0;j<x;j++){cout<<"*";}
				cout<<endl;
			}
		}
void trianguloAsteriscos(int x){
	for(int i=1;i<=x;i++){
		
	
	for(int j=x-i;j<x;j++){cout<<"*";}
cout<<endl;}}
	
//++++++++++++++++++++++++++++++++++++++++++++++++++
void problema6(){
	for(int i=1000;i<10000;i++){
	if(unidad(i)+centena(i)==decena(i)+udeMil(i)){cout<<i<<endl;}
	}
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
		int bin_ent(int x){ 
			int aux=cifras(x);
			if(aux==1){return x;}
			return (x%10)+2*bin_ent(x/10);}
			int ent_bin(int x){
				if(x==1){return 1;}
				else{
					return x%2+10*ent_bin(x/2);}}
				
				//---------------------------------
	
	void curiosos(int x){
		int contador=0,i=1;
		int cifras;
		while(contador<x){
			long long aux=potencia(i,2);
			cifras=log10(i)+1;
			if(i==aux%potencia(10,cifras)){cout<<i<<endl; contador++;}
		i++;
		}
	}
		void futbol(){
			int edad=0,goles=-1, total=0,defensorGoleador=0,goleador=0,jugadorSG=0;
			int golG[3]={0,0,0};
			float mayoresDe25=0;
			char posicion;
			
			while(true){
				cout<<"edad: ";
				cin>>edad;
				cout<<"--"<<"posicion";
				cin>>posicion;
				cout<<"--"<<" goles:  ";
				cin>>goles;
				if((posicion!='0') and edad!=0){
					total++;
					(edad>=16 and edad<23)?golG[0]+=goles:
						(edad>=23 and edad<30)?golG[1]+=goles: golG[2]+=goles;
					
					switch(posicion){
					case 'A':
					{
						if(goles==0){jugadorSG++;}
						
						break;}
					
					case 'D':
					{
						if(goles>3){defensorGoleador++;}
						break;}}
					
					(goleador<goles)? goleador=goles:goleador=goleador;
					if(edad>25){
						mayoresDe25++;}
				}
				else{
					break;}}
			cout<<"porcentaje de jugadores mayores de 25: "<<mayoresDe25*100/total<<"%"<<endl;
			cout<<"jugadores sin goles:" <<jugadorSG<<endl;
			cout<<"goleador del equipo: "<<goleador<<endl;
			for(int i=0;i<3;i++){cout<<"Grupo etario ";
			(i==0)? cout<<"16-22": (i==1)? cout<<"23-29":cout<<"30-36"; 
			cout<<" cantidad: "<<golG[i]<<endl;}
			cout<<"defensores con mas de 3 goles: "<<defensorGoleador;
			
		}
