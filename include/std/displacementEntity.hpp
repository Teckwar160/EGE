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
        public:
            void update(mType *gameContext);

            void updated(char tecla,EGE::CORE::EntityId id,mType *gameContext);
    };
}
#endif