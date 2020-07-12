#include <core/Manager.hpp>

namespace EGE::CORE{
    
    template<typename Type>
    void Manager<Type>::addEntity(){
        entities.push_back(new Type());
    }
}