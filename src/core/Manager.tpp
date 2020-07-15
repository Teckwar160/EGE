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
        this -> entities.clear();
    }

    template<typename Type>
    EntityId Manager<Type>::addEntity(){
        entities.push_back(new Type(numEntities++));
        return entities[entities.size() - 1]->getEntityId();
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

    template<typename Type>
    template<typename CMP>
    void Manager<Type>::addComponent(EntityId id){
        if(id >= 0 && id <= numEntities && entities[id] != nullptr){
            entities[id] -> template addComponent<CMP>();
        }
    }

    template<typename Type>
    template<typename CMP>
    void Manager<Type>::deleteComponent(EntityId id){
        if(id >= 0 && id <= numEntities && entities[id] != nullptr){
            entities[id] -> template deleteComponent<CMP>();
        }
    }

    template<typename Type>
    template<typename CMP>
    CMP* Manager<Type>::getComponent(EntityId id){
        if(id >= 0 && id <= numEntities && entities[id] != nullptr){
            return entities[id] -> template getComponent<CMP>();
        }

        return nullptr;
    }
}