#ifndef WINDOWSTERMINAL
#define WINDOWSTERMINAL
#if defined(_WIN32)

#include <core/Entity.hpp>
#include <core/Manager.hpp>
#include <core/alias.hpp>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>

namespace EGE::STD::TERMINAL::WINDOWS{
    class Terminal : public EGE::CORE::Entity<Terminal>{
        private:
		/**Tamaño en x del tablero*/
		int largo;

		/**Tamaño en y del tablero*/
		int alto;

		/**Instancia de Terminal*/
		static inline Terminal *terminal = nullptr;

		/**
		 *@brief Método constructor del tablero,
		 *@param largo Tamaño en x del tablero.
		 *@param alto Tamaño en y del tablero.
		 */
		Terminal(int largo, int alto);

        public:

		/**
		 * @brief Método que regresa una instancia de Terminal.
		 * @param x Tamaño en horizontal del tablero.
		 * @param y Tamaño en vertical del tablero.
		 * @return Instancia unica de terminal.
		 */
		static Terminal *getTerminal(int x,int y);

		/**
		 * @brief Método que regresa una instancia de Terminal.
		 * @return Instancia unica de terminal.
		 */
		static Terminal *getTerminal();

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

		/**
		 * @brief Método que regresa el largo del tablero.
		 * @return Largo del tablero.
		 */
		int getLargo();

		/**
		 * @brief Método que regresa el alto de ltablero.
		 * @return Alto del tablero.
		 */
		int getAlto();
    };

	class managerTerminal : public EGE::CORE::Manager<Terminal>{
		public:
			EGE::CORE::EntityId addEntity(int x, int y);
	};
}
#endif
#endif