#include <core/Manager.hpp>

namespace EGE::CORE{
    
    template<typename Type>
    void Manager<Type>::freeEntities(Type* i){
        
        if(i != nullptr){
            delete i;
        }
    }

    template<typename Type>
    Manager<Type>::~Manager(){
        this -> traverse(freeEntities);
        std::cout << "\nDestructor de manager\n";
    }

    template<typename Type>
    void Manager<Type>::addEntity(){
        entities.push_back(new Type(numEntities++));
    }

    template<typename Type>
    void Manager<Type>::destroyEntity(EntityId id){
        freeEntities(entities[id]);
        entities[id] = nullptr;
    }

    template<typename Type>
    void Manager<Type>::traverse(void (*pfun)(Type*)){
        for(auto i : this -> entities){
            if(i != nullptr){
                pfun(i);
            }
        }
    }

    template<typename Type>
    void Manager<Type>::applyFuntion(EntityId id, void (*pfun)(Type*)){
        if(id >= 0 && id <= numEntities && entities[id] != nullptr){
            pfun(entities[id]);
        }
    }

    template<typename Type>
    int Manager<Type>::getNumEntities(){
        return numEntities;
    }
}