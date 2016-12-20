# Neutrino_Mixing
Calcular probabilidades de oscilacion en neutrinos a 3 sabores.

Básicamente, la intención del programa es pedir por pantalla qué oscilación en concreto quieres, a qué Energía (GeV), para qué intervalo 
de longitud (km) y qué precisión quieres (divisiones que tendrá ese intervalo de longitud). Esto último será útil para agilizar el cálculo
si lo que quieres es una imagen global de la amplitud de probabilidad, por ejemplo.

Para hacerlo de la forma más rigurosa posible (y si queremos meter la fase de Dirac para la violación de la simetría CP) necesitaremos
una librería que me permita definir y trabajar con variable compleja.

El output del programa debe ser un fichero en el que venga la probabilidad (entre 0 y 1) para cada longitud del intervalo establecido.
