#ifndef SYSTEMCOLLITIONTERMINAL_TPP
#define SYSTEMCOLLITIONTERMINAL_TPP

#include <std/Windows/Systems/systemCollitionTerminal.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    bool systemCollitionTerminal<mType>::update(EGE::CORE::EntityId id,mType *gameContext){
        auto tm = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal();
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);

        int tall = tm -> getTall();
        int width = tm -> getWidth();
        int x;
        int y;

        auto vectorDePosicion = position -> getPosition();

        for(auto i : vectorDePosicion){
            x = std::get<0>(i);
            y = std::get<1>(i);

            if(y == 0 || y >= tall){
                return true;
            }

            if(x == 0 || x >= width){
                return true;
            }
        }
        return false;
    }
}
#endif