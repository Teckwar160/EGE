#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>


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

int main(){
    EGE::CORE::TERMINAL::WINDOWS::Terminal *p;
    EGE::CORE::TERMINAL::WINDOWS::Terminal *w;
    EGE::CORE::TERMINAL::WINDOWS::Terminal *i;
    p = EGE::CORE::TERMINAL::WINDOWS::Terminal::getTerminal(10,10);
    w = EGE::CORE::TERMINAL::WINDOWS::Terminal::getTerminal(100,100);
    i = EGE::CORE::TERMINAL::WINDOWS::Terminal::getTerminal();
    system("cls");
    i -> pintarLimites();

    delete i;
}
