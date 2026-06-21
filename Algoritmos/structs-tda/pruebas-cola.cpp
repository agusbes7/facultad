#include <iostream>
#include "cola.h"
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	cola c=crearCola();
	agregarElem(c,3);
	agregarElem(c,5);
	agregarElem(c,8);
	agregarElem(c,1);
	mostraCola(c);
	int x;
	desencolarElem(c,x);
	mostraCola(c);
	
	return 0;
}
