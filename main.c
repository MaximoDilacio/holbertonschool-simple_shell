#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"


/**
 * free_tokens - lbera un array de punteros
 * @tokens: lista de punteros
*/
void free_tokens(char **tokens)
{
	int j;

	for (j = 0; tokens[j] != NULL; j++)
		free(tokens[j]);
	free(tokens);
}
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
	int _isatty = isatty(STDIN_FILENO);

	while (1)
	{
		if (_isatty != 0)
			prompt();
		resultado = getline(&comando, &largo, stdin);
		if (resultado == -1)
		{
			if (_isatty != 0)
				printf("\n");
			free(comando);
			break;
		}
		if (comando[resultado - 1] == '\n')
			comando[resultado - 1] = '\0';

		tokens = tokenised(comando);
		if (tokens != NULL)
		{
			proceso_hijo(tokens);
			free_tokens(tokens);
			tokens = NULL;
		}
		else
		{
			free_tokens(tokens);
			tokens = NULL;
		}
		comando = NULL;
	}
	if (tokens != NULL)
		free_tokens(tokens);
	return (0);
}
