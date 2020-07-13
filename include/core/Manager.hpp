#ifndef MANAGER_HPP
#define MANAGER_HPP

/**Bibliotecas necesarias*/
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

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

            /**Contador que lleva registro de cada entidad creada en entities*/
            static inline int numEntities = 0;

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

            /**
             * @brief Método que aplica una función a una sola entidad.
             * @param id Identificador de la entidad.
             * @param pfun Función a aplicar a la entidad.
             */
            void applyFuntion(EntityId id, void (*pfun)(Type*));

            /**
             * @brief Método que retorna el número de entidades que maneja el manager.
             * @return Número de entidades creadas por el manager.
             */
            int getNumEntities();

    };
}


#endif