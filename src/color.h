#ifndef COLOR_H_
#define COLOR_H_


typedef struct{
	int id; //5000
	char nombreColor[20];
}eColor;



/** \brief mostrar colores
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int mostrarColores(eColor colores[], int tamC);


/** \brief descripcion de colores
 * \param colores eColor[] array colores
 * \param tamC tamaño color
 * \param idColor variable id color
 * \param descripcion cadena de caracteres
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int cargardescripcionC(eColor colores[], int tamC, int idColor, char descripcion[]);



#endif /* COLOR_H_ */
