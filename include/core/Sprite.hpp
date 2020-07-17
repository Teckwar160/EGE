#ifndef SPRITE_HPP
#define SPRITE_HPP
#if defined(_WIN32)
#include <iostream>
#include <fstream>
#include <core/Manager.hpp>
#include <core/alias.hpp>
#include <core/WindowsTerminal.hpp>

/**!<Definiciones de las flechas del teclado*/
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


namespace EGE::STD::WINDOWS{

    class Pixel{
        private:
            char pixel;
            int x;
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

    class Controles{
        public:
            void movimiento(char Tecla, int *x, int *y, bool flechas = true);
    };  

    class Sprite : public EGE::CORE::Component<Sprite>, Controles{
        private:
            int n;
            int dimensionReal;
            std::string nombre;
            char caracterAIgnorar;
            Pixel **contenedor;
            Pixel *sprite;
            bool usarFlechas;
            void cargadorDeSprite(std::string nombre);
            void convertidorDeR2aR();

        public:
        Sprite(int n, int pX, int pY, std::string nombre, bool usarFlechas = false,char caracterAIgnorar = '*');
        ~Sprite();
        void visualizar(EGE::STD::TERMINAL::WINDOWS::Terminal *cursor, bool ocultar = false);
        void mover(char Tecla, EGE::STD::TERMINAL::WINDOWS::Terminal *tablero);

    };

}

#endif
#endif