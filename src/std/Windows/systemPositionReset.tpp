#ifndef SYSTEMPOSITIONRESET_TPP
#define SYSTEMPOSITIONRESET_TPP

#include <std/Windows/systemPositionReset.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    void systemPositionReset<mType>::positionResetEntity(EGE::CORE::EntityId id, mType *manager, int x, int y){
        auto componentPosition = manager -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);

        componentPosition -> positionReset(x,y);
    }

    template<typename mType>
    void systemPositionReset<mType>::positionResetSprite(EGE::CORE::EntityId id, mType *manager, int x, int y){
        auto componentPosition = manager -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        auto componentSprite = manager -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Sprite>(id);

        componentPosition -> positionResetSprite(componentSprite -> getSprite(),x,y);
    }
}

#endif