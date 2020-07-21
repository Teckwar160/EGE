#include <iostream>
#include <core/Entity.tpp>
#include <core/System.tpp>
#include <core/Component.tpp>
#include <core/Manager.tpp>
#include <std/WindowsTerminal.tpp>

int main(){

    auto tp = EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal(50,30);

    tp -> ocultarCursor();
    tp -> pintarLimites();

    delete tp;
}
