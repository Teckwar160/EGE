#ifndef SYSTEMGENERICCOLLITION_TPP
#define SYSTEMGENERICCOLLITION_TPP

#include <std/systemGenericCollition.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{
    
    template<typename m1, typename m2>
    bool systemGenericCollition<m1,m2>::collitionEntity(EGE::CORE::EntityId id, m1 *mPlayer, m2 *mEntities){

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
    bool systemGenericCollition<m1,m2>::collitionSprite(EGE::CORE::EntityId id, m1 *mPlayer, m2 *mEntities){

            /*Obtenemos el vector de posición y al sprite del jugador*/
            auto componentPositionPlayer = mPlayer -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>(id);
            auto vectorPositionPlayer = componentPositionPlayer -> getPosition();
            auto componentSpritePlayer = mPlayer -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Sprite>(id);
            auto spritePlayer = componentSpritePlayer -> getSprite();


            /*Obtenemos a las entidades con las que se comprobara si choco el jugador*/
            auto entities = mEntities -> getEntities();

            for(auto i : entities){
                /*Obtenemos el vector de posición y al sprite de la entidad en turno*/
                auto componentPositionEntity = i.second -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Position>();
                auto vectorPositionEntity = componentPositionEntity -> getPosition();
                auto componentSpriteEntity = i.second -> template getComponent<EGE::STD::TERMINAL::WINDOWS::Sprite>();
                auto spriteEntity = componentSpriteEntity -> getSprite();

                /*Interadores la P es pla player y la E es para entidad*/
                int kP = 0;
                int kE = 0;

                /*Recorremos al sprite del Player*/
                for(int iP =0; iP<componentSpritePlayer -> getN(); iP++){
                    for(int jP = 0; jP<componentSpritePlayer -> getN(); jP++){
                        
                        /*Recorremos al sprite de Entity*/
                        for(int iE = 0; iE<componentSpriteEntity -> getN(); iE++){
                            for(int jE=0; jE<componentSpriteEntity -> getN(); jE++){

                                /*Verificamos que se esten tocando*/
                                if(std::get<0>(vectorPositionPlayer[kP]) == std::get<0>(vectorPositionEntity[kE])){
                                    if(std::get<1>(vectorPositionPlayer[kP]) == std::get<1>(vectorPositionEntity[kE])){

                                        /*Verificamos que no sean partes a ignorar del sprite*/
                                        if(spritePlayer[iP][jP] != componentSpritePlayer -> getCharToIgnore()){
                                            if(spriteEntity[iE][jE] != componentSpriteEntity -> getCharToIgnore()){
                                                return true;
                                            }
                                        }
                                    }
                                }
                                kE++;
                            }
                        }
                        kP++;

                        /*Reseteamos este iterador ya que se dio una vuelta*/
                        kE = 0;
                    }
                }
            }
            
            return false;
    }
}

#endif