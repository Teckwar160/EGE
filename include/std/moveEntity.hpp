#ifndef MOVEENTITY_HPP
#define MOVEENTITY_HPP

#include <core/System.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    class moveEntity : public EGE::CORE::System<mType>{
        public: 
            void update(mType *gameContext);
            void updated(char tecla, int id,mType *gameContext);
    };
}
#endif