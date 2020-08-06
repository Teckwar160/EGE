#ifndef PIXEL_HPP
#define PIXEL_HPP

namespace EGE::STD::TERMINAL::WINDOWS{
    class Pixel{
        private:
            char pixel;
            int x;
            int y;
        public:
            Pixel();
            ~Pixel();
            void setPixel(char pixel);
            void setX(int x);
            void setY(int y);
            char getPixel();
            int getX();
            int getY();
    };
}

#endif