#ifndef DISPLACEMENTENTITY_HPP
#define DISPLACEMENTENTITY_HPP

#include <core/System.hpp>
#include <std/collitionTerminal.tpp>
#include <std/moveEntity.tpp>
#include <std/visualizeEntity.tpp>
#include <core/Alias.hpp>
#include <std/keyDefinition.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class Sistema que mueve a las entidades siempre y cuando sean visibles.
     */
    template<typename mType>
    class displacementEntity : public EGE::CORE::System<mType>{
        private:
            /**Arreglos de teclas permitidos por el sistema*/
            char  wasd[8] = {'w','W','a','A','s','S','d','D'};
            char arrows[4] = {UP,LEFT,DOWN,RIGHT};
        public:
            /**
             * @brief Método que mueve a una entidad visible.
             * @param key Tecla pulsada.
             * @param id Identificador de la entidad que se movera.
             * @param gameContext Manager de la entidad en cuestión.
             * @param control Sistema de teclas que se usara para mover a la entidad.
             */
            void update(char key,EGE::CORE::EntityId id,mType *gameContext,EGE::CORE::ControlType control);
    };
}
#endif