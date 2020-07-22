#ifndef CONTROLADOR_TPP
#define CONTROLADOR_TPP

#include <std/Controlador.hpp>

namespace EGE::STD::TERMINAL{

    char Controller::moveFilter(char Tecla){
        for(auto i : this -> Teclas){
            if(Tecla == i){
                return Tecla;
            }
        }
    }
}

#endif