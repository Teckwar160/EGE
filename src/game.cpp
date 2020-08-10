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

using namespace EGE::STD::TERMINAL::WINDOWS;

class pacman : public EGE::CORE::Entity<pacman>{
    public:
        pacman(int id) : Entity(id){

        }
};

class managerPacman :  public EGE::STD::TERMINAL::WINDOWS::mSprite<pacman>{

};

class tablero : public EGE::CORE::Entity<tablero>{
    public:
        tablero(EGE::CORE::EntityId id) : Entity(id){

        }
};

class managerTablero : public EGE::STD::TERMINAL::WINDOWS::mSprite<tablero>{

};



int main(){
    
    //Inicializar tablero de juego
    mTerminal terminal;
    //Definir dimensiones
    auto gameterminal = terminal.addEntity(41,30);

    /// Creacion de los sistemas
    
    //Sistema de Entrada
    systemInput entrada;

    //Sistemas para las entidades
    visualizeEntity<managerPacman> viewPacman;
    displacementEntity<managerPacman> disPacman;

    visualizeEntity<managerTablero> viewBoard;

    //Sistema de colision entre las entidades
    systemGenericCollition<managerPacman,managerTablero> colition;
    systemKeyInverter inverter;

    //Creacion de los managers de las entidades
    managerPacman player;
    managerTablero board;

    //Creacion de las entidades como tal
    auto Pacman1 = player.addEntity();
    auto board1 = board.addEntity();

    //Agregar e inicializar componentes
    player.addComponent<Controller>(Pacman1);
    player.spriteInitializer(Pacman1,2,"pacman");
    player.positionInitializer(Pacman1,5,5);

    board.spriteInitializer(board1,40,"laberinto");
    board.positionInitializer(board1,1,1);


    //Empezar la terminal y generar game loop

    terminal.terminalPersonalized(gameterminal,'=','I');
    terminal.terminalDefault(gameterminal);
    char Tecla = 0;

    while(Tecla != 'c'){

        //Leer input
        Tecla = entrada.update();

        // Mover al jugador
        disPacman.update(Tecla,Pacman1,&player,ARROWS);

        //Revisar colisiones
        if(colition.update(Pacman1,&player,&board)){
            disPacman.update(inverter.update(Tecla,ARROWS),Pacman1,&player,ARROWS);

        }
        
        //Dibujamos

        viewPacman.update(Pacman1,&player);
        viewBoard.update(board1,&board);

        
    }



}