#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>
#include <std/Sprite.tpp>
#include <std/Posicion.tpp>
#include <std/Controlador.tpp>

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
};

class visualizeSprite : public EGE::CORE::System<Mnave>{
    public:
        void update(Mnave *gameContext){
            /*Nada*/
        }

        void update(int id, Mnave *gameContext){
            auto sprite = gameContext -> getComponent<EGE::STD::TERMINAL::Sprite>(id);
            auto posicion = gameContext -> getComponent<EGE::STD::TERMINAL::Posicion>(id);
            TerminalType *tm = TerminalType::getTerminal();
            sprite -> visualize(tm,*posicion);
        }
};

int main(){
    #if 0
    TerminalType *tm = TerminalType::getTerminal(50,30);
    visualizeSprite vSprite;
    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::Sprite>(Nave1);
    base.addComponent<EGE::STD::TERMINAL::Posicion>(Nave1);

    base.inicializarSprite(Nave1,3,"nave");
    base.inicializarPosicion(Nave1,2,2);

    tm -> pintarLimites();
    tm -> ocultarCursor();

    vSprite.update(Nave1,&base);

    delete tm;
    #endif

    EGE::STD::TERMINAL::Posicion p;
    EGE::STD::TERMINAL::Controller c;

    p.positionInitializer(2,2,2);

    auto tuplas = p.getPosition();

    for(auto i : tuplas){
        std::cout << "x: " << std::get<0>(i) << std::endl;
        std::cout << "y: " << std::get<1>(i) << std::endl;
    }

    c.move('w',&p);

    p.updatePosition();
    auto tuplas2 = p.getPosition();
    std::cout << "-----------------------" << std::endl;
    
    for(auto i : tuplas2){
        std::cout << "x: " << std::get<0>(i) << std::endl;
        std::cout << "y: " << std::get<1>(i) << std::endl;
    }


}
