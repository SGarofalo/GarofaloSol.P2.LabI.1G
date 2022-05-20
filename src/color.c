#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "color.h"
#include "datawarehouse.h"
#include "informe.h"

int cargardescripcionC(eColor colores[], int tamC, int idColor, char descripcion[]){

	int todoOk =0;
	int flag = 1;

	if(colores != NULL && tamC && descripcion != NULL){

		todoOk =1;		 //me devuelve 1 si se puso a buscar y NO encontro
		for(int i=0;i<tamC;i++){
			if(colores[i].id == idColor){
				strcpy(descripcion,colores[i].nombreColor);
				flag = 0;
				break; // es p/ q no siga iterando
			}
		}
		if(flag == 1){
			todoOk = -1;
		}
	}

	return todoOk;

}


int mostrarColores(eColor colores[], int tamC){

	int todoOk = 0;
	if(colores != NULL && tamC > 0){

		printf("    *** Colores *** \n\n");
		printf("    Id        Descripcion\n");
		for(int i=0; i<tamC; i++){
			printf("    %d       %s\n", colores[i].id, colores[i].nombreColor);
		}
		printf("\n\n");

		todoOk = 1;
	}
	 return todoOk;
}

