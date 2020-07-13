#include <core/Manager.hpp>

namespace EGE::CORE{
    
    template<typename Type>
    void Manager<Type>::addEntity(){
        entities.push_back(new Type(numEntities++));
    }

    template<typename Type>
    void Manager<Type>::traverse(void (*pfun)(Type*)){
        for(auto i : this -> entities){
            pfun(i);
        }
    }

    template<typename Type>
    void Manager<Type>::applyFuntion(EntityId id, void (*pfun)(Type*)){
        if(id >= 0 && id <= numEntities){
            pfun(entities[id]);
        }
    }

    template<typename Type>
    int Manager<Type>::getNumEntities(){
        return numEntities;
    }
}