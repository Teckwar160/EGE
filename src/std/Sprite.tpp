#if defined(_WIN32)
#include <core/Sprite.hpp>

namespace EGE::STD::WINDOWS{
    Pixel::Pixel(){

    }

    Pixel::~Pixel(){

    }

    void Pixel::setPixel(char pixel){
        this -> pixel = pixel;
    }

    void Pixel::setX(int x){
        this -> x = x;
    }

    void Pixel::setY(int y){
        this -> y = y;
    }

    char Pixel::getPixel(){
        return this -> pixel;
    }

    int Pixel::getX(){
        return this -> x;
    }

    int Pixel::getY(){
        return this -> y;
    }

    void Controles::movimiento(char Tecla, int *x, int *y, bool flechas){

        if(flechas){
            switch(Tecla){
                case ARRIBA:
                    *y-=1;
                    break;
                case IZQUIERDA:
                    *x-=1;
                    break;
                case ABAJO:
                    *y+=1;
                    break;
                case DERECHA:
                    *x+=1;
                    break;
            }

        }else{
            switch(Tecla){
                case 'w':
                case 'W':
                    *y-=1;
                    break;
                case 'a': 
                case 'A':
                    *x-=1;
                    break;
                case 's':
                case 'S':
                    *y+=1;
                    break;
                case 'd': 
                case 'D':
                    *x+=1;
                    break;
            }		
        }
    }

    void Sprite::cargadorDeSprite(std::string nombre){

        this -> dimensionReal = n*n;

        /*dirección del sprite*/
        std::string direccion = "resources\\sprites\\"+ nombre + ".txt";

        /*Variable que leé el Sprite*/
        std::ifstream sprite;

        sprite.open(direccion,std::ios::in);

        /*Varibales temporales*/
        char tmp;


        if(!sprite.fail()){
            for(int i = 0; i<this -> n; i++){
                for(int j = 0; j<this -> n; j++){
                    sprite >> tmp;
                    this -> contenedor[i][j].setPixel(tmp);  
                }
            }		
        }else{
            std::cout << "Fallo #0" << std::endl;
        }

        sprite.close();

        /*Ahora quitamos el fondo del sprite*/
        for(int i = 0; i<this -> n; i++){
            for(int j = 0; j<this -> n; j++){
                if(this -> contenedor[i][j].getPixel() == this -> caracterAIgnorar){
                    this -> dimensionReal-= 1;
                }
            }
        }	
    }

    void Sprite::convertidorDeR2aR(){
        /*Iterador*/
        int k=0;

        /*Pasamos de una matriz de R^2 a un vector de R*/
        for(int i = 0; i<this -> n; i++){
            for(int j = 0; j<this -> n; j++){
                if(this -> contenedor[i][j].getPixel() != this -> caracterAIgnorar){
                    this -> sprite[k].setPixel(this -> contenedor[i][j].getPixel());
                    this -> sprite[k].setX(this -> contenedor[i][j].getX());
                    this -> sprite[k].setY(this -> contenedor[i][j].getY());
                    k++;
                }
            }
        }
    }

    Sprite::Sprite(int n, int pX, int pY, std::string nombre,bool usarFlechas, char caracterAIgnorar){

        /*Guardamos datos basicos*/
        this -> n = n;
        this -> nombre = nombre;
        this -> usarFlechas = usarFlechas;
        this -> caracterAIgnorar = caracterAIgnorar;


        /*Creamos al contenedor del Sprite*/
        this -> contenedor = new Pixel*[this -> n];

        for(int i = 0; i<this -> n; i++){
            this -> contenedor[i] = new Pixel[this -> n];
        }	

        /*Carga al sprite al molde*/
        this -> cargadorDeSprite(this -> nombre);


        /*Definimos las coordenadas de cada pixel*/
        for(int i = 0; i<this -> n; i++){
            for(int j = 0; j<this -> n; j++){
                this -> contenedor[i][j].setX(pX +j);
                this -> contenedor[i][j].setY(pY+i);
            }
        }

        /*Creamos el vector que contendra el sprite*/
        this -> sprite = new Pixel[this -> dimensionReal];

        /*Convertimos la matriz a un vector*/
        this -> convertidorDeR2aR();

    }

    Sprite::~Sprite(){

        /*Liberamos la memoria del contenedor*/
        for(int i = 0; i<this -> n; i++){
            delete this -> contenedor[i];
        }

        delete[] this -> contenedor;

        /*Liberamos la memoria del sprite*/
        delete[] this -> sprite;
    }

    void Sprite::visualizar(EGE::STD::TERMINAL::WINDOWS::Terminal *cursor, bool ocultar){

        /*Pone en cursor en el primer pixel del sprite*/
        cursor -> gotoxy(this -> sprite[0].getX() , this -> sprite[0].getY());

        /*Muestra el sprite en pantalla*/
        for(int i = 0;  i< this -> dimensionReal; i++){
            cursor -> gotoxy(this -> sprite[i].getX(), this -> sprite[i].getY());

            if(!ocultar){
                std::cout << this -> sprite[i].getPixel();
            }else{
                std::cout << ' ';
            } 
        }	
    }

    void Sprite::mover(char Tecla,EGE::STD::TERMINAL::WINDOWS::Terminal *tablero){

        /*Variables temporales*/
        int x;
        int y;

        /*Borra al viejo sprite*/
        this -> visualizar(tablero,true);

        /*Recorremos a los pixeles*/
        for(int i = 0; i< this -> dimensionReal; i++){

            /*Obtenemos las coordenadas actuales*/
            x = this -> sprite[i].getX();
            y = this -> sprite[i].getY();

            /*Las asctualizamos*/
            this -> movimiento(Tecla,&x,&y,this -> usarFlechas);

            sprite[i].setX(x);
            sprite[i].setY(y);
        }
    }

}
#endif