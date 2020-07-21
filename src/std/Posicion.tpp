#ifndef POSICION_TPP
#define POSICION_TPP

#include <std/Posicion.hpp>

namespace EGE::STD::TERMINAL{

    void Posicion::positionInitializer(int tam, int x, int y){
        for(size_t i = 0; i < tam; ++i){
            for(size_t j = 0; j < tam; ++j){
               posicion.push_back(std::make_pair(i,j));
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