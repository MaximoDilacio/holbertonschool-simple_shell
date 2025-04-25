#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * print_env - Imprime el entorno
 * @environ: Entorno
*/
void print_env(char **environ)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
/**
 * procesar_comando - procesa y limpia el comando de espacios
 * @comando: comando a procesar
 *
 * Return: comando limpio
 */
char *procesar_comando(char *comando)
{
	size_t len = strlen(comando);
	char *inicio = comando, *fin = comando + (len - 1);

	if (len > 0 && comando[len - 1] == '\n')
		comando[len - 1] = '\0';
	while (*inicio == ' ')
		inicio++;
	while (fin > inicio && *fin == ' ')
		fin--;
	*(fin + 1) = '\0';

	return (inicio);
}
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
			break; }
		comando = procesar_comando(comando);
		tokens = tokenised(comando);
		if (tokens != NULL)
		{
			if (strcmp(tokens[0], "env") == 0)
			{	print_env(environ);
				free_tokens(tokens);
				tokens = NULL; }
			else
			{	proceso_hijo(tokens);
				free_tokens(tokens);
				tokens = NULL; }
		}
		else
		{	free_tokens(tokens);
			tokens = NULL; }
		comando = NULL; }
	if (tokens != NULL)
		free_tokens(tokens);
	return (0); }
