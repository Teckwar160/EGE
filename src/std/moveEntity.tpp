#ifndef MOVEENTITY_TPP
#define MOVEENTITY_TPP

#include <std/moveEntity.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    void moveEntity<mType>::update(char tecla,EGE::CORE::EntityId id,mType *gameContext){
        auto controller = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(id);
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        controller ->move(tecla,position);
    }
}
#endif