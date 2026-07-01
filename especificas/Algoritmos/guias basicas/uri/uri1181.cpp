#include <iostream>
#include <iomanip>
using namespace std;
void cargarmatriz(float a[][12]);
float  sumatotal(float a[][12],float&,const int);
int main(int argc, char *argv[]) {
	float a[12][12]; float prom; char ar;
	int fila; cin>>fila;
	do{cin>>ar;}while(ar!='S' and ar!='M');
	cargarmatriz(a);
	float sum=sumatotal(a,prom,fila);
	
	if(ar=='S'){cout<<fixed<<setprecision(1)<<float(sum)<<endl;}
	else{cout<<fixed<<setprecision(1)<<prom<<endl;}
	
	return 0;}
void cargarmatriz(float a[][12]){
	for(int i=0;i<12;i++) { 
		for(int j=0;j<12;j++) { 
			cin>>a[i][j];}}
	return;}
	float  sumatotal(float a[][12],float & aux,const int fila){
		int can=0; float sum=0;
		for(int i=0;i<12;i++) {sum+=a[fila][i];
				can++;}
		aux=sum/(float(can));
		return sum;}
		
