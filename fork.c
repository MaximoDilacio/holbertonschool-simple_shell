#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

extern char **environ;

/**
 * proceso_hijo - funcion para crear un proceso hijo para mantener
 * el proceso padre
 * @tokens: char almacena grupo de palabras que encontro el getline
 * Return: Retorna 0 si funciona y -1 si hay error
*/

int proceso_hijo(char **tokens)
{
	pid_t pid;
	int estado;

	pid = fork();

	if (pid == -1)
	{
		perror("fallo fork");
		return (-1);
	}
	else if (pid == 0)
	{
		ejecucion(tokens);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &estado, 0);
		return (0);
	}
}
