#ifndef PIXEL_HPP
#define PIXEL_HPP

namespace EGE::STD::TERMINAL::WINDOWS{

    /**
     * @class Clase que se encarga de mantener ordenado a los sprites.
     */
    class Pixel{
        private:
            /**Caracter del pixel*/
            char pixel;

            /**Coordenada relativa en x*/
            int x;

            /**Coordenada relativa en y*/
            int y;

        public:

            /**
             * @brief Método constructor de Pixel.
             */
            Pixel();

            /**
             * @brief Método destructor de Pixel.
             */
            ~Pixel();

            /**
             * @brief Método encargado de definir el caracter del pixel.
             * @param pixel Caracter a guardar.
             */
            void setPixel(char pixel);

            /**
             * @brief Método encargado de definir la coordenada relativa x.
             * @param x Coordenada relativa.
             */
            void setX(int x);

            /**
             * @brief Método encargado de definir la coordenada relativa y.
             * @param y Coordenada relativa.
             */
            void setY(int y);

            /**
             * @brief Método encargado de devolver el caracter de pixel.
             * @return Caracter de pixel.
             */
            char getPixel();

            /**
             * @brief Método encargado de devolver la coordenada relativa x.
             * @return Coordenada relativa.
             */
            int getX();

            /**
             * @brief Método encargado de devolver la coordenada relativa y.
             * @return Coordenada relativa.
             */
            int getY();
    };
}

#endif