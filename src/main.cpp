#include <iostream>
#include "./core/Entity.tpp"
#include "./core/System.tpp"
#include "./core/Component.tpp"
#include "../include/core/Manager.hpp"


class Vida : public EGE::CORE::Component<Vida>{
    public:
        int vida = 100;
};

class Pacman : public EGE::CORE::Entity<Pacman>{
    public:
        /*Esto estara dentro de entity*/
        std::unordered_map<EGE::CORE::ComponentType,EGE::CORE::ComponentBase*> componentes;
        int vida;
};



class fantasma : EGE::CORE::Entity<fantasma>{
    public:
        int vida = 100;
    public:
        void muestraVida(){
            std::cout << vida << std::endl;
        }

};

class managerFantasma : public manager<fantasma>{


};

class systemLifeGhost : public EGE::CORE::System<managerFantasma>{
    public:
     void update(managerFantasma *gameContext)override{
         for(auto i : gameContext ->entities){
             i ->vida -=2;
         }
     }
};

class systemPrintLifeGhost : public EGE::CORE::System<managerFantasma>{
    public:
        void update(managerFantasma *gameContext)override{
            for(auto i : gameContext ->entities){
                i ->muestraVida();
            }           
        }
};


int main(){
    managerFantasma poki;

    poki.entities.push_back(new fantasma());

    systemLifeGhost slg;

    slg.update(&poki);

    systemPrintLifeGhost print;

    print.update(&poki);

}
