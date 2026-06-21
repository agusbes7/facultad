#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#define n 1000
struct fecha{
	int dia,mes,anio;};
struct Persona{
	char nombre[n];
	int edad;
	bool vivo=true;
	fecha nacimiento;};
fecha cargarFecha(int dia,int mes,int anio){
	fecha a;
	a.dia=dia;
	a.mes=mes;
	a.anio=anio;
	return a;
}
fecha cargarFecha(int datos[]){
		fecha a;
		a.dia=datos[0];
		a.mes=datos[1];
		a.anio=datos[2];
		return a;
	}
void mostrarFecha(fecha a){
	cout<<"fecha de nacimiento: ";
	cout<<a.dia<<" del "<<a.mes<< " de "<<a.anio<<endl;
}
Persona cargarPersona(){
	int edad, fechas[3];
	char aux[n];
	
	cout<<"edad: ";
	cin>>edad;
	cout<<"dia: ";
	cin>>fechas[0];
	cout<<" mes ";
	cin>>fechas[1];
	cout<<" anio: ";
	cin>>fechas[2];
fecha fec=cargarFecha(fechas);
cout<<endl<<"Nombre: ";
cin>>ws;
cin.getline(aux,n);
Persona a;
a.edad=edad;
a.nacimiento=fec;
strcpy(a.nombre,aux);
return a;}
	Persona cargarPersona(int i) {
		Persona a;
		switch (i) {
		case 0:
			a.edad = 25;
			a.nacimiento.dia = 12;
			a.nacimiento.mes = 5;
			a.nacimiento.anio = 1999;
			strcpy(a.nombre, "Juan Pérez");
			break;
		case 1:
			a.edad = 30;
			a.nacimiento.dia = 8;
			a.nacimiento.mes = 11;
			a.nacimiento.anio = 1994;
			strcpy(a.nombre, "María González");
			break;
		case 2:
			a.edad = 22;
			a.nacimiento.dia = 3;
			a.nacimiento.mes = 7;
			a.nacimiento.anio = 2002;
			strcpy(a.nombre, "Carlos Ramírez");
			break;
		case 3:
			a.edad = 28;
			a.nacimiento.dia = 15;
			a.nacimiento.mes = 9;
			a.nacimiento.anio = 1996;
			strcpy(a.nombre, "Laura Fernández");
			break;
		case 4:
			a.edad = 35;
			a.nacimiento.dia = 27;
			a.nacimiento.mes = 2;
			a.nacimiento.anio = 1989;
			strcpy(a.nombre, "Andrés López");
			break;
		case 5:
			a.edad = 21;
			a.nacimiento.dia = 10;
			a.nacimiento.mes = 4;
			a.nacimiento.anio = 2003;
			strcpy(a.nombre, "Sofía Martínez");
			break;
		case 6:
			a.edad = 40;
			a.nacimiento.dia = 5;
			a.nacimiento.mes = 6;
			a.nacimiento.anio = 1984;
			strcpy(a.nombre, "Diego Torres");
			break;
		case 7:
			a.edad = 19;
			a.nacimiento.dia = 30;
			a.nacimiento.mes = 8;
			a.nacimiento.anio = 2005;
			strcpy(a.nombre, "Camila Suárez");
			break;
		case 8:
			a.edad = 32;
			a.nacimiento.dia = 21;
			a.nacimiento.mes = 12;
			a.nacimiento.anio = 1992;
			strcpy(a.nombre, "Javier Ríos");
			break;
		case 9:
			a.edad = 27;
			a.nacimiento.dia = 14;
			a.nacimiento.mes = 10;
			a.nacimiento.anio = 1997;
			
		}
		return a;}
void leer(char nombreFile[]);
void escribir(char nombreFile[]);
void leerBinario(char nombreFile[]);
void escribirBinario(char nombreFile[],Persona a);
void leerBinario1Dato(char nombreFile[],int x);
int main(int argc, char *argv[]) {
Persona dat[10];
char bin[]="bddPersonas.bin";
//	for(int i=0;i<10;i++){
//	dat[i]=cargarPersona(i);}
//	
//	escribirBinario(bin,dat[0]);
//	escribirBinario(bin,dat[1]);
//	escribirBinario(bin,dat[2]);
//	escribirBinario(bin,dat[3]);
//	escribirBinario(bin,dat[4]);
	
leerBinario(bin);
//leerBinario(bin);
	return 0;
}
void leer(char nombreFile[]){
	char c;
	int a;
	float b;
	ifstream f;
	f.open(nombreFile);
	if(f.fail()){ cout<<"Fallo la apertura del fichero o no existe"<<endl;
	return;}
//leer hasta fin de archivo
	while(f.get(c)) cout<<c;
//	f>>c>>a>>b;
//	while(!f.eof()){
//		cout<<c<<" "<<a<<" "<<b<<endl;
//	f>>c>>a>>b;}
	
	
	f.close();}
	void escribir(char nombreFile[]){
		ofstream f;
		f.open(nombreFile);
		if(f.fail()){ cout<<"Fallo la apertura del fichero o no existe"<<endl;
		return;}
		char texto[n],c;
	cin.getline(texto,n,'\n');
	f <<endl<<texto << endl;  // Agrega el texto al archivo con un salto de línea
	f.close();
	}

	
void escribirBinario(char nombreFile[],Persona a){
	ofstream f;
	f.open(nombreFile,ios::binary|ios::app);
	if(f.fail()){
		cout<<"fallo la apertura del archivo";
		return;}

	f.write((char *)(&a),sizeof(a));
	f.close();
	}
void leerBinario(char nombreFile[]){
	Persona a;
	ifstream f;
	f.open(nombreFile,ios::binary);
	if(f.fail()){
		cout<<"fallo la apertura del archivo";
		return;}

	while(f.read((char*)&a, sizeof(a))){
		cout<<a.nombre<<endl;
		cout<<" edad: "<<a.edad<<endl;
		cout<<" actividad: "<<boolalpha<<a.vivo;
		cout<<endl;
		mostrarFecha(a.nacimiento);
	}
	f.close();}
	void leerBinario1Dato(char nombreFile[],int x){
		Persona a;
		ifstream f;
		f.open(nombreFile,ios::binary);
		if(f.fail()){
			cout<<"fallo la apertura del archivo";
			return;}
		f.seekg(0, ios::end); // Mueve el puntero al final para obtener el tamaño del archivo
		long fileSize = f.tellg(); // Obtiene la posición del puntero al final (tamaño del archivo)
		if (x >= fileSize || x < 0) {
			cout << "Posición no válida en el archivo" << endl;
			f.close();
			return;
		}
		f.seekg(x*sizeof(a),ios::beg);
		f.read((char*)&a, sizeof(a));
		cout<<a.nombre<<endl;
		cout<<" edad: "<<a.edad<<endl;
		cout<<" actividad: "<<boolalpha<<a.vivo;
		cout<<endl;
		mostrarFecha(a.nacimiento);
		f.close();}
