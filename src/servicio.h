#ifndef SERVICIO_H_
#define SERVICIO_H_


typedef struct{
	int id; //20000
	char descripcion[20];
	float precio;
}eServicio;




/** \brief me muestra los servicios
 * \param servicios eServicio[] array servicios
 * \param tamS tamaño servicio
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarServicios(eServicio servicios[], int tamS);

/** \brief descripcion de servicios
 * \param servicios eServicio[] array servicios
 * \param tamS tamaño servicio
 * \param idServicio variable id servicio
 * \param descripcion cadena de caracteres
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tamS, int idServicio, char descripcion[]);

#endif /* SERVICIO_H_ */
