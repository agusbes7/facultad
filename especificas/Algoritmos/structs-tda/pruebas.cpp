#include <iostream>
#include "pila.h"
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	pila p=crearPila();
	int h;
	apilar(p,3);
	apilar(p,8);
	apilar(p,5);
	mostrar(p);
	invertir(p);
	mostrar(p);
	desapilar(p,h);
	mostrar(p);
	desapilar(p,h);
	desapilar(p,h);
	cout<<setfill('-')<<setw(15)<<"-"<<endl;
	mostrar(p);
	return 0;
}

