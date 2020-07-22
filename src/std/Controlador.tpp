#ifndef CONTROLADOR_TPP
#define CONTROLADOR_TPP

#include <std/Controlador.hpp>
#include <tuple>

namespace EGE::STD::TERMINAL{

    void Controller::move(char tecla,Posicion *position){
        auto tuplaInicial = position -> getPositionInit();

        switch(tecla){
            case 'w':
            case 'W':
            case ARRIBA:
            {
                auto y = std::get<1>(*tuplaInicial);
                y-=1;
                *tuplaInicial = {std::get<0>(*tuplaInicial),y};
            }
                break;
            case 'a':
            case 'A':
            case IZQUIERDA:
            {
                auto x = std::get<0>(*tuplaInicial);
                x-=1;
                *tuplaInicial = {x,std::get<1>(*tuplaInicial)};
                
            }
                break;
            case 's':
            case 'S':
            case ABAJO:
            {
                auto y = std::get<1>(*tuplaInicial);
                y+=1;
                *tuplaInicial = {std::get<0>(*tuplaInicial),y};
            }
                break;
            case 'd':
            case 'D':
            case DERECHA:
            {
                auto x = std::get<0>(*tuplaInicial);
                x+=1;
                *tuplaInicial = {x,std::get<1>(*tuplaInicial)};
            }
                break;
        };
    }
}

#endif