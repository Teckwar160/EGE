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
                    this -> sprite[i][j] = charTemporary;
                }
            }
        }else{
            std::cout << "Fallo #0" << std::endl;
        }

        archive.close();
    }

    /**Métodos publicos*/
    Sprite::Sprite(){
        /*Nada*/
    }

    Sprite::~Sprite(){
        if(this ->state){
            for(int i =0; i< this -> n; i++){
                delete this ->sprite[i];
            }
            delete[] this -> sprite;
        }
    }

    void Sprite::spriteInitializer(int n, std::string name, char charToIgnore){
        this -> state = true;
        this -> n = n;
        this -> name = name;
        this -> charToIgnore = charToIgnore;

        this -> sprite = new char*[this -> n];

        for(int i = 0; i<this -> n; i++){
            this -> sprite[i] = new char[this -> n];
        }

        this -> spriteLoader();
    }

    void Sprite::visualize(EGE::STD::TERMINAL::WINDOWS::Position coordinates,bool view){
        int k = 0;
        auto positionsVector = coordinates.getPosition();
        EGE::STD::TERMINAL::WINDOWS::Terminal *cursor = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal();

        cursor -> gotoxy(std::get<0>(positionsVector[0]),std::get<1>(positionsVector[0]));
        for(int i = 0; i<this -> n; i++){
            for(int j = 0; j<this -> n; j++){
                
               cursor -> gotoxy(std::get<0>(positionsVector[k]),std::get<1>(positionsVector[k])); 

               if(view){
                   if(this -> sprite[i][j] != this -> charToIgnore){
                       std::cout << this -> sprite[i][j];
                   }
               }else{
                   std::cout << " ";
               }
               k++;
            }
        }
    }

    int Sprite::getN(){
        return this -> n;
    }

    char **Sprite::getSprite(){
        return this -> sprite;
    }

    char Sprite::getCharToIgnore(){
        return this -> charToIgnore;
    }

    template<typename mType>
    void mSprite<mType>::spriteInitializer(EGE::CORE::EntityId id,int n,std::string nombre){
        auto sprite = this -> template getComponent<Sprite>(id);
        sprite -> spriteInitializer(n,nombre);
    }

    template<typename mType>
    void mSprite<mType>::positionInitializer(EGE::CORE::EntityId id,int x, int y){
        auto sprite = this -> template getComponent<Sprite>(id);
        auto position = this -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
        position -> positionInitializer(sprite -> getN(),x,y);
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