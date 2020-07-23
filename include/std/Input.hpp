#ifndef INPUT_HPP
#define INPUT_HPP

#include <core/System.hpp>
#include <std/WindowsTerminal.hpp>

namespace EGE::STD::TERMINAL{

    /**
     * @class Clase encargada de atarapar las teclas pulsadas.
     */
    class systemInput : public EGE::CORE::System<int>{

        private:
            /**Ultima tecla pulsada*/
            char Tecla = 0;
        public:
            /**
             * @brief Método heredado no seusara.
             * @param gameContext No importa que sea.
             */
            void update(int *gameContext);

            /**
             * @brief Método encargado de atrapar las teclas pulsadas.
             * @return Ultima tecla pulsada.
             */
            char update();
    };
}

#endif