#ifndef ARCHIVOS_H
#define ARCHIVOS_H

class Archivos{
	int fila;
	int columna;
	char **matrizTexto;
	int **matrizNum;
	int **matrizEnteros;
	char **matrizTextEnteros;
	
	public:
		Archivos();
		void crearArchivo();
		void leerArchivo();
		void setDimensiones(int,int);
		int getFila();
		int getColumna();
		int desenmascarar(int,int,int);
		~Archivos();
	protected:
};

#endif
