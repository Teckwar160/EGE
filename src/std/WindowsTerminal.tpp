/**!<Bibliotecas necesarias*/
#include <core/WindowsTerminal.hpp>

namespace EGE::CORE::TERMINAL::WINDOWS{

    Terminal::Terminal(int largo, int alto){
        this -> largo = largo;
        this -> alto = alto;
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

    void Terminal::ocultarCursor(){
        HANDLE hcon;
        hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursor;

        cursor.dwSize = 2;
        cursor.bVisible = FALSE;

        SetConsoleCursorInfo(hcon,&cursor);		
    }

    void Terminal::pintarLimites(char cHorizontal, char cVertical, char cEsquina1, char cEsquina2, char cEsquina3, char cEsquina4){

        /*Puede el usuario determinar el caracter de borde*/

        /*Pinta las lineas horizontales*/
        for(int i = 0; i<largo; i++){
            this -> gotoxy(i,0); printf("%c",cHorizontal);
            this -> gotoxy(i,alto); printf("%c",cHorizontal);
        }

        /*Pinta las lineas verticales*/
        for(int i = 0; i<alto; i++){
            this -> gotoxy(0,i); printf("%c",cVertical);
            this -> gotoxy(largo,i); printf("%c",cVertical);
        }

        /*Pinta las esquinas*/
        this -> gotoxy(0,0); printf("%c",cEsquina1);
        this -> gotoxy(largo,0); printf("%c",cEsquina2);
        this -> gotoxy(0,alto); printf("%c",cEsquina3);
        this -> gotoxy(largo,alto); printf("%c",cEsquina4);	
    }

    int Terminal::getLargo(){
        return this -> largo;
    }
            
    int Terminal::getAlto(){
        return this -> alto;
    }
}