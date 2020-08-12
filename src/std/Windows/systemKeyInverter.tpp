#ifndef SYSTEMKEYINVERTER_TPP
#define SYSTEMKEYINVERTER_TPP

#include <std/Windows/systemKeyInverter.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    char systemKeyInverter::update(char key,EGE::CORE::ControlType control){
        switch(key){
            case 'w':
            case 'W':
            case UP:
                if(control == WASD) key = 's';
                if(control ==  ARROWS) key = DOWN;
                break;
            case 'a':
            case 'A':
            case LEFT:
                if(control == WASD) key = 'd';
                if(control ==  ARROWS) key = RIGHT;
                break;
            case 's':
            case 'S':
            case DOWN:
                if(control == WASD) key = 'w';
                if(control ==  ARROWS) key = UP;
                break;
            case 'd':
            case 'D':
            case RIGHT:
                if(control == WASD) key = 'a';
                if(control ==  ARROWS) key = LEFT;
                break;
        }
        return key;
    }

}

#endif