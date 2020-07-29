#ifndef COLLITIONTERMINAL_HPP
#define COLLITIONTERMINAL_HPP

#include <core/System.hpp>
#include <core/Alias.hpp>
#include <std/Position.tpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    template<typename mType>
    class collitionTerminal : public EGE::CORE::System<mType>{
        public:
            void update(mType *gameContext);

            bool updated(EGE::CORE::EntityId id, mType *gameContext);
    };
}

#endif