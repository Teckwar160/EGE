#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <std/Windows/Others/keyDefinition.hpp>
#include <core/Component.hpp>
#include <std/Windows/Components/Position.hpp>
#include <std/Windows/Others/Pixel.tpp>
#include <std/Windows/Components/Sprite.tpp>
#include <vector>

namespace EGE::STD::TERMINAL::WINDOWS{
    /**
     * @class Se encarga de dotar de controles a una entidad.
     */
    class Controller : public EGE::CORE::Component<Controller>{
        public:
            
            /**
             * @brief Método encargado de mover a una entidad.
             * @param key Tecla puslada por el usuario.
             * @param position Componenete de posición de una entidad.
             * @param sprite Copia del sprite para calcular bien la posición.
             * @param step Paso que dara la entidad en cada llamada.
             */
            void move(char key,Position *position,std::vector<Pixel> sprite, int step);
            
    };
}

#endif