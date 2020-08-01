#ifndef DISPLACEMENTENTITY_TPP
#define DISPLACEMENTENTITY_TPP

#include <std/displacementEntity.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    void displacementEntity<mType>::update(char key,EGE::CORE::EntityId id,mType *gameContext,EGE::CORE::ControlType control){
        EGE::STD::TERMINAL::WINDOWS::collitionTerminal<mType> collition;
        EGE::STD::TERMINAL::WINDOWS::visualizeEntity<mType> view;
        EGE::STD::TERMINAL::WINDOWS::moveEntity<mType> move;
        EGE::STD::TERMINAL::WINDOWS::systemKeyInverter inverter;
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
            view.update(id,gameContext,false);
            move.update(key,id,gameContext);

            if(collition.update(id,gameContext)){
                move.update(inverter.update(key),id,gameContext);
            }
        }
    }
}
#endif