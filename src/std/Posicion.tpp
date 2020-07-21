#ifndef POSICION_TPP
#define POSICION_TPP

#include <std/Posicion.hpp>

namespace EGE::STD::TERMINAL{

    Posicion::Posicion(){

    }

    Posicion::~Posicion(){

    }

    void Posicion::positionInitializer(int tam, int x, int y){
        for(int i = 0; i < tam; ++i){
            for(int j = 0; j <tam; ++j){
               posicion.push_back(std::make_pair(x+i,y+j));
            }
        }
    }

    std::vector<std::tuple<int,int>> Posicion::getPosition(){
        return this -> posicion; 
    }

    void Posicion::setPosition(void (*pFun)(std::tuple<int,int>*)){
        for(auto i : this -> posicion){
           pFun(&i);
        }
    }
}

#endif //Posicion.tpp