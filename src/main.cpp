#include <iostream>
#include "./core/Entity.tpp"
#include "./core/System.tpp"
#include "./core/Component.tpp"

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

class componenteRender : public EGE::Component<componenteRender>{
    public:
        int x = 10,y= 11;

        int suma(){return x+y;}
};

class systemaDeGestionDeRecursos : public EGE::System<systemaDeGestionDeRecursos>{
    public:
        void print(){
            std::cout << "Me la pela el dark souls\n";
        }
};

int main(){
    systemaDeGestionDeRecursos p;
    p.print();
}
