#ifndef SYSTEMSCORE_TPP
#define SYSTEMSCORE_TPP

#include <std/Windows/Systems/systemScore.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    template<typename mType>
    void systemScore<mType>::scoreInitializer(EGE::CORE::EntityId id, mType *mBoard){
        auto board = mBoard -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Sprite>(id);
        auto spriteBoard = board -> getSprite();
        bool referencePoint = false;

        for(auto it  = spriteBoard.begin(); it != spriteBoard.end(); it++){
            if(it -> getPixel() == '$'){
                it -> setPixel('0');

                if(!referencePoint){
                    referencePoint = true;
                    this -> score = *it;
                } 
            }
        }

        board -> editSprite(spriteBoard);
    }

    template<typename mType>
    void systemScore<mType>::update(int points , EGE::CORE::EntityId id, mType *mBoard){
        this -> points += points;

        if(this -> points > 9999){
            this ->  points = 9999;
        }

        auto board = mBoard -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Sprite>(id);
        auto spriteBoard = board -> getSprite();
            
        int thousands = this -> points/1000;
        int hundreds = (this -> points - (thousands *1000))/100;
        int tens = (this -> points - (thousands*1000 + hundreds*100))/10;
        int units = this -> points -(thousands*1000 + hundreds*100 +tens*10);

        for(auto it  = spriteBoard.begin(); it != spriteBoard.end(); it++){
            if(this -> score.getX() == it -> getX()){
                if(this -> score.getY() == it -> getY()){
                    it -> setPixel('0'+ thousands);
                    it++;
                    it -> setPixel('0'+ hundreds);
                    it++;
                    it -> setPixel('0'+ tens);
                    it++;
                    it -> setPixel('0'+ units);
                    break;
                }
            }
        }

        board -> editSprite(spriteBoard);
    }

    template<typename mType>
    int systemScore<mType>::getPoints(){
        return this -> points;
    } 
}

#endif