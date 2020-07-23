#ifndef MOVEENTITY_HPP
#define MOVEENTITY_HPP

#include <core/System.hpp>
#include <core/Alias.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    class moveEntity : public EGE::CORE::System<mType>{
        public: 
            void update(mType *gameContext);
            void updated(char tecla, EGE::CORE::EntityId id,mType *gameContext);
    };
}
#endif