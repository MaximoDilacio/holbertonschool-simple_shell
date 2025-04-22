#ifndef PRESHELL_H
#define PRESHELL_H
#include <stddef.h>
#include <stdio.h>

extern char **environ;

char **tokenised(char *comando);
int ejecucion(char **tokens);
int proceso_hijo(char **tokens);
char **_getenv(void);

#endif
