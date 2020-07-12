/**Guardas de inclusion*/
#ifndef ENTITY_HPP
#define ENTITY_HPP

/**Alias*/
#include <core/alias.hpp>

/**Bibliotecas necesarias*/
#include <unordered_map>
#include <memory>
#include <core/Component.hpp>


/**Paquete*/
namespace EGE::CORE{

    /**Definición*/
    using mapComponents = std::unordered_map<ComponentType,ComponentBase*>;

    /**
     *@brief Entidad base de todas las entidades.
     */
    class EntityBase{
        private:
            /**Mapa que contendra a los componenetes de las entidades.*/
            mapComponents components;
        public:
            /**Atributo que identifica a las identidades*/
            inline static EntityType nextType = 0;

            /**
             * @brief Método constructor.
             */
            EntityBase();

            /**
             * @brief Método destructor.
             */
            virtual ~EntityBase() = 0;

            /**
             * @brief Método que añade un componente a components.
             *
             * @param component Componente a agragar a components.
            */
            template<typename CMP>
            void addComponent(CMP* component);

            /**
             * @brief Método que nos devuelve un puntero a un componente de components.
             *
             * @return Puntero a un componente.
             */
            template<typename CMP>
            CMP* getComponent();



    };
    
    /**
     * @brief Interface de cualquier objeto del motor.
     */
    template<class Type>
    class Entity : public EntityBase{
        private:
            EntityId id = 0;
        public:
        /**
         * @brief Método constructor vacío.
         */
        Entity();

        /**
         * @brief Método constructor.
         *
         * @param id Identificador de la entidad.
         */
        Entity(EntityId id);

        /**
         * @brief Método destructor.
         */
        virtual ~Entity() = 0;

        /**
         * @brief Método que nos regresa el tipo de entidad.
         * @return EntityType
         */
        static EntityType getEntityType();

    };
}

#endif