#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "informe.h"

int mostrarServicios(eServicio servicios[], int tamS){

	int todoOk = 0;
	if(servicios != NULL && tamS > 0){

		printf("   		 *** Servicios *** \n\n");
		printf("-----------------------------------------------------------------------\n");
		printf("    Id        Descripcion	Precio\n");
		printf("-----------------------------------------------------------------------\n");
		for(int i=0; i<tamS; i++){
			printf("    %d       %-10s	%.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
		}
		printf("\n\n");

		todoOk = 1;
	}
	 return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[], int tamS, int idServicio, char descripcion[]){

	int todoOk =0;
	int flag = 1;

	if(servicios != NULL && tamS>0 && descripcion != NULL){

		todoOk =1;
		for(int i=0;i<tamS;i++){
			if(servicios[i].id == idServicio){

				strcpy(descripcion,servicios[i].descripcion);
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
