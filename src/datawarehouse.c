#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "color.h"

int idMarcas[10]= {1004,1000,1003,1004,1001,1002,1004,1002,1004,1001};
int idColores[10] = {5004,5001,5001,5004,5000,5002,5002,5001,5003,5004};
char cajas[10] = {'a', 'a', 'a','m', 'a', 'm','a', 'm', 'm', 'a'};
int idCliente[10] = {204,203,201,209,207,208,202,205,200,206};

int hardcodearAutos(eAuto lista[], int tam,int cant, int* pId){

	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){ //cant >=0 y =< al tamaño
		contador = 0;
		for(int i=0; i<cant; i++){
			lista[i].id = *pId; //pId es la direc de mem de la var nextId de MAIN
								//con el * accedemos al valor
			(*pId)++; //para INCREMENTAR el valor desde la func
			lista[i].idMarca = idMarcas[i];
			lista[i].idColor = idColores[i];
			lista[i].caja = cajas[i];
			lista[i].idCliente = idCliente[i];
			lista[i].isEmpty = 0; //al llenarlo lo deja en 0

			contador++;
		}

	}

	return contador;
}


