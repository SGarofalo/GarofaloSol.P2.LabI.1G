#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "informe.h"
#include "validacion.h"
#include "cliente.h"

int inicializarTrabajos(eTrabajo trabajos[], int tamT){

	int todoOk = 0;

	if(trabajos != NULL && tamT > 0){

		for(int i=0; i<tamT; i++){

			trabajos[i].isEmpty = 1;
		}

		todoOk = 1;
	}

	return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tamT){


	int indice = -1;
		for(int i=0; i<tamT; i++){
			if(trabajos[i].isEmpty){
				indice = i;
				break;
		}

	}
		return indice;

}

int altaTrabajo(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eAuto lista[], int tam,
		eMarca marcas[], int tamM, eColor colores[], int tamC, int* pIdTrabajo, eCliente clientes[], int tamCl){

	int todoOk = 0;
	int indice;		//me fijo si hay lugar con la func BUSCARLIBRE
	eTrabajo auxTrabajo;
	//eFecha fecha;

	if(trabajos != NULL && tamT>0 && pIdTrabajo != NULL && servicios != NULL && tamS>0 && lista != NULL && tam > 0 && marcas != NULL && tamM > 0 && clientes != NULL && tamCl>0){

		system("cls");
		printf("       				*** Eligio ALTA TRABAJOS ***      \n\n");

		indice = buscarLibreTrabajo(trabajos, tamT);
		if(indice == -1){
			printf("No hay lugar!! \n");
		}else{

			auxTrabajo.id = *pIdTrabajo;
			(*pIdTrabajo)++;

			mostrarServicios(servicios, tamS);
			printf("Ingrese Id Servicios: ");
			scanf("%d", &auxTrabajo.idServicio);

			while( !validadIdServicio(auxTrabajo.idServicio, servicios, tamS)){
				printf("Id Servicio Invalido. Ingrese Id Servicio: ");
				scanf("%d", &auxTrabajo.idServicio);
			}

			mostrarAutos(lista, tam, marcas, tamM, colores, tamC,clientes, tamCl);
			printf("Ingrese Id Auto: ");
			scanf("%d", &auxTrabajo.idAuto);

			while( buscarAutoId(lista, tam, auxTrabajo.idAuto)== -1){ //le paso lista, tam y el ID de la persona q me acaban deingresar
			printf("Id auto Invalido. Ingrese Id auto: ");
			scanf("%d", &auxTrabajo.idAuto);
			}

	        }
				printf("Ingrese fecha: ");
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
            				auxTrabajo.isEmpty = 0;

                			trabajos[indice] = auxTrabajo;
                				todoOk = 1;
		}

		return todoOk;
	}


void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamS, eAuto lista[], int tam){

char descripcionServicio[25];

if(cargarDescripcionServicio(servicios, tamS, unTrabajo.idServicio, descripcionServicio)){


		printf("%d   	%-10s  	 %2d /%2d/ %d      \n",
				unTrabajo.id,
				descripcionServicio,
				unTrabajo.fecha.dia,
				unTrabajo.fecha.mes,
				unTrabajo.fecha.anio
				);
		}

}
int mostrarTrabajos(eTrabajo trabajos[], int tamT, eAuto lista[], int tam, eServicio servicios[], int tamS){

	int todoOk = 0;
	int flag = 1;
	if(trabajos != NULL && tamT>0 && lista != NULL && tam > 0 && servicios != NULL && tamS >0){
		system("cls");
		printf("\n      	   *** Lista de Trabajos *** \n");
		printf("----------------------------------------------------------------------\n");
		printf("ID   		 Servicios   	  Fecha\n");
		printf("-----------------------------------------------------------------------\n");

		for(int i=0; i<tam; i++){

			if((trabajos[i].isEmpty) == 0){
				mostrarTrabajo(trabajos[i], servicios, tamS, lista, tam);
				flag = 0;
			}
		}
		if(flag==1){
			printf("		No hay Trabajos para mostrar. \n\n");
		}
				todoOk = 1;
	}
	return todoOk;

}
