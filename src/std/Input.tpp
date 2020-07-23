#ifndef INPUT_TPP
#define INPUT_TPP

#include <std/Input.hpp>

namespace EGE::STD::TERMINAL{

    void systemInput::update(int *gameContext){
        /*Nada*/
    }

    char systemInput::update(){
        if(kbhit()){
            return getch();
        }
        return 0;
    }
}

#endif