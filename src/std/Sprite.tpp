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

    void Sprite::spriteInitializer(int n, std::string nombre, char caracterAIgnorar){
        this -> estado = true;
        this -> n = n;
        this -> nombre = nombre;
        this -> caracterAIgnorar = caracterAIgnorar;

        this -> contenedor = new char*[this -> n];

        for(int i = 0; i<this -> n; i++){
            this -> contenedor[i] = new char[this -> n];
        }

        this -> spriteLoader();

        this -> sprite = new char[this -> dimensionReal];

        this -> convertidorDeR2aR();


    }
    void Sprite::visualize(TerminalType *cursor, EGE::STD::TERMINAL::Posicion coordenadas, bool mostrar){
        int k = 0;
        auto vectorDePosiciones = coordenadas.getPosition();
        cursor -> gotoxy(std::get<0>(vectorDePosiciones[0]),std::get<1>(vectorDePosiciones[0]));
  
        for(int i = 0; i<this -> n; i++){
            for(int j = 0; j<this -> n; j++){
                
               cursor -> gotoxy(std::get<0>(vectorDePosiciones[k]),std::get<1>(vectorDePosiciones[k])); 

               if(mostrar){
                   if(this -> contenedor[i][j] != this -> caracterAIgnorar){
                       std::cout << this -> contenedor[i][j];
                   }
               }else{
                   std::cout << " ";
               }
               k++;
            }
            std::cout<< std::endl;
        }

    }

    int Sprite::getN(){
        return this -> n;
    }

    int Sprite::getDimensionReal(){
        return this -> dimensionReal;
    }
}

#endif