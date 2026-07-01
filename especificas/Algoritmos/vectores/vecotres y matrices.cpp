#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define tam 50

void cargarvector(int [],int);
void cargarvectorrand(int [],int);
void mostrar(int [],int);
//----------------------
void insertarxIndice(int [],int&,int,int);
void insertar(int [],int&,int);
//----------------------
void borrarxIndice(int [],int&,int);
void borraxValor(int [],int&,int);
void borraxValorT(int [],int&,int);
//----------------------
void intercambiar(int [],int,int,int);
//----------------------
int mayor(int [],int,int,int);
int mayor(int [],int);
//----------------------
int buscar(int [],int,int);
int mayor(int x,int y){ return (x>=y)? x:y;}
//----------------------
void intercambio(int &x,int &y){ int aux=x; x=y; y=aux;}
//----------------------
void rotacionIzq(int [],int);
void rotacionDer(int [],int);

int main(int argc, char *argv[]) {
	int a[tam],tl=25;
	cargarvectorrand(a,tl);
	mostrar(a,tl);
	int aux;
	/*cout<<"valor:";
	cin>>aux;
	insertarxIndice(a,tl,-1,aux);
	mostrar(a,tl);
	borrarxIndice(a,tl,4);
	mostrar(a,tl);
	cout<<"mayor entre: 5 y 15 :"<<mayor(a,tl,5,15);
	cout<<"mayor entre todos :"<<mayor(a,tl);*/
//borraxValor(a,tl,aux);
cout<<endl;
/*int num1,num2;
	cin>>num1;
cin>>num2;
intercambiar(a,tl,num1,num2);
rotacionDer(a,tl);*/
rotacionIzq(a,tl);
mostrar(a,tl);
	return 0;
}

void mostrar( int a[],int tl){
	for(int i=0;i<tl;i++){
		cout<<a[i]<<"-";
	}
	cout<<endl;
}
	void cargarvector( int a[],int tl){
		for(int i=0;i<tl;i++){
			cin>>a[i];
			
		}
		cout<<endl;
	}	
void cargarvectorrand( int a[],int tl){
	srand(time(NULL));
	for(int i=0;i<tl;i++){
		a[i]=rand()%100;
	
	}
	cout<<endl;}
//_-------------------------------------------------------------
	int buscar(int a[],int tl,int elem){
		int b=-1;
		int i=0;
		while(i<tl and b==-1){
			if(a[i]==elem){b=i;}
			i++;}
		return b;
	}
		void insertar(int a[],int &tl,int elem){
			a[tl]=elem;
			tl++;}
		void insertarxIndice(int a[],int &tl,int elem,int posicion){
	
			for(int i=tl;i>posicion;i--){
				a[i]=a[i-1];
			}
			a[posicion]=elem;
			tl++;
		}
			void borrarxIndice(int a[],int &tl,int ind){
				for(int i=ind;i<tl;i++){
					a[i]=a[i+1];
				}
			tl--;}
void borraxValor(int a[],int& tl,int valor){
	int aux=buscar(a,tl,valor);
	if(aux==-1){cout<<"no existe el elemento"<<endl;}
	else{
		for(int i=aux;i<tl;i++){
			a[i]=a[i+1];}
		tl--;
		}
	}
	void borraxValorT(int a[],int& tl,int valor){
	int i=0;
	int aux=buscar(a,tl,valor);
	while(aux!=-1){
	for(int i=aux;i<tl;i++){a[i]=a[i+1];}
			tl--;
	aux=buscar(a,tl,valor);	
	}
	}
		
		
				//------------------------------------
int mayor(int a[],int tl,int inf,int sup){
	int may=a[inf];
	for(int i=inf+1;i<sup;i++){
		may=mayor(may,a[i]);
	}
return may;}
int mayor(int a[],int tl){
	int may=a[0];
	
	for(int i=1;i<tl;i++){
	may=mayor(may,a[i]);}
return may;}
//-------------------------------------------------------------
	void intercambiar(int a[],int tl,int val,int val2){
		int x=buscar(a,tl,val);
		int y=buscar(a,tl,val2);
		if(x!=-1 and y!=-1){intercambio(a[x],a[y]);
	}
	}
		
		void rotacionIzq(int a[],int tl){
			int aux=a[0];
			for(int i=1;i<tl;i++){
				a[i-1]=a[i];
			}
			a[tl-1]=aux;
		}
		void rotacionDer(int a[],int tl){
			int aux=a[tl-1];
			for(int i=tl-1;i>0;i--){
				a[i]=a[i-1];
			}
			a[0]=aux;
		}
		
		
		
