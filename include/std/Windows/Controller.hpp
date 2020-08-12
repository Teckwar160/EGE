#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <std/Windows/keyDefinition.hpp>
#include <core/Component.hpp>
#include <std/Windows/Position.hpp>
#include <std/Windows/Pixel.tpp>
#include <std/Windows/Sprite.tpp>
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
             */
            void move(char key,Position *position,std::vector<Pixel> sprite);
            
    };
}

#endif