#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <core/Component.tpp>
#include <std/Windows/Others/Pixel.tpp>
#include <core/Manager.tpp>
#include <std/Windows/Components/Controller.tpp>
#include <std/Windows/Others/WindowsTerminal.hpp>
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

            /**Nombre del archivo que tiene al dibujo del sprite*/
            std::string name;

            /**Contenedor del sprite*/
            char **container;

            std::vector<Pixel> sprite;

            /**Caracter que se ignorara del contenedor en bruto*/
            char charToIgnore;

            /**
             * @brief Método que se encarga de leer un archivo y cargar al contendor el sprite.
             * @param n Tamaño de la matriz que contiene al sprite.
             */
            void spriteLoader(int n);

            /**
             * @brief Método que se encarga de convertir a una matriz cuadrada a un vector.
             * @param n Grado de la matriz.
             */
            void converterR2ToR(int n);

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
             * @param name Nombre del archivo que contiene al sprite.
             */
            void spriteInitializer(EGE::CORE::EntityId n, std::string name, char charToIgnore);

            /**
             * @brief Método que se encarga de visualizar al sprite con colores por default.
             * @param coordinates Sera de donde se saquen las coordenadas para el gotoxy.
             * @param view Si se muesta el sprite o se oculta.
             */
            void visualize(EGE::STD::TERMINAL::WINDOWS::Position coordinates,bool view = true);

            /**
             * @brief Método que se encarga de visualizar al sprite con el colro que quieras.
             * @param coordinates Sera de donde se saquen las coordenadas para el gotoxy.
             * @param color Color que quieras que tenga el sprite.
             * @param view Si se muesta el sprite o se oculta.
             */
            void visualizeColor(EGE::STD::TERMINAL::WINDOWS::Position coordinates, unsigned short  color,bool view = true);

            /**
             * @brief Método que devuelve el tamaño del vector que contiene a sprite.
             * @return Tamaño del vector que contiene a sprite..
             */
            int getSizeSprite();

            /**
             * @brief Método que retorna el caracter a ignorar del sprite.
             * @return Caracter a ignorar del sprite.
             */
            char getCharToIgnore();

            /**
             * @brief Método que retorna una copia del sprite.
             * @return Vector de tipo sprite.
             */
            std::vector<Pixel> getSprite();

            /**
             * @brief Método que permite modificar el sprite de la entidad. (Solo uso profesional no para usuario final).
             * @param newSprite Nuevo sprite.
             */
            void editSprite(std::vector<Pixel> newSprite);
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
             * @param charToIgnore Caracter que se ignorara al momento de cargar al sprite.
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
             * @brief Método que agrega una entida a entities.
             * @return Identificador de la entidad.
             */
            EGE::CORE::EntityId addEntity();
    };

}
#endif