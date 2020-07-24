#ifndef POSITION_HPP
#define POSITION_HPP

#include <core/Component.hpp>
#include <core/Manager.hpp>
#include <core/Alias.hpp>
#include <iostream>
#include <vector>
#include <tuple>

namespace EGE::STD::TERMINAL{


    /**
     * @class Componente de posición para una entidad.
     */
    class Position : public EGE::CORE::Component<Position>{
        private: 

            /**Tamaño del arreglo*/
            int size;
            /**Vector de las tuplas de posicion de la entidad*/
            std::vector<std::tuple<int,int>> position;

        public:

            Position();

            ~Position();

            /**
             * @brief Metodo para iniciar la posicion del sprite.
             * 
             * @param size Tamaño del arreglo de posiciones.
             * @param x Posición inicial de la entidad en x.
             * @param y Posición inicial de la entidad en y.
             */
            void positionInitializer(int size,int x,int y);

            /**
             * @brief Método para obtener la posición de la entidad
             * 
             * @return Vector con las coordenas de la entidad
             */
            std::vector<std::tuple<int,int>> getPosition();

            std::tuple<int,int> *getPositionInit();

            /**
             * @brief Método para asignarle una posisición a la entidad.
             * 
             * @param void Función para cambiar la posicion del elemento.
             */
            void updatePosition();
    };

    /**
     * @class Clase de posición para objertos sin sprite.
     */
    template <typename mType>
    class mPosition : public EGE::CORE::Manager<mType>{
        public:

            /**
             * @brief Metodo para iniciar la posicion del sprite.
             * 
             * @param size Tamaño del arreglo de posiciones.
             * @param x Posición inicial de la entidad en x.
             * @param y Posición inicial de la entidad en y.
             */
            void positionInitializer(EGE::CORE::EntityId id,int x, int y);

            /**
             * @brief Método que agrega una entidas a entities.
             */
            int addEntity();
    }; 
}

#endif //Position.hpp