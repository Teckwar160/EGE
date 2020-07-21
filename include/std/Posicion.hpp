#ifndef POSICION_HPP
#define POSICION_HPP

#include <core/Component.hpp>
#include <iostream>
#include <vector>
#include <tuple>

namespace EGE:: STD:: TERMINAL{


    /**
     * @class Componente de posición para una entidad.
     */
    class Posicion : public EGE::CORE::Component<Posicion>{
        private: 
        
            /**Tamaño de elarreglo*/
            int tam;
            /**Vector de las tuplas de posicion de la entidad*/
            std::vector<std::tuple<int,int>> posicion;

        public:

            /**
             * @brief Metodo para iniciar la posicion del sprite.
             * 
             * @param int Tamaño del arreglo de posiciones.
             * @param int Posición inicial de la entidad en x.
             * @param int Posición inicial de la entidad en y.
             * 
             */
            void inicializadorDePosicion(int,int,int);

            /**
             * @brief Método para obtener la posición de la entidad
             * 
             * @return Vector con las coordenas de la entidad
             */
            std::vector<std::tuple<int,int>> getPosicion();

            /**
             * @brief Método para asignarle una posisición a la entidad.
             * 
             * @param void* Función para cambiar la posicion del elemento.
             */
            void setPosition(void (*pFun)(std::tuple<int,int>));
    };
}

#endif //Posicion.hpp