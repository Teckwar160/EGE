#ifndef INPUT_TPP
#define INPUT_TPP

#include <std/Windows/Input.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    char systemInput::update(){
        if(kbhit()){
            return getch();
        }
        return 0;
    }
}

#endif