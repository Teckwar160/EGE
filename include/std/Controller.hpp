#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#if defined (_WIN32)
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#else
#define prueba pr
#endif

#include <core/Component.hpp>
#include <std/Position.hpp>

namespace EGE::STD::TERMINAL{
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