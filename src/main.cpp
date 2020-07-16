#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>


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
    managerFantasma poki;
    managerPacman p;


    auto a = poki.addEntity(); // 0
    auto b = poki.addEntity(); // 1
    auto a1 = p.addEntity(); // 0
    auto b1 = p.addEntity(); // 1
    auto c1 = p.addEntity(); // 2

    
    poki.addComponent<Poder>(a);
    poki.addComponent<Defensa>(a);
    
    poki.addComponent<Defensa>(b);
    //poki.deleteComponent<Defensa>(a);
    
    auto fantasmaB = poki.getEntity<fantasma>(1);
    auto fantasmaA = poki.getEntity<fantasma>(0);
    auto pacmanC1  = p.getEntity<Pacman>(2);
    auto pacmanB1  = p.getEntity<Pacman>(1);

    int fantasmaid = fantasmaB -> getEntityId(); // 1
    int pacmanID2 = pacmanC1 -> getEntityId(); // 2
 
    std::cout << fantasmaid << std::endl;
    std::cout << pacmanID2 << std::endl;

}
