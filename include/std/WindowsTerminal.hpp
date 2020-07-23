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
		int width;

		/**Tamaño en y del tablero*/
		int tall;

		/**Instancia de Terminal*/
		static inline Terminal *terminal = nullptr;

		/**
		 *@brief Método constructor del tablero,
		 *@param width Tamaño en x del tablero.
		 *@param tall Tamaño en y del tablero.
		 */
		Terminal(int width, int tall);

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
		 *@param charHorizontal Caracter de las lineas horizontales del tablero.
		 *@param charVertical Caracter de las lineas verticales del tablero.
		 *@param charCorner1 Caracter de la esquina superior izquierda del tablero.
		 *@param charCorner2 Caracter de la esquina superior derecha del tablero.
		 *@param charCorner3 Caracter de la esquina inferiro izquierda del tablero.
		 *@param charCorner4 Carcter de la esquina inferiro derecha del tablero.
		 */
		void pintarLimites(char charHorizontal = 205, char charVertical = 186, char charCorner1 = 201, char charCorner2 = 187, char charCorner3 = 200, char charCorner4 = 188);

		/**
		 * @brief Método que regresa el largo del tablero.
		 * @return Largo del tablero.
		 */
		int getWidth();

		/**
		 * @brief Método que regresa el alto de ltablero.
		 * @return Alto del tablero.
		 */
		int getTall();
    };

	class mTerminal : public EGE::CORE::Manager<Terminal>{
		public:
			EGE::CORE::EntityId addEntity(int x, int y);
	};
}
#endif
#endif