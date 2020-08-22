#ifndef SYSTEMINPUT_TPP
#define SYSTEMINPUT_TPP

#include <std/Windows/Systems/systemInput.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    char systemInput::update(){
        if(kbhit()){
            return getch();
        }
        return 0;
    }
}

#endif