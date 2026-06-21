#include <iostream>
using namespace std;
#define N 50
void cargarMatriz(int a[][N],int tlf,int tlc);
void mostrarMatriz(int a[][N],int tlf,int tlc);
void transpuesta(int a[][N],int& tlf,int& tlc);
int main(int argc, char *argv[]) {
	int a[N][N],tlf=3,tlc=3;
	cargarMatriz(a,tlf,tlc);
	mostrarMatriz(a,tlf,tlc);
	transpuesta(a,tlf,tlc);
	mostrarMatriz(a,tlf,tlc);	
	return 0;
}

void cargarMatriz(int a[][N],int tlf,int tlc){
	for(int i=0;i<tlf;i++){
		for(int j=0;j<tlc;j++){cin>>a[i][j];}
}}
void mostrarMatriz(int a[][N],int tlf,int tlc){
	for(int i=0;i<tlf;i++){
		for(int j=0;j<tlc;j++){cout<<" "<<a[i][j];}
	
	cout<<endl;}
}
	void intercamio(int&x,int&y){ int aux=x;   x=y; y=aux;}
void transpuestaCuadrada(int a[][N],int tl){
	
	for(int i=0;i<tl;i++){
		for(int j=i+1;j<tl;j++){intercamio(a[i][j],a[j][i]);
	}
}}
void transpuesta(int a[][N],int& tlf,int& tlc){
		for(int i=0;i<tlf;i++){
			
			for(int j=i+1;j<tlc;j++){intercamio(a[i][j],a[j][i]);
		}}
intercamio(tlf,tlc);}
