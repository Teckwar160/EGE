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

class tablero :public EGE::CORE::Entity<tablero>{
    public:
        tablero(int id): Entity(id){}
};

class bomberMan : public EGE::CORE::Entity<bomberMan>{
    public:
        bomberMan(int id) : Entity(id){}

        void putBomb(){
            std::cout << "Ha" << std::endl;
        }
};

class bomba : public EGE::CORE::Entity<bomba>{
    public:
        bomba(int id) : Entity(id){}
};

class managerTablero : public EGE::STD::TERMINAL::WINDOWS::mSprite<tablero>{};

class managerBomberMan : public EGE::STD::TERMINAL::WINDOWS::mSprite<bomberMan>{
    public:
        void putBomb( int id ){
            auto tempBomberMan = this-> template getEntity( id );
            tempBomberMan.putBomb();
        }
};

class managerBomba : public EGE::STD::TERMINAL::WINDOWS::mSprite<bomba>{};

int main(){
    /*Se crea el tablero del juego*/
    EGE::STD::TERMINAL::WINDOWS::mTerminal tm;
    //auto terminal = tm.addEntity(8,7);
    auto terminal = tm.addEntity(22,22);
    
    /*Creamos los manager de las entidades del juego*/
    managerTablero mTablero;
    managerBomberMan mBomberMan;
    managerBomba mBomba;

    /*Creamos a las entidades*/
    auto tablero = mTablero.addEntity();
    auto bomberMan = mBomberMan.addEntity();
    auto bomba = mBomba.addEntity();

    /*Agregamos e inicializamos sus componentes*/
    mTablero.addComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(tablero);
    mTablero.spriteInitializer(tablero,21,"tableroBomb");
    mTablero.positionInitializer(tablero,1,1);

    mBomberMan.addComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(bomberMan);
    mBomberMan.spriteInitializer(bomberMan,3,"bomberMan");
    mBomberMan.positionInitializer(bomberMan,1,1);

    mBomba.addComponent<EGE::STD::TERMINAL::WINDOWS::Controller>(bomba);
    mBomba.spriteInitializer(bomba,3,"bomba");

    /*Creamos el sistema de entrada*/
    EGE::STD::TERMINAL::WINDOWS::systemInput entrada;

    /*Creamos los sistemas necesarios para las entidades*/
    EGE::STD::TERMINAL::WINDOWS::visualizeEntity<managerTablero> viewTablero;
    EGE::STD::TERMINAL::WINDOWS::visualizeEntity<managerBomberMan> viewBomberMan;
    EGE::STD::TERMINAL::WINDOWS::displacementEntity<managerBomberMan> dpBomberMan;

    /*Creamos el sistema de colision entre las entidades*/
    EGE::STD::TERMINAL::WINDOWS::systemGenericCollition<managerTablero,managerBomberMan> sCol;
    EGE::STD::TERMINAL::WINDOWS::systemKeyInverter inverter;

    /*Inicalizamos a la  terminal y al metedo de salida del juego*/
    tm.terminalPersonalized(terminal,'-','|');

    //viewTablero.update(tablero,&mTablero);

    char Tecla = 0;

    #if 1
    /*Bucle del juego*/
    while(Tecla != 'c'){
        
        /*Recogemos la tecla*/
        Tecla = entrada.update();

        /*Movemos al jugador*/
        dpBomberMan.update(Tecla,bomberMan,&mBomberMan,ARROWS);  

        /*Uso del sistema de colision*/
        #if 1
        if(Tecla != 0){
            if(sCol.update(bomberMan,&mTablero,&mBomberMan)){
                dpBomberMan.update(inverter.update(Tecla,ARROWS),bomberMan,&mBomberMan,ARROWS);
            }
            else if(Tecla == 'e' or Tecla == 'E'){
                mBomberMan.putBomb( bomberMan );
            }
        }
        #endif
        /*Pintamos al jugador*/
        viewBomberMan.update(bomberMan,&mBomberMan);
        viewTablero.update(tablero,&mTablero);

        /*Espera del juego*/
        Sleep(10);
    }
    #endif
}