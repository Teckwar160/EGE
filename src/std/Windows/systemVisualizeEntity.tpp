#ifndef SYSTEMVISUALIZEENTITY_TPP
#define SYSTEMVISUALIZEENTITY_TPP

#include <std/Windows/systemVisualizeEntity.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    void systemVisualizeEntity<mType>::view(EGE::CORE::EntityId id,mType *gameContext, bool view){
        auto sprite = gameContext ->  template getComponent<Sprite>(id);
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        
        sprite -> visualize(*position,view);
    }

    template<typename mType>
    void systemVisualizeEntity<mType>::viewColor(EGE::CORE::EntityId id,mType *gameContext, unsigned short color, bool view){
        auto sprite = gameContext ->  template getComponent<Sprite>(id);
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        
        sprite -> visualizeColor(*position,color,view);
    }
}
#endif