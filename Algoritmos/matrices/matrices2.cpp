#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define n 40
#define x 5
void mostrar(int [][n],int,int);
void cargar(int [][n],int,int);
void cargar(int [][n],int);
void cargarxRand(int[][n],int,int);
float promedioColumna(int [][n],int,int);
float promediofila(int [][n],int,int );
float promedioF(int [],int);
//float mayor(float x,float y){ return (x>y)?x:y;}
float ultimaspruebas(int[][n],int,int);
void transpuesta(int [][n],int );
void transpuestaG(int [][n],int&,int& );
//---------------------------------------------
void caracterizar(int [][n],int);

int main(int argc, char *argv[]) {
	int a[][n] = {
		{1, 2, 3},
	{2, 4, 5},
		{3, 5, 6}
	},
	tlf=3;
//	cargarxRand(a,tlf,tlf);
	cargar(a,tlf);
	mostrar(a,tlf,tlf);
caracterizar(a,tlf);

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
		void cargar(int a[][n],int tl){
			
			for(int i=0;i<tl;i++){
				for(int j=0;j<tl;j++){
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
//---------------------Caracterizar matrices cuadradas-------------------------------
void mostrar(int a[][n],int tl){
	
	for(int i=0;i<tl;i++){
		for(int j=0;j<tl;j++){
			cout<<a[i][j]<<" ";}
		cout<<endl;}
}
//----------------------------------------------
	
bool esNula(int a[][n],int tl){
	int i=-1;	 bool nula=true;
		while(nula and i<tl){ 		int j=0; i++;
				while(nula and j<tl){(a[i][j]!=0)? nula=false: j++;}}
	return nula;}
//---------------------------------------------------
bool simetrica(int a[][n],int tl){
	int i=0,sim=1;
while(i<tl and sim){
	int j=0;
	while(j<tl and a[i][j]==a[j][i]) j++;
	if(j<tl){sim=0;}
	i++;}
return sim;}
//---------------------------------------------------
bool DiagonalNula(int a[][n],int tl){
	int i=0;
	while(i<tl and a[i][i]==0)i++;
	return(i<tl)? false:true;}
//---------------------------------------------------
bool TriangularSuperior(int a[][n],int tl){ //elementos por debajo de la diagonal principal nulos
	int i=1,triangular=1;
	while(i<tl and triangular){	int j=0;
	while(j<i and a[i][j]==0) j++;
	(j<i)? triangular=0:i++;}
		return triangular;}
//---------------------------------------------------
bool TriangularInferior(int a[][n],int tl){ //elementos por encima de la diagonal principal nulos
		int i=0,triangular=1;
		while(i<tl and triangular){			int j=i+1;
			while(j<tl and a[i][j]==0) j++;
			(j<tl)? triangular=0:i++;}
		return triangular;}
//---------------------------------------------------
bool Diagonal(int a[][n],int tl){
			int i=0,triangular=1;
	while(i<tl and triangular){	int j=0;
		while(j<tl and triangular){
		if(i==j){ 
			if(a[i][j]==0){triangular=0;}
		}
		else{
			if(a[i][j]!=0){triangular=0;}
		}
		j++;}
	i++;}
return triangular;}
//---------------------------------------------------			
bool marco(int a[][n],int tl){
				int i=0,marco=1;
	while(i<tl and marco){int j=0;
		while(j<tl and marco){
		if(i==0 or j==0 or j==tl-1 or i==tl-1){
						(a[i][j]!=0)? j++: marco=0;}
		else{(a[i][j]!=0)? marco=0:j++;}}
		i++;}
return marco;}
//---------------------------------------------------
bool filanula(int a[][n],int tl){
	int i=0,fnula=0;
	while(i<tl and !fnula){int j=0;
		while(j<tl and a[i][j]==0) j++;
	(j<tl)? i++:fnula=1;}
return fnula;}
//--------------------------------------------------
bool columnaNula(int a[][n],int tl){
	int i=0,cnula=0;
	while(i<tl and !cnula){int j=0;
		while(j<tl and a[j][i]==0) j++;
	(j<tl)? i++:cnula=1;}
return cnula;}
//---------------------------------------------------						
void caracterizar(int a[][n],int tl){
	
cout<<boolalpha<<"Matriz nula?:  "<<esNula(a,tl)<<endl;
cout<<boolalpha<<"Matriz simetrica?: "<<simetrica(a,tl)<<endl;
cout<<boolalpha<<"Diagonal Nula?: "<<DiagonalNula(a,tl)<<endl;
cout<<boolalpha<<"TriangularSuperior?: "<<TriangularSuperior(a,tl)<<endl;
cout<<boolalpha<<"Triangular inferior?: "<<TriangularInferior(a,tl)<<endl;
cout<<boolalpha<<"Diagonal?: "<<Diagonal(a,tl)<<endl;
cout<<boolalpha<<"marco?: "<<marco(a,tl)<<endl;
cout<<boolalpha<<"filaNula?: "<<filanula(a,tl)<<endl;
cout<<boolalpha<<"columnaNula?: "<<columnaNula(a,tl)<<endl;
}

