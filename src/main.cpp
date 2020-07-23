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

class nave :public EGE::CORE::Entity<nave>{
    public:
        nave(int id): Entity(id){

        }
};

class Mnave : public EGE::STD::TERMINAL::mSprite<nave>{

};

int main(){

    #if 1
    TerminalType *tm = TerminalType::getTerminal(50,30);
    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::Sprite>(Nave1);
    base.addComponent<EGE::STD::TERMINAL::Position>(Nave1);
    base.addComponent<EGE::STD::TERMINAL::Controller>(Nave1);

    base.spriteInitializer(Nave1,3,"nave");
    base.positionInitializer(Nave1,2,2);

    EGE::STD::TERMINAL::visualizeSprite<Mnave> view;

    tm -> pintarLimites();
    tm -> ocultarCursor();
    view.updated(*tm,Nave1,&base,true);

    delete tm;
    #endif
}
