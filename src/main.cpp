#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>
#include <std/Sprite.tpp>
#include <std/Position.tpp>
#include <std/Controller.tpp>
#include <std/Input.tpp>
#include <std/visualizeEntity.tpp>
#include <std/displacementEntity.tpp>


class nave :public EGE::CORE::Entity<nave>{
    public:
        nave(int id): Entity(id){

        }
};

class perro :public EGE::CORE::Entity<perro>{
    public:
        perro(int id): Entity(id){

        }
};

class Mnave : public EGE::STD::TERMINAL::mSprite<nave>{

};

class mPerro : public EGE::STD::TERMINAL::mPosition<perro>{

};



int main(){
    EGE::STD::TERMINAL::WINDOWS::Terminal *tm = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal(50,30);
    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::Controller>(Nave1);
    base.spriteInitializer(Nave1,3,"nave");
    base.positionInitializer(Nave1,2,2);

    EGE::STD::TERMINAL::visualizeEntity<Mnave> view;
    EGE::STD::TERMINAL::systemInput entrada;
    //EGE::STD::TERMINAL::moveEntity<Mnave> move;
    EGE::STD::TERMINAL::displacementEntity<Mnave> dp;
#if 1
    tm -> terminalInit();
    char Tecla = 0;

    while(Tecla != 'c'){
        
        Tecla = entrada.update();
        if(Tecla == 'w' || Tecla == 'a' || Tecla == 's' ||Tecla == 'd'){
            //view.updated(Nave1,&base,false);
            //move.updated(Tecla,Nave1,&base);
            dp.updated(Tecla,Nave1,&base);
           
        }
        view.updated(Nave1,&base);
        

        Sleep(10);
    }
#endif
    //delete tm;
}
