#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "color.h"
#include "fecha.h"
#include "datawarehouse.h"
#include "informe.h"
#include "validacion.h"
#include "trabajo.h"
#include "cliente.h"


int menu(){

	int opcion;

	system("cls");
	printf("		***	ABM Autos ***		\n\n");
	printf("1- Alta Autos \n");
	printf("2- Baja Autos \n");
	printf("3- Modificar Autos \n");
	printf("4- Ordenar Autos \n");
	printf("5- Listar Marcas\n");
	printf("6- Listar Colores\n");
	printf("7- Lista Servicios\n");
	printf("8- Informes\n");
	printf("9- Alta Trabajo\n");
	printf("10 Listar Trabajos\n");
	printf("11 Listar Clientes\n");
	printf("20- Salir \n");
	printf("Ingrese opcion: ");
	scanf("%d",&opcion);

	return opcion;

}

int inicializarAutos(eAuto lista[], int tam){

	int todoOk = 0;

	if(lista != NULL && tam > 0){

		for(int i=0; i<tam; i++){

			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}

	return todoOk;

}
int buscarLibre(eAuto lista[], int tam){

	int indice = -1;
		for(int i=0; i<tam; i++){
			if(lista[i].isEmpty){
				indice = i;
				break;
		}

	}
		return indice;

}
int altaAuto(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int* pId, eCliente clientes[], int tamCl){

	int todoOk = 0;
	int indice;
	eAuto auxAuto;

	if(lista != NULL && tam > 0 && pId != NULL && marcas != NULL && tamM > 0 && colores != NULL && tamC >0 && clientes != NULL && tamCl>0){

		system("cls");
		printf("       				*** Eligio ALTA AUTOS ***      \n\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1){
			printf("No hay lugar!! \n");
		}else{

			auxAuto.id = *pId;
			(*pId)++;

			mostrarMarcas(marcas, tamM);
			printf("Ingrese Id Marcas: ");
			scanf("%d", &auxAuto.idMarca);

			while(!validarIdMarca(auxAuto.idMarca, marcas, tamM)){

				printf("Id invalido. Ingrese Marcas: ");
				scanf("%d", &auxAuto.idMarca);
			}
			//ID COLOR
			mostrarColores(colores, tamC);
			printf("Ingrese Id Colores: ");
			scanf("%d", &auxAuto.idColor);

			while(!validarIdColor(auxAuto.idColor, colores, tamC)){

				printf("Id invalido. Ingrese Colores: ");
				scanf("%d", &auxAuto.idColor);
			}
			printf("Ingrese caja: ");
			fflush(stdin);
			scanf("%c", &auxAuto.caja);
			while(auxAuto.caja != 'a' && auxAuto.caja != 'm'){
				printf("ERROR, ingrese 'a' para Automatica y 'm' para manual:  ");
				fflush(stdin);
				scanf("%c", &auxAuto.caja);
			}
			//ID CLIENTE
			mostrarClientes(clientes, tamCl);
			printf("Ingrese Id Cliente: ");
			scanf("%d", &auxAuto.idCliente);

			while(!validarIdCliente(auxAuto.idCliente, clientes, tamCl)){

				printf("Id invalido. Ingrese Cliente: ");
				scanf("%d", &auxAuto.idCliente);
			}

			auxAuto.isEmpty = 0;

			lista[indice] = auxAuto;
				todoOk = 1;
		}
	}

		return todoOk;

}
void mostrarAuto(eAuto a, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl){

char descripcionM[20];
char descripcionC[20];
char descripcionCli[20];

cargardescripcionM(marcas, tamM, a.idMarca, descripcionM);
cargardescripcionC(colores, tamC, a.idColor, descripcionC);
cargarDescripcionCliente(clientes, tamCl, a.idCliente, descripcionCli);


		printf("%d   		%-10s  	 	   %-10s     	  	  %c		%-10s\n",
			a.id,
			descripcionM,
			descripcionC,
			a.caja,
			descripcionCli
			);


}
int mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC,eCliente clientes[], int tamCl){
	int todoOk = 0;
	int flag = 1;

	if(lista != NULL && tam > 0 && marcas != NULL && tamM >0 && colores != NULL && tamC >0 && clientes !=NULL && tamCl>0){
		system("cls");
		printf("\n      	    		*** Lista de Autos *** \n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("ID_Auto   	Marca  			 Color   	 		Caja		Cliente\n");
		printf("--------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<tam; i++){

			if((lista[i].isEmpty) == 0){
				mostrarAuto(lista[i], marcas, tamM,colores,tamC, clientes, tamCl);
				flag = 0;
			}
		}
		if(flag == 1){
			printf("		No hay autos para mostrar. \n\n");
		}

		todoOk = 1;
	}


	return todoOk;

}
int buscarAutoId(eAuto lista[], int tam, int id){

	int indice = -1;
		for(int i=0; i<tam; i++){
			if(!lista[i].isEmpty && lista[i].id == id){
				indice = i;
				break;
		}

	}
		return indice;
}
int bajaAuto(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl){
	int todoOk = 0;
	int indice;
	int id;
	char confirma;

	if(lista != NULL && tam>0){

		printf("       					*** Eligio BAJA AUTO ***      \n\n");
		mostrarAutos(lista, tam, marcas, tamM,colores,tamC, clientes, tamCl);
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarAutoId(lista, tam, id);
		if(indice == -1){
			printf("El Id: %d no esta registrado en el sistema.\n", id);

		}else{

			mostrarAuto(lista[indice], marcas, tamM,colores,tamC, clientes, tamCl);
			printf("Confirma baja?\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if(confirma == 's' || confirma == 'S'){
			lista[indice].isEmpty = 1;		//DADO DE BAJA
			todoOk = 1;
			}else{

				printf("Baja cancelada por el usuario.\n"); //NO confirmo.
			}
		}


	}

	return todoOk;
}
int modificarAuto(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl){

	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	int auxMarca;
	int auxColor;
	system("cls");
	printf("     					  *** Eligio MODIFICAR AUTO ***      \n\n");
	mostrarAutos(lista, tam, marcas, tamM, colores, tamC, clientes, tamCl);
	printf("Ingrese Id: ");
	scanf("%d", &id);

	indice = buscarAutoId(lista, tam, id);

	if(indice == -1){
		printf("El Id: %d no esta registrado en el sistema.\n", id);

	}else{

		mostrarAuto(lista[indice], marcas, tamM, colores, tamC, clientes, tamCl);
		printf(" Confirma modificacion? ");
		fflush(stdin);
		scanf("%c", &confirma);
		if(confirma == 's' || 'S'){
		switch(menuModificacion()){

			case 1:
				mostrarMarcas(marcas, tamM);
				printf("Ingrese marca: ");
				scanf("%d", &auxMarca);
				lista[indice].idColor = auxMarca;
			break;
			case 2:
				mostrarColores(colores, tamC);
				printf("Ingrese color: ");
				scanf("%d", &auxColor);
				lista[indice].idColor = auxColor;
			break;
			default:
				printf("Opcion INVALIDA! \n");
		}


				todoOk = 1;
		}else{

			printf("Se ha cancelado la modificacion.\n");
		}
	}

				return todoOk;

}
void ordenarAutos(eAuto lista[], int tam, eMarca marcas[], int tamM){

    eAuto auxiliar;
    char marcaI[20];
    char marcaJ[20];

    for(int i=0;i<tam-1;i++) {
        for(int j=i+1;j<tam;j++){
        	cargardescripcionM(marcas,tamM,lista[i].idMarca,marcaI);
        	cargardescripcionM(marcas,tamM,lista[j].idMarca,marcaJ);
            if(strcmp(marcaI,marcaJ)>0)
            {
                auxiliar=lista[i];
                lista[i]=lista[j];
                lista[j]=auxiliar;
            }
            else
            {
                 if((strcmp(marcaI,marcaJ)==0)&&(lista[i].caja > lista[j].caja))
                {
                    auxiliar=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxiliar;
                }
            }
        }
    }
}


int menuModificacion(){
	int opcion;

	printf("1- Marca \n");
	printf("2- Color \n");
	printf("Ingrese opcion: ");
	scanf("%d",&opcion);


	return opcion;
}

int menuInformes(){
	int opcion;

	printf("	1- Mostrar autos segun MARCA (ID)\n");
	printf("	2- Mostrar autos segun COLOR (ID)\n");
	printf("	3- Mostrar Color MAS Elegido\n");
	printf("	4- Mostrar Color MENOS Elegido\n");
	printf("	5- Mostrar Marca MAS Elegido\n");
	printf("	6- Mostrar Lista de Autos separados x MARCAS\n");
	printf("	7- Cantidad Autos s/ Color y Marca\n");
	printf("	8- Trabajos realizados a un auto\n");
	printf("	9- Cantidad de Servicios que se realizo en Auto\n");
	printf("	10- Trabajos realizados por Fecha\n");

	printf("Ingrese opcion: ");
	scanf("%d",&opcion);
	return opcion;
}
