#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <core/Alias.hpp>
#include <core/Component.hpp>
#include <std/Position.hpp>

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
             */
            void move(char key,Position *position);
            
    };
}

#endif