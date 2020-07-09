#include "../../include/core/Entity.hpp"

namespace EGE{
    template<class Type>
    Entity<Type>::Entity(){
        /*Nada*/
    }

    template<class Type>
    Entity<Type>::Entity(EntityType type){
        this -> type = type;
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

    EntityBase::EntityBase(){
        /*Nada*/
    }

    EntityBase::~EntityBase(){
        /*Nada*/
    }
}
