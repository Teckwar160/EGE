#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>

 
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

class managerFantasma : public EGE::CORE::Manager<fantasma>{

};

void damage(fantasma *i){
    i -> vida -= 99;
}

class systemLifeGhost : public EGE::CORE::System<managerFantasma>{
    public:
     void update(managerFantasma *gameContext)override{
         gameContext -> traverse(damage);
     }
};

class systemPrintLifeGhost : public EGE::CORE::System<managerFantasma>{
    public:
        void update(managerFantasma *gameContext)override{
            for(auto i : gameContext ->getEntities()){
                i ->muestraVida();
            }           
        }
};


int main(){
    managerFantasma poki;

    poki.addEntity();
    poki.addEntity();

    systemLifeGhost slg;

    slg.update(&poki);

    systemPrintLifeGhost print;

    print.update(&poki);

    std::cout << "\n\nhola a todos\n\n";

}
