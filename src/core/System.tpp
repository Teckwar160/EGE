#ifndef SYSTEM_TPP
#define SYSTEM_TPP
#include <core/System.hpp>

namespace EGE::CORE{
    template<typename... Type>
    System<Type...>::System(){}

    template<typename... Type>
    System<Type...>::System(SystemType type){
        this -> type = type;
    }

    template<typename... Type>
    System<Type...>::~System(){
        /*Nada*/
    }

    
    template<typename... Type>
    SystemType System<Type...>::getSystemType(){

        static SystemType _type = nextType++;

        return _type;
    }

    SystemBase::SystemBase(){
        /*Nada*/
    }

    SystemBase::~SystemBase(){
        /*Nada*/
    }
}
#endif