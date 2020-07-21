#ifndef ENTITY_TPP
#define ENTITY_TPP
#include <core/Entity.hpp>

namespace EGE::CORE
{
    template <class Type>
    Entity<Type>::Entity()
    {
        /*Nada*/
    }

    template <class Type>
    Entity<Type>::Entity(EntityId id)
    {
        this->id = id;
    }

    template <class Type>
    Entity<Type>::~Entity()
    {
        /*Nada*/
    }

    template <class Type>
    EntityType Entity<Type>::getEntityType()
    {

        static EntityType _type = nextType++;

        return _type;
    }

    template <class Type>
    EntityId Entity<Type>::getEntityId()
    {

        return this->id;
    }

    /**Métodos de la clase EntityBase*/

    EntityBase::EntityBase()
    {
        /*Nada*/
    }

    EntityBase::~EntityBase()
    {
        for (auto i : components)
        {
            delete i.second;
        }

        components.clear();
    }

    template <typename CMP>
    void EntityBase::addComponent()
    {
        components.insert({CMP::getComponentType(), new CMP()});
    }

    template <typename CMP>
    void EntityBase::deleteComponent()
    {
        for (auto it = components.begin(); it != components.end();)
        {
            if (it->first == CMP::getComponentType())
            {
                delete it->second;
                it = components.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    template <typename CMP>
    CMP *EntityBase::getComponent()
    {

        auto i = components.find(CMP::getComponentType());

        if (i != components.end())
        {
            return static_cast<CMP *>(i->second);
        }

        return nullptr;
    }
} // namespace EGE::CORE
#endif