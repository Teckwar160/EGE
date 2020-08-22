#ifndef SYSTEMINPUT_HPP
#define SYSTEMINPUT_HPP

#include <core/System.hpp>
#include <std/Windows/Others/WindowsTerminal.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class Clase encargada de atrapar las teclas pulsadas.
     */
    class systemInput : public EGE::CORE::System<char>{
        public:
            /**
             * @brief Método encargado de atrapar las teclas pulsadas.
             * @return Ultima tecla pulsada.
             */
            char update();
    };
}

#endif