/**Guardas de inclusion*/
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

/**Alias*/
#include "alias.hpp"

/**Paquete*/
namespace EGE::CORE{

    class ComponentBase{
        public:
            /**Atributo que identifica a los componentes*/
            inline static ComponentType nextType = 0;

            /**
             * @brief Método constructor.
             */
            ComponentBase();

            /**
             * @brief Método destructor.
             */
            virtual ~ComponentBase() = 0;

    };
    
    /**
     * @brief Interface de cualquier component del motor.
     */
    template<class Type>
    class Component : public ComponentBase{
        private:
            ComponentType idEntity = 0;
        public:
        /**
         * @brief Método constructor vacío.
         */
        Component();

        /**
         * @brief Método constructor.
         *
         * @param idEntity Identificador de la entidad a la que pertenece.
         */
        Component(ComponentType idEntity);

        /**
         * @brief Método destructor.
         */
        virtual ~Component() = 0;

        /**
         * @brief Método que nos regresa el tipo de entidad.
         * @return ComponentType
         */
        static ComponentType getComponentType();
    };
}

#endif