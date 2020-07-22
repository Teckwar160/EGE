#ifndef MOVIMIENTO_HPP
#define MOVIMENTO_HPP

#include <core/Component.hpp>
#include <tuple>

namespace EGE::STD::TERMINAL{
    class Movement : public EGE::CORE::Component<Movement>{
        private:
            void update(std::tuple<int,int> *posiciones);

        public:
            void move(char Tecla);
    };
}

#endif