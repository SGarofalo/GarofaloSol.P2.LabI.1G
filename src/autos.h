#ifndef AUTOS_H_
#define AUTOS_H_

#include "marca.h"
#include "color.h"
#include "cliente.h"


typedef struct{
	int id;
	int idMarca;
	int idColor;
	int idCliente;
	char caja;
	int isEmpty;
}eAuto;

/** \brief inicializo autos
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \return int 1 en caso de exito, 0 en caso de error
 */
int inicializarAutos(eAuto lista[], int tam);


/** \brief busco lugar libre en auto
 * \param  lista eAutos[] array autos
 * \param  tam tamaño autos
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int buscarLibre(eAuto lista[], int tam);


/** \brief es el alta de auto
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param *pId puntero de Id
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño clientes
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int altaAuto(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int* pId, eCliente clientes[], int tamCl);


/** \brief muestro el auto
 * \param a eAutos[] variable de auto
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño cliente
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
void mostrarAuto(eAuto a, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);


/** \brief muestro los autos
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño cliente
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutos(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC,eCliente clientes[], int tamCl);


/** \brief baja de auto
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño clientes
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int bajaAuto(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);


/** \brief busco el idAuto
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param id variable id tipo auto
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int buscarAutoId(eAuto lista[], int tam, int id);


/** \brief modifico el auto
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array clientes
 * \param tamCl tamaño clientes
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int modificarAuto(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);


/** \brief ordeno los autos x marca alfabeticamente
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
void ordenarAutos(eAuto lista[], int tam, eMarca marcas[], int tamM);


/** \brief crea el menu de autos y lo muestra en pantalla
 * \return int retorna el valor de la opcion seleccionada
 *
 */

int menu();


/** \brief crea un submenu para elegir que quiere modificar el usuario
 * \return int retorna el valor de la opcion seleccionada
 *
 */
int menuModificacion();


/** \brief crea el menu de informes y lo muestra en pantalla
 * \return int retorna el valor de la opcion seleccionada
 *
 */
int menuInformes();





#endif /* AUTOS_H_ */
