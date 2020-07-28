#ifndef DISPLACEMENTENTITY_HPP
#define DISPLACEMENTENTITY_HPP

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#include <core/System.hpp>
#include <std/collitionTerminal.tpp>
#include <std/moveEntity.tpp>
#include <std/visualizeEntity.tpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    class displacementEntity : public EGE::CORE::System<mType>{
        public:
            void update(mType *gameContext);

            void updated(char tecla,EGE::CORE::EntityId id,mType *gameContext);
    };
}
#endif