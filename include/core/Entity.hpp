/**Guardas de inclusion*/
#ifndef ENTITY_HPP
#define ENTITY_HPP

/**Definiciones de alias*/
using EntityType = int;

/**Paquete*/
namespace EGE{
    /**
     *@brief Interface de cualquier objeto del motor.
     */
    class Entity{
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
    };

    class EntiyBase{
        public:
            inline static EntityType nextType = 0;
            
    };
}

#endif