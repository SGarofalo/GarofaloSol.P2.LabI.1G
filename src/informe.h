#ifndef INFORME_H_
#define INFORME_H_

#include "servicio.h"
#include "trabajo.h"



/** \brief Permite al usuario mostrar los autos de la marca seleccionada
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutosMarca(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);


/** \brief muestra los autos segun marca
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array cliente
 * \param int tamC tamaña cliente
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutosIdMarca(int idMarca, eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC,eCliente clientes[], int tamCl);


/** \brief permite al usuario mostrar los autos del color seleccionado
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array cliente
 * \param int tamC tamaña cliente
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutosIdColor(int idColor, eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC,eCliente clientes[], int tamCl);


/** \brief muestra la lista de autos x color
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarAutosColor(eAuto lista[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl);


/** \brief muestra los autos con el color MAS elegido
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int informarColoraFav(eAuto lista[],int tam,eColor colores[],int tamC);


/** \brief muestra color MENOS elegido AUTOS
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int informarColorMenosFav(eAuto lista[],int tam,eColor colores[],int tamC);


/** \brief muestra MARCA MAS ELEGIDA autos
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int informarMarcaFav(eAuto lista[],int tam,eMarca marcas[],int tamM);



/** \brief muestras todos los autos dividiso por MARCAS
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param clientes eCliente[] array cliente
 * \param int tamC tamaña cliente
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
void mostrarAutoMarcas(eAuto lista[],int tam,eMarca marcas[],int tamM, eColor colores[],int tamC,eCliente clientes[], int tamCl);


/** \brief cuenta los autos x color y marca
 * \param lista eAutos[] array autos
 * \param tam tamaño autos
 * \param marcas eMarca[] array marcas
 * \param taM tamaño marcas
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */

int ContarxColoryMarca(eAuto lista[],int tam,eMarca marcas[],int tamM,eColor colores[],int tamC);


/** \brief
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarTrabajoAuto(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS,eAuto lista[],int tam,eColor colores[],int tamC, eMarca marcas[],int tamM,eCliente clientes[], int tamCl);

/** \brief
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int ContarTrabajoxServicios(eAuto lista[],int tam,eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS);


/** \brief
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \param
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarServiciosXFecha(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS);

#endif /* INFORME_H_ */
