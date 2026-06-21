#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define n 40
#define x 5
void mostrar(int [][n],int,int);
void cargar(int [][n],int,int);
void cargarxRand(int[][n],int,int);
float promedioColumna(int [][n],int,int);
float promediofila(int [][n],int,int );
float promedioF(int [],int);
//float mayor(float x,float y){ return (x>y)?x:y;}
float ultimaspruebas(int[][n],int,int);
void transpuesta(int [][n],int );
void transpuestaG(int [][n],int&,int& );
//---------------------------------------------
int mayorMatriz(int a[][n],int filas,int columna);
int mayorDiagonalPrincipal(int a[][n],int filas,int columna);
int mayorDiagonalSecundaria(int a[][n],int filas,int columna);
int mayorFila(int a[],int tl);
int mayorColumna(int a[][n],int ,int );
int mayorSumaColumna(int a[][n],int fila,int columna);
int main(int argc, char *argv[]) {
	int a[x][n],tlf=3,tlc=4;
	cargarxRand(a,tlf,tlc);
	mostrar(a,tlf,tlc);


	return 0;
}

//------------------------------------------------------------
void mostrar(int a[][n],int fila,int columna){
	
	for(int i=0;i<fila;i++){
		for(int j=0;j<columna;j++){
			cout<<a[i][j]<<" ";}
		cout<<endl;}
		}
void cargar(int a[][n],int fila,int columna){
		
		for(int i=0;i<fila;i++){
			for(int j=0;j<columna;j++){
		cin>>a[i][j];}
			cout<<endl;}}
void cargarxRand(int a[][n],int fila,int columna){
		srand(time(0));	
			for(int i=0;i<fila;i++){
				for(int j=0;j<columna;j++){
					a[i][j]=rand()%1000;}
				}}		
//--------------------------------------------------
float promedioColumna(int a[][n],int tlf,int tlc){
		float aux=0;
		for(int j=0;j<tlf;j++){
			
			aux+=a[j][tlc];}
		aux/=tlf;
		return aux;}
float promediofila(int a[][n],int tlf,int tlc){
			float aux=0;
			for(int j=0;j<tlc;j++){
				
				aux+=a[tlf][j];}
			aux/=tlc;
			return aux;}
	
//------------mejora--------------------------
float promedioF(int a[],int tl){
//puedo pasar la fila a la que quiero calcular el promedio y el tl de columnas
//no puedo hacer eso para promedio de columnas por la organizacion de los arreglos en fxc
	float aux=0;
	for(int i=0;i<tl;i++) aux+=a[i];	
	
	aux/=tl;
	return aux;}
	float ultimaspruebas(int a[][n],int tlf,int tlc){
		float prom=0;
		for(int i=tlc-3;i<tlc;i++){
		float aux=promedioColumna(a,tlf,i);
		if(prom<aux){prom=aux;}}
		
	return prom;	}
void intercambiar(int& a,int& b){ int aux=a; a=b; b=aux;} 	
//---------------------Tipos de matrices-------------------------------
/*void transpuesta (int a[][n],int tl){  //matrices cuadradas 
	for(int i=0;i<tl;i++){
		for(int j=0;j<i;j++){if(i!=j){intercambiar(a[i][j],a[j][i]);}
	}
}}
void transpuestaG(int a[][n],int&filas,int & columnas){
	
for(int i=0;i<filas;i++){
	int j=0+i;
	for(;j<=columnas;j++){
		intercambiar(a[i][j],a[j][i]);
	}
}
int aux=filas;
filas=columnas;
columnas=aux;}
int mayorMatriz(int a[][n],int filas,int columna){
	int mayor=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columna;j++){
			if(a[i][j]>mayor)	mayor=a[i][j];}
			}
return mayor;}
int mayorDiagonalPrincipal(int a[][n],int filas,int columna){
	if(filas!=columna){return -1;}
	int aux=0;
	for(int i=0;i<filas;i++){
		if(aux<a[i][i]) aux=a[i][i];}
	return aux;}
	int mayorDiagonalSecundaria(int a[][n],int filas,int columna){
		//filas arranca en 0 y columnas en tl-1 y mientras una crece la otra decrede
		if(filas!=columna){return -1;}
		int aux=0,j=0;
		for(int i=filas-1;i>0;i--){
			if(aux<a[j][i]) aux=a[j][i];
		j++;}
		return aux;}	
int mayorFila(int a[],int tl){
	//paso toda una fila y el tl pero de las columnas
	int mayor=0;
	for(int i=0;i<tl;i++) if(mayor<a[i]) mayor=a[i];
return mayor;}
int mayorColumna(int a[][n],int tlf, int c){
	//Dejo una columna c estatica y recorro todas las filas de esa columna
	int mayor=0;
	for(int i=0;i<tlf;i++){
		if(mayor<a[i][c]) mayor=a[i][c];}
	return mayor;}
int mayorSumaColumna(int a[][n],int fila,int columna){
	int mayor=0,indice=0;
//invierto el recorrido del usual filas columnas a recorrer todas las filas de una columna para hacer la sumatoria y encontrar el mayor	
	for(int i=0;i<columna;i++){
	int suma=0;
	int j=0;
		for(;j<fila;j++){
				suma+=a[j][i];}
		if(suma>mayor){mayor=suma; indice=i;}
			}
return indice;}*/
