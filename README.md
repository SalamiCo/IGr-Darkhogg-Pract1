Práctica 1 - Informática Gráfica
================================

**Autor:** *Daniel Escoz Solana*

Compilación
-----------

La práctica se ha probado usando GCC 4.6.1 en Ubuntu 11.10. Se requiere el
paquete `libsdl-dev` instalado en el equipo para su correcta compilación. La
compilación en cualquier otro entorno no se ha probado y podría fallar.

Abra un terminal en el directorio de la práctica y a continuación ejecute:

    make clean; make

Tras ello, ejecutar el programa recién generado:

    ./ptg-tree


Uso
---

Controles mediante el ratón:

+ *Click Izquierdo*: Selecciona el cuadrado más pequeño en la posición del ratón
+ *Click Derecho*: Regenera el árbol en la posición del ratón

Controles mediante el teclado:

+ `W` `A` `S` `D`: mueve el área visible de la escena
+ `R` `T`: Incremente/decrementa el zoom de la escena
+ `F` `G`: Hace decrecer/crecer el árbol
+ `V` `B`: Gira el árbol hacia la izquierda/derecha (sólo en modo fijo)
+ `Y` `U`: Elimina/Añade columnas a la ventana (reestablece la cámara)
+ `H` `J`: Elimina/Añade filas a la ventana (reestablece la cámara)
+ `1` `2`: Establece el modo de color en *arco-iris* o *árbol*
+ `8` `9`: Establece el modo de ángulo en *fijo* o *aleatorio*

Cualquier modificación sobre el árbol deseleccionará el cuadrado seleccionado.
Todos los movimientos de cámara (translaciones y escalas) afectan a la cámara
sobre la que esté situado (o se hayasituado por última vez) el ratón.