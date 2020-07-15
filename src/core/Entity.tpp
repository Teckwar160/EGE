#include <core/Entity.hpp>

namespace EGE::CORE{

    /**Métodos de la clase Entity*/
    template<class Type>
    Entity<Type>::Entity(EntityId id){
        this -> id = id;
    }

    template<class Type>
    Entity<Type>::~Entity(){
        /*Nada*/
    }
 
    template<class Type>
    EntityType Entity<Type>::getEntityType(){

        static EntityType _type = nextType++;

        return _type;
    }

    template<class Type>
    EntityId Entity<Type>::getEntityId(){
        return id;
    }

    /**Métodos de la clase EntityBase*/

    EntityBase::EntityBase(){
        /*Nada*/
    }

    EntityBase::~EntityBase(){
        /*Nada*/
    }

    template<typename CMP>
    void EntityBase::addComponent(CMP *component){
        //components[component -> getComponentType()] = component;
        components.insert({component -> getComponentType(),component});
    }

    template<typename CMP>
    void EntityBase::deleteComponent(){
        delete components[CMP::getComponentType()];
        
        for(auto it = components.begin(); it != components.end();){
            if(it ->first == CMP::getComponentType()){
                it = components.erase(it);
            }else{
                ++it;
            }
        }
    }

    template<typename CMP>
    CMP* EntityBase::getComponent(){

        auto i = components.find(CMP::getComponentType());

        if(i != components.end()){
            return static_cast<CMP*>(i -> second);
        }

        return nullptr;
        
    }
}
