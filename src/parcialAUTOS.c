#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "datawarehouse.h"
#include "informe.h"
#include "validacion.h"
#include "cliente.h"

#define TAM 10
#define TAM_M 5//notoco
#define TAM_C 5
#define TAM_S 4
#define TAM_T 50
#define TAM_CL 10

int main(void) {

	setbuf(stdout, NULL);

	char seguir = 's';
	int nextID = 3000;
	int nextIDTrabajo = 50000;
	eAuto lista[TAM];
	eTrabajo trabajos[TAM_T];
	char salida;
	int flagAlta = 0;


	eMarca marcas[TAM_M] = {
		{1000, "Renault"},
		{1001, "Ford"},
		{1002, "Fiat"},
		{1003, "Chevrolet"},
		{1004, "Peugeot"}
	};

	eColor colores[TAM_C] = {
		{5000, "Negro"},
		{5001, "Blanco"},
		{5002, "Rojo"},
		{5003, "Verde"},
		{5004, "Azul"}
	};

	eServicio servicios[TAM_S] = {
		{20000, "Lavado",450.00},
		{20001, "Pulido",500.00},
		{20002, "Encerado",600.00},
		{20003, "Completo",900.00}
	};

	eCliente clientes[TAM_CL] = {
		{200, "Martin", 'm'},
		{201, "Lucia", 'f'},
		{202, "Leonel", 'm'},
		{203, "Facundo", 'm'},
		{204, "Luciano", 'm'},
		{205, "Maria", 'f'},
		{206, "Walter", 'm'},
		{207, "Elvira", 'f'},
		{208, "Diego", 'm'},
		{209, "Lucio", 'm'},
	};

	if(!inicializarAutos(lista, TAM)){
		printf("Error al inicializar \n");
	}
	if(!inicializarTrabajos(trabajos, TAM_T)){
		printf("Error al inicializar \n");
	}

	hardcodearAutos(lista, TAM, 8, &nextID);

	do{
			switch(menu()){

					case 1:
						if(altaAuto(lista, TAM, marcas, TAM_M, colores, TAM_C, &nextID, clientes, TAM_CL) == 0){
							printf("No se pudo realizar el alta \n");
						}else{
							printf("ALTA EXITOSA!!! \n");
						}

						flagAlta = 1;

					break;
					case 2:
						if(flagAlta == 0){
							printf("Primero debe ingresar el alta\n");
						}else{
						if(bajaAuto(lista, TAM, marcas, TAM_M, colores, TAM_C, clientes, TAM_CL) == 0){
							printf("No se pudo realizar la baja \n");
						}else{
							printf("BAJA EXITOSA!!! \n");
						}
						}
					break;
					case 3:
						if(flagAlta == 0){
							printf("Primero debe ingresar el alta \n" );

						}else{
						modificarAuto(lista, TAM, marcas, TAM_M, colores, TAM_C, clientes, TAM_CL);
						}
					break;
					case 4:
						if(flagAlta == 0){
							printf("Primero debe ingresar el alta \n");

						}else{
							ordenarAutos(lista, TAM, marcas, TAM_M);
							mostrarAutos(lista, TAM, marcas, TAM_M, colores, TAM_C, clientes, TAM_CL);
						}
					break;
					case 5:
						mostrarMarcas(marcas, TAM_M);
					break;
					case 6:
						mostrarColores(colores, TAM_C);
					break;
					case 7:
						system("cls");
						mostrarServicios(servicios, TAM_S);
					break;
					case 8:   //--------- INFORMES ----------//
							switch(menuInformes()){
							case 1:
								mostrarAutosMarca(lista, TAM, marcas, TAM_M,colores,TAM_C, clientes, TAM_CL);
							break;
							case 2:
								mostrarAutosColor(lista, TAM, marcas, TAM_M, colores, TAM_C, clientes, TAM_CL );
							break;
							case 3:
								system("cls");
								informarColoraFav(lista, TAM, colores, TAM_C);
							break;
							case 4:
								informarColorMenosFav(lista, TAM, colores, TAM_C);
							break;
							case 5:
								informarMarcaFav(lista, TAM, marcas, TAM_M);
							break;
							case 6:
								mostrarAutoMarcas(lista, TAM, marcas, TAM_M, colores, TAM_C, clientes, TAM_CL);
							break;
							case 7:
								ContarxColoryMarca(lista, TAM, marcas, TAM_M, colores, TAM_C);
							break;
							case 8:
								mostrarTrabajoAuto (trabajos, TAM_T,servicios, TAM_S, lista, TAM, colores, TAM_C, marcas, TAM_M, clientes, TAM_CL);
							break;
							case 9:
								ContarTrabajoxServicios(lista, TAM, trabajos, TAM_T, servicios, TAM_S);
							break;
							case 10:
								mostrarServiciosXFecha(trabajos, TAM_T, servicios, TAM_S);
							break;

							}
					break;
					case 9:
						if(altaTrabajo(trabajos, TAM_T, servicios, TAM_S, lista, TAM, marcas, TAM_M, colores, TAM_C, &nextIDTrabajo, clientes, TAM_CL) == 0){
							printf("No se pudo realizar el alta de Trabajos\n");
						}else{
							printf("ALTA TRABAJO EXITOSA!!! \n");
						}
					break;
					case 10:
						system("cls");
						mostrarTrabajos(trabajos, TAM_T, lista, TAM, servicios, TAM_S);
					break;
					case 11:
						mostrarClientes(clientes, TAM_CL);
					break;
					case 20:
						printf("		Seguro quiere salir? ");
						fflush(stdin);
						scanf("%c", &salida);

						if (salida == 's'|| salida == 'S'){
							seguir = 'n';
							printf("	Gracias, vuelva pronto\n");
						}
						else{
							printf("		Usted no salio\n");
						}
					break;
					default:
						printf("Opcion invalida!! \n");
					}
					system("pause");


	}while(seguir == 's');



	return 0;
}





