#ifndef SYSTEMKEYINVERTER_TPP
#define SYSTEMKEYINVERTER_TPP

#include <std/systemKeyInverter.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    char systemKeyInverter::update(char key){
        switch(key){
            case 'w':
            case 'W':
            case UP:
                key = 's';
                break;
            case 'a':
            case 'A':
            case LEFT:
                key = 'd';
                break;
            case 's':
            case 'S':
            case DOWN:
                key = 'w';
                break;
            case 'd':
            case 'D':
            case RIGHT:
                key = 'a';
                break;
        }
        return key;
    }

}

#endif