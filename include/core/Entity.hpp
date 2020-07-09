/**Guardas de inclusion*/
#ifndef ENTITY_HPP
#define ENTITY_HPP

/**Definiciones de alias*/
using EntityType = int;

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
            EntityType type = 0;
        public:
        /**
         *@brief Método constructor vacío.
         */
        Entity();

        /**
         *@brief Método constructor.
         *
         *@param type Identificador de la entidad.
         */
        Entity(EntityType type);

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