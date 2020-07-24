#ifndef VISUALIZEENTITY_HPP
#define VISUALIZEENTITY_HPP

#include <core/System.hpp>
#include <std/Sprite.hpp>
#include <core/Alias.hpp>

namespace EGE::STD::TERMINAL{

    /**
     * @class Sistema para poder visualizar una entidad en pantalla.
     */
    template<typename mType>
    class visualizeEntity : public EGE::CORE::System<mType>{
        public: 

            /**
             * @brief Método que actualiza los sistemas.
             * 
             * @param gameContext Es un manager que gestiona.
             */
            void update(mType *gameContext);

            /**
             * @brief Método para actualizar la imagen de la entidad en pantalla.
             * 
             * @param tecla Tecla que el usuario ingreso.
             * @param id Id de la entidad a la que se le actualizará el movimiento.
             * @param *gameContext Manager de la entidad.
             * @param view Indicador si la entidad se debe de ver o no.
             */
            void updated(TerminalType *cursor,EGE::CORE::EntityId id,mType *gameContext,bool view = true);
    };
}
#endif