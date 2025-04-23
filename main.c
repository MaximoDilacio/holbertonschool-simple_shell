#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"


/**
 * main - Funcion principal del programa con bucle infinito
 * Return: 0
*/

int main(void)
{
	char *comando = NULL;
	size_t largo = 0;
	ssize_t resultado;
	char **tokens = NULL;
	int j;

	while (1)
	{
		printf("$ ");

		resultado = getline(&comando, &largo, stdin);
		if (resultado == -1)
			break;
		if (comando[resultado - 1] == '\n')
			comando[resultado - 1] = '\0';
		if (strcmp(comando, "exit") == 0)
			break;

		tokens = tokenised(comando);
		if (tokens != NULL)
		{
			proceso_hijo(tokens);
			for (j = 0; tokens[j] != NULL; j++)
				free(tokens[j]);
			free(tokens);
			tokens = NULL;
		}
		free(tokens);
		free(comando);
		comando = NULL;
	}
	printf("\n");
	free(comando);
	return (0);
}
