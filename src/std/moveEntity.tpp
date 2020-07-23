#ifndef MOVEENTITY_TPP
#define MOVEENTITY_TPP

#include <std/moveEntity.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    void moveEntity<mType>::update(mType *gameContext){
        /*Nada*/
    }

    template<typename mType>
    void moveEntity<mType>::updated(char tecla,int id,mType *gameContext){
        auto controller = gameContext -> template getComponent<EGE::STD::TERMINAL::Controller>(id);
        auto position = gameContext -> template getComponent<EGE::STD::TERMINAL::Position>(id);
        controller ->move(tecla,position);
    }
}
#endif