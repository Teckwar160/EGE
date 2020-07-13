#include <core/Manager.hpp>

namespace EGE::CORE{
    
    template<typename Type>
    void Manager<Type>::addEntity(){
        entities.push_back(new Type());
    }

    template<typename Type>
    void Manager<Type>::traverse(void (*pfun)(Type*)){
        for(auto i : this -> entities){
            pfun(i);
        }
    }
}