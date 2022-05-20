#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "marca.h"
#include "color.h"
#include "fecha.h"
#include "datawarehouse.h"
#include "servicio.h"
#include "trabajo.h"
#include "validacion.h"
#include "cliente.h"
//----------------------------Mostrar autos segun MARCA a eleccion con mostrarAutosIdMarca & mostrarAutosMarca
int mostrarAutosIdMarca(int idMarca, eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC,eCliente clientes[], int tamCl){ //FUNCION REUTILIZABLE

	int todoOk = 0;
	char descMarca[20];
	int flag = 1;

	if(lista != NULL && tam > 0 && marcas != NULL && tamM>0 && colores != NULL && tamC >0){

		system("cls");
		printf("\n      	    	*** Lista de Autos por Marca *** \n");
		printf("------------------------------------------------------------------------------------------------\n");
		printf("ID_Auto   	Marca  			 Color   	 		Caja		Cliente\n");
		printf("------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<tam; i++){

			if(!lista[i].isEmpty && lista[i].idMarca == idMarca){

				mostrarAuto(lista[i], marcas, tamM, colores, tamC, clientes, tamCl);
				flag=0;
			}
		}
		if(flag == 1){
			cargardescripcionM(marcas, tam, idMarca, descMarca);
			printf("				No hay autos de la marca %s \n", descMarca);
		}

		todoOk = 1;
	}
	return todoOk;


}
//-------------------------
int mostrarAutosMarca(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl){

	int todoOk = 0;
	int idMarca;
	if(lista != NULL && tam > 0 && marcas != NULL && tamM>0 && colores !=NULL && tamC>0 && clientes != NULL && tamCl>0){
		system("cls");
		printf("\n      	    		*** Listar Autos de una Marca *** \n");

		mostrarMarcas(marcas, tamM);
		printf("Ingrese Id Marca: ");
		scanf("%d", &idMarca);

		while(!validarIdMarca(idMarca, marcas, tamM)){
			printf("Id invalido. Ingrese Marca: ");
			scanf("%d", &idMarca);
		}
		mostrarAutosIdMarca(idMarca, lista,tam, marcas, tamM, colores, tamC, clientes, tamCl);

		todoOk = 1;
	}
	return todoOk;

}

//---------------------------Mostrar autos segun COLOR a eleccion con mostrarAutosIdColor & mostrarAutosColor
int mostrarAutosIdColor(int idColor, eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC,eCliente clientes[], int tamCl){ //FUNCION REUTILIZABLE

	int todoOk = 0;
	char descColor[20];
	int flag = 1;

	if(lista != NULL && tam > 0 && marcas != NULL && tamM>0 && colores != NULL && tamC >0){

		system("cls");
		printf("\n      	    	*** Lista de Autos por Color *** \n");
		printf("------------------------------------------------------------------------------------------------\n");
		printf("ID_Auto   	Marca  			 Color   	 		Caja		Cliente\n");
		printf("------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<tam; i++){

			if(!lista[i].isEmpty && lista[i].idColor == idColor){

				mostrarAuto(lista[i], marcas, tamM, colores, tamC, clientes, tamCl);
				flag=0;
			}
		}
		if(flag == 1){
			cargardescripcionC(colores, tamC, idColor, descColor);
			printf("				No hay autos del color %s \n", descColor);
		}

		todoOk = 1;
	}
	return todoOk;


}

int mostrarAutosColor(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl){

	int todoOk = 0;
	int idColor;
	if(lista != NULL && tam > 0 && marcas != NULL && tamM>0 && colores !=NULL && tamC>0){

		system("cls");
		printf("\n      	    	*** Lista de Autos por Color *** \n");

		mostrarColores(colores, tamC);
		printf("Ingrese Id Color: ");
		scanf("%d", &idColor);

		while(!validarIdColor(idColor, colores, tamC)){
			printf("Id invalido. Ingrese Id Color: ");
			scanf("%d", &idColor);
		}
		}
		mostrarAutosIdColor(idColor, lista,tam, marcas, tamM, colores, tamC, clientes, tamCl);

		todoOk = 1;
	return todoOk;
	}

//--------------------------- MOSTRAR COLOR MAS ELEGIDO-------------------------------
int informarColoraFav(eAuto lista[],int tam,eColor colores[],int tamC){
    int retorno=-1;
    int contador[tamC];
    int maximoColor;

    if(lista!=NULL&&tam>0&&colores!=NULL&&tamC>0)
    {
        system("cls");
        printf("\n    	*** Color Mas Elegido ***\n\n");

        for(int i=0;i<tamC;i++) {
            contador[i]=0;
            for(int j=0;j<tam;j++)
            {
                if(lista[j].idColor==colores[i].id&&lista[j].isEmpty==0)
                {
                    contador[i]++;
                }
            }
        }

        for(int i=0;i<tamC;i++)
        {
            if(i==0||contador[i]>maximoColor)
            {
            	maximoColor=contador[i];
            }
        }

        printf("\n El color/es mas Elegido/s de Autos es: \n");

        for(int i=0;i<tamC;i++)
        {
            if(contador[i]==maximoColor)
            {
                printf("-%s\n",colores[i].nombreColor);
            }
        }

        retorno=0;
    }

    return retorno;
}

//------------------ EL COLOR MENOS ELEGIDO-------------------
int informarColorMenosFav(eAuto lista[],int tam,eColor colores[],int tamC){
    int retorno=-1;
    int contador[tamC];
    int minimoColor;

    if(lista!=NULL&&tam>0&&colores!=NULL&&tamC>0)
    {
        system("cls");
        printf("\n    	*** Color Menos Elegido *** \n\n");

        for(int i=0;i<tamC;i++) {
            contador[i]=0;
            for(int j=0;j<tam;j++)
            {
                if(lista[j].idColor==colores[i].id&&lista[j].isEmpty==0)
                {
                    contador[i]++;
                }
            }
        }

        for(int i=0;i<tamC;i++) {
            if(i==0||contador[i]<minimoColor)
            {
            	minimoColor=contador[i];
            }
        }

        		printf("\n El color/es Menos Elegido/s de Autos es: \n");

        for(int i=0;i<tamC;i++)
        {
            if(contador[i]==minimoColor)
            {
                printf("-%s\n",colores[i].nombreColor);
            }
        }

        retorno=0;
    }

    return retorno;
}

//---------------------------MARCA MAS ELEGIDA----------------
int informarMarcaFav(eAuto lista[],int tam,eMarca marcas[],int tamM){
    int retorno=-1;
    int contador[tamM];
    int maximoMarca;

    if(lista!=NULL&&tam>0&&marcas!=NULL&&tamM>0)
    {
        system("cls");
        printf("    	*** Marca Mas Elegida ***\n\n");

        for(int i=0;i<tamM;i++) {
            contador[i]=0;
            for(int j=0;j<tam;j++)
            {
                if(lista[j].idMarca==marcas[i].id&&lista[j].isEmpty==0)
                {
                    contador[i]++;
                }
            }
        }

        for(int i=0;i<tamM;i++)
        {
            if(i==0||contador[i]>maximoMarca)
            {
            	maximoMarca=contador[i];
            }
        }

        printf("\n La marca mas Elegido/s de Autos es: \n");

        for(int i=0;i<tamM;i++)
        {
            if(contador[i]==maximoMarca)
            {
                printf("-%s\n",marcas[i].descripcion);
            }
        }

        retorno=0;
    }

    return retorno;
}
//MOSTRAR AUTOS X MARCA

						//Mostrar todos los autos divididos por marcas
void mostrarAutoMarcas(eAuto lista[],int tam,eMarca marcas[],int tamM, eColor colores[],int tamC,eCliente clientes[], int tamCl){
{
    char descripcionMarca[20];
    system("cls");
    printf("		*** Listado de Autos por marca *** \n\n");


    for(int i=0; i<tamM; i++)
    {
        int flag=0;
        cargardescripcionM(marcas,tamM, marcas[i].id, descripcionMarca);
        printf("---------------------------\n");
        printf("Marca: %s\n",descripcionMarca);
        printf("---------------------------\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("ID_Auto   	Marca  			 Color   	 		Caja		Clientes\n");
		printf("-------------------------------------------------------------------------------------------------\n");
        for(int j=0;j<tam;j++)
        {
            if(lista[i].isEmpty==0&&lista[j].idMarca==marcas[i].id)
            {
                mostrarAuto(lista[j],marcas,tamM, colores,tamC,clientes, tamCl);
                flag=1;
            }
        }
        if(!flag)
        {
        printf("\n 			 No hay autos ingresados de esa marca \n");
        }
        printf("------------------------------------------------------------------------------\n\n");
    }
}

}


//-------------------CONTAR POR COLOR Y MARCA---------------------
int ContarxColoryMarca(eAuto lista[],int tam,eMarca marcas[],int tamM,eColor colores[],int tamC){

	int todoOk= 0;
    int auxColor;
    int auxMarca;
    int contador=0;

    if(lista!=NULL && tam>0 && marcas != NULL && tamM>0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("\n   		***	Cantidad de Autos por Color y Tipo 	***\n\n");

        mostrarColores(colores, tamC);
        printf("Ingrese el Id Color: ");
        scanf("%d", &auxColor);
        while(auxColor < 5000 || auxColor > 5004){
            printf("Id invalido. Ingrese el Id Color: ");
            scanf("%d", &auxColor);
        }

        mostrarMarcas(marcas, tamM);
        printf("Ingrese el Id Marca: ");
        scanf("%d", &auxMarca);
        while(auxMarca < 1000 || auxMarca > 1004){
            printf("Id invalido. Ingrese el Id Color: ");
            scanf("%d", &auxColor);
        }
        for(int i=0;i<tam;i++)
        {
            if(lista[i].idColor==auxColor&&lista[i].idMarca==auxMarca&&lista[i].isEmpty==0)
            {
                contador++;
            }
        }

        if(!contador)
        {
            printf("\n 	No existen Autos de ese tipo y color\n\n");
        }else if(contador==1)
        {
            printf("\n	Solo hay un Auto con ese color y tipo\n\n");
        }else
        {
            printf("\n Cantidad de Autos de este color y tipo es: %d\n\n",contador);
        }
    }

    return todoOk;
}
//			SERVICIO DE UN AUTO
int mostrarTrabajoAuto(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS,eAuto lista[],int tam,eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[], int tamCl){
    int todoOk=0;
    int auxAuto;
    int flag=0;

    if(trabajos!=NULL && tamT>0 && servicios!=NULL && tamS>0 && lista!=NULL && tamM>0 && colores != NULL && tamC>0 && marcas!=NULL && tamM>0 && clientes != NULL && tamCl > 0){

        printf("	*** Trabajos realizados a un Auto ***\n\n");

        mostrarAutos(lista, tam,marcas,tamM,colores,tamC,clientes, tamCl);
		printf("Ingrese Id Auto: ");
		scanf("%d", &auxAuto);
        while(auxAuto < 3000 || auxAuto > 3010){
            printf("Id invalido. Ingrese el Id Auto: ");
            scanf("%d", &auxAuto);
        }
        printf("\n\n");
        printf("\n      	    	*** Lista de Trabajos realizados *** \n");
		printf("---------------------------------------------------------------------\n");
		printf("ID_Auto   	Servicio  	 	Fecha  	\n");
		printf("---------------------------------------------------------------------\n");
		for (int i = 0; i < tamM; i++) {
			if (trabajos[i].idAuto == auxAuto && trabajos[i].isEmpty == 0) {
				mostrarTrabajo(trabajos[i], servicios, tamS, lista, tam);
				flag = 1;
			}
		}
        if(flag == 0)
        {
            printf("	No se ha realizado trabajos a ese Auto \n\n");
        }

        todoOk=1;
    }

    return todoOk;
}
// CONTAR SERVICIO Q SE LE REALIZO A UN AUTO
int ContarTrabajoxServicios(eAuto lista[],int tam,eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS){

	int todoOk= 0;
    int auxServ;
    int contador=0;

    if(lista!=NULL && tam>0 && trabajos != NULL && tamT>0 && servicios!=NULL && tamS>0)
    {
        system("cls");
        printf("\n   		***	Cantidad de Trabajos por Servicios	***\n\n");


		mostrarServicios(servicios, tamS);
        printf("Ingrese el Id Servicio: ");
        scanf("%d", &auxServ);
        while(auxServ < 20000 || auxServ > 20003){
            printf("Id invalido. Ingrese el Id Servicio: ");
            scanf("%d", &auxServ);
        }

        }
        for(int i=0;i<tamT;i++){
            if(trabajos[i].idServicio==auxServ&&lista[i].isEmpty==0)
            {
                contador++;
            }
        }

        if(!contador){
            printf("\n 	No existen Autos con ese Servicio\n\n");
        }else if(contador==1){
            printf("\n	Solo hay un Auto con ese Servicio\n\n");
        }else{
            printf("\n Cantidad de Autos con ese Servicio es: %d\n\n",contador);
        }
    return todoOk;
    }

// TRABAJOS REALIZADOS X FECHA
int mostrarServiciosXFecha(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS){
    int retorno=-1;
    eFecha fecha;
    char auxServicio[25];
    int flag=0;

    if(trabajos!=NULL&&tamT>0&&servicios!=NULL&&tamS>0)
    {
        system("cls");
        printf("   ***	 Mostrar Servicios por Fecha 	***\n\n");

        printf("Ingrese dia: ");
        scanf("%d", &fecha.dia);
        while(fecha.dia<1||fecha.dia>31)
        {	printf("Dia invalido. Ingrese dia: ");
        	scanf("%d", &fecha.dia);
        }
        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);
        while(fecha.mes<1||fecha.mes>12)
        {
        	printf("Mes invalido. Ingrese mes: ");
        	scanf("%d", &fecha.mes);
        }
        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio);
        while(fecha.anio<1970||fecha.anio>2030)
        {
        	printf("Anio invalido. Ingrese anio: ");
        	scanf("%d", &fecha.anio);
        }
        printf("\n\n Los Servicios realizados en esa fecha fueron: \n");
        for(int i=0;i<tamT;i++)
        {
            if(trabajos[i].fecha.dia==fecha.dia&&trabajos[i].fecha.mes==fecha.mes&&trabajos[i].fecha.anio==fecha.anio&&trabajos[i].isEmpty==0)
            {
            	cargarDescripcionServicio(servicios, tamS, trabajos[i].idServicio, auxServicio);

                printf("-%s\n",auxServicio);
                flag=1;
            }
        }

        if(!flag)
        {
            printf("No hay trabajos cargados ese dia\n");
        }

        retorno=0;
    }

    return retorno;
}

