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
            if(col.collition(Nave1,&base,&nodriza)){
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
