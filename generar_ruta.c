#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"
/**
 * generar_ruta - recorre path probando el comando,
 * si encuentra el comando, concatena ambas cadenas
 * @comando: char que almacena el contenido de la linea ingresada
 * Return: NULL si falla
*/

char *generar_ruta(char *comando)
{
	char *ruta_final = NULL;
	char **path_dir = _getenv();
	int i;

	if (path_dir == NULL)
	{
		perror("fallo _getenv");
		return (NULL);
	}
	for (i = 0; path_dir[i] != NULL; i++)
	{
		if ((ruta_final = _asprintf(path_dir[i], comando))== NULL)
		{
			perror("fallo _asprintf\n");
			free_tokens(path_dir);
			return (NULL);
		}
		if (access(ruta_final, X_OK) == 0)
		{
			free_tokens(path_dir);
			return (ruta_final);
		}
		free(ruta_final);
		ruta_final = NULL;
	}
	free_tokens(path_dir);
	return (NULL);
}
