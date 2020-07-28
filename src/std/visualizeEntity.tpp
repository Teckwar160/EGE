#ifndef VISUALIZEENTITY_TPP
#define VISUALIZEENTITY_TPP

#include <std/visualizeEntity.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    void visualizeEntity<mType>::update(mType *gameContext){
        /*Nada*/
    }

    template<typename mType>
    void visualizeEntity<mType>::updated(EGE::CORE::EntityId id,mType *gameContext, bool view){
        auto sprite = gameContext ->  template getComponent<Sprite>(id);
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::Position>(id);
        auto cursor = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal();

        sprite -> visualize(cursor,*position,view);
    }
}
#endif