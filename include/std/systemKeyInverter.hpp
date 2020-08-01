#ifndef SYSTEMKEYINVERTER_HPP
#define SYSTEMKEYINVERTER_HPP

#include <core/System.hpp>
#include <core/Alias.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    class systemKeyInverter : public EGE::CORE::System<char>{
        public:
            char update(char key);
    };
}

#endif