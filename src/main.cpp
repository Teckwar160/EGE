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



int main(){
    managerFantasma poki;

    auto a = poki.addEntity(); //0
    
    poki.addComponent<Vida>(a);
    poki.addComponent<Poder>(a);
    poki.addComponent<Defensa>(a);

    poki.deleteComponent<Defensa>(a);

    auto tmp = poki.getComponent<Defensa>(a);

    if(tmp == nullptr){
        std::cout << "\nSe borro\n";
    }

 

}
