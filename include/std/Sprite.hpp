#ifndef SPRITE_HPP
#define SPRITE_HPP

#if defined (_WIN32)
#include <std/WindowsTerminal.hpp>
#define Terminal EGE::STD::TERMINAL::WINDOWS::Terminal
#else
#include <std/LinuxTerminal.hpp>
#define Terminal EGE::STD::TERMINAL::LINUX::Terminal
#endif


#include <core/Component.hpp>
#include <std/Posicion.hpp>
#include <fstream>
#include <iostream>
#define Posicion EGE::STD::TERMINAL::Posicion

namespace EGE::STD::TERMINAL{

    /**
     * @class Parte visual de una entity.
     */
    class Sprite : public EGE::CORE::Component<Sprite>{
        private:
            /**Tamaño de la matriz que tiene el dibujo del sprite*/
            int n;

            /**Dimension real del sprite es decir ya sin apoyos*/
            int dimensionReal;

            /**Nombre del archivo que tiene al dibujo del sprite*/
            std::string nombre;

            /**Contenedor del sprite en bruto*/
            char **contenedor;

            /**Contenedor del sprite ya pulido*/
            char *sprite;

            /**Caracter que se ignorara del contenedor en bruto*/
            char caracterAIgnorar;

            /**Estado de la memoria solicitada*/
            bool estado = false;

            /**
             * @brief Método que se encarga de leer un archivo y cargar al contendor el sprite.
             */
            void cargadorDeSprite();

            /**
             * @brief Método encargado de convertir una matriz de R2 a R
             */
            void convertidorDeR2aR();

        public:

            /**
             * @brief Método constructor de sprite.
             */
            Sprite();

            /**
             * @brief Método destructor de sprite.
             */
            ~Sprite();

            /**
             * @brief Método encargado de inicializar a un sprite.
             * @param n Tamaño de la matriz del sprite.
             * @param nombre Nombre del archivo que contiene al sprite.
             */
            void inicializarSprite(int n, std::string nombre);

            /**
             * @brief Método que se encarga de visualizar al sprite.
             * @param cursor Solo para uso de gotoxy de la terminal.
             * @param coordenadas Sera de donde se saquen las coordenadas para el gotoxy.
             * @param mostrar Si se muesta el sprite o se oculta.
             */
            void visualizar(Terminal *cursor, Posicion coordenadas,bool mostrar = true);

            /**
             * @brief Método que devuelve el grado de la matriz.
             * @return Grado de la matriz.
             */
            int getN();

            /**
             * @brief Método que devuelve el tamaño real del sprite.
             * @return Tamaño real del sprite.
             */
            int getDimensionReal();

    };

}
#endif