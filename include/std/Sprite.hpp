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

            bool estado = false;

            void cargadorDeSprite();

            void convertidorDeR2aR();

        public:
            Sprite();
            ~Sprite();
            void inicializarSprite(int n, std::string nombre);
            void visualizar(Terminal *cursor, Posicion coordenadas,bool mostrar = true);
            int getN();
            int getDimensionReal();

    };

}
#endif