#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>
#include <std/Sprite.tpp>
#include <std/Posicion.tpp>

class nave :public EGE::CORE::Entity<nave>{
    public:
        nave(int id): Entity(id){

        }
};

class Mnave : public EGE::CORE::Manager<nave>{
    public:
        void inicializarSprite(int id,int n,std::string nombre){
            auto sprite = getComponent<EGE::STD::TERMINAL::Sprite>(id);

            sprite -> spriteInitializer(n,nombre);
        }

        void inicializarPosicion(int id,int x, int y){
            auto sprite = getComponent<EGE::STD::TERMINAL::Sprite>(id);
            auto posicion = getComponent<EGE::STD::TERMINAL::Posicion>(id);

            posicion -> positionInitializer(sprite -> getN(),x,y);

        }

        void mostrarSprite(EGE::STD::TERMINAL::WINDOWS::Terminal *cursor,int id){
            auto sprite = getComponent<EGE::STD::TERMINAL::Sprite>(id);
            auto posicion = getComponent<EGE::STD::TERMINAL::Posicion>(id);

            sprite -> visualize(cursor,*posicion);
        }
};

int main(){
    TerminalType *tm = TerminalType::getTerminal(50,30);

    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::Sprite>(Nave1);
    base.addComponent<EGE::STD::TERMINAL::Posicion>(Nave1);

    base.inicializarSprite(Nave1,3,"nave");
    base.inicializarPosicion(Nave1,2,2);

    tm -> pintarLimites();
    tm -> ocultarCursor();

    base.mostrarSprite(tm,Nave1);

    delete tm;
}
