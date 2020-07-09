/**Guardas de inclusion*/
#ifndef ENTITY_HPP
#define ENTITY_HPP

/**Alias*/
#include "alias.hpp"

/**Paquete*/
namespace EGE{

    class EntityBase{
        public:
            /**Atributo que identifica a las identidades*/
            inline static EntityType nextType = 0;

            /**
             *@brief Método constructor.
             */
            EntityBase();

            /**
             *@brief Método destructor.
             */
            virtual ~EntityBase() = 0;

    };
    
    /**
     *@brief Interface de cualquier objeto del motor.
     */
    template<class Type>
    class Entity : public EntityBase{
        private:
            EntityId id = 0;
        public:
        /**
         *@brief Método constructor vacío.
         */
        Entity();

        /**
         *@brief Método constructor.
         *
         *@param id Identificador de la entidad.
         */
        Entity(EntityId id);

        /**
         *@brief Método destructor.
         */
        virtual ~Entity() = 0;

        /**
         *@brief Método que nos regresa el tipo de entidad.
         *@return EntityType
         */
        static EntityType getEntityType();
    };
}

#endif