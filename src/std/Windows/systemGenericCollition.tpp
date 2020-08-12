#ifndef SYSTEMGENERICCOLLITION_TPP
#define SYSTEMGENERICCOLLITION_TPP

#include <std/Windows/systemGenericCollition.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    
    template<typename m1, typename m2>
    bool systemGenericCollition<m1,m2>::collition(EGE::CORE::EntityId id, m1 *mPlayer, m2 *mEntities){

            /*Obtenemos el vector de posición del juador*/
            auto componentPositionPlayer = mPlayer -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
            auto vectorPositionPlayer = componentPositionPlayer -> getPosition();

            /*Obtenemos a las entidades con las que se comprobara si choco el jugador*/
            auto entities = mEntities -> getEntities();

            for(auto i : entities){

                /*Obtenemos el vector de posición de la entidad en turno*/
                auto componentPositionEntity = i.second -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>();
                auto vectorPositionEntity = componentPositionEntity -> getPosition();

                /*Comprobamos si en algun punto estan colisionando*/
                for(auto j: vectorPositionPlayer){
                    for(auto k: vectorPositionEntity){
                        if(std::get<0>(j) == std::get<0>(k)){
                            if(std::get<1>(j) == std::get<1>(k)){
                                return true;
                            }
                        }
                    }
                }
            }
            
            return false;
    }

    template<typename m1, typename m2>
    bool systemGenericCollition<m1,m2>::collitionId(EGE::CORE::EntityId id,m1 *mPlayer, m2 *mEntities, EGE::CORE::EntityId *collitionId){

            /*Obtenemos el vector de posición del juador*/
            auto componentPositionPlayer = mPlayer -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
            auto vectorPositionPlayer = componentPositionPlayer -> getPosition();

            /*Obtenemos a las entidades con las que se comprobara si choco el jugador*/
            auto entities = mEntities -> getEntities();

            for(auto i : entities){

                /*Obtenemos el vector de posición de la entidad en turno*/
                auto componentPositionEntity = i.second -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>();
                auto vectorPositionEntity = componentPositionEntity -> getPosition();

                /*Comprobamos si en algun punto estan colisionando*/
                for(auto j: vectorPositionPlayer){
                    for(auto k: vectorPositionEntity){
                        if(std::get<0>(j) == std::get<0>(k)){
                            if(std::get<1>(j) == std::get<1>(k)){
                                *collitionId = i.second -> getEntityId();
                                return true;
                            }
                        }
                    }
                }
            }
            
            return false;       
    }
}

#endif