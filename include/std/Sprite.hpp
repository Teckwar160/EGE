#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <core/Component.hpp>
#include <fstream>
#include <iostream>

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

            void cargadorDeSprite(std::string nombre);

        public:
            Sprite();
            ~Sprite();
            void inicializarSprite(int n, std::string nombre);
            void visualizar(bool mostrar = true);
            int getN();
            int getDimensionReal();

    };

}
#endif