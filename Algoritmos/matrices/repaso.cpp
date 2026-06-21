#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define tam 50
void cargarvector(int [][tam],int);
void cargarvectorrand(int [][tam],int);
void cargarvectorrand2(int [][tam],int,int);
void mostrar(int [][tam],int);
void mostrar(int [][tam],int,int);
int sumaFila(int [][tam],int,int);
int sumaFila2(int [],int);
int sumaColumna(int [][tam],int,int);
float promediofila(int [],int);
float promediocolumna(int [][tam],int,int);
void prueba();
void problema2();
void transpuesta(int [][tam],int&,int&);
void intercambio(int &a,int&b){int aux=a; a=b; b=aux;}

int main(int argc, char *argv[]) {
int a[tam][tam],tlf=3,tlc=4;
cargarvectorrand2(a,tlf,tlc);
mostrar(a,tlf,tlc);
cout<<setfill('-')<<setw(20)<<"-"<<endl;
transpuesta(a,tlf,tlc);
mostrar(a,tlf,tlc);
	return 0;
}
void transpuesta(int a[][tam],int& tlf, int& tlc){
if(tlf==tlc){
	for(int i=0;i<tlc;i++) { 
		for(int j=i+0;j<tlf;j++){
			if(i!=j){
			intercambio(a[i][j],a[j][i]);
		}}
	}
}
else{
	for(int i=0;i<tlf;i++){
		for(int j=i;j<tlc;j++){
			intercambio(a[i][j],a[j][i]);
		}
	}
	intercambio(tlf,tlc);
	
}}

void mostrar( int a[][tam],int tl){
	for(int i=0;i<tl;i++){
		for(int j=0;j<tl;j++) { 
		cout<<a[i][j]<<"  ";}
	
	cout<<endl;
}}
	
	void cargarvector( int a[][tam],int tl){
		for(int i=0;i<tl;i++){
			for(int j=0;j<tl;j++) { 
			cin>>a[i][j];}
			}}	
		void cargarvectorrand( int a[][tam],int tl){
			srand(time(NULL));
			for(int i=0;i<tl;i++){
				for(int j=0;j<tl;j++) { 
				a[i][j]=rand()%500;
							}}}
			void cargarvectorrand2( int a[][tam],int tlf,int tlc){
				srand(time(NULL));
				for(int i=0;i<tlf;i++){
					for(int j=0;j<tlc;j++) { 
						a[i][j]=rand()%200;
					}}}
				
			void mostrar(int a[][tam],int tlf,int tlc){
				for(int i=0;i<tlf;i++) { 
					for(int j=0;j<tlc;j++) { 
						cout<<a[i][j]<<" ";
					}
					cout<<endl;
				}
			}
			int sumaFila(int a[][tam],int tl,int fila){
	
	int sum=0;
	for(int i=0;i<tl;i++) { 
		sum+=a[fila][i];
	}
return sum;}
	int sumaFila2(int a[],int tl){
		int sum=0;
		for(int i=0;i<tl;i++) { sum+=a[i]; }
	return sum;}
int sumaColumna(int a[][tam],int tl,int columna){
	int sum=0;
	for(int i=0;i<tl;i++) { 
		sum+=a[i][columna];
	}
return sum;}
bool  triangularsuperior(int a[][3],int tl){
	bool triangular=true;
	int i=1;
	while(i<tl and triangular){
	int j=0;
		while(j<i and triangular) {
			if(a[i][j]!=0){triangular=false;}
			j++;
			
		}
		i++;
	}
	return triangular;}
bool triangularInferior(int a[][3],int tl){
	bool triangular=true;
	int i=0;
	while(i<tl and triangular){
		int j=i+1;
		while(j<tl and triangular) {
			if(a[i][j]!=0){triangular=false;}
			j++;
			
		}
		i++;
	}
	return triangular;}
	bool diagonal(int a[][3],int tl){
		bool diagon=true;
		int i=0;
		while(i<tl and diagon){
			int j=0;
			while(j<tl and diagon){
				if(i!=j){
					if(a[i][j]!=0){diagon=false;}
				}
				j++;
				}
			i++;}
		return diagon;}
	
void prueba(){
	
int a[3][3]={
	 1, 0 ,0, 
	0, 2, 0,
    0, 0, 3};
cout<<"triangular sup"<<triangularsuperior(a,3)<<endl;
cout<<"triangular inferior"<<triangularInferior(a,3)<<endl;
cout<<"diagonal :"<<diagonal(a,3);
}
void problema2(){
	int a[tam][tam]={0},tlf=4,tlc=50;
	cargarvectorrand2(a,tlf,tlc);
	mostrar(a,tlf,tlc);
	system("Pause");

	int sumfila,sumcolumna;
for(int i=0;i<tlc;i++){cout<<"cantidad pasajeros destino: "<<i<<"  "<<sumaColumna(a,tlf,i)<<endl;}
for(int i=0;i<tlf;i++){	cout<<"cantidad pasajeros categoria: "<< i<<" "<<sumaFila2(a[i],tlc)<<endl;}

	int j=0;
	
	for(int i=0;i<tlc;i++){
	int cantidad=sumaColumna(a,tlf,i);
	if(cantidad==0){j++;
	cout<<" en la localidad "<<i<< "no se vendio ningun pasaje"<<endl;}
	}
	if(j==0){cout<<"en todas las localidades se vendieron pasajes"<<endl;}
	
	int menor=sumaColumna(a,tlf,0), indice=0;
	for(int i=1;i<tlc;i++) {
		int suma=sumaColumna(a,tlf,i);
		if(menor>suma){
			menor=suma;
			indice=i;
		}
	}
	cout<<"en la localidad "<<indice<<" se vendieron la menor cantidad de pasajes "<<menor<<endl;
	
	for(int i=0;i<tlc;i++){
		int cantidad=sumaColumna(a,tlf,i);
		if(cantidad>500){cout<<"Localidad "<<i<<" pasajes "<<cantidad<<endl;}
	}
	
}
float promediofila(int a[],int tlc){
	float prom=0;
		for(int i=0;i<tlc;i++) { prom+=a[i]; }
prom=prom/tlc;
		return prom;
}
	
	float promediocolumna(int a[][tam],int tlf,int columna){
		float prom=0;
		for(int i=0;i<tlf;i++) { 
prom+=a[i][columna];			
		}
		prom=prom/tlf;
	return prom;}
