#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
#define N 100

void cargarMatrizCuadrada(int [][N],int );
void cargarMatrizCuadradaR(int [][N],int );
void cargarMatriz(int [][N],int fila,int  columna );
void cargarMatrizR(int a[][N],int fila,int columna );
void cargarMatrizR(int a[][N],int fila,int modulo );
//-----------------------------------------------------------
void mostrarMatriz(int [][N],int );
void mostrarMatrizCuadrada(int a[][N],int tl);
void mostrarMatrizR(int [][N],int );
void mostrarMatriz(int [][N],int fila,int  columna );
int sumaxFila(int [],int tl);
int sumaxColumna(int [][N],int col,int tl);
void estudioMatrizCuadrada(int a[][N],int tl);
//--------------------------------------
void prueba();
void llenadomagico(int[][N],int);
int main(int argc, char *argv[]) {
	//prueba();
	int a[N][N],tl=20;
	llenadomagico(a,tl);
	mostrarMatrizCuadrada(a,tl);
	return 0;
}

//--------MANUAL--------------------------
void cargarMatrizCuadrada(int a[][N],int tl ){
	
	for(int i=0;i<tl;i++){
		for(int j=0;j<tl;j++){
			cin>>a[i][j];}}}
	//---------Aleatoria-----------------------
	void cargarMatrizCuadradaR(int a[][N],int tl ){
		srand(time(0));
		for(int i=0;i<tl;i++){
			for(int j=0;j<tl;j++){
				a[i][j]=rand()%1000;}}}
//--------MANUAL--------------------------
	void cargarMatriz(int a[][N],int fila,int  columna ){
	for(int i=0;i<fila;i++){
		for(int j=0;j<columna;j++){cin>>a[i][j];}}}
//---------Aleatoria-----------------------
void cargarMatrizR(int a[][N],int fila,int columna ){
srand(time(0));
for(int i=0;i<fila;i++){
	for(int j=0;j<columna;j++){a[i][j]=rand()%1000;}}}
//---------Aleatoria con modulo para la funcion rand-----------------------
void cargarMatrizR(int a[][N],int fila,int columna,int modulo ){
srand(time(0));
for(int i=0;i<fila;i++){
	for(int j=0;j<columna;j++){a[i][j]=rand()%modulo;}}}
//-------------------------------------------------
//-------------------------------------------------
//-------------------------------------------------
					void mostrarMatrizCuadrada(int a[][N],int tl){
						for(int i=0;i<tl;i++){
							for(int j=0;j<tl;j++){
								cout<<a[i][j]<<" ";}
							cout<<endl;}}
						
						void mostrarMatriz(int a[][N],int fila,int columna){
							for(int i=0;i<fila;i++){
								for(int j=0;j<columna;j++){
									cout<<a[i][j]<<" ";}
								cout<<endl;}}
//-------------------------------------------------
//-------------------------------------------------
							
int sumaxFila(int a[],int tl){
								int sum=0;
								for(int i=0;i<tl;i++){sum+=a[i];}
								return sum;}
int sumaxColumna(int a[][N],int c,int tlf){
									int sum=0;
									
									for(int i=0;i<tlf;i++){sum+=a[i][c];}
									return sum;}
									
int diagonalPrincipal(int a[][N],int tl){
										
										int suma=0;
										for(int i=0;i<tl;i++){ suma+=a[i][i];}
										return suma;}
										
int diagonalSecundaria(int a[][N],int tl){
											int suma=0;
											for(int i=0;i<tl;i++){suma+=a[i][tl-1-i];}
											return suma;}
											
void itema(int a[][N],int tl){
												for(int i=0;i<tl;i++){
													int total=0;
													for(int j=0;j<tl;j++){
														total+= (i==j)? 0:a[i][j];
													}
													cout<<"Servidor: "<<i<<" Total de kbEnviados: "<<total<<endl;
													cout<<"prueba funcion"<<endl;
													cout<<i<<" : "<<sumaxFila(a[i],tl)<<endl;
												}}
void itemb(int a[][N],int tl){
													int mayor=sumaxFila(a[0],tl);
													int indice=0;
													for(int i=1;i<tl;i++){
														int aux=sumaxFila(a[i],tl);
														
														if(mayor<aux){
															mayor=aux;
															indice=i;
														}
													}
													cout<<"servidor que mas envio :"<<indice<<endl;}
													
void itemc(int a[][N],int tl,int cota){
														
														for(int i=0;i<tl;i++){
															int aux= sumaxColumna(a,i,tl);
															if(aux>cota){cout<<"servidor: "<<i<<" recibio datos por encima de la cota"<<endl;
															}
														}
													}
void prueba(){
															int a[N][N],b[N][N],c[N][N];
															int tlf,tlc,tl;
															tl=3;
															cargarMatrizR(a,tl,tl,100);
															cout<<"problema 1"<<endl;
															mostrarMatrizCuadrada(a,tl);
															itema(a,tl);
															itemb(a,tl);
															itemc(a,tl,300);
															
															
															cout<<setfill('-')<<setw(25)<<"-"<<endl;
															system("Pause");
															system("cls");
															
															cout<<endl<<"Matrices cuadrada estudio"<<endl;
															cargarMatrizR(b,tl,tl,2);
															mostrarMatrizCuadrada(b,tl);
															estudioMatrizCuadrada(b,tl);
															cout<<setfill('-')<<setw(25)<<"-"<<endl;
															system("Pause");
															system("cls");
															
														}
															
															
															
															
bool triangularSuperior(int a[][N],int tl){
																bool triangular =true;
																int i=1;
																while(triangular and i<tl){
																	int j=0;
																	while(triangular and j<i){
																		triangular=(a[i][j]==0)?true:false;
																		j++;}
																	i++;}
																return triangular;}
bool triangularInferior(int a[][N],int tl){
																	bool triangular =true;
																	int i=0;
																	while(triangular and i<tl){
																		int j=i+1;
																		while(triangular and j<tl){
																			triangular=(a[i][j]==0)?true:false;
																			j++;}
																		i++;}
																	return triangular;}
bool filaNula(int a[][N],int tl){
																		int i=0,fnula=0;
																		
																		while(i<tl and !fnula){
																			
																			int j=0;
																			while(j<tl and a[i][j]==0) j++;
																			
																			(j<tl)? i++:fnula++;}
																		return fnula;}
bool columnaNula(int a[][N],int tl){
																			int i=0,fnula=0;
																			
																			
																			while(i<tl and !fnula){
																				
																				int j=0;
																				while(j<tl and a[j][i]==0) j++;
																				
																				(j<tl)? i++:fnula++;}
																			return fnula;}
bool identidad(int a[][N],int tl){
																				bool f=true;
																				int i=0;
																				while(f and i<tl){
																					int j=0;
																					while(j<tl and f){
																						
																						if(i==j){ f= (a[i][j]==1)? true:false;}
																						else{
																							f= (a[i][j]!=0)? false:true;}
																						j++;}
																					i++;}
																				return f;}
void llenadomagico(int a[][N],int tl){
	int tlf=tl;
	int tlc=tl;
	int numero=1;
	
	for(int i=0;i<tlf;i++){
		//derecha
		int j=i;
		for(;j<tlc;j++){a[i][j]=numero++;}
		//abajo
		j=i+1;
		for(;j<tlf;j++){a[j][tlc-1]=numero++;}
		tlc--;
		//izquierda
		j=tlc-1;
		for(;j>=i;j--){a[tlf-1][j]=numero++;}
		--tlf;
		//arriba 
		j=tlf-1;
		for(;j>i;j--){a[j][i]=numero++;}
	}
}
	
void estudioMatrizCuadrada(int a[][N],int tl){
																					
																					
																					cout<<endl;
																					cout<<"suma elementos diagonalPrincipal: "<<diagonalPrincipal(a,tl)<<endl;
																					cout<<"suma elementos diagonalSecundaria: "<<diagonalSecundaria(a,tl)<<endl;
																					cout<<"triangularInferior: "<<triangularInferior(a,tl)<<endl;
																					cout<<"triangularSuperior: "<<triangularSuperior(a,tl)<<endl;
																					cout<<"fila nula:" <<filaNula(a,tl)<<endl;
																					cout<<"columna nula: "<<columnaNula(a,tl)<<endl;
																				}
																					
