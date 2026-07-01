#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
#define n 100
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
void problema1GuiaMatrices(int a[][n],int tl);
void problema2GuiaMatrices(int a[][n],int tlf, int tlc);
bool cuadradoMagico(int a[][n],int tl);
void problema8Nodos(int a[][n],int tl);
void jugada(int a[][n],int tlf,int tlc);
void MatrizEspiral(int [][n],int tl);
void MatrizEspiralInversa(int [][n],int tl);
int main(int argc, char *argv[]) {
	int a[n][n],	tlf=40,tlc=20,tl=6;
	cargarxRand(a,tl,tl);
mostrar(a,tl,tl);
problema8Nodos(a,tl);

	return 0;
}

//------------------------------------------------------------
void mostrar(int a[][n],int fila,int columna){
	
	for(int i=0;i<fila;i++){
		for(int j=0;j<columna;j++){
			cout<<" "<<setfill(' ')<<setw(4)<<a[i][j];}
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
					a[i][j]=rand()%2;}
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
bool cuadradoMagico(int a[][n],int tl){
bool magico= true;
int numeroMagico=0;
int diagonalSecundaria=0;

for(int i=0;i<tl;i++){
	numeroMagico+=a[i][i];
diagonalSecundaria+=a[i][tl-1-i];
}
if(numeroMagico!=diagonalSecundaria){return false;}
//Suma por filas
int i=0;
while(i<tl and magico){
int sumaf=0,j=0;
	while(j<tl){
		sumaf+=a[i][j];
	j++;}
	(sumaf==numeroMagico)? i++:magico=false;
	}
//suma por columnas
i=0;

while(i<tl and magico){
	int sumac=0,j=0;
	while(j<tl){
		sumac+=a[j][i];
		j++;}
	(sumac==numeroMagico)? i++:magico=false;
}
return magico;}
	
	
	

int totalKb(int a[][n],int tl){
	int suma=0;
	for(int i=0;i<tl;i++){
		for(int j=0;j<tl;j++)suma+=a[i][j];

	}
	return suma;}
	int total(int a[][n],int tlf,int tlc){
		int suma=0;
		for(int i=0;i<tlf;i++){
			for(int j=0;j<tlc;j++)suma+=a[i][j];
			
		}
		return suma;}
int mayorEnvioKb(int a[][n],int tl){
	
int mayor=0,indice=0;

for(int i=0;i<tl;i++){
	int sum=0;
	for(int j=0;j<tl;j++)	sum+=a[i][j];
	if(mayor<sum){mayor=sum; indice=i;}
}
return indice;	}
void cotaKb(int a[][n],int tl,int cota){
	
	cout<<"Cota de datos enviados: "<<cota<<endl;
	
	for(int i=0;i<tl;i++){
		int sum=0;
		for(int j=0;j<tl;j++)	sum+=a[j][i];
		if(sum>cota){cout<<"servidor "<<i<<" superó la cota establecida"<<endl;}
	}
	return;	}

void problema1GuiaMatrices(int a[][n],int tl){
	
	cout<<"total de Kb enviados: "<<totalKb(a,tl)<<endl;
	cout<<"Servidor con mayor envios de Kb: "<<mayorEnvioKb(a,tl)<<endl;
	cotaKb(a,tl,2500);
}
int SumaxColumna(int a[][n],int tlf,int c){
	int sum=0;
	for(int i=0;i<tlf;i++){	sum+=a[i][c];}
	return sum;}
int SumaxFila(int a[],int tlc){
	int sum=0;
	for(int i=0;i<tlc;i++){sum+=a[i];}
	return sum;}

void  localidadesNulas(int a[][n],int tlf,int tlc){
	cout<<"localidad en las que no se vendio ningun pasaje"<<endl;
	
	for(int i=0;i<tlc;i++){
		int j=0,suma=0;
		while(suma==0 and j<tlf) {
			suma+=a[j][i];
			j++;}
	if(suma==0){cout<<"Destino: "<<i<<" sin ventas"<<endl;}
		i++;
	}
}

	int localidadMenosVendida(int a[][n],int tlf,int tlc){
		cout<<"localidad en las que no se vendio ningun pasaje"<<endl;
		int b[n]={0};
		for(int i=0;i<tlc;i++){
			for(int j=0;j<tlf;j++)	b[i]+=a[j][i];}
		int menor=0;
		for(int i=1;i<tlc;i++){
			if(b[i]>0 and b[menor]>b[i]){menor=i;}
		}
	return menor;}
		int localidadMasMilPasajeros(int a[][n],int tlf,int tlc){
			int contador=0;
			int b[n]={0};
			for(int i=0;i<tlc;i++){
				int sumador=0;
				for(int j=0;j<tlf;j++)	sumador+=a[j][i];
			if(sumador>1000){contador++;}
			}
			return contador;}
void pasajerosxLocalidad(int a[][n],int tlf,int tlc){
	
	cout<<"Pasajeros por localidad "<<endl;
		for(int i=0;i<tlc;i++){
		cout<<"Destino turistico:  "<<i<<" "<<SumaxColumna(a,tlf,i)<<endl;}
}
	
	void pasajerosxCategoria(int a[][n],int tlf,int tlc){

		cout<<"Pasajeros por categoria"<<endl;
				for(int i=0;i<tlf;i++){
			cout<<"categoria:  "<<i<<" "<<SumaxFila(a[i],tlc)<<endl;}
		}
bool categoriasNulas(int a[][n],int tlf,int tlc){
	bool existen=false;
	int i=0;
	while(i<tlf and !existen){
		int suma=0,j=0;
		while(suma==0 and j<tlc){
			suma+=a[i][j];
			j++;}
		if(suma==0){existen=true;}
		i++;
		}
return existen;	}
	

void problema2GuiaMatrices(int a[][n],int tlf, int tlc){

	pasajerosxCategoria(a,tlf,tlc);
	system("Pause");
	system("cls");
	cout<<"localidad que menos pasajes vendio: "<<localidadMenosVendida(a,tlf,tlc)<<endl;
	cout<<"cantidad de localidades que superaron las 1000 ventas: "<<localidadMasMilPasajeros(a,tlf,tlc)<<endl;
	system("Pause");
	system("cls");
	pasajerosxLocalidad(a,tlf,tlc);
	system("Pause");
	system("cls");
	localidadesNulas(a,tlf,tlc);
	cout<<"Existen categorias de aviones sin ventas?: "<<boolalpha<<categoriasNulas(a,tlf,tlc)<<endl;
}
	
/*
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

*/
	
bool fichasverdes(int a[],int columnas,int index){
	bool verde=true;
if(index+2>=columnas){return false;}
if(a[index+1]==2){
	if(a[index+2]!=2){verde=false;}}
else{verde=false;}
return verde;}
void cambiarfichasverdes(int a[],int columnas,int index){
	a[index]=0;
	a[index+2]=0;
	
}

void jugada(int a[][n],int fila,int columna){
	bool aux=false;
	for(int i=0;i<fila;i++){
		for(int j=0;j<columna;j++){
			if(a[i][j]==2){
		if(fichasverdes(a[i],columna,j)){
			aux=true;
			cambiarfichasverdes(a[i],columna,j);
		
		j+=2;}
			}
		
		}}
cout<<boolalpha<<"True:"<<aux<<endl;	
}
//-------------------------------------------------------
void MatrizEspiral(int a[][n],int tl){
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
void MatrizEspiralInversa(int a[][n],int tl){
	int tlf=tl;
	int tlc=tl;
	int numero=1;
	
	for(int i=tl/2;i>=0;i--){
	for (int j = tlc-i-1; j >= i - 1; j--) {
	a[i][j] = numero++;  // Llenar hacia la izquierda
	}
	
	// 2. Recorrer hacia abajo
	for (int j = i; j <= tlf-1- i; j++) {
	a[j+1][i-1] = numero++;  // Llenar columna hacia abajo
	}
	
	// 3. Recorrer hacia la derecha
	for (int j = i; j <= tlc - i; j++) {
	a[tlf - i][j] = numero++;  // Llenar fila hacia la derecha
	}

	// 4. Recorrer hacia arriba
	for (int j = tlf - i - 1; j >= i; j--) {
	a[j][tlc - i] = numero++;  // Llenar columna hacia arriba
	}
	}
}	
	//-------------------------------------------------------
bool nodosPendiente(int a[][n],int tl,int c){
		int j=0;
		int pendiente=0;
		while(j<tl and pendiente<2){
			if(a[c][j]==1){pendiente++;}
			j++;}
		return (pendiente==1)? true:false;}
	
	bool nodosAislados(int a[][n],int tl,int c){
			int j=0;
			int pendiente=0;
			while(j<tl and pendiente<1){
				if(a[c][j]==1){pendiente++;}
				j++;}
			return (pendiente==0)? true: false;}
	bool gradosNodos(int a[][n],int tl){
		bool grado=true;
		int i=0;
		whle(grado and i<tl){
			int j=0,cnt=0;
			while(j<tl and cnt<3){
				if(i!=j){
				if(a[i][j]==1){cnt++;}}
				j++;}
			if(cnt!=2){ grado=false;}
			i++;}
			return grado;}
	bool NodoCicloEucleriano(int a[][n],int tl){
	if(!gradosNodos(a,tl)){return false;}
	bool ciclo=true;
	
		
	}
	void problema8Nodos(int a[][n],int tl){
	
	cout<<"nodo "<<0<<" aislado?: "<<boolalpha<<nodosAislados(a,tl,0)<<endl;
	cout<<"nodo "<<1<<" pendiente?: "<<boolalpha<<nodosPendiente(a,tl,1)<<endl;
}
