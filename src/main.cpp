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

class Mnave : public EGE::CORE::Manager<nave>{
    public:
        void inicializarSprite(int id,int n,std::string nombre){
            auto sprite = getComponent<EGE::STD::TERMINAL::Sprite>(id);

            sprite -> spriteInitializer(n,nombre);
        }

        void inicializarPosicion(int id,int x, int y){
            auto sprite = getComponent<EGE::STD::TERMINAL::Sprite>(id);
            auto posicion = getComponent<EGE::STD::TERMINAL::Position>(id);

            posicion -> positionInitializer(sprite -> getN(),x,y);

        }
};

class visualizeSprite : public EGE::CORE::System<Mnave>{
    public:
        void update(Mnave *gameContext){
            /*Nada*/
        }

        void update(int id, Mnave *gameContext){
            auto sprite = gameContext -> getComponent<EGE::STD::TERMINAL::Sprite>(id);
            auto posicion = gameContext -> getComponent<EGE::STD::TERMINAL::Position>(id);
            TerminalType *tm = TerminalType::getTerminal();
            sprite -> visualize(tm,*posicion);
        }
};
#if 0
template<typename type>
class ManagerSprite : public EGE::CORE::Manager<sprite>{

};
#endif
int main(){
    #if 1
    TerminalType *tm = TerminalType::getTerminal(50,30);
    visualizeSprite vSprite;
    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::Sprite>(Nave1);
    base.addComponent<EGE::STD::TERMINAL::Position>(Nave1);

    base.inicializarSprite(Nave1,3,"nave");
    base.inicializarPosicion(Nave1,2,2);

    tm -> pintarLimites();
    tm -> ocultarCursor();

    vSprite.update(Nave1,&base);

    delete tm;
    #endif
#if 0
    EGE::STD::TERMINAL::Position p;
    EGE::STD::TERMINAL::Controller c;
    EGE::STD::TERMINAL::systemInput s;
    p.positionInitializer(2,2,2);

    auto tuplas = p.getPosition();

    for(auto i : tuplas){
        std::cout << "x: " << std::get<0>(i) << std::endl;
        std::cout << "y: " << std::get<1>(i) << std::endl;
    }

    c.move('d',&p);
    auto tuplas2 = p.getPosition();
    std::cout << "-----------------------" << std::endl;
    
    for(auto i : tuplas2){
        std::cout << "x: " << std::get<0>(i) << std::endl;
        std::cout << "y: " << std::get<1>(i) << std::endl;
    }
#endif

}
