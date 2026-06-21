#include <iostream>      // Para las operaciones de entrada/salida
#include <vector>       // Para utilizar la clase vector
#include <algorithm>    // Para funciones de algoritmos como sort
#include <sstream>      // Para utilizar stringstream
#include <cstring>   
using namespace std;
#define N 20
#define D 10
#define M 50
#define C 4
struct sorteo{
	int sorteo[20];
	int estadisticas[C][D]={0};
int mayores[C];};
int unidad(int);
int decena(int);
int centena(int);
int uniMil(int);
int doscifras(int);
int trescifras(int);
void inicializar(int[]);
//-----------------------------------
void combinaciones3(int );
void combinaciones4(int );
//----------------------------------
void mostrarEstadisticas(sorteo);
void estadisticas(sorteo&);
//---------------------------------------
void obtenerMayores(sorteo& );
void mostrarMayores(sorteo& );

int main(int argc, char *argv[]) {
	sorteo A = {{1234, 4321, 5678, 8765, 9999, 1000, 2020, 3333, 4444, 5555, 
		6666, 7777, 8888, 9009, 1010, 2022, 3030, 4040, 5050, 6060}};
	
	estadisticas(A);
	mostrarEstadisticas(A);
//	mostrarMayores(A);
	return 0;
}

//--------------------------------------------------------------- 
int unidad(int x){return x%10;}
int decena(int x){ return unidad(x/10);}
int centena(int x){ return decena(x/10);}
int uniMil(int x){ return x/1000;}
//------------------------------------------
int doscifras(int x){ return decena(x)*10+unidad(x);}
int trescifras(int x){return centena(x)*100+doscifras(x);}
//---------------------------------------------------
int combinaciones3(int x, int y){
	int aux[3];
	aux[0]=centena(x);				aux[1]=decena(x);			aux[2]=unidad(x);
	
	int combinaciones[6][3] = {
		{aux[0], aux[1], aux[2]},  		{aux[0], aux[2], aux[1]},
		{aux[1], aux[0], aux[2]},		{aux[1], aux[2], aux[0]},
		{aux[2], aux[0], aux[1]},		{aux[2], aux[1], aux[0]}};  
		
		for (int i = 0; i < 6; i++) {
			cout << i + 1 << ": " << combinaciones[i][0] << combinaciones[i][1] << combinaciones[i][2] <<" - ";
			if(i>0 and i%2==0){cout<<endl;}}
		if (y >= 1 && y <= 6) {
			return combinaciones[y - 1][0] * 100 + combinaciones[y - 1][1] * 10 + combinaciones[y - 1][2];
		} else {return -1;}}
	
	
int combinaciones4(int x, int y){
	int aux[4];
	aux[0] = uniMil(x);			aux[1] = centena(x);			aux[2] = decena(x); 			aux[3] = unidad(x);
	
	int combinaciones[24][4] = {
		{aux[0], aux[1], aux[2], aux[3]},		{aux[0], aux[1], aux[3], aux[2]},  
		{aux[0], aux[2], aux[1], aux[3]},		{aux[0], aux[2], aux[3], aux[1]},  
		{aux[0], aux[3], aux[1], aux[2]},		{aux[0], aux[3], aux[2], aux[1]},  
		{aux[1], aux[0], aux[2], aux[3]},		{aux[1], aux[0], aux[3], aux[2]},  
		{aux[1], aux[2], aux[0], aux[3]},		{aux[1], aux[2], aux[3], aux[0]},  
		{aux[1], aux[3], aux[0], aux[2]},		{aux[1], aux[3], aux[2], aux[0]},  
		{aux[2], aux[0], aux[1], aux[3]},		{aux[2], aux[0], aux[3], aux[1]},  
		{aux[2], aux[1], aux[0], aux[3]},		{aux[2], aux[1], aux[3], aux[0]},  
		{aux[2], aux[3], aux[0], aux[1]},		{aux[2], aux[3], aux[1], aux[0]},  
		{aux[3], aux[0], aux[1], aux[2]},		{aux[3], aux[0], aux[2], aux[1]},  
		{aux[3], aux[1], aux[0], aux[2]},		{aux[3], aux[1], aux[2], aux[0]},  
		{aux[3], aux[2], aux[0], aux[1]},		{aux[3], aux[2], aux[1], aux[0]}};
	
	
	for (int i = 0; i < 24; i++) {
		cout << i + 1 << ": " << combinaciones[i][0] << combinaciones[i][1] << combinaciones[i][2] << combinaciones[i][3]<<" - ";
	if(i>0 and i%3==0){cout<<endl;}}
	
	
	if (y >= 1 && y <= 24) {		
						return combinaciones[y - 1][0] * 1000 + combinaciones[y - 1][1] * 100 + combinaciones[y - 1][2] * 10 + combinaciones[y - 1][3];}
	else {
		return -1;}
}
//----------------------------------------------------
	void estadisticas(sorteo& A) {
		for (int i = 0; i < 20; i++) {
			int num = A.sorteo[i];
			
			// Incrementar las estadísticas para cada posición de dígitos
			A.estadisticas[0][uniMil(num)]++;    // Unidad de mil
			A.estadisticas[1][centena(num)]++;   // Centena
			A.estadisticas[2][decena(num)]++;    // Decena
			A.estadisticas[3][unidad(num)]++;    // Unidad
		}
		char c[20]="hola mundo";
	obtenerMayores(A,c);}
	void mostrarMayores(sorteo& A) {
		const char* posiciones[C] = {"Unidad de mil", "Centena", "Decena", "Unidad"};
		
		for (int i = 0; i < C; i++) {
			cout << "Mayores en la " << posiciones[i] << ": " << A.mayores[i] << endl;
		}
	}
	
	void mostrarEstadisticas(sorteo A) {
		const char* posiciones[] = {"Mil:", "Cen:", "Dec:", "Uni:"};
		
		// Mostrar encabezado de dígitos con tabulaciones adicionales
		cout << "      0   1   2   3   4   5   6   7   8   9" << endl;
		
		// Mostrar estadísticas por posición
		for (int i = 0; i < C; i++) {
			cout << posiciones[i] << "  ";
			for (int j = 0; j < D; j++) {
				cout << A.estadisticas[i][j] << "   ";  // Agregar espacios para alineación
			}
			cout << endl;
		}
	}
	void obtenerMayores(sorteo& A, char extras[]) {
		int mayores[C]; // Arreglo para almacenar los mayores de cada posición
		
		for (int i = 0; i < C; ++i) {
			mayores[i] = 0; // Inicializar el mayor de cada posición
			
			for (int j = 0; j < D; ++j) {
				// Encontrar el máximo en cada posición
				if (A.estadisticas[i][j] > A.estadisticas[i][mayores[i]]) {
					mayores[i] = j; // Guardar el índice del mayor
				}}
		A.mayores[i]=mayores[i];}}
	void inicializar(int a[]){
		for(int i=0;i<20;i++){
			cin>>a[i];}}
