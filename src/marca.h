#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id; //5000
	char descripcion[20];
}eMarca;




/** \brief me muestra las marcas
 * \param marcas eMarcas[] array marcas
 * \param tamM tamaño marcas
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarMarcas(eMarca marcas[], int tamM);



/** \brief descripcion de marcs
 * \param marcas eMarcas[] array marcas
 * \param tamM tamaño marcas
 * \param idMarca variable id marca
 * \param descripcion cadena de caracteres
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int cargardescripcionM(eMarca marcas[], int tamM, int idMarca, char descripcion[]);
#endif /* MARCA_H_ */
