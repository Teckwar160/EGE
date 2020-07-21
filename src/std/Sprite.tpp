#ifndef SPRITE_TPP
#define SPRITE_TPP

#include <std/Sprite.hpp>

namespace EGE::STD::TERMINAL{

    /**Métodos privados*/

    void Sprite::spriteLoader(){
        this -> dimensionReal = this -> n*this -> n;

        std::string direccion = "resources\\sprites\\"+ this -> nombre + ".txt";

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
                    this -> dimensionReal -=1;
                }
            }
        }
    }

    void Sprite::convertidorDeR2aR(){
        int k =0;

        for(int i = 0; i< this -> n; i++){
            for(int j = 0; j<this -> n; j++){
                if(this ->contenedor[i][j] != this -> caracterAIgnorar){
                    this -> sprite[k] = this -> contenedor[i][j];
                    k++;
                }
            }
        }
    }

    /**Métodos publicos*/
    Sprite::Sprite(){
        /*Nada*/
    }

    Sprite::~Sprite(){
        if(this ->estado){
            for(int i =0; i< this -> n; i++){
                delete this ->contenedor[i];
            }

            delete[] this -> contenedor;

            delete[] this -> sprite;
        }
    }

    void Sprite::spriteInitializer(int n, std::string nombre){
        this -> estado = true;
        this -> n = n;
        this -> nombre = nombre;

        this -> contenedor = new char*[this -> n];

        for(int i = 0; i<this -> n; i++){
            this -> contenedor[i] = new char[this -> n];
        }

        this -> spriteLoader();

        this -> sprite = new char[this -> dimensionReal];

        this -> convertidorDeR2aR();


    }
    void Sprite::visualize(Terminal *cursor, Posicion coordenadas, bool mostrar){


    }

    int Sprite::getN(){
        return this -> n;
    }

    int Sprite::getDimensionReal(){
        return this -> dimensionReal;
    }
}

#endif