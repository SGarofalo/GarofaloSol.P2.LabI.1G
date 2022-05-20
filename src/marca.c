#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "datawarehouse.h"
#include "informe.h"

int cargardescripcionM(eMarca marcas[], int tamM, int idMarca, char descripcion[]){

	int todoOk =0;
	int flag = 1;

	if(marcas != NULL && tamM && descripcion != NULL){

		todoOk =1;
		for(int i=0;i<tamM;i++){
			if(marcas[i].id == idMarca){
				strcpy(descripcion,marcas[i].descripcion);
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			todoOk = -1;
		}
	}

	return todoOk;

}

int mostrarMarcas(eMarca marcas[], int tamM){

	int todoOk = 0;
	if(marcas != NULL && tamM > 0){

		printf("    *** Marcas *** \n\n");
		printf("    Id        Descripcion\n");
		for(int i=0; i<tamM; i++){
			printf("    %d       %s\n", marcas[i].id, marcas[i].descripcion);
		}
		printf("\n\n");

		todoOk = 1;
	}
	 return todoOk;
}

