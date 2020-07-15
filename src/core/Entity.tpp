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
        for(auto it = components.begin(); it != components.end();){
            it = components.erase(it);
            ++it;
        }
    }

    template<typename CMP>
    void EntityBase::addComponent(){
        components.insert({CMP::getComponentType(),new CMP()});
    }

    template<typename CMP>
    void EntityBase::deleteComponent(){
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
