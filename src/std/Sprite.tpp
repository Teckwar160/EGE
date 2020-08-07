#ifndef SPRITE_TPP
#define SPRITE_TPP

#include <std/Sprite.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    /**Métodos privados*/

    void Sprite::spriteLoader(){

        std::string address = "resources\\sprites\\"+ this -> name + ".txt";

        std::ifstream archive;

        archive.open(address,std::ios::in);

        char charTemporary;

        if(!archive.fail()){
            for(int i = 0; i< this -> n; i++){
                for(int j = 0; j<this -> n; j++){
                    archive >> charTemporary;
                    this -> container[i][j] = charTemporary;
                }
            }
        }else{
            std::cout << "Fallo #0" << std::endl;
        }

        archive.close();
    }

    void Sprite::converterR2ToR(){
        for(int i=0; i<this ->n; i++){
            for(int j = 0; j<this ->n; j++){
                if(this -> container[i][j] != this -> charToIgnore){
                    Pixel tmpPixel;
                    tmpPixel.setPixel(this -> container[i][j]);
                    tmpPixel.setX(j);
                    tmpPixel.setY(i);
                    this -> sprite.push_back(tmpPixel);                   
                }
            }
        }
    }

    /**Métodos publicos*/
    Sprite::Sprite(){
        /*Nada*/
    }

    Sprite::~Sprite(){

    }

    void Sprite::spriteInitializer(int n, std::string name, char charToIgnore){
        this -> n = n;
        this -> name = name;
        this -> charToIgnore = charToIgnore;

        this -> container = new char*[this -> n];

        for(int i = 0; i<this -> n; i++){
            this -> container[i] = new char[this -> n];
        }

        this -> spriteLoader();

        this -> converterR2ToR();


        for(int i =0; i< this -> n; i++){
            delete this ->container[i];
        }
        delete[] this -> container;

    }

    void Sprite::visualize(EGE::STD::TERMINAL::WINDOWS::Position coordinates,bool view){
        auto positionsVector = coordinates.getPosition();
        EGE::STD::TERMINAL::WINDOWS::Terminal *cursor = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal();

       // cursor -> gotoxy(this ->sprite[0].getX() + std::get<0>(positionsVector[0]),this ->sprite[0].getY() + std::get<1>(positionsVector[0]));

        for(int i=0; i<this -> getSizeSprite(); i++){
            cursor -> gotoxy(std::get<0>(positionsVector[i]),std::get<1>(positionsVector[i]));

            if(view){
                std::cout << this -> sprite[i].getPixel();
            }else{
                std::cout << " ";
            }
        }
    }

    int Sprite::getSizeSprite(){
        return this -> sprite.size();
    }

    char Sprite::getCharToIgnore(){
        return this -> charToIgnore;
    }

    int Sprite::getN(){
        return this -> n;
    }

    std::vector<Pixel> Sprite::getSprite(){
        return this -> sprite;
    }

    template<typename mType>
    void mSprite<mType>::spriteInitializer(EGE::CORE::EntityId id,int n,std::string nombre,char charToIgnore){
        auto sprite = this -> template getComponent<Sprite>(id);
        sprite -> spriteInitializer(n,nombre,charToIgnore);
    }

    template<typename mType>
    void mSprite<mType>::positionInitializer(EGE::CORE::EntityId id,int x, int y){
        auto sprite = this -> template getComponent<Sprite>(id);
        auto position = this -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        position -> positionInitiaizerSprite(sprite ->getSizeSprite(),sprite -> getSprite(),x,y);
    }

    template<typename mType>
    int mSprite<mType>::addEntity(){
        auto id = EGE::CORE::Manager<mType>::addEntity();

        this -> template addComponent<Sprite>(id);
        this -> template addComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        return id;
    }
}

#endif