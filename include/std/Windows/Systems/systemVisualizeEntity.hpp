#ifndef SYSTEMVISUALIZEENTITY_HPP
#define SYSTEMVISUALIZEENTITY_HPP

#include <core/System.hpp>
#include <std/Windows/Components/Sprite.hpp>
#include <core/Alias.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class Sistema para poder visualizar una entidad en pantalla.
     */
    template<typename mType>
    class systemVisualizeEntity : public EGE::CORE::System<mType>{
        public: 
            /**
             * @brief Método para actualizar la imagen de la entidad en pantalla.
             * @param id Id de la entidad a la que se le actualizará el movimiento.
             * @param gameContext Manager de la entidad.
             * @param view Indicador si la entidad se debe de ver o no.
             */
            void view(EGE::CORE::EntityId id,mType *gameContext,bool view = true);

            /**
             * @brief Método para actualizar la imagen de la entidad en pantalla y le da un color.
             * @param id Id de la entidad a la que se le actualizará el movimiento.
             * @param gameContext Manager de la entidad.
             * @param color Color que tendra la entidad.
             * @param view Indicador si la entidad se debe de ver o no.
             */
            void viewColor(EGE::CORE::EntityId id,mType *gameContext,unsigned short color,bool view = true);
    };
}
#endif