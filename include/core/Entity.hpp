/**Guardas de inclusion*/
#ifndef ENTITY_HPP
#define ENTITY_HPP

/**Definiciones de alias*/
using EntityId = int;

/**Paquete*/
namespace EGE{
    /**
     *@brief Interface de cualquier objeto del motor.
     */
    class Entity{
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
    };
}

#endif