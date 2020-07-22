#ifndef ENTRADA_TPP
#define ENTRADA_TPP

#include <std/Entrada.hpp>

namespace EGE::STD::TERMINAL{

    void systemInput::update(int *gameContext){
        /*Nada*/
    }

    char systemInput::update(){
        if(kbhit()){
            Tecla = getch();
        }
        return Tecla;
    }
}

#endif