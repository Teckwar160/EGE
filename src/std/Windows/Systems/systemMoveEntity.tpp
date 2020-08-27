#ifndef SYSTEMMOVEENTITY_TPP
#define SYSTEMMOVEENTITY_TPP

#include <std/Windows/Systems/systemMoveEntity.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    void systemMoveEntity<mType>::update(char tecla,EGE::CORE::EntityId id,mType *gameContext,int step){
        auto controller = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(id);
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        auto sprite = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Sprite>(id);

        controller ->move(tecla,position,sprite -> getSprite(),step);
    }
}
#endif