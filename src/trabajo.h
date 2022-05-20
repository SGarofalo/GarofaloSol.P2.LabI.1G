#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "autos.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "cliente.h"


typedef struct{
	int id;
	int idAuto;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;



/** \brief inicializo trabajos
 * \param lista eTrabajos[] array trabajos
 * \param tam tamaño trabajos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tamT);


/** \brief busco lugar libre en trabajo
 * \param  trabajos eTrabajos[] array trabajos
 * \param  tam tamaño trabajos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tamT);


/** \brief es el alta de trabajo
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param *pId puntero de Id
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño clientes
 * \param  trabajos eTrabajos[] array trabajos
 * \param  tam tamaño trabajos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eAuto lista[], int tam,
		eMarca marcas[], int tamM, eColor colores[], int tamC, int* pIdTrabajo, eCliente clientes[], int tamCl);


/** \brief muestro los trabajo
 * \param a eAutos[] variable de auto
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño cliente
 * \param  trabajos eTrabajos[] array trabajos
 * \param  tam tamaño trabajos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamT, eAuto lista[], int tam, eServicio servicios[], int tamS);


/** \brief muestro el trabajo
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño cliente
 * \param  trabajos eTrabajos[] array trabajos
 * \param  tam tamaño trabajos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamS, eAuto lista[], int tam);

#endif /* TRABAJO_H_ */

