#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * contador - funcion para contar caracteres de un array
 * @a: char que contiene el array
 * Return: retorna i (Cantidad de caracteres del array)
*/
int contador(char *a)
{
	int i = 0;

	if (a == NULL)
	{
		return (NULL);
	}

	while (a[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _asprintf - funcion para concatenar dos arrays
 * @a: array 1
 * @b: array 2
 * Return: Si falla retorna NULL, si no, retorna candena_final
*/
char *_asprintf(char *a, char *b)
{
	int len_a, len_b, len, i, j, k = 0;
	char *cadena_final = NULL;

	len_a = contador(a);
	len_b = contador(b);
	len = len_a + len_b;

	cadena_final = malloc(sizeof(char) * (len + 2));
	if (cadena_final == NULL)
	{
		perror("malloc fallo");
		return (NULL);
	}

	for (i = 0; i < len_a; i++)
	{
		cadena_final[k] = a[i];
		k++;
	}
	cadena_final[k] = '/';
	k = k + 1;
	for (j = 0; j < len_b; j++)
	{
		cadena_final[k] = b[j];
		k++;
	}
	cadena_final[k] = '\0';

	return (cadena_final);
}
