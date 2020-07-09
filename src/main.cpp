#include <iostream>
#include "..\include\core\Entity.hpp"
#include "core\Entity.tpp"

/**
 *@brief Clase pokemon
 */
class pokemon : public EGE::Entity<pokemon>{
    public:
        void print(){
            std::cout << "Picachu: " << this -> getEntityType() << std::endl;
        }
};

class digimon : public EGE::Entity<digimon>{
     public:
        void print(){
            std::cout << "Digimon: " << this -> getEntityType() << std::endl;
        }   
};

int main(){
    pokemon poke;
    digimon di;
    di.print();
    poke.print();
    di.print();

    pokemon p;
    p.print();

    if(di.getEntityType() == pokemon::getEntityType()){
        std::cout << "Si jalo\n";
    }else{
        std::cout << "No jalo\n";
    }
}