#ifndef SPRITE_HPP
#define SPRITE_HPP
#if defined(_WIN32)
#include <iostream>
#include <fstream>
#include <core/Manager.hpp>
#include <core/alias.hpp>
#include <std/WindowsTerminal.hpp>

/**!<Definiciones de las flechas del teclado*/
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


namespace EGE::STD::WINDOWS{

    /**
     * @class Clase base que contiene a lso caracteres de los sprites.
     */
    class Pixel{
        private:

            /**Caracter que representa el pixel*/
            char pixel;

            /**Posición en x del pixel*/
            int x;

            /**Posción en y del pixel*/
            int y;

        public:
            /**
             * @brief Método constructor de Pixel.
             */
            Pixel();

            /**
             * @brief Destructor de la clase.
             */
            ~Pixel();

            /**
             * @brief Método que define el caracter del Pixel.
             * @param pixel Caracter de Pixel.
             */
            void setPixel(char pixel);

            /**
             * @brief Método que define la posición en x.
             * @param x Posición en x;
             */
            void setX(int x);

            /**
             * @brief Método que define la posición en y.
             * @param y Posición en y;
             */
            void setY(int y);

            /**
             * @brief Método que nosregresa el caracter del pixel.
             * @return Caracter del pixel.
             */
            char getPixel();

            /**
             * @brief Método que nos regresa la posición en x.
             * @return Posicione en x.
             */
            int getX();

            /**
             * @brief Método que nos regresa la posición en y.
             * @return Posicione en y.
             */
            int getY();
    };

    /**
     * @class Controles basicos de un sprite.
     */
    class Controles{
        protected:
            /**Decisión de si se usara un control o otro*/
            bool usarFlechas;

        public:
            /**
             * @brief Método que se encarga de dotar a un sprite con controles de movimiento.
             * @param Tecla Tecla pulsada por el jugador.
             * @param x Posición en x del pixel.
             * @param y Posición en y del pixel.
             * @param felchas Si se usaran o no las flechas del teclado.
             */
            void movimiento(char Tecla, int *x, int *y);
    };  

    /**
     * @brief Parte grafica en terminal de una entidad.
     */
    class Sprite : public EGE::CORE::Component<Sprite>, Controles{
        private:
            /**Tamaño de la matriz en bruto del sprite*/
            int n;

            /**Dimension real del sprite*/
            int dimensionReal;

            /**Nombre del archivo con el diseño del sprite*/
            std::string nombre;

            /**Caracter que se ignorara del contenedor del archivo*/
            char caracterAIgnorar;

            /**Contenedor que tendra al sprite en bruto*/
            Pixel **contenedor;

            /**Contenedor pulido del sprite*/
            Pixel *sprite;

            /**
             * @brief Método que lee un .txt y lo pasa a una matriz.
             * @param nombre Nombre del archivo que contiene al sprite.
             */
            void cargadorDeSprite(std::string nombre);

            /**
             * @brief Método que convierte una matriz de nxn a un vector de tamaño n.
             */
            void convertidorDeR2aR();

        public:

            /**
             * @brief Método constructor de un sprite.
             * @param n Grado de la matriz que contiene al sprite.
             * @param px Posición en x del primer pixel en la esquina superior izquierda.
             * @param py Posición en y del primer pixel en la esquina superior izquierda.
             * @param nombre Nombre del archivo que contiene al sprite.
             * @param usarFlechas Decisión de si se usaran las flechas del teclado o el wasd.
             * @param caracterAIgnorar Caracterer que se ignorara del sprite.
             */
            Sprite(int n, int pX, int pY, std::string nombre, bool usarFlechas = false,char caracterAIgnorar = '*');

            /**
             * @brief Método constructor vacío.
             */
            Sprite();

            /**
             * @brief Método destructor del sprite.
             */
            ~Sprite();

            /**
             * @brief Método que pinta o borra a un sprite.
             * @param cursor Solo para uso de gotoxy.
             * @param ocultar Decisión de si se muestra o se borra un sprite.
             */
            void visualizar(EGE::STD::TERMINAL::WINDOWS::Terminal *cursor, bool ocultar = false);

            /**
             * @brief Método que mueve a un sprite.
             * @param Tecla Tecla pulsada por el jugador.
             * @param tablero Solo para uso de gotoxy.
             */
            void mover(char Tecla, EGE::STD::TERMINAL::WINDOWS::Terminal *tablero);

            void inicializarSprite(int n, int pX, int pY, std::string nombre, bool usarFlechas = false,char caracterAIgnorar = '*');

            int getDimensionReal();

            Pixel *getSprite();

    };

}

#endif
#endif