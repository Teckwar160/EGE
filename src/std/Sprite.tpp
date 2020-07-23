#ifndef SPRITE_TPP
#define SPRITE_TPP

#include <std/Sprite.hpp>

namespace EGE::STD::TERMINAL{

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

    void Sprite::visualize(TerminalType *cursor, EGE::STD::TERMINAL::Position coordinates,bool view){
        int k = 0;
        auto positionsVector = coordinates.getPosition();

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
}

#endif