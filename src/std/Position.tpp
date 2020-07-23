#ifndef POSITION_TPP
#define POSITION_TPP

#include <std/Position.hpp>

namespace EGE::STD::TERMINAL{

    Position::Position(){ }

    Position::~Position(){ }

    void Position::positionInitializer(int size, int x, int y){
        this -> size = size;

        for(int i = 0; i <this -> size; ++i){
            for(int j = 0; j <this -> size; ++j){
               position.push_back(std::make_pair(x+j,y+i));
            }
        }
    }

    std::vector<std::tuple<int,int>> Position::getPosition(){
        return this -> position; 
    }

    std::tuple<int,int> *Position::getPositionInit(){
        return &position[0];
    }

    void Position::updatePosition(){

        auto newPosition = position[0];
        this -> position.clear();

        for(int i = 0; i<this -> size; i++){
            for(int j=0; j<this -> size; j++){
                this -> position.push_back(std::make_pair(std::get<0>(newPosition)+j,std::get<1>(newPosition)+i));
            }
        }
    }
}

#endif //Posicion.tpp