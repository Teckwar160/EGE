#include "..\..\include\core\Entity.hpp"

namespace EGE{
    Entity::Entity(){
        /*Nada*/
    }

    Entity::Entity(EntityType type){
        this -> type = type;
    }
}