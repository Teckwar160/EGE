#ifndef SPRITE_TPP
#define SPRITE_TPP

#include <std/Sprite.hpp>

namespace EGE::STD::TERMINAL{

    /**Métodos privados*/

    void Sprite::cargadorDeSprite(std::string nombre){
        this -> dimensionReal = this -> n*this -> n;

        std::string direccion = "resources\\sprites\\"+ nombre + ".txt";

        std::ifstream archivo;

        archivo.open(direccion,std::ios::in);

        char caracterTemporal;

        if(!archivo.fail()){
            for(int i = 0; i< this -> n; i++){
                for(int j = 0; j<this -> n; j++){
                    archivo >> caracterTemporal;
                    this -> contenedor[i][j] = caracterTemporal;
                }
            }
        }else{
            std::cout << "Fallo #0" << std::endl;
        }

        archivo.close();

        for(int i =0; i<this -> n; i++){
            for(int j=0; j< this -> n; j++){
                if(this -> contenedor[i][j] == this -> caracterAIgnorar){
                    
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

    void Sprite::inicializarSprite(int n, std::string nombre){
        this -> n = n;
        this -> nombre = nombre;

        this -> contenedor = new char*[this -> n];

        for(int i = 0; i<this -> n; i++){
            this -> contenedor[i] = new char[this -> n];
        }


    }
    void Sprite::visualizar(bool mostrar){

    }

    int Sprite::getN(){
        return this -> n;
    }

    int Sprite::getDimensionReal(){
        return this -> dimensionReal;
    }
}

#endif