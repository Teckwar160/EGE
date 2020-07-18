#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>
#include <std/Sprite.tpp>

class fantasma : public EGE::CORE::Entity<fantasma>{
    public:
        int vida = 100;
    public:
        void muestraVida(){
            std::cout << vida << std::endl;
        }

        fantasma(int id) : Entity(id){

        }

        ~fantasma(){
            /*Nada*/
        }

};


class managerFantasma : public EGE::CORE::Manager<fantasma>{
    public:
        ~managerFantasma(){
            std::cout << "\nDestructor de managerFantasma\n";
        }
};

class Vida : public EGE::CORE::Component<Vida>{
    public:
        void print(){
            std::cout << "\nSoy vida\n";
        }
};

class Defensa : public EGE::CORE::Component<Defensa>{
    public:
        void print(){
            std::cout << "\nSoy defensa\n";
        }
};

class Poder : public EGE::CORE::Component<Poder>{
    public:
        void print(){
            std::cout << "\nSoy poder\n";
        }
};

void print(fantasma *p){
    p -> muestraVida();
}

void print2(fantasma *p){
    std::cout << "\nSoy aplyfuntion\n";
}



class Pacman : public EGE::CORE::Entity<Pacman>{
    public:
      int vida = 100;
  public:

      Pacman(int id) : Entity(id){

      }

      ~Pacman(){
          /*Nada*/
      }

};

class managerPacman : public EGE::CORE::Manager<Pacman>{
  public:
    ~managerPacman(){
        std::cout << "\nDestructor de managerPacman\n";
    }
};

class systemCollision : public EGE::CORE::System<managerPacman, managerFantasma>{
    public:
    void update(managerPacman* mPacman, managerFantasma* mFantasma) override {

    }
};

class nave : public EGE::CORE::Entity<nave>{
    public:
        nave(int id) :Entity(id){

        }
};

class managerNave : public EGE::CORE::Manager<nave>{

};

class sistemaDeColision : public EGE::CORE::System<managerNave,EGE::STD::TERMINAL::WINDOWS::managerTerminal>{
    public:
        bool choco = false;
    public:
        void update(managerNave *mNave, EGE::STD::TERMINAL::WINDOWS::managerTerminal *mTerminal) override{
            auto avion = mNave -> getComponent<EGE::STD::WINDOWS::Sprite>(0);
            auto terminal = mTerminal -> getEntity<EGE::STD::TERMINAL::WINDOWS::Terminal>(0);

            auto avionSprite = avion -> getSprite();
            for(int i = 0; i< avion -> getDimensionReal();i++){
                if(avionSprite[i].getX() >= terminal -> getLargo()-1 || avionSprite[i].getX() == 1){
                    choco = true;
                    return;
                }

                if(avionSprite[i].getY() >= terminal -> getAlto() || avionSprite[i].getY() == 0){
                    choco = true;
                    return;
                }   
            }

            choco = false;

        }
};
 



int main(){
    EGE::STD::TERMINAL::WINDOWS::Terminal *w;

    w = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal(80,30);

    EGE::STD::TERMINAL::WINDOWS::managerTerminal mTe;

    mTe.addEntity(80,30);

    managerNave hangar;

    auto avion = hangar.addEntity();

    hangar.addComponent<EGE::STD::WINDOWS::Sprite>(avion);

    auto spriteAvion = hangar.getComponent<EGE::STD::WINDOWS::Sprite>(avion);

    spriteAvion -> inicializarSprite(3,2,2,"nave",true);
    bool continuar = true;
    
    sistemaDeColision coco;
    char Tecla;
    char Tecla2;

    system("cls");
    w -> pintarLimites();
    w -> ocultarCursor();

    while(continuar){

        w -> ocultarCursor();

        if(kbhit()){
            Tecla2 = getch();

            spriteAvion -> mover(Tecla2,w);
            if(Tecla2 == 'c'){
                continuar = false;
            }
        }
        spriteAvion -> visualizar(w);
        coco.update(&hangar,&mTe);

        if(coco.choco){
            switch(Tecla2){
                case ARRIBA:
                    Tecla = ABAJO;
                    break;
                case ABAJO:
                    Tecla = ARRIBA;
                    break;
                case DERECHA:
                    Tecla =IZQUIERDA;
                    break;
                case IZQUIERDA:
                    Tecla = DERECHA;
                    break;
            }
            spriteAvion -> mover(Tecla,w);
            w -> pintarLimites();
        }

        Sleep(20);
        
    }

    
}
