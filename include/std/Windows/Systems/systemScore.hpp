#ifndef SYSTEMSCORE_HPP
#define SYSTEMSCORE_HPP

#include <std/Windows/Others/Pixel.tpp>
#include <core/Alias.hpp>
#include <vector>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class sistema que se encarga de llevar el score del jugador.
     */
    template<typename mType>
    class systemScore{
        private:
            /**Punto de referencia para poner el score*/
            Pixel score;

            /**Puntos del jugador*/
            int points = 0;
        public:

            /**
             * @brief Método que se encarga de inicializar el score.
             * @param id Identificador de la entidad que llevara el score.
             * @param mBoard Manager de la entidad que llevara el score.
             */
            void scoreInitializer(EGE::CORE::EntityId id, mType *mBoard);

            /**
             * @brief Método que se encarga de actualizar el valor del score.
             * @param points Puntos que se sumaran al score.
             * @param id Identificador de la entidad que llevara el score.
             * @param mBoard Manager de la entidad que llevara el score.
             */
            void update(int points , EGE::CORE::EntityId id, mType *mBoard);

            /**
             * @brief Método que retorna la cantidad de puntos del score.
             * @return Puntos del score.
             */
            int getPoints();
    };
}

#endif