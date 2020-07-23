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
#include <std/moveEntity.tpp>

class nave :public EGE::CORE::Entity<nave>{
    public:
        nave(int id): Entity(id){

        }
};

class Mnave : public EGE::STD::TERMINAL::mSprite<nave>{

};

int main(){
    TerminalType *tm = TerminalType::getTerminal(50,30);
    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::Controller>(Nave1);
    base.spriteInitializer(Nave1,3,"nave");
    base.positionInitializer(Nave1,2,2);

    EGE::STD::TERMINAL::visualizeEntity<Mnave> view;
    EGE::STD::TERMINAL::systemInput entrada;
    EGE::STD::TERMINAL::moveEntity<Mnave> move;

    tm -> pintarLimites();
    tm -> ocultarCursor();
    char Tecla = 0;

    while(Tecla != 'c'){
        
        Tecla = entrada.update();
        if(Tecla == 'w' || Tecla == 'a' || Tecla == 's' ||Tecla == 'd'){
            view.updated(tm,Nave1,&base,false);
            move.updated(Tecla,Nave1,&base);
           
        }
        view.updated(tm,Nave1,&base);
        

        Sleep(10);
    }

    delete tm;
}
