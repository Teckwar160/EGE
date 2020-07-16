#ifndef WINDOWSTERMINAL
#define WINDOWSTERMINAL

#include <core/Entity.hpp>
#include <core/Manager.hpp>
#include <core/alias.hpp>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

namespace EGE::CORE::TERMINAL::WINDOWS{
    class Terminal : public EGE::CORE::Entity<Terminal>{
        private:
		/**Tamaño en x del tablero*/
		int largo;

		/**Tamaño en y del tablero*/
		int alto;

		/**Caracter de las lineas horizontales del tablero*/
		char cHorizontal;

		/**Caracter de las lineas verticales del tablero*/
		char cVertical;

		/**Caracter de la esquina superior izquierda del tablero*/
		char cEsquina1;

		/**Caracter de la esquina superior derecha del tablero*/
		char cEsquina2;

		/**Caracter de la esquina inferiro izquierda del tablero*/
		char cEsquina3;

		/**Carcter de la esquina inferiro derecha del tablero*/
		char cEsquina4;

        public:
		/**
		 *@brief Método constructor del tablero,
		 *si se desea se pueden colocar unicamente los parametros de largo y alto y
		 *se creara un tablero por default, si se desea personalizar usar los demas paramatros.
		 *
		 *@param largo Tamaño en x del tablero.
		 *@param alto Tamaño en y del tablero.
		 */
		Terminal(int largo, int alto);

		/**
		 *@brief Método destructor de la clase.
		 */
		~Terminal();

		/**
		 *@brief Método que mueve el cursor en la temrinal.
		 *@param x Coordenada en x en la temrinal.
		 *@param y Coordenada en y en la temrinal.
		 */
		void gotoxy(int x, int y);

		/**
		 *@brief Método que oculta el cursor de la terminal.
		 */
		void ocultarCursor();

		/**
		 *@brief Métdodo que pinta los limites del tablero.
		 *@param cHorizontal Caracter de las lineas horizontales del tablero.
		 *@param cVertical Caracter de las lineas verticales del tablero.
		 *@param cEsquina1 Caracter de la esquina superior izquierda del tablero.
		 *@param cEsquina2 Caracter de la esquina superior derecha del tablero.
		 *@param cEsquina3 Caracter de la esquina inferiro izquierda del tablero.
		 *@param cEsquina4 Carcter de la esquina inferiro derecha del tablero.
		 */
		void pintarLimites(char cHorizontal = 205, char cVertical = 186, char cEsquina1 = 201, char cEsquina2 = 187, char cEsquina3 = 200, char cEsquina4 = 188);

		int getLargo();

		int getAlto();
    };

    class managerTerminal : public EGE::CORE::Manager<Terminal>{
        public:
            EntityId addEntity(int x, int y);
    };
}

#endif