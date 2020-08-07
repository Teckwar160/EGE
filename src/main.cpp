#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>
#include <std/Sprite.tpp>
#include <std/Position.tpp>
#include <std/Controller.tpp>
#include <std/Input.tpp>
#include <std/visualizeEntity.tpp>
#include <std/displacementEntity.tpp>
#include <std/systemGenericCollition.tpp>
#include <std/systemKeyInverter.tpp>

class nave :public EGE::CORE::Entity<nave>{
    public:
        nave(int id): Entity(id){

        }
};

class Mnave : public EGE::STD::TERMINAL::WINDOWS::mSprite<nave>{

};

class enemy : public EGE::CORE::Entity<enemy>{
    public:
        enemy(EGE::CORE::EntityId id) : Entity(id){

        }
};

class mEnemy : public EGE::STD::TERMINAL::WINDOWS::mSprite<enemy>{

};

/*
    Este es una prueba de un sistema de colisio nque busca especificamente
    dos entidades en el tablero y ve si estas chocaron.
    Funciona pero ya no lo volvi un sistema formal.
*/
#if 0
class systemGenericCollition : public EGE::CORE::System<Mnave,mEnemy>{
    public:
        void update(Mnave *p, mEnemy *q){

        }

        bool update(EGE::CORE::EntityId  idPlayer, EGE::CORE::EntityId idEnemy, Mnave *player, mEnemy *enemies){
            auto positionPlayer = player -> getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(idPlayer);
            auto vectorPosition = positionPlayer -> getPosition();

            auto positionEnemy = enemies -> getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(idEnemy);
            auto vectorEnemy = positionEnemy -> getPosition();

            for(auto i : vectorPosition){
                for(auto j: vectorEnemy){

                    if(std::get<0>(i) == std::get<0>(j)){
                        if(std::get<1>(i) == std::get<1>(j)){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
};
#endif



int main(){
    #if 1
    /*Se crea el tablero del juego*/
    EGE::STD::TERMINAL::WINDOWS::mTerminal tm;
    auto terminal = tm.addEntity(50,30);
    
    /*Creamos los manager de las entidades del juego*/
    Mnave base;
    mEnemy nodriza;

    /*Creamos a las entidades*/
    auto Nave1 = base.addEntity();
    auto enemy = nodriza.addEntity();

    /*Agregamos e inicializamos sus componentes*/
    base.addComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(Nave1);
    base.spriteInitializer(Nave1,3,"nave");
    base.positionInitializer(Nave1,11,11);

    nodriza.addComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(enemy);
    nodriza.spriteInitializer(enemy,10,"tablero");
    nodriza.positionInitializer(enemy,10,10);

    /*Creamos el sistema de entrada*/
    EGE::STD::TERMINAL::WINDOWS::systemInput entrada;

    /*Creamos los sistemas necesarios para las entidades*/
    EGE::STD::TERMINAL::WINDOWS::visualizeEntity<Mnave> view;
    EGE::STD::TERMINAL::WINDOWS::displacementEntity<Mnave> dp;

    EGE::STD::TERMINAL::WINDOWS::visualizeEntity<mEnemy> view2;
    EGE::STD::TERMINAL::WINDOWS::displacementEntity<mEnemy> dp2;

    /*Creamos el sistema de colision entre las entidades*/
    EGE::STD::TERMINAL::WINDOWS::systemGenericCollition<Mnave,mEnemy> col;
    EGE::STD::TERMINAL::WINDOWS::systemKeyInverter inverter;

    /*Inicalizamos a la  terminal y al metedo de salida del juego*/
    tm.terminalPersonalized(terminal,'-','|');

    char Tecla = 0;

    /*Bucle del juego*/
    while(Tecla != 'c'){
        
        /*Recogemos la tecla*/
        Tecla = entrada.update();

        /*Movemos al jugador*/
        dp.update(Tecla,Nave1,&base,ARROWS);  

        /*Uso del sistema de colision*/
        #if 1
        if(Tecla != 0){
            if(col.update(Nave1,&base,&nodriza)){
                dp.update(inverter.update(Tecla,ARROWS),Nave1,&base,ARROWS);
            }
        }
        #endif
        /*Pintamos al jugador*/
        view.update(Nave1,&base);

        /*Movemos y pintamos al enemigo*/
        dp2.update(Tecla,enemy,&nodriza,WASD);  
        view2.update(enemy,&nodriza);


        /*Espera del juego*/
        Sleep(10);
    }
    #endif
}
