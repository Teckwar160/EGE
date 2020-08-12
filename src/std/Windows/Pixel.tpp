#ifndef PIXEL_TPP
#define PIXEL_TPP

#include <std/Windows/Pixel.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    Pixel::Pixel(){

    }

    Pixel::~Pixel(){

    }

    void Pixel::setPixel(char pixel){
        this -> pixel = pixel;
    }

    void Pixel::setX(int x){
        this -> x = x;
    }

    void Pixel::setY(int y){
        this -> y = y;
    }

    char Pixel::getPixel(){
        return this -> pixel;
    }

    int Pixel::getX(){
        return this -> x;
    }

    int Pixel::getY(){
        return this -> y;
    }

}

#endif