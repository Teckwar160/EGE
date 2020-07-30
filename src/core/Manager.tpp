#ifndef MANAGER_TPP
#define MANAGER_TPP
#include <core/Manager.hpp>

namespace EGE::CORE{

    /*Métodos de manager Base*/
    ManagerBase::ManagerBase(){
        /*Nada*/
    }

    ManagerBase::~ManagerBase(){
        /*Nada*/
    }

    /*Métodos de manager*/

    template<typename Type>
    ManagerType Manager<Type>::getManagerType(){
        static ManagerType _type = nextType++;

        return _type;
    }
    
    template<typename Type>
    void Manager<Type>::freeEntities(Type* i){
       delete i;
    }

    template<typename Type>
    Manager<Type>::~Manager(){
        this -> traverse(freeEntities);
        this -> entities.clear();
    }

    template<typename Type>
    EntityId Manager<Type>::addEntity(){
        entities.insert({numEntities,new Type(numEntities)});
        numEntities++;
        return entities[entities.size() - 1]->getEntityId();
    }

    template<typename Type>
    void Manager<Type>::destroyEntity(EntityId id){
        freeEntities(entities.find(id) -> second);
        entities.erase(id);
    }

    template<typename Type>
    void Manager<Type>::traverse(void (*pfun)(Type*)){
        for(auto i : this -> entities){
           pfun(i.second);
        }
    }

    template<typename Type>
    void Manager<Type>::applyFuntion(EntityId id, void (*pfun)(Type*)){
        if(id >= 0 && id <= numEntities){
            pfun(entities.find(id) -> second);
        }
    }

    template<typename Type>
    int Manager<Type>::getNumEntities(){
        return numEntities;
    }

    template<typename Type>
    template<typename CMP>
    void Manager<Type>::addComponent(EntityId id){
        if(id >= 0 && id <= numEntities){
            entities.find(id) -> second -> template addComponent<CMP>();
        }
    }

    template<typename Type>
    template<typename CMP>
    void Manager<Type>::deleteComponent(EntityId id){
        if(id >= 0 && id <= numEntities){
            entities.find(id) -> second -> template deleteComponent<CMP>();
        }
    }

    template<typename Type>
    template<typename CMP>
    CMP* Manager<Type>::getComponent(EntityId id){
        if(id >= 0 && id <= numEntities){
            return entities.find(id) -> second -> template getComponent<CMP>();
        }

        return nullptr;
    }

    template<typename Type>
    template<typename Ent>
    Ent* Manager<Type>::getEntity(EntityId id){
        if(id >= 0 && id <= numEntities){
            return entities.find(id) -> second;
        }
        return nullptr;
    }

    template<typename Type>
    std::unordered_map<EntityId,Type*> Manager<Type>::getEntities(){
        return this -> entities;
    }
}
#endif