# Como usar EGE

## ¿Dónde empiezo a hacer mi juego?

Ya viene incluido un archivo main en la carpeta src/main.cpp en el ya viene incluida la librería del core pero hace falta que incluya la de la STD esta dependerá de su sistema operativo.

### Windows:

include <std/Windows/WindowsSTD.hpp>

### Linux:

include <std/Linux/LinuxSTD.hpp>

## ¿Cómo compilo mi juego? (Solo el archivo main.cpp)

Para hacer esto tiene que crear el archivo make.exe o make.out dependiendo el sistema.

## Instruccion para compilar el archivo make.cpp

g++ make.cpp -o make.(out/exe)

### Windows:

En el cmd despues de compilar el make.cpp ejecutar make

### Linux:

En terminal despues de compilar el make.cpp ejecutar ./make

## ¿Y si tengo más archivos además del main?

Si usted trabajo de modo modular tendrá que ir agregando uno a uno sus archivos .cpp al make.cpp y repetir los pasos de compilación del make

Ejemplo:

"g++ -Wall -std=c++17 -o main src/main.cpp ejemplo.cpp ejemplo2.cpp -Iinclude -Isrc"


## ¿Y si quiero compilar con archivos .tpp?

Para esto tendra que hacer una carpeta con sus archivos .hpp en include/nombreDeSuCarpeta y sus archivos .tpp en src/nombreDeSuCarpeta. Una vez hecho esto no tendrá que modificar la instrucción del make y lo podrá seguir usando como viene por default. (Ojo es recomendable que el nombre de la carpeta de .hpp y .tpp sea el mismo nombre)