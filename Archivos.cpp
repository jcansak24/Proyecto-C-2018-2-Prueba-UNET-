#include "Archivos.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Principal.h"

using namespace std;

Archivos::Archivos(){
	columna=4;
}

void Archivos::crearArchivo(){
	ofstream archivo;
	archivo.open("PRUEBA.txt",ios::out);//abriendo o creando el archivo
	if(archivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);
	}else{
		archivo<<"Esto es una prueba \npara el parcial de programación I\nde la Unet.\n";
	}
	archivo.close();
}
void Archivos::leerArchivo(){
	ifstream lectura,lectura2,lecturaEnteros;
		
	lectura.open("PRUEBA.txt",ios::in);//abrimos el archivo para leer lo que hay en él
	char linea[128];
	char letra;
	int cont=0,num;
	
	lectura.get(letra);
	while(!lectura.eof()){
		cont++;
		for(int i=0;i<getColumna();i++){
			lectura.get(letra);				
		}				
	}
	lectura.close();
	//cout<<cont<<endl;
	
	matrizTexto = new char*[cont];
	matrizNum = new int*[cont];
	matrizEnteros = new int*[cont];
	matrizTextEnteros = new char*[cont];
	for(int k=0;k<cont;k++){
		matrizTexto[k]=new char[getColumna()];
		matrizTextEnteros[k]=new char[getColumna()];
		matrizNum[k]=new int[getColumna()];
		matrizEnteros[k]=new int[getColumna()];
	}
	lectura2.open("PRUEBA.txt",ios::in);
	int z=0;
	if(lectura2.fail()){
		cerr<<"el fichero no existe"<<endl;
		exit(1);
	}else{
		lectura2.get(letra);
		while(!lectura2.eof()){
			for(int i=0;i<cont;i++){
				for(int j=0;j<getColumna();j++){
					if(i==16){
						if(j<2){
							matrizTexto[i][z]=letra;
							matrizNum[i][z]=(unsigned)(int)letra;
							//cout<<matrizTexto[i][z]<<"\t";
							lectura2.get(letra);
							z++;	
						}else{
							matrizTexto[i][j]='\0';
							matrizNum[i][j]=0;
							//cout<<matrizTexto[i][j]<<"\t";
							lectura2.get();
						}
						
					}else{
						matrizTexto[i][j]=letra;
						matrizNum[i][j]=(unsigned int)letra;
						if(matrizNum[i][j]<0){
							matrizNum[i][j]=256+(int)letra;
						}
						//cout<<letra<<"\t";
						lectura2.get(letra);
					}
				}
				//cout<<"\n";
			}
		}
		lectura2.close();
		setDimensiones(cont,columna);
		//cout<<"\n";
		for(int x=0;x<getFila();x++){
			for(int y=0;y<getColumna();y++){	
				//cout<<matrizNum[x][y]<<" ";		
			}
			//cout<<"\n";
		}	
	}
	
	//cout<<"\n";
	lecturaEnteros.open("ENTEROS.txt",ios::in);
	char codigo[12];
	int numDesenmas;
	int numero;
	if(lecturaEnteros.fail()){
		cerr<<"el fichero no existe"<<endl;
		exit(1);
	}else{
		lecturaEnteros.getline(codigo,11);
		while(!lecturaEnteros.eof()){	
			for(int i=0;i<cont;i++){
				numero=atoi(codigo);
				for(int j=0;j<getColumna();j++){
					numDesenmas = desenmascarar(8,j*8,numero);
					if(i==16){
						if(j<2){
							matrizEnteros[i][z]=numDesenmas;
							//cout<<matrizEnteros[i][z]<<"\t";
							z++;	
						}else{
							matrizEnteros[i][j]=numDesenmas;
							//cout<<matrizEnteros[i][j]<<"\t";
							lecturaEnteros.getline(codigo,11);
						}		
					}else{
						matrizEnteros[i][j]=numDesenmas;
						if(matrizEnteros[i][j]<0){
							matrizEnteros[i][j]=256+numDesenmas;
						}
						//cout<<matrizEnteros[i][j]<<"\t";	
					}
					switch(numDesenmas){
						case 69:
							matrizTextEnteros[i][j]='E';
							break;
							
						case 29440:
							matrizTextEnteros[i][j]='s';
							break;
							
						case 7602176:
							matrizTextEnteros[i][j]='t';
							break;
						
						case 1862270976:
							matrizTextEnteros[i][j]='o';
							break;
						
						case 32:
							matrizTextEnteros[i][j]=' ';
							break;
						
						case 25856:
							matrizTextEnteros[i][j]='e';
							break;
						
						case 7536640:
							matrizTextEnteros[i][j]='s';
							break;
						
						case 536870912:
							matrizTextEnteros[i][j]=' ';
							break;
						
						case 117:
							matrizTextEnteros[i][j]='u';
							break;
						
						case 28160:
							matrizTextEnteros[i][j]='n';
							break;
						
						case 6356992:
							matrizTextEnteros[i][j]='a';
							break;
						
						case 112:
							matrizTextEnteros[i][j]='p';
							break;
						
						case 29184:
							matrizTextEnteros[i][j]='r';
							break;
						
						case 7667712:
							matrizTextEnteros[i][j]='u';
							break;
						
						case 1694498816:
							matrizTextEnteros[i][j]='e';
							break;
						
						case 98:
							matrizTextEnteros[i][j]='b';
							break;	
						
						case 24832:
							matrizTextEnteros[i][j]='a';
							break;
							
						case 2097152:
							matrizTextEnteros[i][j]=' ';
							break;
							
						case 167772160:
							matrizTextEnteros[i][j]='\n';
							break;
							
						case 7471104:
							matrizTextEnteros[i][j]='r';
						
							break;
							
						case 1627389952:
							matrizTextEnteros[i][j]='a';
							break;
							
						case 7077888:
							matrizTextEnteros[i][j]='l';
							break;
							
						case 1660944384:
							matrizTextEnteros[i][j]='c';
							break;
							
						case 105:
							matrizTextEnteros[i][j]='i';
							break;
							
						case 100:
							matrizTextEnteros[i][j]='d';
							break;
							
						case 1879048192:
							matrizTextEnteros[i][j]='p';
							break;	
							
						case 114:
							matrizTextEnteros[i][j]='r';
							break;	
							
						case 28416:
							matrizTextEnteros[i][j]='o';
							break;	
							
						case 6750208:
							matrizTextEnteros[i][j]='g';
							break;	
						
						case 1912602624:
							matrizTextEnteros[i][j]='r';
							break;	
							
						case 97:
							matrizTextEnteros[i][j]='a';
							break;	
							
						case 27904:
							matrizTextEnteros[i][j]='m';
							break;	
							
						case 62208:
							matrizTextEnteros[i][j]='ó';
							break;	
							
						case 7208960:
							matrizTextEnteros[i][j]='n';
							break;	
							
						case 73:
							matrizTextEnteros[i][j]='I';
							break;	
							
						case 2560:
							matrizTextEnteros[i][j]='\n';
							break;	
							
						case 6553600:
							matrizTextEnteros[i][j]='d';
							break;	
							
						case 27648:
							matrizTextEnteros[i][j]='l';
							break;	
							
						case 85:
							matrizTextEnteros[i][j]='U';
							break;	
							
						case 6619136:
							matrizTextEnteros[i][j]='e';
							break;		
							
						case 1946157056:
							matrizTextEnteros[i][j]='t';
							break;
							
						case 46:
							matrizTextEnteros[i][j]='.';
							break;
							
						/*case 0:
							matrizTextEnteros[i][j]=' ';
							break;*/					
					}
				}
				lecturaEnteros.getline(codigo,11);
				//cout<<"\n";	
			}
		}
	}
	lecturaEnteros.close();
	for(int y=0;y<getFila();y++){
		for(int z=0;z<getColumna();z++){	
			cout<<""<<matrizTextEnteros[y][z];
		}
	}
	system("PAUSE>NULL");
}
void Archivos::setDimensiones(int fila,int columna){
	this->fila=fila;
	this->columna=columna;	
}
int Archivos::getFila(){
	return fila;
}
int Archivos::getColumna(){
	return columna;
}

int Archivos::desenmascarar(int cantBits,int cerosDer,int numero){
	int mascara,resultado;
	
	mascara=(pow(2,cantBits))-1;
	numero>>=cerosDer;
	resultado=numero&mascara;
	resultado<<=cerosDer;
	return resultado;
}

Archivos::~Archivos(){}
