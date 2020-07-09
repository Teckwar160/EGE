#include "..\..\include\core\Entity.hpp"

namespace EGE{
    Entity::Entity(){
        /*Nada*/
    }

    Entity::Entity(EntityId id){
        this -> id = id;
    }
}