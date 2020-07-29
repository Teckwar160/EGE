#ifndef DISPLACEMENTENTITY_TPP
#define DISPLACEMENTENTITY_TPP

#include <std/displacementEntity.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    template<typename mType>
    void displacementEntity<mType>::update(mType *gameContext){

    }

    template<typename mType>
    void displacementEntity<mType>::updated(char key,EGE::CORE::EntityId id,mType *gameContext,EGE::CORE::ControlType control){
        EGE::STD::TERMINAL::WINDOWS::collitionTerminal<mType> collition;
        EGE::STD::TERMINAL::WINDOWS::visualizeEntity<mType> view;
        EGE::STD::TERMINAL::WINDOWS::moveEntity<mType> move;
        bool flag = false;

        if(control == WASD){
            for(auto i : this -> wasd){
                if(key == i){
                    flag = true;
                    break;
                }
            }
        }else if(control == ARROWS){
            for(auto i : this -> arrows){
                if(key == i){
                    flag = true;
                    break;
                }
            }           
        }


        if(flag){
            view.updated(id,gameContext,false);
            move.updated(key,id,gameContext);

            if(collition.updated(id,gameContext)){

                switch(key){
                    case 'w':
                    case 'W':
                    case UP:
                            key = DOWN;
                        break;
                    case 'a':
                    case 'A':
                    case LEFT:
                            key = RIGHT;
                        break;
                    case 's':
                    case 'S':
                    case DOWN:
                            key = UP;
                        break;
                    case 'd':
                    case 'D':
                    case RIGHT:
                            key = LEFT;
                        break;
                };
                move.updated(key,id,gameContext);
            }
        }
    }
}
#endif