#ifndef SYSTEMDISPLACEMENTENTITY_TPP
#define SYSTEMDISPLACEMENTENTITY_TPP

#include <std/Windows/systemDisplacementEntity.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    template<typename mType>
    void systemDisplacementEntity<mType>::update(char key,EGE::CORE::EntityId id,mType *gameContext,EGE::CORE::ControlType control){
        EGE::STD::TERMINAL::WINDOWS::collitionTerminal<mType> collition;
        EGE::STD::TERMINAL::WINDOWS::systemVisualizeEntity<mType> view;
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
            view.view(id,gameContext,false);
            move.update(key,id,gameContext);

            if(collition.update(id,gameContext)){
                move.update(inverter.update(key,control),id,gameContext);
            }
        }
    }
}
#endif