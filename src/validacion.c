#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "marca.h"
#include "color.h"
#include "informe.h"
#include "trabajo.h"
#include "cliente.h"

int validarIdMarca(int id, eMarca marcas[], int tamM){
	int todoOk =0; //esta = NO ESTA

	if(marcas != NULL && tamM>0){

		for(int i=0;i<tamM;i++){

			if(marcas[i].id == id){
				todoOk = 1;	 //ESTA
				break;
			}
		}

	}

	return todoOk; //ESTA
	}

int validarIdColor(int id, eColor colores[], int tamC){
	int todoOk =0; //esta = NO ESTA

	if(colores != NULL && tamC>0){

		for(int i=0;i<tamC;i++){

			if(colores[i].id == id){

				todoOk = 1;	 //ESTA
				break;
			}
		}

	}

	return todoOk; //ESTA
	}
int validadIdServicio(int id, eServicio servicios[], int tamS){
	int todoOk =0; // NO ESTA

	if(servicios != NULL && tamS>0){

		for(int i=0;i<tamS;i++){

			if(servicios[i].id == id){
				todoOk = 1;	 //ESTA
				break;
			}
		}

	}

	return todoOk; //ESTA
	}
int validarIdCliente(int id, eCliente clientes[], int tamCl){
	int todoOk =0; //esta = NO ESTA

	if(clientes != NULL && tamCl>0){

		for(int i=0;i<tamCl;i++){

			if(clientes[i].id == id){
				todoOk = 1;	 //ESTA
				break;
			}
		}

	}

	return todoOk; //ESTA
	}
