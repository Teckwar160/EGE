#ifndef SYSTEMCOLLITIONTERMINAL_HPP
#define SYSTEMCOLLITIONTERMINAL_HPP

#include <core/System.hpp>
#include <core/Alias.hpp>
#include <std/Windows/Components/Position.tpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class Sistema que se encarga de verificar si una entidad sigue en el tablero del juego.
     */
    template<typename mType>
    class systemCollitionTerminal : public EGE::CORE::System<mType>{
        public:
            /**
             * @brief Método que verifica si la entidad sigue en el tablero.
             * @param id Identificador de la entidad que se movera.
             * @param gameContext Manager de la entidad en cuestión.
             */
            bool update(EGE::CORE::EntityId id, mType *gameContext);
    };
}

#endif