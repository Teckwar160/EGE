#ifndef VISUALIZEENTITY_TPP
#define VISUALIZEENTITY_TPP

#include <std/Windows/visualizeEntity.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    void visualizeEntity<mType>::update(EGE::CORE::EntityId id,mType *gameContext, bool view){
        auto sprite = gameContext ->  template getComponent<Sprite>(id);
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        
        sprite -> visualize(*position,view);
    }
}
#endif