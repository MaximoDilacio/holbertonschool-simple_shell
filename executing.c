#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * verificar_ruta - Funcion para verificar si la ruta es absoluta
 * @comando: Char que almacena el contenido de la linea ingresada
 * Return: ruta absoluta o NULL
*/
char *verificar_ruta(char *comando)
{
	if ((strchr(comando, '/') != NULL) && (access(comando, X_OK) == 0))
		return (strdup(comando));
	return (NULL);
}
/**
 * buscar_comando - funcion para corroborar si ruta es valida o no
 * si es valida, la retorna, si no lo es llama a la funcion generar_ruta
 * @comando: Char para almacenar el comando ingresado
 * Return: Retorna ruta si es valida, si no llama a la funcion generar_ruta
*/
char *buscar_comando(char *comando)
{
	char *ruta = verificar_ruta(comando);

	if (ruta)
		return (ruta);
	return (generar_ruta(comando));
}

/**
 * ejecucion - Funcion para validar si se puede ejecutar el programa
 * @tokens: char que almacena flags
 * Return: Retorna -1 si falla y devuelve mensaje de error
 * o retorna 0 y ejecuta el programa
*/
int ejecucion(char **tokens)
{
	char *ruta_comando = buscar_comando(tokens[0]);

	if (ruta_comando == NULL)
	{
		fprintf(stderr, "preshell: 1: %s: not found\n", tokens[0]);
		return (-1);
	}

	if (execve(ruta_comando, tokens, environ) == -1)
	{
		perror("fallo ejecucion\n");
		free(ruta_comando);
		return (-1);
	}

	free(ruta_comando);
	return (0);
}
