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

int main(){
    EGE::STD::TERMINAL::WINDOWS::Terminal *w;

    EGE::STD::WINDOWS::Sprite nave(3,2,2,"nave",true);


    w = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal(80,30);

    system("cls");
    w -> pintarLimites();
    w -> ocultarCursor();
    bool sigue = true;
    while(sigue){
        w -> ocultarCursor();
        if(kbhit()){
            char tecla = getch();

            nave.mover(tecla,w);

            if(tecla == 'c'){
                sigue = false;
            }
        }
        nave.visualizar(w);

    }
    system("cls");
    delete w;
}
