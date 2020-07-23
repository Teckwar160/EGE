#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <core/Component.tpp>
#include <std/Position.hpp>
#include <core/Manager.tpp>
#include <std/Controller.tpp>
#include <core/Alias.hpp>
#include <fstream>
#include <iostream>

#if defined (_WIN32)
#include <std/WindowsTerminal.hpp>
#define TerminalType EGE::STD::TERMINAL::WINDOWS::Terminal
#else
#include <std/LinuxTerminal.hpp>
#define TerminalType EGE::STD::TERMINAL::LINUX::Terminal
#endif

namespace EGE::STD::TERMINAL{

    /**
     * @class Parte visual de una entity.
     */
    class Sprite : public EGE::CORE::Component<Sprite>{
        private:
            /**Tamaño de la matriz que tiene el dibujo del sprite*/
            int n;

            /**Nombre del archivo que tiene al dibujo del sprite*/
            std::string name;

            /**Contenedor del sprite*/
            char **sprite;

            /**Caracter que se ignorara del contenedor en bruto*/
            char charToIgnore;

            /**Estado de la memoria solicitada*/
            bool state = false;

            /**
             * @brief Método que se encarga de leer un archivo y cargar al contendor el sprite.
             */
            void spriteLoader();

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
            void spriteInitializer(EGE::CORE::EntityId n, std::string name, char charToIgnore = '*');

            /**
             * @brief Método que se encarga de visualizar al sprite.
             * @param cursor Solo para uso de gotoxy de la terminal.
             * @param coordenadas Sera de donde se saquen las coordenadas para el gotoxy.
             * @param mostrar Si se muesta el sprite o se oculta.
             */
            void visualize(TerminalType *cursor, EGE::STD::TERMINAL::Position coordinates,bool view = true);

            /**
             * @brief Método que devuelve el grado de la matriz.
             * @return Grado de la matriz.
             */
            int getN();
    };

    template<typename mType>
    class mSprite : public EGE::CORE::Manager<mType>{
        public:
            void spriteInitializer(EGE::CORE::EntityId id,int n,std::string nombre);
            void positionInitializer(EGE::CORE::EntityId id,int x, int y);
            int addEntity();
    };

}
#endif