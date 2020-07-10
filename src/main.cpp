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

class Vida : public EGE::CORE::Component<Vida>{
    public:
        int vida = 100;
};

class Pacman : public EGE::CORE::Entity<Pacman>{
    public:
        /*Esto estara dentro de entity*/
        std::unordered_map<EGE::CORE::ComponentType,EGE::CORE::ComponentBase*> componentes;
};

class managerPacman : public GameContext{
    public:
        std::vector<EGE::CORE::EntityBase*> pacmans;
        void crearPacman(){
            pacmans.push_back(new Pacman());
            Vida *v = new Vida();
            static_cast<Pacman*>(pacmans[0]) -> componentes.insert(std::make_pair(Vida::getComponentType(),v));
        }
};


int main(){
    Pacman p;
    Vida *v = new Vida();
    
    p.addComponent<Vida>(v);

    Vida *tmp = p.getComponent<Vida>();

    std::cout << tmp -> vida << std::endl;
}
