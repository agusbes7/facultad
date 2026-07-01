#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
#define n 100
void inicializar(int [],int);
void mostrar(int [],int);
void pruebas();
int main(int argc, char *argv[]) {
	//pruebas();
	float num1=3.14,num2=6.022;
	float *pnum=NULL;
	pnum=&num1;
	
	cout<<"punum: "<<*pnum<<endl;
	num2=*pnum;
	cout<<"Num2: "<<num2<<endl;
	cout<<"pnum: "<<pnum<<endl;
	cout<<"Num2: "<<&num2<<endl;
	return 0;
}

void inicializar(int a[],int tl){
	srand(time(NULL));
	for(int i=0;i<tl;i++) { a[i]=rand()%200; }
}
void mostrar(int a[],int tl){
	for(int i=0;i<tl;i++) { cout<<a[i]<<" "; }
cout<<endl;}
void pruebas(){
	int *a[10]={NULL};
	int b[n]={0}, tl=10;
	inicializar(b,tl);
	mostrar(b,tl);
	for(int i=0;i<10;i++){
		a[i]=&b[i];}
	mostrar(*a,tl);
	
	cout<<*(a+2)<<endl;
	cout<<(a+2)<<endl;
	cout<<*(*(a+2));
	
	
}
	
	void ejemplo(){
		int *a=NULL, b=5;
		a=&b;
		
		
		cout << "Valor apuntado por a (*a): " << *a << endl;
		cout << "Direccion del puntero a (&a): " << &a << endl;
		cout << "Valor de b: " << b << endl;
		cout << "Direccion de b (&b): " << &b << endl;
		cout << "Valor de a (lo que guarda el puntero): " << a << endl;
	}
void inverso(){
	char aux[]="dabale arroz a la zorra el abad";
	char *p=aux;
	
	int x=strlen(aux);
	
	for(int i=x-1;i>=0;i--){cout<<*(p+i);}
	
}
