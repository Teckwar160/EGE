#include <core/System.hpp>

namespace EGE::CORE{
    template<class Type>
    System<Type>::System(){}

    template<class Type>
    System<Type>::System(SystemType type){
        this -> type = type;
    }

    template<class Type>
    System<Type>::~System(){
        /*Nada*/
    }

    
    template<class Type>
    SystemType System<Type>::getSystemType(){

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
