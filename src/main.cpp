#include <iostream>
#include <core/Core.hpp>
#include <std/Windows/WindowsSTD.hpp>

class nave : public EGE::CORE::Entity<nave>{
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
    base.positionInitializer(Nave1,2,2);

    nodriza.addComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(enemy);
    nodriza.spriteInitializer(enemy,13,"tablero");
    nodriza.positionInitializer(enemy,9,9);

    /*Prueba de resetSystem*/
    EGE::STD::TERMINAL::WINDOWS::systemPositionReset<Mnave> reset;

    reset.positionResetSprite(Nave1,&base,2,10);

    /*Creamos el sistema de entrada*/
    EGE::STD::TERMINAL::WINDOWS::systemInput entrada;

    /*Creamos los sistemas necesarios para las entidades*/
    EGE::STD::TERMINAL::WINDOWS::systemVisualizeEntity<Mnave> view;
    EGE::STD::TERMINAL::WINDOWS::systemDisplacementEntity<Mnave> dp;

    EGE::STD::TERMINAL::WINDOWS::systemVisualizeEntity<mEnemy> view2;
    EGE::STD::TERMINAL::WINDOWS::systemDisplacementEntity<mEnemy> dp2;

    /*Creamos el sistema de colision entre las entidades*/
    EGE::STD::TERMINAL::WINDOWS::systemGenericCollition<Mnave,mEnemy> col;
    EGE::STD::TERMINAL::WINDOWS::systemKeyInverter inverter;

    /*Inicalizamos a la  terminal y al metedo de salida del juego*/
    tm.terminalSetColor(terminal,252);
    tm.terminalPersonalized(terminal,'-','|');

    /*Prueba de score*/
    EGE::STD::TERMINAL::WINDOWS::systemScore<mEnemy> score;
    score.scoreInitializer(enemy,&nodriza);

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
        view.viewColor(Nave1,&base,249);

        /*Movemos y pintamos al enemigo*/
        dp2.update(Tecla,enemy,&nodriza,WASD);  
        view2.viewColor(enemy,&nodriza,250);


        if(Tecla == 'e'){
            score.update(2,enemy,&nodriza);
        }

        if(Tecla == 'r'){
            score.update(9997,enemy,&nodriza);
        }

        /*Espera del juego*/
        Sleep(10);
    }
    #endif
}
