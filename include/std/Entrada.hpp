#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include <core/System.hpp>
#include <std/WindowsTerminal.hpp>

namespace EGE::STD::TERMINAL{

    class systemInput : public EGE::CORE::System<int>{

        private:
            char Tecla = 0;
        public:
            void update(int *gameContext);
            char update();
    };
}

#endif