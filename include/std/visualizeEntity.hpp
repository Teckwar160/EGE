#ifndef VISUALIZEENTITY_HPP
#define VISUALIZEENTITY_HPP

#include <core/System.hpp>
#include <std/Sprite.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    class visualizeEntity : public EGE::CORE::System<mType>{
        public: 
            void update(mType *gameContext);
            void updated(TerminalType *cursor,int id,mType *gameContext,bool view = true);
    };
}
#endif