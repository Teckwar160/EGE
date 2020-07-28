#ifndef DISPLACEMENTENTITY_HPP
#define DISPLACEMENTENTITY_HPP

#include <core/System.hpp>
#include <std/collitionTerminal.tpp>
#include <std/moveEntity.tpp>
#include <std/visualizeEntity.tpp>
#include <core/Alias.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    class displacementEntity : public EGE::CORE::System<mType>{
        private:
            char  wasd[8] = {'w','W','a','A','s','S','d','D'};
            char arrows[4] = {UP,LEFT,DOWN,RIGHT};
        public:
            void update(mType *gameContext);

            void updated(char key,EGE::CORE::EntityId id,mType *gameContext,EGE::CORE::ControlType control);
    };
}
#endif