#ifndef POSITION_TPP
#define POSITION_TPP

#include <std/Position.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

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

    void Position::positionInitiaizerSprite(int size, std::vector<Pixel> sprite, int x, int y){
        this -> size = size;

        for(int i = 0; i<this -> size; i++){
            position.push_back(std::make_pair(sprite[i].getX() + x,sprite[i].getY()+y));
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

    template<typename mType>
    void mPosition<mType>::positionInitializer(EGE::CORE::EntityId id, int x, int y){
        auto posicion = this -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        posicion -> positionInitializer(1,x,y);
    }

    template<typename mType>
    int mPosition<mType>::addEntity(){
        auto id = EGE::CORE::Manager<mType>::addEntity();
        this -> template addComponent<Position>(id);
        return id;
    }
}

#endif //Posicion.tpp