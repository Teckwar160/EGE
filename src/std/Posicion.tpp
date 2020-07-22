#ifndef POSICION_TPP
#define POSICION_TPP

#include <std/Posicion.hpp>
#include <std/Controlador.hpp>

namespace EGE::STD::TERMINAL{

    Posicion::Posicion(){ }

    Posicion::~Posicion(){ }

    void Posicion::positionInitializer(int tam, int x, int y){
        this -> tam = tam;
        for(int i = 0; i < tam; ++i){
            for(int j = 0; j <tam; ++j){
               posicion.push_back(std::make_pair(x+j,y+i));
            }
        }
    }

    std::vector<std::tuple<int,int>> Posicion::getPosition(){
        return this -> posicion; 
    }

    std::tuple<int,int> *Posicion::getPositionInit(){
        return &posicion[0];
    }

    void Posicion::updatePosition(){

        auto posicionNueva = posicion[0];
        this -> posicion.clear();

        for(int i = 0; i<tam; i++){
            for(int j=0; j<tam; j++){
                this -> posicion.push_back(std::make_pair(std::get<0>(posicionNueva)+j,std::get<1>(posicionNueva)+i));
            }
        }
        std::cout << "LLEgoo";
    }
}

#endif //Posicion.tpp