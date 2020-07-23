#ifndef VISUALIZEENTITY_HPP
#define VISUALIZEENTITY_HPP

#include <core/System.hpp>
#include <std/Sprite.hpp>
#include <core/Alias.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    class visualizeEntity : public EGE::CORE::System<mType>{
        public: 
            void update(mType *gameContext);
            void updated(TerminalType *cursor,EGE::CORE::EntityId id,mType *gameContext,bool view = true);
    };
}
#endif