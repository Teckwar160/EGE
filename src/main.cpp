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

class Mnave : public EGE::STD::TERMINAL::WINDOWS::mSprite<nave>{

};





int main(){
    EGE::STD::TERMINAL::WINDOWS::Terminal *tm = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal(50,30);
    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(Nave1);
    base.spriteInitializer(Nave1,3,"nave");
    base.positionInitializer(Nave1,2,2);

    EGE::STD::TERMINAL::WINDOWS::visualizeEntity<Mnave> view;
    EGE::STD::TERMINAL::WINDOWS::systemInput entrada;
    EGE::STD::TERMINAL::WINDOWS::displacementEntity<Mnave> dp;

    tm -> terminalInit();
    char Tecla = 0;

    while(Tecla != 'c'){
        
        Tecla = entrada.update();

        dp.updated(Tecla,Nave1,&base,ARROWS);  

        view.updated(Nave1,&base);
        
        Sleep(10);
    }

    delete tm;
}
