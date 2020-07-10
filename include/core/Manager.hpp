#ifndef MANAGER_HPP
#define MANAGER_HPP

/**Bibliotecas necesarias*/
#include <unordered_map>
#include <vector>

template<typename Type>
class manager{
    public:
        std::vector<Type*> entities;
        std::unordered_map<EGE::CORE::ComponentType,std::vector<EGE::CORE::ComponentBase>> components;
};
#endif