#ifndef PRESHELL_H
#define PRESHELL_H
#include <stddef.h>
#include <stdio.h>

extern char **environ;

void prompt();
void free_tokens(char **tokens);
ssize_t _getline(char **ptrline, size_t *size, FILE *stream);
char **tokenised(char *comando);
int ejecucion(char **tokens);
int proceso_hijo(char **tokens);
char **_getenv(void);
char *_asprintf(char *a, char *b);
char *generar_ruta(char *comando);

#endif
