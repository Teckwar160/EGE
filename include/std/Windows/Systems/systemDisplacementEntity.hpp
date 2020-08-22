#ifndef SYSTEMDISPLACEMENTENTITY_HPP
#define SYSTEMDISPLACEMENTENTITY_HPP

#include <core/System.hpp>
#include <std/Windows/Systems/systemCollitionTerminal.tpp>
#include <std/Windows/systems/systemmoveEntity.tpp>
#include <std/Windows/Systems/systemVisualizeEntity.tpp>
#include <core/Alias.hpp>
#include <std/Windows/Systems/systemKeyInverter.tpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class Sistema que mueve a las entidades siempre y cuando sean visibles.
     */
    template<typename mType>
    class systemDisplacementEntity : public EGE::CORE::System<mType>{
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
             * @return True si choco contra los marcos de la terminal en caso contrario false. 
             */
            bool update(char key,EGE::CORE::EntityId id,mType *gameContext,EGE::CORE::ControlType control);
    };
}
#endif