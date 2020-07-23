#ifndef INPUT_TPP
#define INPUT_TPP

#include <std/Input.hpp>

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