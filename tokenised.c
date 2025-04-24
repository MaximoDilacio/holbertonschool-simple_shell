#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * conteo_tokens - Funcion para contar tokens
 * @comando: Char que almacena el comando ingresado
 * Return: retorna el numero de tokens
*/

int conteo_tokens(char *comando)
{
	int nro_token = 0;
	char *token;
	char *copia = strdup(comando);

	if (copia == NULL)
	{
		perror("fallo dup");
		free(comando);
		return (1);
	}
	token = strtok(copia, " ");
	while (token != NULL)
	{
		nro_token++;
		token = strtok(NULL, " ");
	}
	free(copia);
	return (nro_token);
}

/**
 * tokenised - Funcion para separar por espacios el comano de sus argumentos
 * @comando: char que almacena el input de entrada
 * Return: si falla NULL, y si no retorna el grupo de tokens
 * con los espacios marcados
*/
char **tokenised(char *comando)
{	char *copia = NULL, *token;
	char **tokens = NULL;
	int nro_token, j, i = 0;

	nro_token = conteo_tokens(comando);
	tokens = malloc(sizeof(char *) * (nro_token + 1));
	if (tokens == NULL)
	{
		perror("malloc fallo");
		free(comando);
		return (NULL);
	}
	copia = strdup(comando);
	if (copia == NULL)
	{	perror("fallo dup");
		free(comando);
		free(tokens);
		return (NULL);
	}
	token = strtok(copia, " ");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{	perror("fallo dup");
			for (j = 0; j < i; j++)
				free(tokens[j]);

			free(tokens);
			free(copia);
			free(comando);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;
	free(copia);
	free(comando);
	return (tokens);
}
