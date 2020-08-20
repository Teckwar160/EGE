#ifndef CONTROLLER_TPP
#define CONTROLLER_TPP

#include <std/Windows/Controller.hpp>
#include <tuple>

namespace EGE::STD::TERMINAL::WINDOWS{

    void Controller::move(char key,Position *position,std::vector<Pixel> sprite){
        auto firstTuple = position -> getFirstPosition();

        switch(key){
            case 'w':
            case 'W':
            case UP:
            {
                auto y = std::get<1>(*firstTuple);
                y-=1;
                *firstTuple = {std::get<0>(*firstTuple),y};
            }
                break;
            case 'a':
            case 'A':
            case LEFT:
            {
                auto x = std::get<0>(*firstTuple);
                x-=1;
                *firstTuple = {x,std::get<1>(*firstTuple)};
                
            }
                break;
            case 's':
            case 'S':
            case DOWN:
            {
                auto y = std::get<1>(*firstTuple);
                y+=1;
                *firstTuple = {std::get<0>(*firstTuple),y};
            }
                break;
            case 'd':
            case 'D':
            case RIGHT:
            {
                auto x = std::get<0>(*firstTuple);
                x+=1;
                *firstTuple = {x,std::get<1>(*firstTuple)};
            }
                break;
        };
        position ->updatePosition(sprite);
    }
}
#endif