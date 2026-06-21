#define TF 20
struct pila{
	int pila[TF];
	int TL;
};
//interfaz publica
bool  apilar(pila&,int valor);
bool desapilar(pila&,int& valor);
pila crearPila();
bool vacia(pila p);
bool llena(pila p);
void mostrar(pila p);
void invertir(pila& p);
