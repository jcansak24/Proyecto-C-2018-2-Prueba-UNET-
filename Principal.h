#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Archivos.h"

class Principal
{
	Archivos *a;
		
	public:
		Principal();
		void cargarDatos();
		void mostrarDatos();
		~Principal();
	protected:
};

#endif
