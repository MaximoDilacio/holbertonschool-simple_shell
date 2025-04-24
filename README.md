<h1 align="center">Simple Shell</h1>

Este repositorio tiene todas las funciones necesarias para que la simple shell funcione correctamente, esta es una Shell mas básica que la Shell original.

<h2 align="center">Description</h2>

Simple Shell es un pequeño intérprete de comandos desarrollado en C. Lee lo que escribe el usuario, analiza el comando y lo ejecuta, simulando el comportamiento básico de un shell de Unix.

<h2 align="center">Valor de retorno</h2>

En este proyecto, el valor de retorno cumple un rol clave para saber si las funciones se ejecutaron correctamente o si hubo algún error. Tanto funciones del sistema como fork(), execve(), wait() y funciones propias como executing() o tokenised() devuelven un número que indica el resultado de su ejecución.

<ul>
  <li>0 suele significar que todo salió bien.</li>
  <li>-1 o otros valores distintos de 0 indican errores o situaciones especiales que deben manejarse (como un comando no válido o un fallo en la creación de procesos).</li>
</ul>
Estos valores permiten al shell tomar decisiones, mostrar mensajes de error o continuar con otras tareas sin que el programa falle inesperadamente.

<h2 align="center">Archivos</h2>
<ul>
  <li><strong>main.c</strong>: Punto de entrada del programa. Contiene el bucle principal que lee y ejecuta comandos.</li>
  <li><strong>shell.h</strong>: Archivo de encabezado. Declara funciones y estructuras utilizadas en todo el proyecto.</li>
  <li><strong>_asprintf.c</strong>: Implementa una versión personalizada de asprintf para formatear cadenas dinámicamente.</li>
  <li><strong>_getenv.c</strong>: Contiene la función _getenv, que busca variables de entorno.</li>
  <li><strong>executing.c</strong>: Define la función executing, encargada de ejecutar los comandos ingresados por el usuario.</li>
  <li><strong>fork.c</strong>: Implementa la función fork, que crea procesos hijo para ejecutar comandos.</li>
  <li><strong>tokenised.c</strong>: Contiene la función tokenised, que divide la entrada del usuario en tokens (comando y argumentos).</li>
  <li><strong>README.md</strong>: Documentación del proyecto. Explica su propósito, cómo compilarlo y cómo usarlo.</li>
  <li><strong>simple_shell</strong>: Archivo ejecutable generado al compilar. Inicia el shell cuando se ejecuta desde la terminal.</li>
</ul>


<h1>Cómo usar la Simple Shell</h1>

  <h2>1. Compilación</h2>
  <p>Primero, necesitas compilar el código fuente. Abre una terminal y usa el siguiente comando para compilar los archivos fuente:</p>
  <p><strong>gcc -o simple_shell main.c executing.c fork.c tokenised.c _getenv.c _asprintf.c</strong></p>
  <p>Esto generará un archivo ejecutable llamado <strong>simple_shell</strong>.</p>

  <h2>2. Ejecutar el Shell</h2>
  <p>Para ejecutar la Simple Shell, usa el siguiente comando en tu terminal:</p>
  <p><strong>./simple_shell</strong></p>
  <p>Esto abrirá el shell y podrás comenzar a ingresar comandos.</p>

  <h2>3. Ingresar comandos</h2>
  <p>Una vez que el shell esté en ejecución, podrás ingresar comandos del sistema, como:</p>
  <ul>
    <li><strong>ls</strong> – Muestra los archivos y directorios del directorio actual.</li>
    <li><strong>pwd</strong> – Muestra el directorio de trabajo actual.</li>
    <li><strong>exit</strong> – Sale del shell y cierra el programa.</li>
  </ul>

  <h2>4. Salir del Shell</h2>
  <p>Para salir del shell, simplemente escribe <strong>exit</strong> y presiona <strong>Enter</strong>.</p>

  <h2>Posibles errores:</h2>
  <p>Si ingresas un comando no reconocido, el shell mostrará un mensaje de error indicando que el comando no se encontró.</p>


<h2>Ejemplo de Uso:</h2>

<p>1. Inicia el shell:</p>
<p><strong>$ ./simple_shell</strong></p>

<p>2. Ingresa el comando <strong>ls</strong> para listar los archivos:</p>
<p><strong>$ ls</strong></p>
<p>Archivo1.txt  Archivo2.txt  Carpeta/</p>

<p>3. Ingresa el comando <strong>pwd</strong> para ver el directorio actual:</p>
<p><strong>$ pwd</strong></p>
<p>/home/usuario</p>

<p>4. Para salir, usa el comando <strong>exit</strong>:</p>
<p><strong>$ exit</strong></p>


