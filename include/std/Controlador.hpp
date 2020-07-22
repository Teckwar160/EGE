#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#if defined (_WIN32)
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#else
#define prueba pr
#endif

#include <core/Component.hpp>
#include <std/Entrada.hpp>

namespace EGE::STD::TERMINAL{

    class Controller : public EGE::CORE::Component<Controller>{
        private:
            char Teclas[] = {'w','W','a','A','s','S','d','D',ARRIBA,IZQUIERDA,ABAJO,DERECHA};
        public:
            char moveFilter(char Tecla);
    };
}

#endif