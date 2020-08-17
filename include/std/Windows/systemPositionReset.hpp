#ifndef SYSTEMPOSITIONRESET_HPP
#define SYSTEMPOSITIONRESET_HPP

#include <core/System.hpp>
#include <core/Alias.hpp>
#include <std/Windows/Position.tpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    template <typename mType>
    class systemPositionReset : public EGE::CORE::System<mType>{
        public:

            /**
             * @brief Método que resetea la posición de una entidad.
             * @param id Identificador de la entidad que se reseteara su posición.
             * @param manager Manager que maneja a la entidad a modificar.
             * @param x Nueva posición en x de la entidad.
             * @param y Nueva posición en y de la entidad.
             */
            void positionResetEntity(EGE::CORE::EntityId id, mType *manager, int x, int y);


            /**
             * @brief Método que resetea la posición de una entidad con sprite.
             * @param id Identificador de la entidad que se reseteara su posición.
             * @param manager Manager que maneja a la entidad a modificar.
             * @param x Nueva posición en x de la entidad.
             * @param y Nueva posición en y de la entidad.
             */
            void positionResetSprite(EGE::CORE::EntityId id, mType *manager, int x, int y);
    };

}

#endif