#include <core/Entity.hpp>

namespace EGE::CORE{
    template<class Type>
    Entity<Type>::Entity(){
        /*Nada*/
    }

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

    /**Métodos de la clase EntityBase*/

    EntityBase::EntityBase(){
        /*Nada*/
    }

    EntityBase::~EntityBase(){
        /*Nada*/
    }

    template<typename CMP>
    void EntityBase::addComponent(CMP *component){
        components[component -> getComponentType()] = component;
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
