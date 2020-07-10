#include <iostream>
#include "./core/Entity.tpp"
#include "./core/System.tpp"
#include "./core/Component.tpp"
#include <unordered_map>
#include <vector>

/*Fabrica abstracta*/


class GameContext{
    public:

};

class manager : public GameContext{

};

class manager2 : public GameContext{

};

void actualizar(GameContext *p){

}

class Vida : public EGE::Component<Vida>{
    public:
        int vida = 100;
};

class Pacman : public EGE::Entity<Pacman>{
    public:
        /*Esto estara dentro de entity*/
        std::unordered_map<EGE::ComponentType,EGE::ComponentBase*> componentes;
};

class managerPacman : public GameContext{
    public:
        std::vector<EGE::EntityBase*> pacmans;
        void crearPacman(){
            pacmans.push_back(new Pacman());
            Vida *v = new Vida();
            static_cast<Pacman*>(pacmans[0]) -> componentes.insert(std::make_pair(Vida::getComponentType(),v));
        }
};


int main(){
    managerPacman p;
    p.crearPacman();
    std::cout << static_cast<Vida*>(static_cast<Pacman*>(p.pacmans[0]) -> componentes[Vida::getComponentType()]) -> vida <<std::endl;

}
