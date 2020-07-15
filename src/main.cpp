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

};

class managerPacman : public EGE::CORE::Manager<Pacman>{
};



int main(){
    managerFantasma poki;
    managerFantasma poki2;
    managerPacman p;


    std::cout << poki.getManagerType() << std::endl;
    std::cout << poki2.getManagerType() << std::endl;
    std::cout << p.getManagerType() << std::endl;

    auto a = poki.addEntity(); //0
    auto b = poki.addEntity();
    auto c = poki.addEntity();
    poki.destroyEntity(b);

    poki.applyFuntion(a,print2);

    poki.addComponent<Vida>(c);
    poki.addComponent<Poder>(a);
    poki.addComponent<Defensa>(a);

    poki.deleteComponent<Defensa>(a);

    auto tmp = poki.getComponent<Vida>(c);

    if(tmp == nullptr){
        std::cout << "\nSe borro\n";
    }

    tmp -> print();
 

}
