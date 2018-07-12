#include "Principal.h"
#include <iostream>
#include <string.h>

using namespace std;

Principal::Principal(){
	a = new Archivos();
}

void Principal::mostrarDatos(){
	a->leerArchivo();
}


Principal::~Principal(){}
