#ifndef MOVEENTITY_HPP
#define MOVEENTITY_HPP

#include <core/System.hpp>
#include <core/Alias.hpp>

namespace EGE::STD::TERMINAL{
    /**
     * @class Sistema encargado de otorgar movimiento a una entidad
     */
    template<typename mType>
    class moveEntity : public EGE::CORE::System<mType>{
        public: 

            /**
             * @brief Método que actualiza los sistemas.
             * 
             * @param gameContext Es un manager que gestiona.
             */
            void update(mType *gameContext);

            /**
             * @brief Método para actualizar la posición de la entidad.
             * 
             * @param tecla Tecla que el usuario ingreso.
             * @param id Id de la entidad a la que se le actualizará el movimiento.
             * @param *gameContext Manager de la entidad.
             */
            void updated(char tecla, EGE::CORE::EntityId id,mType *gameContext);
    };
}
#endif