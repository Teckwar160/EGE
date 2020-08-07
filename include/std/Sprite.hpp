#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <core/Component.tpp>
#include <std/Pixel.tpp>
#include <core/Manager.tpp>
#include <std/Controller.tpp>
#include <std/WindowsTerminal.hpp>
#include <core/Alias.hpp>
#include <vector>
#include <fstream>
#include <iostream>

namespace EGE::STD::TERMINAL::WINDOWS{

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
            char **container;

            std::vector<Pixel> sprite;

            /**Caracter que se ignorara del contenedor en bruto*/
            char charToIgnore;

            /**
             * @brief Método que se encarga de leer un archivo y cargar al contendor el sprite.
             */
            void spriteLoader();

            void converterR2ToR();

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
            void spriteInitializer(EGE::CORE::EntityId n, std::string name, char charToIgnore);

            /**
             * @brief Método que se encarga de visualizar al sprite.
             * @param cursor Solo para uso de gotoxy de la terminal.
             * @param coordenadas Sera de donde se saquen las coordenadas para el gotoxy.
             * @param mostrar Si se muesta el sprite o se oculta.
             */
            void visualize(EGE::STD::TERMINAL::WINDOWS::Position coordinates,bool view = true);

            /**
             * @brief Método que devuelve el grado de la matriz.
             * @return Grado de la matriz.
             */
            int getSizeSprite();

            /**
             * @brief Método que retorna el caracter a ignorar del sprite.
             * @return Caracter a ignorar del sprite.
             */
            char getCharToIgnore();

            int getN();

            std::vector<Pixel> getSprite();
    };

    /**
     * @class Manager para inicializar una entidad.
     */
    template<typename mType>
    class mSprite : public EGE::CORE::Manager<mType>{
        public:
            /**
             * @brief Método encargado de inicializar a un sprite.
             * 
             * @param id Id de la entidad creada.
             * @param n Tamaño de la matriz del sprite.
             * @param nombre Nombre del archivo que contiene al sprite.
             */
            void spriteInitializer(EGE::CORE::EntityId id,int n,std::string nombre, char charToIgnore = '*');

            /**
             * @brief Metodo para iniciar la posicion del sprite.
             * 
             * @param size Tamaño del arreglo de posiciones.
             * @param x Posición inicial de la entidad en x.
             * @param y Posición inicial de la entidad en y.
             */
            void positionInitializer(EGE::CORE::EntityId id,int x, int y);

            /**
             * @brief Método que agrega una entidas a entities.
             */
            int addEntity();
    };

}
#endif