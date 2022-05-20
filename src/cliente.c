#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "trabajo.h"

int mostrarClientes(eCliente clientes[], int tamCl){

	int todoOk = 0;
	if(clientes != NULL && tamCl > 0){

		printf("   		 *** clientes *** \n\n");
		printf("---------------------------------------------------------------\n");
		printf("    Id        Nombre		Sexo\n");
		printf("----------------------------------------------------------------\n");
		for(int i=0; i<tamCl; i++){
			printf("    %d       %-10s	%c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
		}
		printf("\n\n");

		todoOk = 1;
	}
	 return todoOk;
}

int cargarDescripcionCliente(eCliente clientes[], int tamCl, int idcliente, char nombreC[]){

	int todoOk =0;
	int flag = 1;

	if(clientes != NULL && tamCl>0 && nombreC != NULL){

		todoOk =1;
		for(int i=0;i<tamCl;i++){
			if(clientes[i].id == idcliente){

				strcpy(nombreC,clientes[i].nombre);
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

