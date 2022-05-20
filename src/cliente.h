#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int id;
	char nombre[25];
	char sexo;
}eCliente;



/** \brief me muestra los clientes
 * \param clientes eCliente[] array cliente
 * \param int tamC tamaña cliente
 * \return int 1 en caso de exito, 0 en caso de error

 */
int mostrarClientes(eCliente clientes[], int tamCl);


/** \brief datos cargados del cliente
 * \param clientes eCliente[] array cliente
 * \param int tamC tamaña cliente
 * \param int idCliente le paso id cliente
 * \param char nombre[] cadena de caracteres del nombre cliente
 * \return int 1 en caso de exito, 0 en caso de error
 *
 */
int cargarDescripcionCliente(eCliente clientes[], int tamCl, int idcliente, char nombreC[]);



#endif /* CLIENTE_H_ */
