== INTRODUCCIÓN ==

Este archivo describe el paquete que contiene el evaluador, plantillas, y su
uso.


== CONTENIDOS DEL PAQUETE ==

El paquete incluye los siguientes archivos y carpetas:

* guessnum.c, guessnum.cpp, guessnum.java, guessnum.py: Plantillas para
  ensamblar tu código.
* test.sh: Script para probar tu código contra el caso test.in.
* test.in: Archivo de caso de entrada utilizado para probar tu código.
* examples: Carpeta con ejemplos en diferentes lenguajes de códigos y su
  interpretación en el evaluador.
* Los demás archivos son utilizados por el evaluador y NO deberían ser
  modificados.


== ELABORACIÓN DE CASOS DE ENTRADA ==

Para probar tu código deberás editar el archivo `test.in`. El caso será
interpretado por el evaluador de la siguiente forma:

* Única línea - Dos números: n, s. n = número límite a adivinar,
  s = número secreto.


== PROCEDIMIENTO PARA PROBAR TU CÓDIGO ==

1. Escribe tu código dentro de la plantilla que corresponde a tu lenguaje
   (guessnum.c para C, guessnum.cpp para C++, guessnum.java para Java,
   guessnum.py para Python).
2. Edita el archivo `test.in`. Este archivo será utilizado como caso de entrada.
3. Ejecuta el script `test.sh` mandando como único parámetro la extensión del
   lenguaje que utilizaste para tu código. Puedes realizarlo mediante el
   comando siguiente:
       sh test.sh [lenguaje]
4. El evaluador compilará y ejecutará tu código contra el caso que elaboraste.
   Puedes recibir los siguientes veredictos:
       + WA - Did not call answer(): Tu código no llamó en ningún momento a la
         función `responder()` o `answer()`. Recuerda hacerlo para confirmar tu
         respuesta.
       + WA - Wrong number: Tu código llamó a `responder()` o `answer()` con un
         número diferente al secreto.
       + WA - Guess limit excceded: Tu código trató de llamar más de 100
         veces a `adivinar()`/`guess()`.
       + AC: ¡Felicidades! Tu programa resolvió el caso de prueba correctamente.
