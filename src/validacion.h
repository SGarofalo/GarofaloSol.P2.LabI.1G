#ifndef VALIDACION_H_
#define VALIDACION_H_
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "cliente.h"

/** \brief validar id de la marca
 * \param int id le paso id marcas
 * \param marcas eMarca[] array marca
 * \param int tamM tamaño marca
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int validarIdMarca(int id, eMarca marcas[], int tamM);


/** \brief validar id del color
 * \param int id le paso id colores
 * \param colores eColor[] array color
 * \param int tamC tamaño color
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int validarIdColor(int id, eColor colores[], int tamC);



/** \brief validar id del servicio
 * \param int id le paso id servicio
 * \param servicios eServicio[] array servicio
 * \param int tamS tamaño servicio
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int validadIdServicio(int id, eServicio servicios[], int tamS);



/** \brief validar id del cliente
 * \param int idCliente le paso id cliente
 * \param clientes eCliente[] array cliente
 * \param int tamC tamaña cliente
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int validarIdCliente(int id, eCliente clientes[], int tamCl);

#endif /* VALIDACION_H_ */
