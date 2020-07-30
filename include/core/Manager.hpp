#ifndef MANAGER_HPP
#define MANAGER_HPP

/**Bibliotecas necesarias*/
#include <unordered_map>
#include <vector>

/**Alias*/
#include <core/Alias.hpp>

namespace EGE::CORE{

    class ManagerBase{
        protected:
            /**Atributo que identifica el tipo de sistema*/
            inline static ManagerType nextType = 0;
        public:
            /**
             *@brief Método constructor.
             */
            ManagerBase();

            /**
             *@brief Método destructor.
             */
            virtual ~ManagerBase() = 0;
    };

    /**
     * @brief Clase base de todos los managers.
     */
    template<typename Type>
    class Manager : public ManagerBase{
        protected:
            /**Mapa que contiene a todas las entidades que manejara el manager*/
            std::unordered_map<EntityId,Type*> entities;

            /**Contador que lleva registro de cada entidad creada en entities*/
            static inline int numEntities = 0;

            /**Método que libera la memoria de entities*/
            static void freeEntities(Type*);

        public:
            /**
             * @brief Método que destruye a las entidades de entitites
             */
            ~Manager();

            /**
             * @brief Método que agrega una entidas a entities.
             */
            EntityId addEntity();

            /**
             * @brief Método que destruye una entidad de entities.
             */
            void destroyEntity(EntityId id);

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

            /**
             * @brief Método que añade un componente a components.
             * @param id Identificador de la entidad a la que se le agregara el component.
            */
            template<typename CMP>
            void addComponent(EntityId id);

            /**
             * @brief Método que elimina un component de la entity.
             */
            template<typename CMP>
            void deleteComponent(EntityId id);

            /**
             * @brief Método que retorna un component.
             * @return Apuntador a un component.
             */
            template<typename CMP>
            CMP* getComponent(EntityId id);

            /**
             * @brief Método que nos regresa el tpo de manager.
             * @return Tipo de manager.
             */
            ManagerType getManagerType();

            /**
             * @brief Método para regresar una entidad 
             * @return Apuntador a una entidad
             */
            template<typename Ent>
            Ent* getEntity(EntityId id);

            /**
             * @brief Método que regresa una copia del mapa de entidades.
             * @return Mapa de netidades.
             */
            std::unordered_map<EntityId,Type*> getEntities();
    };
}


#endif