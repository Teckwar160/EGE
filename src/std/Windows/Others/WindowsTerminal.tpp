#ifndef WINDOWSTERMINAL_TPP
#define WINDOWSTERMINAL_TPP

#include <std/Windows/Others/WindowsTerminal.hpp>

namespace EGE::STD::TERMINAL::WINDOWS{

    Terminal::Terminal(int width, int tall){
        this -> width = width;
        this -> tall = tall;
    }

    Terminal *Terminal::getTerminal(int x,int y){
        if(terminal != nullptr){
            return terminal;
        }else{
            terminal = new Terminal(x,y);
            return terminal;
        }
    }

    Terminal *Terminal::getTerminal(){
        return terminal;
    }

    Terminal::~Terminal(){
        delete terminal;
    }

    void Terminal::gotoxy(int x, int y){
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;

        SetConsoleCursorPosition(hcon,dwPos);
    }

    void Terminal::setColor(unsigned short color){
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon,color);
    }

    void Terminal::hideCursor(){
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursor;

        cursor.dwSize = 2;
        cursor.bVisible = FALSE;

        SetConsoleCursorInfo(hcon,&cursor);		
    }

    void Terminal::drawLimits(char charHorizontal, char charVertical, char charCorner1, char charCorner2, char charCorner3, char charCorner4){

        /**Modifica el tamaño de la terminal*/
        std::string primera = "mode con:cols=" + std::to_string(this -> width +2);
        std::string segunda = " lines=" + std::to_string(this -> tall+1);
        std::string limites = primera + segunda;

        system(limites.c_str());

        /*Pinta las lineas horizontales*/
        for(int i = 0; i<this -> width; i++){
            this -> gotoxy(i,0); printf("%c",charHorizontal);
            this -> gotoxy(i,this -> tall); printf("%c",charHorizontal);
        }

        /*Pinta las lineas verticales*/
        for(int i = 0; i<tall; i++){
            this -> gotoxy(0,i); printf("%c",charVertical);
            this -> gotoxy(this -> width,i); printf("%c",charVertical);
        }

        /*Pinta las esquinas*/
        this -> gotoxy(0,0); printf("%c",charCorner1);
        this -> gotoxy(this -> width,0); printf("%c",charCorner2);
        this -> gotoxy(0,this -> tall); printf("%c",charCorner3);
        this -> gotoxy(this -> width,this -> tall); printf("%c",charCorner4);	

    }

    int Terminal::getWidth(){
        return this -> width;
    }
            
    int Terminal::getTall(){
        return this -> tall;
    }

    void Terminal::init(){
        this -> hideCursor();
        this -> drawLimits(205,186,201,187,200,188);
    }

    EGE::CORE::EntityId mTerminal::addEntity(int x, int y){
        if(!this -> isCreated){
            this -> isCreated = true;
            entities.insert({numEntities,EGE::STD::TERMINAL::WINDOWS::Terminal::getTerminal(x,y)});
            numEntities++;
        }
        return entities[entities.size() - 1]->getEntityId();

    };

    void mTerminal::terminalDefault(EGE::CORE::EntityId id){
        auto terminal = entities.find(id);
        terminal -> second -> init();
    }

    void mTerminal::terminalPersonalized(EGE::CORE::EntityId id,char charHorizontal,char charVertical, char charCorner1, char charCorner2, char charCorner3, char charCorner4){
        auto terminal = entities.find(id);
        terminal -> second -> hideCursor();
        terminal -> second ->drawLimits(charHorizontal,charVertical,charCorner1,charCorner2,charCorner3,charCorner4);
    }

    void mTerminal::terminalSetColor(EGE::CORE::EntityId id, unsigned short color){
        auto terminal = entities.find(id);
        terminal -> second -> setColor(color);
    }
}
#endif