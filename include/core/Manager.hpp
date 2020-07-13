#ifndef MANAGER_HPP
#define MANAGER_HPP

/**Bibliotecas necesarias*/
#include <unordered_map>
#include <vector>

/**Alias*/
#include <core/alias.hpp>

namespace EGE::CORE{
    /**
     * @brief Clase base de todos los managers.
     */
    template<typename Type>
    class Manager{
        protected:
            /**Vector que contiene a todas las entidades que manejara el manager*/
            std::vector<Type*> entities;
            /**Mapa que contiene a todos los componenetes que manejara el manager*/
            std::unordered_map<EGE::CORE::ComponentType,std::vector<EGE::CORE::ComponentBase>> components;
        public:
            /**
             * @brief Método que agrega una entidas a entities.
             */
            void addEntity();

            /**
             * @brief Método que aplica una función a todas las entidades.
             * @param pfun Función a aplicar a todos los elementos.
             */
            void traverse(void (*pfun)(Type*));

            std::vector<Type*> getEntities(){
                return entities;
            }

    };
}


#endif