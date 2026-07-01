#define TF 20

struct cola{
	int primero,ultimo;
	int datos[TF];
	
};

cola crearCola();
bool agregarElem(cola& c,int elemento);
bool desencolarElem(cola& c,int elemento);
bool vacia(cola c);
bool llena(cola c);
void mostraCola(cola c);
