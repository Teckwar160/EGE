#ifndef COLLITIONTERMINAL_HPP
#define COLLITIONTERMINAL_HPP

#include <core/System.hpp>
#include <core/Alias.hpp>
#include <std/Position.tpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class Sistema que se encarga de verificar si una entidad sigue en el tablero del juego.
     */
    template<typename mType>
    class collitionTerminal : public EGE::CORE::System<mType>{
        public:

            /**
             * @brief Métdodo heredado no usar.
             * @param gameContext Manager de la entidad en cuestión.
             */
            void update(mType *gameContext);

            /**
             * @brief Método que verifica si la entidad sigue en el tablero.
             * @param id Identificador de la entidad que se movera.
             * @param gameContext Manager de la entidad en cuestión.
             */
            bool updated(EGE::CORE::EntityId id, mType *gameContext);
    };
}

#endif