#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>
#include <std/Sprite.tpp>

class nave :public EGE::CORE::Entity<nave>{
    public:
        nave(int id): Entity(id){

        }
};

class Mnave : public EGE::CORE::Manager<nave>{
    public:
        void inicializarSprite(int id,int n,std::string nombre){
            auto sprite = getComponent<EGE::STD::TERMINAL::Sprite>(id);

            sprite -> inicializarSprite(n,nombre);
        }

        void mostrarSprite(int id){
            auto sprite = getComponent<EGE::STD::TERMINAL::Sprite>(id);
            //auto posicion = getComponent<EGE::STD::TERMINAL::Posicion>(id);

            //sprite -> visualizar(cursor,posicion,);
        }
};

int main(){

    Mnave base;

    auto Nave1 = base.addEntity();

    base.addComponent<EGE::STD::TERMINAL::Sprite>(Nave1); 

}
