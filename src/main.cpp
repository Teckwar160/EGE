#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>


class Pacman : public EGE::CORE::Entity<Pacman>{
    public:
        /*Esto estara dentro de entity*/
        std::unordered_map<EGE::CORE::ComponentType,EGE::CORE::ComponentBase*> componentes;
        int vida;
};



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

void damage(fantasma *i){
    i -> vida -= 5;
}

void print(fantasma *i){
    std::cout << i -> vida << std::endl;
}

class systemLifeGhost : public EGE::CORE::System<managerFantasma>{
    public:
     void update(managerFantasma *gameContext)override{
         gameContext -> traverse(damage);
     }
};

class systemPrintLife : public EGE::CORE::System<managerFantasma>{
    public:
        void update(managerFantasma *gameContext)override{
            gameContext -> traverse(print);
        }
};

class Vida : public EGE::CORE::Component<Vida>{
    public:
        int vida = 100;
        void print(){
            std::cout << vida << std::endl;
        }
};




int main(){
    managerFantasma poki;

    fantasma tinky(0);

    tinky.addComponent<Vida>();

    auto k = tinky.getComponent<Vida>();

    k -> print();

   // tinky.deleteComponent<Vida>();

    auto f = tinky.getComponent<Vida>();

    if(f == nullptr){
        std::cout << "si se elimino bien\n";
    }

    delete k;
    delete f;



}
