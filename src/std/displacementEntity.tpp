#ifndef DISPLACEMENTENTITY_TPP
#define DISPLACEMENTENTITY_TPP

#include <std/displacementEntity.hpp>

namespace EGE::STD::TERMINAL{
    template<typename mType>
    void displacementEntity<mType>::update(mType *gameContext){

    }

    template<typename mType>
    void displacementEntity<mType>::updated(char tecla,EGE::CORE::EntityId id,mType *gameContext){
        EGE::STD::TERMINAL::collitionTerminal<mType> collition;
        EGE::STD::TERMINAL::visualizeEntity<mType> view;
        EGE::STD::TERMINAL::moveEntity<mType> move;

        view.updated(id,gameContext,false);
        move.updated(tecla,id,gameContext);

        if(collition.updated(id,gameContext)){

            switch(tecla){
                case 'w':
                case 'W':
                case UP:
                        tecla = DOWN;
                    break;
                case 'a':
                case 'A':
                case LEFT:
                        tecla = RIGHT;
                    break;
                case 's':
                case 'S':
                case DOWN:
                        tecla = UP;
                    break;
                case 'd':
                case 'D':
                case RIGHT:
                        tecla = LEFT;
                    break;
            };
            move.updated(tecla,id,gameContext);
        }
    }
}
#endif