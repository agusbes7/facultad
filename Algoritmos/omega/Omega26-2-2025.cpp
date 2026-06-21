#include <iostream>
using namespace std;
//Problema peones negros atorados

#define N 100
void cargarMatriz(int [][N],int);
void mostrarMatriz(int [][N],int);
int AtoradosMatriz(int [][N],int);
int AtoradosMatriz2(int [][N],int);
int main(int argc, char *argv[]) {
	int a[N][N],tl;
	cin>>tl;
	cargarMatriz(a,tl);
cout<<AtoradosMatriz2(a,tl);

	return 0;
}

void cargarMatriz( int a[][N],int tl){
	for(int i=0;i<tl;i++){
		for(int j=0;j<tl;j++){
			cin>>a[i][j];
		}
	}
}
	void mostrarMatriz( int a[][N],int tl){
		for(int i=0;i<tl;i++){
			for(int j=0;j<tl;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
int AtoradosMatriz(int a[][N],int tl){
	int cantidad=0;
	int i=0;
	//Fila 0
	for(int j=0;j<tl;j++){
if(a[i][j]==1){cantidad++;}}
//-------------------------------------------------------------------------
//resto
	i++;
	for(;i<tl;i++){
		for(int j=0;j<tl;j++){
int anteriorDiagonal=1;			//analizar columna izquierda o derecha si es j=0 o j=tl-1
			
if(a[i][j]==1){
	int aux=1;
//dividir 2 casos 
if(j==0 or j==tl-1){anteriorDiagonal=(j==0)? 1:-1;}
else{aux=2;}

	
	switch(aux){
			case 1:{
				if(a[i-1][j]!=0 and a[i-1][j+anteriorDiagonal]!=2){cantidad++;}
		break;}
	case 2:{
	if(a[i-1][j]!=0){
		if(a[i-1][j+anteriorDiagonal]!=2 and a[i-1][j-anteriorDiagonal]!=2){cantidad++;}
		
		break;}}}}


}

		
		
		
}
	
	

return cantidad;}

	
	
	int AtoradosMatriz2(int a[][N],int tl){
		int cantidad=0;
		int i=0;
		//Fila 0
		for(int j=0;j<tl;j++){
			if(a[i][j]==1){cantidad++;}}
	i++;
		int izq=0,der=tl-1;
		
	for(;i<tl;i++){
		if(a[i][izq]==1){
			if(a[i-1][izq+1]!=2 and a[i-1][izq]!=0){cantidad++;}}
		if(a[i][der]==1){
			if(a[i-1][der-1]!=2 and a[i-1][der]!=0){cantidad++;}}		
	}
	for(int i=1;i<tl;i++){
		for(int j=1;j<tl-1;j++){
			if(a[i][j]==1){
				int izq=j-1;
				int der=j+1;
	if(a[i-1][j]!=0){
		if(a[i-1][izq]!=2 and a[i-1][der]!=2){cantidad++;}}}}}
				
				
	return cantidad;}
